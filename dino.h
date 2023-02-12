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

static const int COMMON = 0;
static const int RARE = 1;
static const int EPIC = 2;
static const int LEGENDARY = 3;
static const int UNIQUE = 4;
static const int APEX = 5;

struct DinoKind
{
    std::string name;
    int rarity;
    int flock;
    int health;
    int damage;
    int speed;
    double armor;
    double crit;
    double crit_reduction_resistance;
    double damage_over_time_resistance;
    double damage_reduction_resistance;
    double rend_resistance;
    double speed_reduction_resistance;
    double stun_resistance;
    double swap_prevention_resistance;
    double taunt_resistance;
    double vulnerable_resistance;
    double armor_reduction_resistance;
    std::vector<std::vector<const Ability *>> ability;
    const CounterAbility *counter_attack;

    DinoKind(const std::string &_name, int _rarity, int _flock, int _health, int _damage, int _speed, int _armor, int _crit,
            double _crit_reduction_resistance,
            double _damage_over_time_resistance,
            double _damage_reduction_resistance,
            double _rend_resistance,
            double _speed_reduction_resistance,
            double _stun_resistance,
            double _swap_prevention_resistance,
            double _taunt_resistance,
            double _vulnerable_resistance,
            double _armor_reduction_resistance,
            std::initializer_list<std::initializer_list<Ability *>> _ability, CounterAbility *_counter_attack)
        : name(_name)
        , rarity(_rarity)
        , flock(_flock)
        , health(_health)
        , damage(_damage)
        , speed(_speed)
        , armor(_armor / 100.)
        , crit(_crit / 100.)
        , crit_reduction_resistance(_crit_reduction_resistance / 100.)
        , damage_over_time_resistance(_damage_over_time_resistance / 100.)
        , damage_reduction_resistance(_damage_reduction_resistance / 100.)
        , rend_resistance(_rend_resistance / 100.)
        , speed_reduction_resistance(_speed_reduction_resistance / 100.)
        , stun_resistance(_stun_resistance / 100.)
        , swap_prevention_resistance(_swap_prevention_resistance / 100.)
        , taunt_resistance(_taunt_resistance / 100.)
        , vulnerable_resistance(_vulnerable_resistance / 100.)
        , armor_reduction_resistance(_armor_reduction_resistance / 100.)
        , counter_attack(_counter_attack)
    {
        for (auto &ability_it: _ability)
            ability.emplace_back(ability_it.begin(), ability_it.end());
    }
    DinoKind(const std::string &_name, int _rarity, int _flock, int _health, int _damage, int _speed, int _armor, int _crit,
            double _crit_reduction_resistance,
            double _damage_over_time_resistance,
            double _damage_reduction_resistance,
            double _rend_resistance,
            double _speed_reduction_resistance,
            double _stun_resistance,
            double _swap_prevention_resistance,
            double _taunt_resistance,
            double _vulnerable_resistance,
            double _armor_reduction_resistance,
            std::initializer_list<Ability *> _ability, CounterAbility *_counter_attack)
        : DinoKind(
            _name,
            _rarity,
            _flock,
            _health,
            _damage,
            _speed,
            _armor,
            _crit,
            _crit_reduction_resistance,
            _damage_over_time_resistance,
            _damage_reduction_resistance,
            _rend_resistance,
            _speed_reduction_resistance,
            _stun_resistance,
            _swap_prevention_resistance,
            _taunt_resistance,
            _vulnerable_resistance,
            _armor_reduction_resistance,
            {_ability},
            _counter_attack)
    {}
};

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
    int max_health;
    int health; // текущее количество жизней
    double damage; // базовая атака
    int speed; // текущая скорость
    int ability_id = -1; // номер атаки
    int priority = 0; // приоритет в текущем ходу
    bool minor = false;
    bool threatened = false; // угнетение в текущем ходу
    std::vector<modifiers::Mod> mods;
    double vulnerability = 0;
    double damage_factor = 1;
    double speed_factor = 1;
    double crit_chance_factor;
    double armor;
    bool taunt = false;
    int total_health;
    int max_total_health;
    int round = 0;
    int turn = 0;
    Dino *attacker = nullptr; // это норм
    int revenge = 0;
    bool revenge_ready = false;
    int last_damage = 0;
    int devour_heal = 0;
    int damage_over_time = 0;
    std::multiset<double, std::greater<double>> shield{0};
    std::multiset<std::pair<double, double>, dodge_cmp> dodge{std::make_pair(0, 0)};
    int cooldown[4] = {};
    double prepared_damage_factor = 0;
    bool crit = false;
    bool killer = false;
    std::vector<int> flock_segment;
    int n_positive_effects = 0;
    int stun = 0;
    std::set<double, std::greater<double>> cloak_factor;
    std::string name;

    Dino(int _team, int _index, int _level, int _health_boost, int _damage_boost, int _speed_boost, const DinoKind *_kind);

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
        return Round(speed * SpeedFactor());
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
    double CritChanceFactor() const
    {
        if (crit_chance_factor < 0)
            return 0;
        if (crit_chance_factor > 1)
            return 1;
        return crit_chance_factor;
    }
    double Armor() const
    {
        if (armor < 0)
            return 0;
        if (armor > 1)
            return 1;
        return armor;
    }
    bool Alive() const
    {
        return health > 0 || round + 1 < rounds;
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
    void Hit(const Dino &attacker, int damage);
    void Heal(const Dino &healer, int heal);
    int Absorb(int damage);
    int HealAbsorb(int heal);
    const ::Ability *Ability(int i) const
    {
        return kind->ability[round][i];
    }
    void Revenge(Dino &source);
};

#endif // __JWA_CALC__DINO__H__
