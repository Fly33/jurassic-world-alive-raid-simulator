#include "dino.h"
#include "modifiers.h"
#include "actions.h"
#include "logger.h"
#include <memory>

using namespace std;
using namespace modifiers;
using namespace actions;

modifiers::Revenge Revenge;

bool Ability::Priority(Dino &dino) const
{
    if (dino.threatened)
        return threatened_ability->priority;
    return priority;
}

void Ability::Do(Dino &self, Dino *team[], int size) const
{
    auto &action_groups = self.threatened ? threatened_ability->action_groups : this->action_groups;
    for (int i = 0; i < (int)action_groups.size(); ++i) {
        action_groups[i]->Do(self, team, size);
    }
}

static const double LevelFactor[] = {
        0,
        0.2953027716977619,
        0.31006791028265,
        0.3255713057967825,
        0.3418498710866216,
        0.3589423646409527,
        0.37688948287300034,
        0.3957339570166504,
        0.4155206548674829,
        0.43629668761085705,
        0.45811152199139993,
        0.48101709809096993,
        0.5050679529955184,
        0.5303213506452944,
        0.5568374181775592,
        0.5846792890864372,
        0.6139132535407591,
        0.644608916217797,
        0.6768393620286869,
        0.7106813301301212,
        0.7462153966366274,
        0.7835261664684589,
        0.8227024747918819,
        0.863837598531476,
        0.9070294784580498,
        0.9523809523809523,
        1,
        1.05,
        1.1025,
        1.1576250000000001,
        1.2155062500000002
};
static const double BoostFactor[] = {1.0, 1.025, 1.05, 1.075, 1.1, 1.125, 1.15, 1.175, 1.2, 1.225, 1.25, 1.275, 1.3, 1.325, 1.35, 1.375, 1.4, 1.425, 1.45, 1.475, 1.5};

Dino::Dino(int _team, int _index, int _level, int _health_boost, int _damage_boost, int _speed_boost, const DinoKind *_kind, int _rounds)
    : kind(_kind)
    , rounds(_rounds)
    , team(_team)
    , index(_index)
    , level(_level)
    , health_boost(_health_boost)
    , damage_boost(_damage_boost)
    , speed_boost(_speed_boost)
    , max_health(_kind->health * LevelFactor[level] * BoostFactor[health_boost])
    , health(max_health)
    , damage(_kind->damage * LevelFactor[level] * BoostFactor[damage_boost])
    , speed(_kind->speed + 2 * speed_boost)
    , crit_chance_factor(_kind->crit)
    , armor(_kind->armor)
{
    for (int i = 0; i < rounds; ++i) {
        total_health += kind[i].health * LevelFactor[level] * BoostFactor[health_boost];
    }
    max_total_health = total_health;
    for (int i = 0; i < (int)kind[round].ability.size(); ++i) {
        cooldown[i] = kind[round].ability[i]->delay;
    }
}

bool Dino::Prepare(int _ability_id)
{
    if (!Alive())
        return true;
    if (cooldown[_ability_id] != 0)
        return false;
    for (int i = 0; i < 4; ++i) {
        if (cooldown[i] > 0)
            --cooldown[i];
    }
    ability_id = _ability_id;
    cooldown[ability_id] = kind[round].ability[ability_id]->cooldown;
    threatened = kind[round].ability[ability_id]->Threatened(*this);
    priority = kind[round].ability[ability_id]->Priority(*this);
    return true;
}

void Dino::Attack(Dino *team[], int size)
{
    if (!Alive())
        return;
    LOG("%s uses %s!\n", Name().c_str(), kind[round].ability[ability_id]->name.c_str());
    kind[round].ability[ability_id]->Do(*this, team, size);
}

void Dino::CounterAttack(Dino *team[], int size)
{
    if (!Alive())
        return;
    if (attacker && kind[round].counter_attack) {
        LOG("%s uses %s!\n", Name().c_str(), kind[round].ability[ability_id]->name.c_str());
        bool thrtnd = threatened;
        threatened = kind[round].counter_attack->Threatened(*this);
        kind[round].counter_attack->Do(*this, team, size);
        threatened = thrtnd;
    }
    attacker = nullptr;
}

void Dino::Impose(const Modifier *mod, Dino &author)
{
    mod->Impose(*this, &mods.emplace_back(mod));
    LOG("%s imposes %s to %s for %d turn(s)%s\n", author.Name().c_str(), mod->name.c_str(), Name().c_str(), mod->duration, mod->number ? strprintf(" %d attack(s)", mod->number).c_str() : "");
}

void Dino::Dispose(int type_flags, Dino &author)
{
    for(auto mod_it = mods.begin(); mod_it != mods.end(); ) {
        if (mod_it->modifier->Type() & type_flags) {
            auto modifier = mod_it->modifier;
            modifier->Dispose(*this, &*mod_it);
            mods.erase(mod_it++);
            LOG("%s disposes %s from %s\n", author.Name().c_str(), modifier->name.c_str(), Name().c_str());
        } else
            ++mod_it;
    }
}

void Dino::PassTurn()
{
    for (auto mod_it = mods.begin(); mod_it != mods.end(); ) {
        if (mod_it->duration == 0) {
            auto modifier = mod_it->modifier;
            modifier->Dispose(*this, &*mod_it);
            mods.erase(mod_it++);
            LOG("%s has %s expired\n", Name().c_str(), modifier->name.c_str());
        } else
            --mod_it++->duration;
    }
}

void Dino::DevourHeal()
{
    if (health == 0 || devour_heal == 0)
        return;
    Heal(devour_heal);
    LOG("%s is [devour] healed by %d\n", Name().c_str(), devour_heal);
}

void Dino::DamageOverTime(Dino *team[], int team_size)
{
    if (health == 0 || damage_over_time == 0)
        return;
    Hit(damage_over_time);
    LOG("%s is damaged [over time] by %d\n", Name().c_str(), damage_over_time);
    if (!Alive()) {
        LOG("%s dies!\n", Name().c_str());
        Revenge(team, team_size);
    } else if (health == 0)
        LOG("%s is immune to HP changes.\n", Name().c_str());
}

std::string Dino::Name() const
{
    if (team != 0)
        return strprintf("%s#%d (+%d;*%d;>%d)", kind[round].name.c_str(), index, health, Damage(), Speed());
    return strprintf("%s (+%d;*%d;>%d)", kind[round].name.c_str(), health, Damage(), Speed());
}

void Dino::Revive()
{
    health = max_health = kind[round].health * LevelFactor[level] * BoostFactor[health_boost];
    for (int i = 0; i < (int)kind[round].ability.size(); ++i) {
        cooldown[i] = kind[round].ability[i]->delay;
    }
}

void Dino::Revenge(Dino *team[], int team_size)
{
    for (int i = 0; i < team_size; ++i) {
        if (team[i]->team != this->team)
            continue;
        if (!team[i]->Alive())
            continue;
        team[i]->Impose(&::Revenge, *this);
    }
}

void Dino::Hit(int damage)
{
    if (damage > health)
        damage = health;
    health -= damage;
    total_health -= damage;
}

void Dino::Heal(int heal)
{
    if (heal > max_health - health)
        heal = max_health - health;
    health += heal;
    total_health += heal;
}
