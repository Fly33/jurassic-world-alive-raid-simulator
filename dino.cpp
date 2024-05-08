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

bool ActionOrderCmp(const Dino &dino1, const Dino &dino2)
{
    if (dino1.priority > dino2.priority)
        return true;
    if (dino1.priority < dino2.priority)
        return false;
    if (dino1.Speed() > dino2.Speed())
        return true;
    if (dino1.Speed() < dino2.Speed())
        return false;
    if (dino1.level > dino2.level)
        return true;
    if (dino1.level < dino2.level)
        return false;
    if (dino1.kind->rarity > dino2.kind->rarity)
        return true;
    if (dino1.kind->rarity < dino2.kind->rarity)
        return false;
    if (dino1.minor < dino2.minor)
        return true;
    if (dino1.minor > dino2.minor)
        return false;
    if ((!dino1.minor && dino1.index < dino2.index) ||
        (dino1.minor && dino1.index > dino2.index))
        return true;
//    if ((!dino1.minor && dino1.index > dino2.index) ||
//        (dino1.minor && dino1.index < dino2.index))
//        return false;
    return false;
}

static int PointsDistribution(int points, int index, const vector<int> &max)
{
    int n = (int)max.size();
    int left = -1, right = points * n;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        int curr_points = 0;
        for (int i = 0; i < (int)max.size(); ++i) {
            curr_points += min(max[i], (middle + n - 1 - i) / n);
        }
        if (curr_points >= points)
            right = middle;
        else
            left = middle;
    }
    return min(max[index], (right + n - 1 - index) / n);
}

Dino::Dino(int _team, int _index, int _level, int _health_boost, int _damage_boost, int _speed_boost, const DinoKind *_kind)
    : Dino(_team, _index, _level, _health_boost, _damage_boost, _speed_boost,
           _kind->is_omega ? PointsDistribution(_kind->level_points[_level], 1, {_kind->max_omega_damage_points, _kind->max_omega_health_points, _kind->max_omega_speed_points, _kind->max_omega_armor_points, _kind->max_omega_crit_chance_points, _kind->max_omega_crit_factor_points}) : 0,
           _kind->is_omega ? PointsDistribution(_kind->level_points[_level], 0, {_kind->max_omega_damage_points, _kind->max_omega_health_points, _kind->max_omega_speed_points, _kind->max_omega_armor_points, _kind->max_omega_crit_chance_points, _kind->max_omega_crit_factor_points}) : 0,
           _kind->is_omega ? PointsDistribution(_kind->level_points[_level], 2, {_kind->max_omega_damage_points, _kind->max_omega_health_points, _kind->max_omega_speed_points, _kind->max_omega_armor_points, _kind->max_omega_crit_chance_points, _kind->max_omega_crit_factor_points}) : 0,
           _kind->is_omega ? PointsDistribution(_kind->level_points[_level], 3, {_kind->max_omega_damage_points, _kind->max_omega_health_points, _kind->max_omega_speed_points, _kind->max_omega_armor_points, _kind->max_omega_crit_chance_points, _kind->max_omega_crit_factor_points}) : 0,
           _kind->is_omega ? PointsDistribution(_kind->level_points[_level], 4, {_kind->max_omega_damage_points, _kind->max_omega_health_points, _kind->max_omega_speed_points, _kind->max_omega_armor_points, _kind->max_omega_crit_chance_points, _kind->max_omega_crit_factor_points}) : 0,
           _kind->is_omega ? PointsDistribution(_kind->level_points[_level], 5, {_kind->max_omega_damage_points, _kind->max_omega_health_points, _kind->max_omega_speed_points, _kind->max_omega_armor_points, _kind->max_omega_crit_chance_points, _kind->max_omega_crit_factor_points}) : 0,
           _kind)
{}

Dino::Dino(int _team, int _index, int _level, int _health_boost, int _damage_boost, int _speed_boost,
     int _omega_health_points, int _omega_damage_points, int _omega_speed_points, int _omega_armor_points, int _omega_crit_chance_points, int _omega_crit_factor_points,
     const DinoKind *_kind)
    : kind(_kind)
    , rounds((int)kind->round.size())
    , team(_team)
    , index(_index)
    , level(_level)
    , health_boost(_health_boost)
    , damage_boost(_damage_boost)
    , speed_boost(_speed_boost)
    , name(team != 0 ? strprintf("%s#%d", kind->name.c_str(), _index) : kind->name)
    , omega_health_points(_omega_health_points)
    , omega_damage_points(_omega_damage_points)
    , omega_speed_points(_omega_speed_points)
    , omega_armor_points(_omega_armor_points)
    , omega_crit_chance_points(_omega_crit_chance_points)
    , omega_crit_factor_points(_omega_crit_factor_points)
{
    for (int i = 0; i < (int)kind->round.size(); ++i) {
        InitRound(i);
        max_total_health += max_health;
    }
    InitRound();
    total_health = max_total_health;
    for (int i = 1; i < kind->flock; ++i) {
        flock_segment.push_back(i * max_health / kind->flock);
    }
}

void Dino::InitRound(int round)
{
    if (health_boost > 20)
        health = max_health = health_boost;
    else if (kind->is_omega)
        health = max_health = (Round(round).health + kind->omega_health_step * omega_health_points) * BoostFactor[health_boost];
    else
        health = max_health = Round(round).health * LevelFactor[level] * BoostFactor[health_boost];

    if (damage_boost > 20)
        damage = damage_boost;
    else if (kind->is_omega)
        damage = (Round(round).damage + kind->omega_damage_step * omega_damage_points) * BoostFactor[damage_boost];
    else
        damage = Round(round).damage * LevelFactor[level] * BoostFactor[damage_boost];

    if (speed_boost > 20)
        speed = speed_boost;
    else if (kind->is_omega)
        speed = Round(round).speed + kind->omega_speed_step * omega_speed_points + 2 * speed_boost;
    else
        speed = Round(round).speed + 2 * speed_boost;

    if (kind->is_omega)
        armor = Round(round).armor + kind->omega_armor_step * omega_armor_points;
    else
        armor = Round(round).armor;

    if (kind->is_omega)
        crit_chance = Round(round).crit_chance + kind->omega_crit_chance_step * omega_crit_chance_points;
    else
        crit_chance = Round(round).crit_chance;

    if (kind->is_omega)
        crit_factor = Round(round).crit_factor + kind->omega_crit_chance_step * omega_crit_factor_points;
    else
        crit_factor = Round(round).crit_factor;

    if (kind->is_omega) {
        crit_reduction_resistance   = GetRestriction(level, RestrictionType::CritReductionResistance, Round(round).crit_reduction_resistance);
        damage_over_time_resistance = GetRestriction(level, RestrictionType::DamageOverTimeResistance, Round(round).damage_over_time_resistance);
        damage_reduction_resistance = GetRestriction(level, RestrictionType::DamageReductionResistance, Round(round).damage_reduction_resistance);
        rend_resistance             = GetRestriction(level, RestrictionType::RendResistance, Round(round).rend_resistance);
        speed_reduction_resistance  = GetRestriction(level, RestrictionType::SpeedReductionResistance, Round(round).speed_reduction_resistance);
        stun_resistance             = GetRestriction(level, RestrictionType::StunResistance, Round(round).stun_resistance);
        swap_prevention_resistance  = GetRestriction(level, RestrictionType::SwapPreventionResistance, Round(round).swap_prevention_resistance);
        taunt_resistance            = GetRestriction(level, RestrictionType::TauntResistance, Round(round).taunt_resistance);
        vulnerability_resistance    = GetRestriction(level, RestrictionType::VulnerabilityResistance, Round(round).vulnerability_resistance);
        armor_reduction_resistance  = GetRestriction(level, RestrictionType::ArmorReductionResistance, Round(round).armor_reduction_resistance);
        affliction_resistance       = GetRestriction(level, RestrictionType::AfflictionResistance, Round(round).affliction_resistance);
        ability = Round(round).ability;
        ability.resize((int)GetRestriction(level, RestrictionType::Ability, 2));
        counter_attack = (int)GetRestriction(level, RestrictionType::Counter, 0) ? Round(round).counter_attack : nullptr;
    } else {
        crit_reduction_resistance = Round(round).crit_reduction_resistance;
        damage_over_time_resistance = Round(round).damage_over_time_resistance;
        damage_reduction_resistance = Round(round).damage_reduction_resistance;
        rend_resistance = Round(round).rend_resistance;
        speed_reduction_resistance = Round(round).speed_reduction_resistance;
        stun_resistance = Round(round).stun_resistance;
        swap_prevention_resistance = Round(round).swap_prevention_resistance;
        taunt_resistance = Round(round).taunt_resistance;
        vulnerability_resistance = Round(round).vulnerability_resistance;
        armor_reduction_resistance = Round(round).armor_reduction_resistance;
        affliction_resistance = Round(round).affliction_resistance;
        ability = Round(round).ability;
        counter_attack = Round(round).counter_attack;
    }

    for (int i = 0; i < (int)ability.size(); ++i) {
        cooldown[i] = ability[i]->delay;
    }
}

double Dino::GetRestriction(int level, RestrictionType type, double _default)
{
    double result = _default;
    double max_level = 0;
    for (const auto &restriction: kind->restrictions) {
        if (restriction.type != type)
            continue;
        if (restriction.level > level)
            continue;
        if (restriction.level <= max_level)
            continue;
        max_level = restriction.level;
        result = restriction.restriction;
    }
    return result;
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
    ability[ability_id]->Prepare(*this, &cooldown[ability_id], &priority);
    return true;
}

void Dino::Attack(Dino team[], int size)
{
    if (!Alive())
        return;
    REMOVE_MODS(*this, mod_it->BeforeAction(), DEBUG("%s has %s expired", Name().c_str(), mod_it->Name().c_str()));
    if (!stun) {
        INFO("%s uses %s!", Name().c_str(), ability[ability_id]->name.c_str());
        ability[ability_id]->Do(*this, team, size);
    }
    REMOVE_MODS(*this, mod_it->AfterAction(), DEBUG("%s has %s expired", Name().c_str(), mod_it->Name().c_str()));
    affliction += affliction_factor;
}

void Dino::CounterAttack(Dino team[], int size)
{
    if (Alive() && attacker && !stun && counter_attack) {
        INFO("%s counter-attacks using %s!", Name().c_str(), counter_attack->name.c_str());
        counter_attack->Do(*this, team, size);
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
    int dot = ::Round(max_health * damage_over_time);
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
    InitRound();
    if (total)
        total_health = max_total_health;
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
