# -*- coding: utf-8 -*-

import requests
import re
import sys
import html
import json


def DevName(s, guid=''):
    return '_'.join(re.split(r'\W+', ''.join(w.capitalize() for w in s.split()))) + guid[:4].upper()


print("Get bosses...", file=sys.stderr)
res = requests.get("https://www.paleo.gg/games/jurassic-world-alive/bossdex")
assert res.status_code == 200
# print(res.text, file=sys.stderr)
match = re.search(r'<script id="__NEXT_DATA__" type="application/json">(.*?)</script>', res.text)
assert match
data = json.loads(match[1])
# print(json.dumps(data, indent=2))
creatures = data["props"]["pageProps"]["creatures"]

temp = {}
for creature in creatures:
    temp[creature["uuid"]] = creature
boss = []
for creature in creatures:
    if creature["type"] != "raid_boss":
        continue
    # res = requests.get(f'https://www.paleo.gg/games/jurassic-world-alive/bossdex/{creature["uuid"]}')
    # assert res.status_code == 200    
    b = {
        "paleo_id": creature["uuid"],
        "name": creature["name"],
        "jwacalc_id": DevName(creature["name"][:-5]),
        "rarity": creature["rarity"],
        "health": creature["health"],
        "damage": creature["damage"],
        "speed": creature["speed"],
        "armor": creature["armor"],
        "crit_chance": creature["crit"],
        "crit_factor": creature["critm"],
        "level": creature["level"],
        "health_boost": creature["boostHealth"],
        "damage_boost": creature["boostDamage"],
        "speed_boost": creature["boostSpeed"],
        "minions": [
            {
                "paleo_id": minion["uuid"],
                "name": temp[minion["uuid"]]["name"],
                "rarity": temp[minion["uuid"]]["rarity"],
                "health": temp[minion["uuid"]]["health"],
                "damage": temp[minion["uuid"]]["damage"],
                "speed": temp[minion["uuid"]]["speed"],
                "armor": temp[minion["uuid"]]["armor"],
                "crit_chance": temp[minion["uuid"]]["crit"],
                "crit_factor": temp[minion["uuid"]]["critm"],
                "level": minion["level"],
                "health_boost": minion["boostHealth"],
                "damage_boost": minion["boostDamage"],
                "speed_boost": minion["boostSpeed"],
            } for minion in creature["minions"]
        ]
    }
    boss.append(b)
    # break

# print(json.dumps(boss, indent=2))
# exit()

print("Get dinos...", file=sys.stderr)
res = requests.get("https://www.paleo.gg/games/jurassic-world-alive/dinodex", {"Referer": "https://www.paleo.gg/games/jurassic-world-alive/bossdex"})
assert res.status_code == 200
# print(res.text, file=sys.stderr)
match = re.search(r'<script id="__NEXT_DATA__" type="application/json">(.*?)</script>', res.text)
assert match
data = json.loads(match[1])
# print(json.dumps(data, indent=2))
creatures = data["props"]["pageProps"]["dex"]["items"]

dino = []
for i, creature in enumerate(creatures):
    # if creature["name"] != "Rexy":
        # continue
    print("Processing ({}/{}) {}".format(i+1, len(creatures), creature["name"]), file=sys.stderr)
    res = requests.get(f'https://www.paleo.gg/games/jurassic-world-alive/dinodex/{creature["uuid"]}')
    assert res.status_code == 200
    # print(res.text, file=sys.stderr)
    match = re.search(r'<script id="__NEXT_DATA__" type="application/json">(.*?)</script>', res.text)
    assert match
    props = json.loads(match[1])["props"]["pageProps"]
    # print(json.dumps(props, indent=2))
    # break
    details = props["detail"]
    # name = html.unescape(dino[i][1])
    # dino[i] = {
        # "name": name,
        # "paleo_id": dino[i][0],
        # "jwacalc_id": DevName(name)
    # }
    # abilities = re.findall(r'width:50px;height:50px[^>]*>(.*?)</div>.*?/games/jurassic-world-alive/dinodex\?move=[^>]*>([^<]+)', res.text)
    # dino[i]["abilities"] = [{"index": i, "name": html.unescape(ability[1]), "html": ability[0]} for i, ability in enumerate(abilities)]
    # print(dino[i])
    # print(res.text, file=sys.stderr)
    # break

    d = {
        "name": creature["name"],
        "paleo_id": creature["uuid"],
        "jwacalc_id": DevName(creature["name"]),
        "rarity": details["rarity"],
        "health": details["health"],
        "damage": details["damage"],
        "speed": details["speed"],
        "armor": details["armor"],
        "crit_chance": details["crit"],
        "crit_factor": details["critm"],
        "abilities": [
            {
                "icon": ability["icon"] or f'/images/move/regular/{ability["uuid"]}.png',
                "name": props["__namespaces"]["dinodex-move"][ability["uuid"]],
                "alert": "if_alert" in ability,
                "revenge": "if_revenge" in ability,
                "priority": ability["priority"],
                "precise": any(item.get("action") == "bypass_dodge" for item in ability["effects"]),
            } for ability in details["moves"]
        ]
    }
    if "points" in details:
        d["points"] = {
            "delta": {
                "health": details["points"]["delta"]["health"] or 0,
                "damage": details["points"]["delta"]["damage"] or 0,
                "speed": details["points"]["delta"]["speed"] or 0,
                "armor": details["points"]["delta"]["armor"] or 0,
                "crit_chance": details["points"]["delta"]["crit"] or 0,
                "crit_factor": details["points"]["delta"]["critm"] or 0,
            },
            "cap": {
                "health": details["points"]["pcap"]["health"] or 0,
                "damage": details["points"]["pcap"]["damage"] or 0,
                "speed": details["points"]["pcap"]["speed"] or 0,
                "armor": details["points"]["pcap"]["armor"] or 0,
                "crit_chance": details["points"]["pcap"]["crit"] or 0,
                "crit_factor": details["points"]["pcap"]["critm"] or 0,
            }
        }
    dino.append(d)

# print(json.dumps(dino, indent=2))

print(json.dumps({"dino": dino, "boss": boss}))
