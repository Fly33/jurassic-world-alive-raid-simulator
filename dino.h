#ifndef __JWA_CALC__DINO__H__
#define __JWA_CALC__DINO__H__

#include <vector>
#include <memory>
#include <string>
#include <list>
#include <initializer_list>
#include <functional>
#include <set>
#include <list>
#include "ability.h"
#include "strprintf.h"
#include "modifiers.h"
#include "actions.h"
#include "utils.h"
#include "pack.h"

static const int COMMON = 0;
static const int RARE = 1;
static const int EPIC = 2;
static const int LEGENDARY = 3;
static const int UNIQUE = 4;
static const int APEX = 5;
static const int OMEGA = 6;

struct DinoRound
{
	int health;
	int damage;
	int speed;
	double armor;
	double crit_chance;
	double crit_factor;
	double crit_reduction_resistance;
	double damage_over_time_resistance;
	double damage_reduction_resistance;
	double rend_resistance;
	double speed_reduction_resistance;
	double stun_resistance;
	double swap_prevention_resistance;
	double taunt_resistance;
	double vulnerability_resistance;
	double armor_reduction_resistance;
	double affliction_resistance;
	std::vector<const Ability *> ability;
	const CounterAbility *counter_attack;
    DinoRound(int _health, int _damage, int _speed, int _armor, int _crit_chance, int _crit_factor,
            double _crit_reduction_resistance,
            double _damage_over_time_resistance,
            double _damage_reduction_resistance,
            double _rend_resistance,
            double _speed_reduction_resistance,
            double _stun_resistance,
            double _swap_prevention_resistance,
            double _taunt_resistance,
            double _vulnerability_resistance,
            double _armor_reduction_resistance,
			double _affliction_resistance,
            std::initializer_list<Ability *> _ability, CounterAbility *_counter_attack)
        : health(_health)
        , damage(_damage)
        , speed(_speed)
        , armor(_armor / 100.)
        , crit_chance(_crit_chance / 100.)
	    , crit_factor(_crit_factor / 100.)
        , crit_reduction_resistance(_crit_reduction_resistance / 100.)
        , damage_over_time_resistance(_damage_over_time_resistance / 100.)
        , damage_reduction_resistance(_damage_reduction_resistance / 100.)
        , rend_resistance(_rend_resistance / 100.)
        , speed_reduction_resistance(_speed_reduction_resistance / 100.)
        , stun_resistance(_stun_resistance / 100.)
        , swap_prevention_resistance(_swap_prevention_resistance / 100.)
        , taunt_resistance(_taunt_resistance / 100.)
        , vulnerability_resistance(_vulnerability_resistance / 100.)
        , armor_reduction_resistance(_armor_reduction_resistance / 100.)
		, affliction_resistance(_affliction_resistance / 100.)
		, ability(_ability.begin(), _ability.end())
		, counter_attack(_counter_attack)
    {}
};

enum class RestrictionType {
    Ability,
    Counter,
    SwapIn,
    OnEscape,
    CritReductionResistance,
    DamageOverTimeResistance,
    DamageReductionResistance,
    RendResistance,
    SpeedReductionResistance,
    StunResistance,
    SwapPreventionResistance,
    TauntResistance,
    VulnerabilityResistance,
    ArmorReductionResistance,
    AfflictionResistance,
};

struct Restriction
{
    int level;
    RestrictionType type;
    double restriction;
    Restriction(int _level, RestrictionType _type, double _restriction)
        : level(_level)
        , type(_type)
        , restriction(_restriction)
    {}
};

struct DinoKind
{
    std::string name;
    int rarity;
    int flock;
    int omega_health_step;
    int omega_damage_step;
    int omega_speed_step;
    double omega_armor_step;
    double omega_crit_chance_step;
    double omega_crit_factor_step;
    int max_omega_health_points;
    int max_omega_damage_points;
    int max_omega_speed_points;
    int max_omega_armor_points;
    int max_omega_crit_chance_points;
    int max_omega_crit_factor_points;
    std::vector<int> level_points;
    std::vector<Restriction> restrictions;
    std::vector<DinoRound> round;

    DinoKind(const std::string &_name, int _rarity, int _flock, std::initializer_list<DinoRound> _round)
        : name(_name)
        , rarity(_rarity)
        , flock(_flock)
        , omega_health_step(0)
        , omega_damage_step(0)
        , omega_speed_step(0)
        , omega_armor_step(0)
        , omega_crit_chance_step(0)
        , omega_crit_factor_step(0)
        , max_omega_health_points(0)
        , max_omega_damage_points(0)
        , max_omega_speed_points(0)
        , max_omega_armor_points(0)
        , max_omega_crit_chance_points(0)
        , max_omega_crit_factor_points(0)
        , level_points{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        , restrictions{
            {1, RestrictionType::Counter, 1},
            {1, RestrictionType::Ability, 4}
        }
        , round(_round.begin(), _round.end())
    {}
    DinoKind(const std::string &_name, int _rarity, int _flock,
             int _omega_health_step, int _omega_damage_step, int _omega_speed_step, double _omega_armor_step, double _omega_crit_chance_step, double _omega_crit_factor_step,
             int _max_omega_health_points, int _max_omega_damage_points, int _max_omega_speed_points, int _max_omega_armor_points, int _max_omega_crit_chance_points, int _max_omega_crit_factor_points,
             std::initializer_list<int> _level_points,
             std::initializer_list<Restriction> _restrictions,
             std::initializer_list<DinoRound> _round)
        : name(_name)
        , rarity(_rarity)
        , flock(_flock)
        , omega_health_step(_omega_health_step)
        , omega_damage_step(_omega_damage_step)
        , omega_speed_step(_omega_speed_step)
        , omega_armor_step(_omega_armor_step / 100.)
        , omega_crit_chance_step(_omega_crit_chance_step / 100.)
        , omega_crit_factor_step(_omega_crit_factor_step / 100.)
        , max_omega_health_points(_max_omega_health_points)
        , max_omega_damage_points(_max_omega_damage_points)
        , max_omega_speed_points(_max_omega_speed_points)
        , max_omega_armor_points(_max_omega_armor_points)
        , max_omega_crit_chance_points(_max_omega_crit_chance_points)
        , max_omega_crit_factor_points(_max_omega_crit_factor_points)
        , level_points(_level_points.begin(), _level_points.end())
        , restrictions(_restrictions.begin(), _restrictions.end())
        , round(_round.begin(), _round.end())
    {}
};

bool ActionOrderCmp(const Dino &dino1, const Dino &dino2);

struct dodge_cmp
{
    constexpr bool operator()(const std::pair<double, double> &lhs, const std::pair<double, double> &rhs ) const
    {
        if (lhs.first * lhs.second > rhs.first * rhs.second)
            return true;
        if (lhs.first * lhs.second < rhs.first * rhs.second)
            return false;
        if (lhs.first > rhs.first)
            return true;
//        if (lhs.first < rhs.first)
//            return false;
        return false;
    }
};

struct Dino
{
    const DinoKind *kind; // базовые параметры
    int rounds;
    int team; // команда
    int index; // позиция в схеме
    int level;
    int health_boost;
    int damage_boost;
    int speed_boost;
    int max_health = 0;
    int health = 0; // текущее количество жизней
    double damage = 0; // базовая атака
    int speed = 0; // текущая скорость
    int ability_id = -1; // номер атаки
    int priority = 0; // приоритет в текущем ходу
    bool minor = false;
    bool threatened = false; // угнетение в текущем ходу
    std::vector<modifiers::Mod> mods;
    double vulnerability = 0;
    double damage_factor = 1;
    double speed_factor = 1;
    double armor_base = 0;
    double armor_change = 0;
    double crit_chance_base = 0;
    double crit_chance_change = 0;
    double crit_factor = 0;
    double affliction = 0;
    double affliction_factor = 0;
    bool taunt = false;
    int total_health = 0;
    int max_total_health = 0;
    int initial_total_health = 0;
    int round = 0;
    int turn = 0;
    Dino *attacker = nullptr; // это норм
    int revenge = 0;
    bool revenge_ready = false;
    int last_damage = 0;
    int devour_heal = 0;
    double damage_over_time = 0;
    std::multiset<double, std::greater<double>> shield{0};
    std::multiset<std::pair<double, double>, dodge_cmp> dodge{std::make_pair(0, 0)};
    int cooldown[4] = {};
    bool crit = false;
    bool killer = false;
    std::vector<int> flock_segment;
    int n_positive_effects = 0;
    int stun = 0;
    std::multiset<double, std::greater<double>> cloak_factor;
    std::string name;
    class Stats *stats = nullptr;
    int omega_health_points;
    int omega_damage_points;
    int omega_speed_points;
    int omega_armor_points;
    int omega_crit_chance_points;
    int omega_crit_factor_points;
    double crit_reduction_resistance;
    double damage_over_time_resistance;
    double damage_reduction_resistance;
    double rend_resistance;
    double speed_reduction_resistance;
    double stun_resistance;
    double swap_prevention_resistance;
    double taunt_resistance;
    double vulnerability_resistance;
    double armor_reduction_resistance;
    double affliction_resistance;
    std::vector<const Ability *> ability;
    const CounterAbility *counter_attack;

    Dino(int _team, int _index, int _level, int _health_boost, int _damage_boost, int _speed_boost, const DinoKind *_kind);
    Dino(int _team, int _index, int _level, int _health_boost, int _damage_boost, int _speed_boost,
         int _omega_health_points, int _omega_damage_points, int _omega_speed_points, int _omega_armor_points, int _omega_crit_chance_points, int _omega_crit_factor_points,
         const DinoKind *_kind);

    void InitRound()
    {
        return InitRound(this->round);
    }
    void InitRound(int round);
    double GetRestriction(int level, RestrictionType type, double _default = 0);
    int Damage() const
    {
        return floor(damage * DamageFactor());
    }
    double SpeedFactor() const
    {
        if (speed_factor < 0)
            return 0;
        return speed_factor;
    }
    int Speed() const
    {
        return ::Round(speed * SpeedFactor());
    }
    bool Prepare(int ability_id, bool minor = false);
    void Attack(Dino team[], int team_size);
    void CounterAttack(Dino team[], int team_size);
    void Impose(const modifiers::Modifier *mod, Dino &author);
    void Dispose(int type_flags, Dino &author);
    double DamageFactor() const
    {
        if (damage_factor < 0)
            return 0;
        return damage_factor;
    }
    double CritChance() const
    {
    	double crit_chance = crit_chance_base + crit_chance_change;
        if (crit_chance < 0)
            return 0;
        if (crit_chance > 1)
            return 1;
        return crit_chance;
    }
    double Armor() const
    {
    	double armor = armor_base + armor_change;
        if (armor < 0)
            return 0;
        if (armor > 1)
            return 1;
        return armor;
    }
    bool Alive() const
    {
        return total_health > 0;
    }
    void PassTurn();
    bool Taunt() const
    {
        return taunt;
    }
    void DevourHeal();
    void DamageOverTime(Dino team[], int team_size);
    std::string Name() const;
    void Revive(bool total);
    double Shield() const
    {
        return *shield.begin();
    }
    double DodgeChance() const
    {
        if (dodge.size() == 0)
            return 0;
        return dodge.begin()->first;
    }
    double DodgeFactor() const
    {
        if (dodge.size() == 0)
            return 1;
        return dodge.begin()->second;
    }
    double CloakFactor() const
    {
        if (cloak_factor.size() == 0)
            return 1;
        return *cloak_factor.begin();
    }
    double ResistanceFactor(double Dino::*resistance) const
    {
    	return 1 - Norm(this->*resistance - affliction);
    }
    void Hit(const Dino &attacker, int damage, bool premature = false);
    void Heal(const Dino &healer, int heal);
    int Absorb(int damage);
    int HealAbsorb(int heal);
    void Revenge(Dino &source);
private:
    const DinoRound &Round() const
    {
    	return Round(this->round);
    }
    const DinoRound &Round(int round) const
    {
    	return kind->round[round];
    }
//    const DinoRound *operator ->() const
//	{
//    	return &Round();
//	}
};

#include "unpack.h"

#endif // __JWA_CALC__DINO__H__
