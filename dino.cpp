#include "dino.h"
#include "modifiers.h"
#include "actions.h"
#include "logger.h"
#include <memory>
#include <memory.h>
#include "stats.h"
#include "pack.h"

using namespace std;
using namespace modifiers;
using namespace actions;

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

Dino::Dino(int _team, int _index, int _level, int _health_boost, int _damage_boost, int _speed_boost, const DinoKind *_kind)
    : kind(_kind)
    , rounds((int)kind->round.size())
    , team(_team)
    , index(_index)
    , level(_level)
    , health_boost(_health_boost)
    , damage_boost(_damage_boost)
    , speed_boost(_speed_boost)
    , max_health(health_boost <= 20 ? _kind->round[0].health * LevelFactor[level] * BoostFactor[health_boost] : health_boost)
    , health(max_health)
    , damage(damage_boost <= 20 ? _kind->round[0].damage * LevelFactor[level] * BoostFactor[damage_boost] : damage_boost)
    , speed(speed_boost <= 20 ? _kind->round[0].speed + 2 * speed_boost : speed_boost)
    , name(team != 0 ? strprintf("%s#%d", kind->name.c_str(), _index) : kind->name)
{
    for (int i = 0; i < (int)Round(0).ability.size(); ++i) {
        cooldown[i] = Round(0).ability[i]->delay;
    }
    for (int i = 0; i < (int)kind->round.size(); ++i) {
    	max_total_health += health_boost <= 20 ? Round(i).health * LevelFactor[level] * BoostFactor[health_boost] : health_boost;
    }
    total_health = max_total_health;
    for (int i = 1; i < kind->flock; ++i) {
        flock_segment.push_back(i * max_health / kind->flock);
    }
}

bool Dino::Prepare(int _ability_id, bool minor)
{
    if (!Alive())
        return true;
    if (index != 0 && cooldown[_ability_id] != 0) // index == 0 => boss
        return false;
    this->minor = minor;
    for (int i = 0; i < 4; ++i) {
        if (cooldown[i] > 0)
            --cooldown[i];
    }
    ability_id = _ability_id;
    Round().ability[ability_id]->Prepare(*this, &cooldown[ability_id], &priority);
    return true;
}

void Dino::Attack(Dino team[], int size)
{
    if (!Alive())
        return;
    REMOVE_MODS(*this, mod_it->BeforeAction(), DEBUG("%s has %s expired", Name().c_str(), mod_it->Name().c_str()));
    if (!stun) {
        INFO("%s uses %s!", Name().c_str(), Round().ability[ability_id]->name.c_str());
        Round().ability[ability_id]->Do(*this, team, size);
    }
    REMOVE_MODS(*this, mod_it->AfterAction(), DEBUG("%s has %s expired", Name().c_str(), mod_it->Name().c_str()));
    affliction += affliction_factor;
}

void Dino::CounterAttack(Dino team[], int size)
{
    if (Alive() && attacker && !stun && Round().counter_attack) {
        INFO("%s counter-attacks using %s!", Name().c_str(), Round().counter_attack->name.c_str());
        Round().counter_attack->Do(*this, team, size);
    }
    attacker = nullptr;
}

void Dino::Impose(const Modifier *mod, Dino &author)
{
	auto mod_it = &mods.emplace_back(mod);
	mod_it->Impose(*this);
    INFO("%s imposes %s to %s for %d turn(s)%s", author.Name().c_str(), mod_it->Name().c_str(), Name().c_str(), mod->duration, mod->number ? strprintf(" %d attack(s)", mod->number).c_str() : "");
}

void Dino::Dispose(int type_flags, Dino &author)
{
    REMOVE_MODS(*this, mod_it->Type() & type_flags, INFO("%s disposes %s from %s", author.Name().c_str(), mod_it->Name().c_str(), Name().c_str()));
}

void Dino::PassTurn()
{
    REMOVE_MODS(*this, mod_it->OnEndOfTurn(), DEBUG("%s has %s expired", Name().c_str(), mod_it->Name().c_str()));
}

void Dino::DevourHeal()
{
    if (health == 0 || devour_heal == 0)
        return;
    int devour_heal = HealAbsorb(this->devour_heal);
    Heal(*this, devour_heal);
    WARNING("%s is [devour] healed by %d", Name().c_str(), devour_heal);
}

void Dino::DamageOverTime(Dino team[], int team_size)
{
    if (!Alive() || damage_over_time == 0)
        return;
    int dot = ::Round(max_total_health * damage_over_time);
    Hit(*this, dot, true);
    WARNING("%s is damaged [over time] by %d", Name().c_str(), dot);
    if (!Alive()) {
        ERROR("%s dies!", Name().c_str());
        REMOVE_MODS(*this, true, DEBUG("%s took %s to the grave", Name().c_str(), mod_it->Name().c_str()));
        for (int i = 0; i < team_size; ++i) {
            if (team[i].team != this->team)
                continue;
            team[i].Revenge(*this);
        }
    } else if (health == 0)
        INFO("%s is immune to HP changes.", Name().c_str());
}

string Dino::Name() const
{
    return strprintf("%s (+%d,*%d,>%d)", name.c_str(), health, Damage(), Speed());
}

void Dino::Revive(bool total)
{
    if (total)
        actions::Remove(ALL_EFFECTS).Do(*this, *this);
    health = max_health = health_boost <= 20 ? Round().health * LevelFactor[level] * BoostFactor[health_boost] : health_boost;
    damage = damage_boost <= 20 ? Round().damage * LevelFactor[level] * BoostFactor[damage_boost] : damage_boost;
    speed = speed_boost <= 20 ? Round().speed + 2 * speed_boost : speed_boost;
    if (total)
        total_health = max_total_health;
    for (int i = 0; i < (int)Round().ability.size(); ++i) {
        cooldown[i] = Round().ability[i]->delay;
    }
    INFO("%s is revived!", Name().c_str());
}

void Dino::Hit(const Dino &attacker, int damage, bool premature)
{
    auto old_health = health;
    auto full_damage = damage;
    if (premature && damage >= total_health) {
        damage = total_health;
        health = 0;
    } else {
        if (damage >= health)
            damage = health;
        health -= damage;
    }
    total_health -= damage;
    if (stats)
        stats->RegisterHit(attacker.index, index, old_health, health, full_damage, damage);
}

void Dino::Heal(const Dino &healer, int heal)
{
    auto old_health = health;
    auto full_heal = heal;
    if (heal > max_health - health)
        heal = max_health - health;
    health += heal;
    total_health += heal;
    if (stats)
        stats->RegisterHit(healer.index, index, old_health, health, -full_heal, -heal);
}

int Dino::Absorb(int damage)
{
    if (kind->flock == 1)
        return damage;
    auto it = upper_bound(flock_segment.rbegin(), flock_segment.rend(), health, greater<int>());
    if (it != flock_segment.rend() && health - *it < damage)
        return health - *it;
    return damage;
}

int Dino::HealAbsorb(int heal)
{
    if (kind->flock == 1)
        return heal;
    auto it = lower_bound(flock_segment.begin(), flock_segment.end(), health, less<int>());
    if (it != flock_segment.end() && *it - health < heal)
        return *it - health;
    return heal;
}

void Dino::Revenge(Dino &source)
{
    static const modifiers::Revenge revenge;
    if (this->revenge) {
        Dispose(REVENGE, source);
        revenge_ready = false;
    }
    Impose(&revenge, source);
}
