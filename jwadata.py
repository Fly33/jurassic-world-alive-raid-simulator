import sys
import os
import json
import re
import traceback
import json_fix

PATH = "assets\\Database\\"
DATA = "Assets\\Data\\DataDatabase.json"


def DevName(s, guid=''):
    return ''.join(re.split(r'\W+', ''.join(w.capitalize() for w in s.split()))) + guid[:4].upper()


def Name(s):
    return ''.join(w.capitalize() for w in re.split(r'(\W+)', s)).strip()


def GetPath(path):
    with open(path, encoding="utf8") as f:
        return json.load(f)


def Num(x):
    if type(x) is float:
        return str(x).rstrip('0').rstrip('.')
    return str(x)


GuidData = {}


def GetGuid(data, guid):
    if guid not in GuidData:
        GuidData[guid] = GetPath(PATH + data['Data'][guid])
    return GuidData[guid]


class Action:
    def __init__(self, name, *args, **flags):
        self.name = name
        self.flags = [key for key, value in flags.items() if value]
        self.args = args

    def ToString(self):
        name = self.name
        args = self.args
        if self.flags:
            flags = '|'.join(self.flags)
            args = (*args, flags)
        args = ', '.join(str(arg) for arg in args)
        return f'{name}({args})'

    def ToCompact(self):
        name = GetShort('actions::' + self.name)
        args = self.args
        if self.flags:
            flags = '|'.join(GetShort(flag) for flag in self.flags)
            args = (*args, flags)
        args = ','.join(Num(arg) for arg in args)
        return f'{name}({args})'

    def __json__(self):
        return self.ToString()


def ParseAction(data, guid):
    try:
        action_data = GetGuid(data, guid)
        action = {}
        if action_data.get("tg", "Self") == "Self":
            action["Target"] = "Self"
        elif action_data.get("tg", "Self") == "Ally":
            if action_data.get("tc", 1) == 4:
                action["Target"] = "Team"
            elif action_data.get("tr", "None") == "LowestHPIgnoringMaxHP":
                action["Target"] = "LowestHPTeammate"
            elif action_data.get("tr", "None") == "LowestCrit": # unused
                action["Target"] = "LowestCritTeammate"
            elif action_data.get("tr", "None") == "None":
                action["Target"] = "Team"
            else:
                raise Exception(f'Unknown target "{action_data.get("tr")}"')
        elif action_data.get("tg", "Self") == "Enemy":
            if action_data.get("tc", 1) == 4:
                action["Target"] = "AllOpponents"
            elif action_data.get("tr", "None") == "MostBuffed":
                action["Target"] = "MostPositiveEffects"
            elif action_data.get("tr", "None") == "HighestCrit": # unused
                action["Target"] = "HighestCrit"
            elif action_data.get("tr", "None") == "HighestDamage":
                action["Target"] = "HighestDamage"
            elif action_data.get("tr", "None") == "LowestDamage":
                action["Target"] = "LowestDamage"
            elif action_data.get("tr", "None") == "HighestHP":
                action["Target"] = "HighestHP"
            elif action_data.get("tr", "None") == "LowestHP":
                action["Target"] = "LowestHP"
            elif action_data.get("tr", "None") == "Random":
                action["Target"] = "Random"
            elif action_data.get("tr", "None") == "HighestSpeed":
                action["Target"] = "Fastest"
            elif action_data.get("tr", "None") == "LowestSpeed":
                action["Target"] = "Slowest"
            elif action_data.get("tr", "None") == "None":
                action["Target"] = "AllOpponents"
            else:
                raise Exception(f'Unknown target "{action_data.get("tr")}"')
        elif action_data.get("tg", "None") == "Contextual":
            action["Target"] = "Attacker"
        else:
            raise Exception(f'Unknown target "{action_data.get("tg")}"')
        type = action_data['$type']
        if type.startswith("BeDa"):
            if type.startswith("BeDaBaDa"):
                action["Action"] = Action("Attack", action_data["dm"] / 10000000., BYPASS_ARMOR=action_data["sb"], PRECISE=action_data["db"], ALWAYS_CRITS=action_data["ach"])
            elif type.startswith("BeDaMeDa"):
                action["Action"] = Action("DevouringAttack", action_data["dm"] / 10000000., action_data["mp"] / 100000., action_data["md"], BYPASS_ARMOR=action_data["sb"], PRECISE=action_data["db"])
            elif type.startswith("BeDaHpBaDa"):
                if action_data['tg'] == "Self":
                    action["Action"] = Action("Sacrifice", action_data["dp"] / 100000.)
                else:
                    action["Action"] = Action("Rend", action_data["dp"] / 100000., BYPASS_ARMOR=action_data["sb"], PRECISE=action_data["db"])
            else:
                raise Exception(f'Unknown action type "{type.split(",")[0]}"')
        elif type.startswith("BeEf"):
            if type.startswith("BeEfIn"):
                if type.startswith("BeEfInScDa"):
                    action["Action"] = Action("Remove", POSITIVE_EFFECTS=True)
                elif type.startswith("BeEfInNuDa"):
                    action["Action"] = Action("Remove",
                                            DODGE=action_data["ne"]=="Dodge",
                                            CLOAK=action_data["ne"]=="Cloak",
                                            INCREASED_SPEED=action_data["ne"]=="BuffSpeed",
                                            TAUNT=action_data["ne"]=="Taunt",
                                            INCREASED_CRIT_CHANCE=action_data["ne"]=="BuffCrit",
                                            INCREASED_DAMAGE=action_data["ne"]=="BuffAttack")
                elif type.startswith("BeEfInDeShDa"):
                    action["Action"] = Action("Remove", SHIELD=True)
                elif type.startswith("BeEfInClDa"):
                    action["Action"] = Action("Cleanse", 
                                            NEGATIVE_EFFECTS=not action_data.get("ce") or action_data.get("ce") == "All",
                                            REDUCED_DAMAGE=action_data.get("ce")=="DebuffAttack",
                                            VULNERABILITY=action_data.get("ce")=="Vulnerable",
                                            REDUCED_SPEED=action_data.get("ce")=="DebuffSpeed",
                                            DAMAGE_OVER_TIME=action_data.get("ce")=="DamageOverTime",
                                            REDUCED_CRIT_CHANCE=action_data.get("ce")=="DebuffCrit")
                elif type.startswith("BeEfInReDeDaDa"):
                    action["Action"] = Action("Cleanse", REDUCED_DAMAGE=True)
                elif type.startswith("BeEfInReHaFoSwDa"):
                    action["Action"] = Action("Swap")
                else:
                    raise Exception(f'Unknown action type "{type.split(",")[0]}"')
            elif type.startswith("BeEfDu"):
                if type.startswith("BeEfDuSwPrDa"):
                    action["Action"] = Action("UnableToSwap", action_data["d"])
                elif type.startswith("BeEfDuVuDa"):
                    action["Action"] = Action("ImposeVulnerability", action_data["vuln"] / 100000., action_data["d"], action_data["eac"])
                elif type.startswith("BeEfDuShDa"):
                    action["Action"] = Action("Shield", action_data["slvl"] / 100000., action_data["d"] if action_data.get("dho") != "END_OF_THIS_TURN" else 0, action_data["eac"])
                elif type.startswith("BeEfDuStDa"):
                    action["Action"] = Action("Stun", action_data["ps"] / 100000., action_data["d"])
                elif type.startswith("BeEfDuDoDa"):
                    action["Action"] = Action("DamageOverTime", action_data["ppt"] / 100000., action_data["d"])
                elif type.startswith("BeEfDuLoDa"):
                    action["Action"] = Action("UnableToSwap", action_data["d"])
                elif type.startswith("BeEfDuTaDa"):
                    action["Action"] = Action("Taunt", action_data["d"])
                elif type.startswith("BeEfDuDodDa"):
                    action["Action"] = Action("Dodge", action_data["p"] / 100000., action_data["pdr"] / 100000., action_data["d"] if action_data.get("dho") != "END_OF_THIS_TURN" else 0, action_data["eac"])
                elif type.startswith("BeEfDuInDa"):
                    action["Action"] = Action("Cloak", action_data["mn"] / 10000000., action_data["p"] / 100000., action_data["pdr"] / 100000., action_data["d"])
                elif type.startswith("BeEfDuBuDeDa"):
                    if action_data["aa"] == "AttackPower":
                        if action_data["p"] > 0:
                            action["Action"] = Action("IncreaseDamage", action_data["p"] / 100000., action_data["d"], action_data["eac"])
                        else:
                            action["Action"] = Action("ReduceDamage", -action_data["p"] / 100000., action_data["d"], action_data["eac"])
                    elif action_data["aa"] == "CriticalHitChance":
                        if action_data["p"] > 0:
                            action["Action"] = Action("IncreaseCritChance", action_data["p"] / 100000., action_data["d"], action_data["eac"])
                        else:
                            action["Action"] = Action("ReduceCritChance", -action_data["p"] / 100000., action_data["d"], action_data["eac"])
                    elif action_data["aa"] == "Speed":
                        if action_data["p"] > 0:
                            action["Action"] = Action("IncreaseSpeed", action_data["p"] / 100000., action_data["d"])
                        else:
                            action["Action"] = Action("ReduceSpeed", -action_data["p"] / 100000., action_data["d"])
                    elif action_data["aa"] == "Armor":
                        if action_data["p"] > 0:
                            action["Action"] = Action("IncreaseArmor", action_data["p"] / 100000., action_data["d"], action_data["eac"])
                        else:
                            action["Action"] = Action("ReduceArmor", -action_data["p"] / 100000., action_data["d"], action_data["eac"])
                    else:
                        raise Exception(f'Unknown buff kind "{action_data["aa"]}"')
                else:
                    raise Exception(f'Unknown action type "{type.split(",")[0]}"')
            else:
                raise Exception(f'Unknown action type "{type.split(",")[0]}"')
        elif type.startswith("BeHe"):
            if type.startswith("BeHePeDa"):
                if action_data.get("ttb"):
                    action["Action"] = Action("RallyHeal", action_data["p"] / 100000.)
                elif action_data.get("pb") == "TargetMaxHp":
                    action["Action"] = Action("FixedHeal", action_data["p"] / 100000.)
                elif action_data.get("pb") == "HealerBuffedAttack":
                    action["Action"] = Action("Heal", action_data["p"] / 10000000.)
                else:
                    raise Exception(f'Unknown action type "{type.split(",")[0]}"')
            else:
                raise Exception(f'Unknown action type "{type.split(",")[0]}"')
        else:
            raise Exception(f'Unknown action type "{type.split(",")[0]}"')
        
        return action
    except Exception:
        print(action_data)
        raise


ImmutableTargets = ('Self', 'Team', 'AllOpponents', 'Attacker', 'Last')


def ParseAbility(data, guid, l10n):
    try:
        if not guid:
            return {
                'dev_name': "",
                'name': "Ability disabled",
                'delay': 0,
                'cooldown': 0,
                'priority': "false",
                'actions': []
            }
        ability_data = GetGuid(data, guid)
        name = l10n.get(ability_data['n'], ability_data['n'])
        ability = {
            'dev_name': DevName(name, guid),
            'name': Name(name),
            'delay': ability_data['cod'],
            'cooldown': ability_data['c'],
            'priority': "true" if ability_data['pri'] != 'n' else "false",
            'actions': []
        }
        default_target = "Unknown"
        for action_data in ability_data['bl']:
            action = ParseAction(data, action_data['b']['guid'])
            if action_data['t'] == 's':
                default_target = action["Target"]
            elif action_data['t'] == 'u' and default_target != "Unknown":
                action["Target"] = default_target if default_target in ImmutableTargets else "Last"
            if len(ability['actions']) > 0 and (
                    ability['actions'][-1]["Target"] in ImmutableTargets and ability['actions'][-1]["Target"] == action["Target"] or 
                    ability['actions'][-1]["Target"] not in ImmutableTargets and action["Target"] == "Last"
                ) and (
                    ability['actions'][-1]["Action"].name == "Remove" and action["Action"].name == "Remove" or
                    ability['actions'][-1]["Action"].name == "Cleanse" and action["Action"].name == "Cleanse"
                ):
                ability['actions'][-1]["Action"].flags.extend(action["Action"].flags)
            else:
                ability['actions'].append(action)
        return ability
    except:
        print(ability_data)
        print(ability)
        raise


Factors = {
    25: "1./4",
    33: "1./3",
    50: "1./2",
    66: "2./3"
}


def GetAbility(data, ability_data, kind, ability_dex, l10n):
    try:
        if ability_data['ai']['guid'] not in ability_dex:
            ability = ParseAbility(data, ability_data['ai']['guid'], l10n=l10n)
            ability['type'] = kind + 'Ability'
            if ability_data['$type'].startswith('ThAbIt'):
                ability_threatened = ParseAbility(data, ability_data['otai']['guid'], l10n=l10n)
                ability['type'] = 'Threatened' + ability['type']
                if ability_data['hltc'] == "lower":
                    ability['threatened_compare'] = '<='
                elif ability_data['hltc'] == "higher":
                    ability['threatened_compare'] = '>'
                else:
                    raise Exception(f'Unknown threatened condition "{ability_data["hltc"]}')
                ability['threatened_factor'] = Factors[ability_data['hltv']]
                ability['threatened'] = ability_threatened
            elif ability_data['$type'].startswith('ReAbIt'):
                ability_revenge = ParseAbility(data, ability_data['rai']['guid'], l10n=l10n)
                ability['type'] = 'Revenge' + ability['type']
                ability['revenge'] = ability_revenge
            ability_dex[ability_data['ai']['guid']] = ability
        return ability_dex[ability_data['ai']['guid']]
    except:
        print(ability_data)
        raise


def GetDino(l10n, data, dino_data, ability_dex):
    try:
        rarity = GetGuid(data, dino_data['r']['guid'])
        attr = GetGuid(data, dino_data['rl'][0]['att']['guid'])
        if dino_data["dn"] == "BTroodoboa": # исправляем косяки макак
             dino_data['lkn'] = 'IDS_BTROODOBOA'
        elif dino_data['lkn'] == "IDS_MKOOLASUCHUS2":
            dino_data['lkn'] = "IDS_MKOOLASUCH2"
        if dino_data['lkn'].startswith('IDS_M') and dino_data['lkn'][:4] + dino_data['lkn'][5:] in l10n:
            name = l10n.get(dino_data['lkn'][:4] + dino_data['lkn'][5:]) + ' MINION'
        elif dino_data['lkn'] in l10n:
            name = l10n.get(dino_data['lkn'])
        elif dino_data['lkn'] == 'IDS_BARCTODUS':
            name = "ARCTODUS BOSS"
        else:
            assert(False)
        dino = {
            'dev_name': DevName(name),
            'name': Name(name),
            'rarity': l10n[rarity['localizedName']],
            'flock': 3 if dino_data.get('it', False) else 1,
            'health': attr['hp'],
            'damage': attr['miap'],
            'speed': attr['s'],
            'armor': attr['def'] / 100000,
            'crit': attr['chc'] / 100000,
            'crit_reduction_resistance': attr['rcrit'] / 100000,
            'damage_over_time_resistance': attr['rdot'] / 100000,
            'damage_reduction_resistance': attr['rd'] / 100000,
            'rend_resistance': attr['rr'] / 100000,
            'speed_reduction_resistance': attr['rdec'] / 100000,
            'stun_resistance': attr['rs'] / 100000,
            'swap_prevention_resistance': attr['rsp'] / 100000,
            'taunt_resistance': attr['rt'] / 100000,
            'vulnerable_resistance': attr['rv'] / 100000,
            'armor_reduction_resistance': attr.get('rarm', 0) / 100000,
            'ability': None,
            'counter': None,
        }
        dino['ability'] = [[GetAbility(data, ability_data, '', ability_dex, l10n=l10n)['dev_name'] for ability_data in dino_data['rl'][round]['al']] for round in range(len(dino_data['rl']))]
        if dino_data['rl'][0]['ac']:
            dino['counter'] = GetAbility(data, dino_data['rl'][0]['ac'], 'Counter', ability_dex, l10n=l10n)['dev_name']
        return dino
    except:
        print(dino_data)
        raise


CREATURES_STATIC_DATA = "Assets\\Data\\CreaturesStaticData\\"


def GetTeam(l10n, data, dino_dex, ability_dex):
    for file in os.listdir(PATH + CREATURES_STATIC_DATA):
        dino_data = GetPath(PATH + CREATURES_STATIC_DATA + file)
        if not dino_data['el']:
            continue
        dino = GetDino(l10n, data, dino_data, ability_dex)
        dino_dex[dino['dev_name']] = dino


def GetParticipant(l10n, data, participant_data, dino_dex, ability_dex):
    participant = {
        'level': participant_data['rdct']['crlvl'],
        'health_boost': participant_data['rdct']['aepht'],
        'damage_boost': participant_data['rdct']['aepat'],
        'speed_boost': participant_data['rdct']['aepst'],
        'dino': None
    }
    if participant_data['rdct']['pvecrsd']['guid'] not in dino_dex:
        dino_data = GetGuid(data, participant_data['rdct']['pvecrsd']['guid'])
        dino_dex[participant_data['rdct']['pvecrsd']['guid']] = GetDino(l10n, data, dino_data, ability_dex)
    participant['dino'] = dino_dex[participant_data['rdct']['pvecrsd']['guid']]['dev_name']
    return participant


RAID_STATIC_DATA = "Assets\\Data\\Raid\\"


def GetRaid(l10n, data, raid_dex, boss_dex, boss_ability_dex, minion_dex, ability_dex):
    for file in os.listdir(PATH + RAID_STATIC_DATA):
        if not file.startswith("RaidDataTest"):
            continue
        raid_data = GetPath(PATH + RAID_STATIC_DATA + file)
        raid = {
            'boss': GetParticipant(l10n, data, raid_data['rdaipy'][0], boss_dex, boss_ability_dex),
            'minion': [GetParticipant(l10n, data, raid_data['rdaipy'][minion], minion_dex, ability_dex) for minion in range(1, len(raid_data['rdaipy']))]
        }
        raid_dex.append(raid)


def CodeNum(x):
    a = '_qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890'
    r = ''
    r += a[x % 53]
    x //= 53
    while True:
        r += a[x % 63]
        x //= 63
        if x == 0:
            break
    return r


Codes = {}


def GetCode(x):
    if x not in Codes:
        while True:
            code = CodeNum(len(Codes))
            if code not in ('or', 'if', 'do'):
                break
            Codes[hash(code)] = code
        Codes[x] = code
    return Codes[x]


Shorts = {}


def GetShort(x):
    a = 'qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM'
    if x not in Shorts:
        if len(Shorts) < len(a): 
            Shorts[x] = a[len(Shorts)]
        else:
            Shorts[x] = GetCode(x)
    return Shorts[x]


def GetEntity(x, entity):
    if x not in entity:
        entity[x] = GetShort(x)
    return entity[x]


# def WriteDinoDex(dino_file, ability_file, dino_dex):
    # with open(dino_file + ".json", "w") as f:
        # json.dump(dino_dex, f, indent=4)
    # with open(dino_file + ".h", "w") as f:
        # print(f'#ifndef __{dino_file.upper()}__H__', file=f)
        # print(f'#define __{dino_file.upper()}__H__', file=f)
        # print(f'', file=f)
        # print(f'#include "dino.h"', file=f)
        # print(f'', file=f)
        # print(f'namespace {dino_file} {{', file=f)
        # print(f'', file=f)
        # for dino in sorted(dino_dex.values(), key=lambda dino: dino['dev_name']):
            # print(f'extern DinoKind {dino["dev_name"]};', file=f)
        # print(f'', file=f)
        # print(f'}} // namespace {dino_file}', file=f)
        # print(f'', file=f)
        # print(f'#endif // __{dino_file.upper()}__H__', file=f)
    # with open(dino_file + ".cpp", "w") as f:
        # print(f'#include "{dino_file}.h"', file=f)
        # print(f'#include "{ability_file}.h"', file=f)
        # print(f'', file=f)
        # print(f'using namespace {ability_file};', file=f)
        # print(f'', file=f)
        # print(f'namespace {dino_file} {{', file=f)
        # print(f'', file=f)
        # for dino in sorted(dino_dex.values(), key=lambda dino: dino['dev_name']):
            # print(f'DinoKind {dino["dev_name"]}("{dino["name"]}", {dino["rarity"]}, {dino["flock"]}, '\
                  # f'{dino["health"]}, {dino["damage"]}, {dino["speed"]}, {dino["armor"]}, {dino["crit"]}, '\
                  # f'{dino["crit_reduction_resistance"]}, '\
                  # f'{dino["damage_over_time_resistance"]}, '\
                  # f'{dino["damage_reduction_resistance"]}, '\
                  # f'{dino["rend_resistance"]}, '\
                  # f'{dino["speed_reduction_resistance"]}, '\
                  # f'{dino["stun_resistance"]}, '\
                  # f'{dino["swap_prevention_resistance"]}, '\
                  # f'{dino["taunt_resistance"]}, '\
                  # f'{dino["vulnerable_resistance"]}, {{', file=f)
            # for round in range(len(dino['ability'])):
                # print(f'    {{', file=f)
                # for ability in range(len(dino['ability'][round])):
                    # print(f'        &{dino["ability"][round][ability]}{"," if ability != len(dino["ability"][round]) - 1 else ""}', file=f)
                # print(f'    }}{"," if round != len(dino["ability"]) - 1 else ""}', file=f)
            # print(f'}}, {"&" + dino["counter"] if dino["counter"] else "nullptr"});', file=f)
            # print('', file=f)
        # print(f'}} // namespace {dino_file}', file=f)


def WriteDinoDex(dino_dex, f):
    for dino in sorted(dino_dex.values(), key=lambda dino: dino['dev_name']):
        print(f'DinoKind {dino["dev_name"]}("{dino["name"]}", {dino["rarity"]}, {dino["flock"]}, '\
              f'{dino["health"]}, {dino["damage"]}, {dino["speed"]}, {dino["armor"]}, {dino["crit"]}, '\
              f'{dino["crit_reduction_resistance"]}, '\
              f'{dino["damage_over_time_resistance"]}, '\
              f'{dino["damage_reduction_resistance"]}, '\
              f'{dino["rend_resistance"]}, '\
              f'{dino["speed_reduction_resistance"]}, '\
              f'{dino["stun_resistance"]}, '\
              f'{dino["swap_prevention_resistance"]}, '\
              f'{dino["taunt_resistance"]}, '\
              f'{dino["vulnerable_resistance"]}, '\
              f'{dino["armor_reduction_resistance"]}, {{', file=f)
        for round in range(len(dino['ability'])):
            print(f'    {{', file=f)
            for ability in range(len(dino['ability'][round])):
                print(f'        &{dino["ability"][round][ability]}{"," if ability != len(dino["ability"][round]) - 1 else ""}', file=f)
            print(f'    }}{"," if round != len(dino["ability"]) - 1 else ""}', file=f)
        print(f'}}, {"&" + dino["counter"] if dino["counter"] else "nullptr"});', file=f)
        print('', file=f)


def WriteCompactDinoDex(dino_dex, f):
    for dino in sorted(dino_dex.values(), key=lambda dino: dino['dev_name']):
        print(f'{GetShort("DinoKind")} {GetCode(dino["dev_name"])}("{dino["name"]}",{GetShort(dino["rarity"])},{dino["flock"]},'\
              f'{dino["health"]},{dino["damage"]},{dino["speed"]},{Num(dino["armor"])},{Num(dino["crit"])},'\
              f'{Num(dino["crit_reduction_resistance"])},'\
              f'{Num(dino["damage_over_time_resistance"])},'\
              f'{Num(dino["damage_reduction_resistance"])},'\
              f'{Num(dino["rend_resistance"])},'\
              f'{Num(dino["speed_reduction_resistance"])},'\
              f'{Num(dino["stun_resistance"])},'\
              f'{Num(dino["swap_prevention_resistance"])},'\
              f'{Num(dino["taunt_resistance"])},'\
              f'{Num(dino["vulnerable_resistance"])},'\
              f'{Num(dino["armor_reduction_resistance"])},{{', file=f, end='')
        for round in range(len(dino['ability'])):
            print(f'{{', file=f, end='')
            for ability in range(len(dino['ability'][round])):
                print(f'&{GetCode(dino["ability"][round][ability])}{"," if ability != len(dino["ability"][round]) - 1 else ""}', file=f, end='')
            print(f'}}{"," if round != len(dino["ability"]) - 1 else ""}', file=f, end='')
        print(f'}},{"&" + GetCode(dino["counter"]) if dino["counter"] else GetShort("nullptr")});', file=f, end='')


def WriteAbilityActions(actions, f):
    for i in range(len(actions)):
        if i == 0 or not (
                actions[i]["Target"] in ImmutableTargets and actions[i-1]["Target"] == actions[i]["Target"] or 
                actions[i-1]["Target"] not in ImmutableTargets and actions[i]["Target"] == "Last"
            ):
            print(f'    Target{actions[i]["Target"]}(', file=f)
        print(f'        {actions[i]["Action"].ToString()}', end='', file=f)
        if i == len(actions)-1 or not (
                actions[i]["Target"] in ImmutableTargets and actions[i]["Target"] == actions[i+1]["Target"] or 
                actions[i]["Target"] not in ImmutableTargets and actions[i+1]["Target"] == "Last"
            ):
            print(f'\n    )', end='', file=f)
        if i != len(actions)-1:
            print(f',', file=f)
        else:
            print(f'', file=f)


def WriteCompactAbilityActions(actions, f):
    for i in range(len(actions)):
        if i == 0 or not (
                actions[i]["Target"] in ImmutableTargets and actions[i-1]["Target"] == actions[i]["Target"] or 
                actions[i-1]["Target"] not in ImmutableTargets and actions[i]["Target"] == "Last"
            ):
            print(f'{GetShort("actions::Target"+actions[i]["Target"])}(', file=f, end='')
        print(f'{actions[i]["Action"].ToCompact()}', end='', file=f)
        if i == len(actions)-1 or not (
                actions[i]["Target"] in ImmutableTargets and actions[i]["Target"] == actions[i+1]["Target"] or 
                actions[i]["Target"] not in ImmutableTargets and actions[i+1]["Target"] == "Last"
            ):
            print(f')', end='', file=f)
        if i != len(actions)-1:
            print(f',', file=f, end='')


# def WriteAbilityDex(ability_file, ability_dex):
    # with open(ability_file + ".json", "w") as f:
        # json.dump(ability_dex, f, indent=4)
    # with open(ability_file + ".h", "w") as f:
        # print(f'#ifndef __{ability_file.upper()}__H__', file=f)
        # print(f'#define __{ability_file.upper()}__H__', file=f)
        # print(f'', file=f)
        # print(f'#include "ability.h"', file=f)
        # print(f'', file=f)
        # print(f'namespace {ability_file} {{', file=f)
        # print(f'', file=f)
        # for ability in sorted(ability_dex.values(), key=lambda ability: ability['dev_name']):
            # print(f'extern {ability["type"]} {ability["dev_name"]};', file=f)
        # print(f'', file=f)
        # print(f'}} // namespace {ability_file}', file=f)
        # print(f'', file=f)
        # print(f'#endif // __{ability_file.upper()}__H__', file=f)
    # with open(ability_file + ".cpp", "w") as f:
        # print(f'#include "{ability_file}.h"', file=f)
        # print(f'#include "actions.h"', file=f)
        # print(f'#include "dino.h"', file=f)
        # print(f'', file=f)
        # print(f'using namespace actions;', file=f)
        # print(f'', file=f)
        # print(f'namespace {ability_file} {{', file=f)
        # print(f'', file=f)
        # for ability in sorted(ability_dex.values(), key=lambda ability: ability['dev_name']):
            # if ability["type"] == "CounterAbility" or ability["type"] == "ThreatenedCounterAbility":
                # print(f'{ability["type"]} {ability["dev_name"]}("{ability["name"]}", {{', file=f)
            # else:
                # print(f'{ability["type"]} {ability["dev_name"]}("{ability["name"]}", {ability["delay"]}, {ability["cooldown"]}, {ability["priority"]}, {{', file=f)
            # WriteAbilityActions(ability["actions"], f) 
            # if ability["type"] == "RevengeAbility":
                # print(f'}}, {ability["revenge"]["delay"]}, {ability["revenge"]["cooldown"]}, {ability["revenge"]["priority"]}, {{', file=f)
                # WriteAbilityActions(ability["revenge"]["actions"], f) 
            # elif ability["type"] == "ThreatenedAbility":
                # print(f'}}, [](Dino &self) {{ return self.total_health {ability["threatened_compare"]} self.max_total_health * {ability["threatened_factor"]}; }}, {ability["threatened"]["delay"]}, {ability["threatened"]["cooldown"]}, {ability["threatened"]["priority"]}, {{', file=f)
                # WriteAbilityActions(ability["threatened"]["actions"], f) 
            # elif ability["type"] == "ThreatenedCounterAbility":
                # print(f'}}, [](Dino &self) {{ return self.total_health {ability["threatened_compare"]} self.max_total_health * {ability["threatened_factor"]}; }}, {{', file=f)
                # WriteAbilityActions(ability["threatened"]["actions"], f) 
            # print(f'}});', file=f)
            # print(f'', file=f)
        # print(f'}} // namespace {ability_file}', file=f)


def WriteAbilityDex(ability_dex, f):
    for ability in sorted(ability_dex.values(), key=lambda ability: ability['dev_name']):
        if ability["type"] == "CounterAbility" or ability["type"] == "ThreatenedCounterAbility":
            print(f'{ability["type"]} {ability["dev_name"]}("{ability["name"]}", {{', file=f)
        else:
            print(f'{ability["type"]} {ability["dev_name"]}("{ability["name"]}", {ability["delay"]}, {ability["cooldown"]}, {ability["priority"]}, {{', file=f)
        WriteAbilityActions(ability["actions"], f) 
        if ability["type"] == "RevengeAbility":
            print(f'}}, {ability["revenge"]["delay"]}, {ability["revenge"]["cooldown"]}, {ability["revenge"]["priority"]}, {{', file=f)
            WriteAbilityActions(ability["revenge"]["actions"], f) 
        elif ability["type"] == "ThreatenedAbility":
            print(f'}}, [](Dino &self) {{ return self.total_health {ability["threatened_compare"]} self.max_total_health * {ability["threatened_factor"]}; }}, {ability["threatened"]["delay"]}, {ability["threatened"]["cooldown"]}, {ability["threatened"]["priority"]}, {{', file=f)
            WriteAbilityActions(ability["threatened"]["actions"], f) 
        elif ability["type"] == "ThreatenedCounterAbility":
            print(f'}}, [](Dino &self) {{ return self.total_health {ability["threatened_compare"]} self.max_total_health * {ability["threatened_factor"]}; }}, {{', file=f)
            WriteAbilityActions(ability["threatened"]["actions"], f) 
        print(f'}});', file=f)
        print(f'', file=f)


def WriteCompactAbilityDex(ability_dex, f):
    for ability in sorted(ability_dex.values(), key=lambda ability: ability['dev_name']):
        if ability["type"] == "CounterAbility" or ability["type"] == "ThreatenedCounterAbility":
            print(f'{GetShort(ability["type"])} {GetCode(ability["dev_name"])}("{ability["name"]}",{{', file=f, end='')
        else:
            print(f'{GetShort(ability["type"])} {GetCode(ability["dev_name"])}("{ability["name"]}",{ability["delay"]},{ability["cooldown"]},{GetShort(ability["priority"])},{{', file=f, end='')
        WriteCompactAbilityActions(ability["actions"], f) 
        if ability["type"] == "RevengeAbility":
            print(f'}},{ability["revenge"]["delay"]},{ability["revenge"]["cooldown"]},{GetShort(ability["revenge"]["priority"])},{{', file=f, end='')
            WriteCompactAbilityActions(ability["revenge"]["actions"], f) 
        elif ability["type"] == "ThreatenedAbility":
            print(f'}},[]({GetShort("Dino")}&{GetCode("self")}){{return {GetCode("self")}.{GetShort("total_health")}{ability["threatened_compare"]}{GetCode("self")}.{GetShort("max_total_health")}*{ability["threatened_factor"]};}},{ability["threatened"]["delay"]},{ability["threatened"]["cooldown"]},{GetShort(ability["threatened"]["priority"])},{{', file=f, end='')
            WriteCompactAbilityActions(ability["threatened"]["actions"], f) 
        elif ability["type"] == "ThreatenedCounterAbility":
            print(f'}},[]({GetShort("Dino")}&{GetCode("self")}){{return {GetCode("self")}.{GetShort("total_health")}{ability["threatened_compare"]}{GetCode("self")}.{GetShort("max_total_health")}*{ability["threatened_factor"]};}},{{', file=f, end='')
            WriteCompactAbilityActions(ability["threatened"]["actions"], f) 
        print(f'}});', file=f, end='')


# def WriteDex(dino_dex, minion_dex, boss_dex, raid_dex):
    # with open("raid_dex.json", "w") as f:
        # json.dump(raid_dex, f, indent=4)
    # with open("dex.h", "w") as f:
        # print(f'#ifndef __DEX__H__', file=f)
        # print(f'#define __DEX__H__', file=f)
        # print(f'', file=f)
        # print(f'#include <map>', file=f)
        # print(f'#include <string>', file=f)
        # print(f'#include "dino.h"', file=f)
        # print(f'', file=f)
        # print(f'extern std::map<std::string, std::vector<Dino>> BossDex;', file=f)
        # print(f'extern std::map<std::string, const DinoKind *> DinoDex;', file=f)
        # print(f'', file=f)
        # print(f'#endif // __DEX__H__', file=f)
    # with open("dex.cpp", "w") as f:
        # print(f'#include "dex.h"', file=f)
        # print(f'#include "dino_dex.h"', file=f)
        # print(f'#include "minion_dex.h"', file=f)
        # print(f'#include "boss_dex.h"', file=f)
        # print(f'', file=f)
        # print(f'using namespace std;', file=f)
        # print(f'using namespace minion_dex;', file=f)
        # print(f'using namespace boss_dex;', file=f)
        # print(f'using namespace dino_dex;', file=f)
        # print(f'', file=f)
        # print(f'map<string, vector<Dino>> BossDex = {{', file=f)
        # for raid in sorted(raid_dex, key=lambda raid: raid["boss"]["dino"]):
            # print(f'    make_pair<string, vector<Dino>>("{raid["boss"]["dino"]}", {{Dino(0, 0, {raid["boss"]["level"]}, {raid["boss"]["health_boost"]}, {raid["boss"]["damage_boost"]}, {raid["boss"]["speed_boost"]}, &{raid["boss"]["dino"]})', end='', file=f)
            # for id, minion in enumerate(raid["minion"]):
                # print(f', Dino(0, {id+5}, {minion["level"]}, {minion["health_boost"]}, {minion["damage_boost"]}, {minion["speed_boost"]}, &{minion["dino"]})', end='', file=f)
            # print(f'}}),', file=f)
        # print(f'}};', file=f)
        # print(f'', file=f)
        # print(f'map<string, const DinoKind *> DinoDex = {{', file=f)
        # for dino in sorted(dino_dex.values(), key=lambda dino: dino['dev_name']):
            # print(f'    make_pair("{dino["dev_name"]}", &{dino["dev_name"]}),', file=f)
        # print(f'}};', file=f)


def WriteDex(dino_dex, minion_dex, ability_dex, boss_dex, boss_ability_dex, raid_dex, f):
    print(f'#include "dex.h"', file=f)
    print(f'#include "actions.h"', file=f)
    print(f'#include "dino.h"', file=f)
    print(f'', file=f)
    print(f'using namespace actions;', file=f)
    print(f'', file=f)
    print(f'namespace boss {{', file=f)
    print(f'', file=f)
    WriteAbilityDex(boss_ability_dex, f)
    print(f'', file=f)
    WriteDinoDex(boss_dex, f)
    print(f'', file=f)
    print(f'}} // namespace boss', file=f)
    print(f'', file=f)
    WriteAbilityDex(ability_dex, f)
    print(f'', file=f)
    WriteDinoDex(minion_dex, f)
    print(f'', file=f)
    WriteDinoDex(dino_dex, f)
    print(f'', file=f)
    print(f'using namespace std;', file=f)
    print(f'using namespace boss;', file=f)
    print(f'', file=f)
    print(f'map<string, vector<Dino>> BossDex = {{', file=f)
    for raid in sorted(raid_dex, key=lambda raid: raid["boss"]["dino"]):
        print(f'    make_pair<string, vector<Dino>>("{raid["boss"]["dino"][:-4]}", {{Dino(0, 0, {raid["boss"]["level"]}, {raid["boss"]["health_boost"]}, {raid["boss"]["damage_boost"]}, {raid["boss"]["speed_boost"]}, &{raid["boss"]["dino"]})', end='', file=f)
        for id, minion in enumerate(raid["minion"]):
            print(f', Dino(0, {id+5}, {minion["level"]}, {minion["health_boost"]}, {minion["damage_boost"]}, {minion["speed_boost"]}, &{minion["dino"]})', end='', file=f)
        print(f'}}),', file=f)
    print(f'}};', file=f)
    print(f'', file=f)
    print(f'map<string, const DinoKind *> DinoDex = {{', file=f)
    for dino in sorted(dino_dex.values(), key=lambda dino: dino['dev_name']):
        print(f'    make_pair("{dino["dev_name"]}", &{dino["dev_name"]}),', file=f)
    print(f'}};', file=f)


def WriteCompactDex(dino_dex, minion_dex, ability_dex, boss_dex, boss_ability_dex, raid_dex, f):
    print(f'#include "dex.h"', file=f)
    print(f'#include "actions.h"', file=f)
    print(f'#include "modifiers.h"', file=f)
    print(f'#include "dino.h"', file=f)
    print(f'#include "compact_dex.h"', file=f)
    print(f'using namespace actions;', file=f)
    print(f'namespace boss {{', file=f, end='')
    WriteCompactAbilityDex(boss_ability_dex, f)
    WriteCompactDinoDex(boss_dex, f)
    print(f'}}', file=f)
    WriteCompactAbilityDex(ability_dex, f)
    WriteCompactDinoDex(minion_dex, f)
    WriteCompactDinoDex(dino_dex, f)
    print(f'using namespace boss;', file=f)
    print(f'{GetShort("std::map")}<{GetShort("std::string")},{GetShort("std::vector")}<{GetShort("Dino")}>> BossDex={{', file=f, end='')
    for raid in sorted(raid_dex, key=lambda raid: raid["boss"]["dino"]):
        print(f'{GetShort("std::make_pair")}<{GetShort("std::string")},{GetShort("std::vector")}<{GetShort("Dino")}>>("{raid["boss"]["dino"][:-4]}",{{{GetShort("Dino")}(0,0,{Num(raid["boss"]["level"])},{Num(raid["boss"]["health_boost"])},{Num(raid["boss"]["damage_boost"])},{Num(raid["boss"]["speed_boost"])},&{GetCode(raid["boss"]["dino"])})',end='',file=f)
        for id, minion in enumerate(raid["minion"]):
            print(f',{GetShort("Dino")}(0,{id+5},{minion["level"]},{minion["health_boost"]},{minion["damage_boost"]},{minion["speed_boost"]},&{GetCode(minion["dino"])})', end='', file=f)
        print(f'}}),', file=f, end='')
    print(f'}};', file=f)
    print(f'{GetShort("std::map")}<{GetShort("std::string")},const {GetShort("DinoKind")} *> DinoDex = {{', file=f, end='')
    for dino in sorted(dino_dex.values(), key=lambda dino: dino['dev_name']):
        print(f'{GetShort("std::make_pair")}("{dino["dev_name"]}",&{GetCode(dino["dev_name"])}),', file=f, end='')
    print(f'}};', file=f)


def WriteShorts(f):
    print(f'#ifndef __JWA_CALC__COMPACT_H__', file=f)
    print(f'#define __JWA_CALC__COMPACT_H__', file=f)
    print(f'', file=f)
    for (k, v) in Shorts.items():
        print(f'#define {v} {k}', file=f)
    # for (k, v) in Types.items():
    #     print(f'using {v} = {k};', file=f)
    # for (k, v) in Consts.items():
    #     print(f'static const auto {v} = {k};', file=f)
    print(f'', file=f)
    print(f'#endif // __JWA_CALC__COMPACT_H__', file=f)


def GetAll():
    l10n = GetPath("Localization_JW_2_Global_ENGLISH.json")
    data = GetPath(PATH + DATA)
    dino_dex = {}
    ability_dex = {}
    raid_dex = []
    boss_dex = {}
    boss_ability_dex = {}
    minion_dex = {}
    GetTeam(l10n, data, dino_dex, ability_dex)
    GetRaid(l10n, data, raid_dex, boss_dex, boss_ability_dex, minion_dex, ability_dex)

    with open("dino_dex.json", "w") as f:
        json.dump(dino_dex, f, indent=4)
    with open("minion_dex.json", "w") as f:
        json.dump(minion_dex, f, indent=4)
    with open("boss_dex.json", "w") as f:
        json.dump(boss_dex, f, indent=4)
    with open("ability_dex.json", "w") as f:
        json.dump(ability_dex, f, indent=4)
    with open("boss_ability_dex.json", "w") as f:
        json.dump(boss_ability_dex, f, indent=4)
    with open("raid_dex.json", "w") as f:
        json.dump(raid_dex, f, indent=4)
    with open("dex.cpp", "w") as f:
        WriteDex(dino_dex, minion_dex, ability_dex, boss_dex, boss_ability_dex, raid_dex, f)
    with open("compact_dex.cpp", "w") as f:
        WriteCompactDex(dino_dex, minion_dex, ability_dex, boss_dex, boss_ability_dex, raid_dex, f)
    with open("compact_dex.h", "w") as f:
        WriteShorts(f)

def main():
    #unfold()
    #search2()
    GetAll()

if __name__ == "__main__":
    main()
