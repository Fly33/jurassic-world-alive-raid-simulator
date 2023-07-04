#ifndef __JWA_CALC__MODIFIERS__H__
#define __JWA_CALC__MODIFIERS__H__

#include <string>
#include "strprintf.h"
#include "pack.h"

struct Dino;

static const int REDUCED_DAMAGE = 1 << 0;
static const int DODGE = 1 << 1;
static const int CLOAK = 1 << 2;
static const int INCREASED_SPEED = 1 << 3;
static const int SHIELD = 1 << 4;
static const int TAUNT = 1 << 5;
static const int REDUCED_CRIT_CHANCE = 1 << 6;
static const int VULNERABILITY = 1 << 7;
static const int INCREASED_CRIT_CHANCE = 1 << 8;
static const int INCREASED_DAMAGE = 1 << 9;
static const int REDUCED_SPEED = 1 << 10;
static const int DAMAGE_OVER_TIME = 1 << 11;
static const int REVENGE = 1 << 12;
static const int DEVOUR_HEAL = 1 << 13;
static const int STUN = 1 << 14;
static const int INCREASED_ARMOR = 1 << 15;
static const int REDUCED_ARMOR = 1 << 16;
static const int AFFLICTION = 1 << 17;

static const int NEGATIVE_EFFECTS = REDUCED_DAMAGE|VULNERABILITY|REDUCED_SPEED|DAMAGE_OVER_TIME|REDUCED_CRIT_CHANCE|REDUCED_ARMOR|AFFLICTION;
static const int POSITIVE_EFFECTS = DODGE|CLOAK|INCREASED_SPEED|SHIELD|TAUNT|INCREASED_CRIT_CHANCE|INCREASED_DAMAGE|DEVOUR_HEAL|INCREASED_ARMOR;
static const int ALL_EFFECTS = NEGATIVE_EFFECTS|POSITIVE_EFFECTS|REVENGE|STUN;

namespace modifiers
{

struct Mod;

struct Modifier
{
    const std::string name;
    int duration;
    int number;

    Modifier(const std::string &_name, int _duration, int _number = 0)
        : name(_name)
        , duration(_duration)
        , number(_number)
    {
    }
    virtual ~Modifier() {}
    virtual void Impose(Dino &target, Mod *mod) const = 0;
    virtual void Dispose(Dino &target, Mod *mod) const = 0;
    virtual int Type() const = 0;
    virtual bool OutgoingAttack(Mod *mod) const
    {
        return false;
    }
    virtual bool IncomingAttack(Mod *mod) const
    {
        return false;
    }
    virtual bool OutgoingHeal(Mod *mod) const
    {
        return false;
    }
    virtual bool OnAction(Mod *mod) const
    {
        return false;
    }
    virtual bool OnEndOfTurn(Mod *mod) const
    {
        return false;
    }
    virtual std::string Name(const Mod *mod) const
    {
    	return name;
    }
};

struct Mod
{
    const Modifier *modifier;
    int duration;
    int number;
    double value = 0;
    Mod(const Modifier *_modifier)
        : modifier(_modifier)
        , duration(_modifier->duration)
        , number(_modifier->number)
    {
    }
    ~Mod()
    {
    }
    void Impose(Dino &target)
    {
    	modifier->Impose(target, this);
    }
    void Dispose(Dino &target)
    {
    	modifier->Dispose(target, this);
    }
    bool OutgoingAttack()
    {
        return modifier->OutgoingAttack(this);
    }
    bool IncomingAttack()
    {
        return modifier->IncomingAttack(this);
    }
    bool OutgoingHeal()
    {
        return modifier->OutgoingHeal(this);
    }
    bool OnAction()
    {
        return modifier->OnAction(this);
    }
    bool OnEndOfTurn()
    {
        return modifier->OnEndOfTurn(this);
    }
    int Type()
    {
        return modifier->Type();
    }
    std::string Name() const
    {
    	return modifier->Name(this);
    }
};

#define REMOVE_MODS(self, condition, log) \
    do { \
        for (auto mod_it = (self).mods.begin(); mod_it != (self).mods.end(); ) { \
            if (condition) { \
                mod_it->Dispose(self); \
                (log); \
                std::swap(*mod_it, (self).mods.back()); \
                (self).mods.pop_back(); \
            } else \
                ++mod_it; \
        } \
    } while(false)


struct Vulnerability: public Modifier
{
    double factor;

    Vulnerability(double _factor, int _duration, int _number)
        : Modifier("vulnerability", _duration, _number)
        , factor(_factor)
    {
    }
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual std::string Name(const Mod *mod) const
    {
    	return strprintf("%s by %.1lf%%", name.c_str(), mod->value * 100);
    }
    virtual int Type() const override
    {
        return VULNERABILITY;
    }
    virtual bool IncomingAttack(Mod *mod) const override
    {
        return !--mod->number;
    }
    virtual bool OnEndOfTurn(Mod *mod) const override
    {
        return mod->duration-- == 0;
    }
};

struct Taunt: public Modifier
{
    Taunt(int _duration)
        : Modifier("taunt", _duration)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual int Type() const override
    {
        return TAUNT;
    }
    virtual bool OnEndOfTurn(Mod *mod) const override
    {
        return mod->duration-- == 0;
    }
};

struct IncreasedCritChance: public Modifier
{
    double factor;
    IncreasedCritChance(double _factor, int _duration, int _number)
        : Modifier("increased crit chance", _duration, _number)
        , factor(_factor)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual std::string Name(const Mod *mod) const
    {
    	return strprintf("%s by %.1lf%%", name.c_str(), factor * 100);
    }
    virtual int Type() const override
    {
        return INCREASED_CRIT_CHANCE;
    }
    virtual bool OutgoingAttack(Mod *mod) const override
    {
        return !--mod->number;
    }
    virtual bool OnAction(Mod *mod) const override
    {
        return --mod->duration == 0;
    }
};

struct IncreasedDamage: public Modifier
{
    double factor;
    IncreasedDamage(double _factor, int _duration, int _number)
        : Modifier("increased damage", _duration, _number)
        , factor(_factor)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual std::string Name(const Mod *mod) const
    {
    	return strprintf("%s by %.1lf%%", name.c_str(), factor * 100);
    }
    virtual int Type() const override
    {
        return INCREASED_DAMAGE;
    }
    virtual bool OutgoingAttack(Mod *mod) const override
    {
        return !--mod->number;
    }
    virtual bool OutgoingHeal(Mod *mod) const override
    {
        return !--mod->number;
    }
    virtual bool OnAction(Mod *mod) const override
    {
        return --mod->duration == 0;
    }
};

struct ReducedSpeed: public Modifier
{
    double factor;
    ReducedSpeed(double _factor, int _duration, int _number)
        : Modifier("reduced speed", _duration, _number)
        , factor(_factor)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual std::string Name(const Mod *mod) const
    {
    	return strprintf("%s by %.1lf%%", name.c_str(), mod->value * 100);
    }
    virtual int Type() const override
    {
        return REDUCED_SPEED;
    }
    virtual bool OnEndOfTurn(Mod *mod) const override
    {
        return mod->duration-- == 0;
    }
};

struct ReducedDamage: public Modifier
{
    double factor;
    ReducedDamage(double _factor, int _duration, int _number)
        : Modifier("reduced damage", _duration, _number)
        , factor(_factor)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual std::string Name(const Mod *mod) const
    {
    	return strprintf("%s by %.1lf%%", name.c_str(), mod->value * 100);
    }
    virtual int Type() const override
    {
        return REDUCED_DAMAGE;
    }
    virtual bool OutgoingAttack(Mod *mod) const override
    {
        return !--mod->number;
    }
    virtual bool OutgoingHeal(Mod *mod) const override
    {
        return !--mod->number;
    }
    virtual bool OnAction(Mod *mod) const override
    {
        return --mod->duration == 0;
    }
};

struct Dodge : public Modifier
{
    double chance;
    double factor;
    bool this_turn;
    Dodge(double _chance, double _factor, int _duration, int _number)
        : Modifier("dodge", _duration, _number)
        , chance(_chance)
        , factor(_factor)
    	, this_turn(_duration == 0)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual std::string Name(const Mod *mod) const
    {
    	return strprintf("%.1lf%% chance to dodge by %.1lf%%", chance * 100, factor * 100);
    }
    virtual int Type() const override
    {
        return DODGE;
    }
    virtual bool IncomingAttack(Mod *mod) const override
    {
        return !--mod->number;
    }
    virtual bool OnAction(Mod *mod) const override
    {
        return mod->duration-- == 0 && !this_turn;
    }
    virtual bool OnEndOfTurn(Mod *mod) const override
    {
        return this_turn;
    }
};

struct IncreasedSpeed: public Modifier
{
    double factor;
    IncreasedSpeed(double _factor, int _duration, int _number)
        : Modifier("increased speed", _duration, _number)
        , factor(_factor)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual std::string Name(const Mod *mod) const
    {
    	return strprintf("%s by %.1lf%%", name.c_str(), factor * 100);
    }
    virtual int Type() const override
    {
        return INCREASED_SPEED;
    }
    virtual bool OnEndOfTurn(Mod *mod) const override
    {
        return mod->duration-- == 0;
    }
};

struct ReducedCritChance: public Modifier
{
    double factor;
    ReducedCritChance(double _factor, int _duration, int _number)
        : Modifier("reduced crit chance", _duration, _number)
        , factor(_factor)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual std::string Name(const Mod *mod) const
    {
    	return strprintf("%s by %.1lf%%", name.c_str(), mod->value * 100);
    }
    virtual int Type() const override
    {
        return REDUCED_CRIT_CHANCE;
    }
    virtual bool OutgoingAttack(Mod *mod) const override
    {
        return !--mod->number;
    }
    virtual bool OnAction(Mod *mod) const override
    {
        return --mod->duration == 0;
    }
};

struct Shield : public Modifier
{
    double factor;
    bool this_turn;
    Shield(double _factor, int _duration, int _number)
        : Modifier("shield", _duration, _number)
        , factor(_factor)
    	, this_turn(_duration == 0)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual std::string Name(const Mod *mod) const
    {
    	return strprintf("%s by %.1lf%%", name.c_str(), factor * 100);
    }
    virtual int Type() const override
    {
        return SHIELD;
    }
    virtual bool IncomingAttack(Mod *mod) const override
    {
        return !--mod->number;
    }
    virtual bool OnAction(Mod *mod) const override
    {
        return mod->duration-- == 0 && !this_turn;
    }
    virtual bool OnEndOfTurn(Mod *mod) const override
    {
        return this_turn;
    }
};

struct Revenge : public Modifier
{
    Revenge()
        : Modifier("revenge", 1)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual int Type() const override
    {
        return REVENGE;
    }
    virtual bool OnAction(Mod *mod) const override
    {
        return mod->duration == 0;
    }
    virtual bool OnEndOfTurn(Mod *mod) const override
    {
        return mod->duration-- == 0;
    }
};

struct DevourHeal : public Modifier
{
    double factor;
    DevourHeal(double _factor, int _duration)
        : Modifier("devour heal", _duration)
        , factor(_factor)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual std::string Name(const Mod *mod) const
    {
    	return strprintf("%s by %.0lf", name.c_str(), mod->value);
    }
    virtual int Type() const override
    {
        return DEVOUR_HEAL;
    }
    virtual bool OnEndOfTurn(Mod *mod) const override
    {
        return mod->duration-- == 0;
    }
};

struct DamageOverTime : public Modifier
{
    double factor;
    DamageOverTime(double _factor, int _duration)
        : Modifier("damage over time", _duration)
        , factor(_factor)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual std::string Name(const Mod *mod) const
    {
    	return strprintf("%s by %.1lf%%", name.c_str(), mod->value * 100);
    }
    virtual int Type() const override
    {
        return DAMAGE_OVER_TIME;
    }
    virtual bool OnEndOfTurn(Mod *mod) const override
    {
        return mod->duration-- == 0;
    }
};

struct Stun : public Modifier
{
    Stun(int _duration)
        : Modifier("stun", _duration)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual int Type() const override
    {
        return STUN;
    }
    virtual bool OnAction(Mod *mod) const override
    {
        return --mod->duration == 0;
    }
};

struct Cloak : public Modifier
{
    double attack_factor;
    double dodge_chance;
    double dodge_factor;
    Cloak(double _attack_factor, double _dodge_chance, double _dodge_factor, int _duration, int _number = 0)
        : Modifier("cloak", _duration, _number)
        , attack_factor(_attack_factor)
        , dodge_chance(_dodge_chance)
        , dodge_factor(_dodge_factor)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual std::string Name(const Mod *mod) const
    {
    	return strprintf("cloak %.1lfx damage on next attack and %.1lf%% chance to dodge by %.1lf%%", attack_factor, dodge_chance, dodge_factor);
    }
    virtual int Type() const override
    {
        return CLOAK;
    }
    virtual bool IncomingAttack(Mod *mod) const override
    {
        return !--mod->number;
    }
    virtual bool OnAction(Mod *mod) const override
    {
        return mod->duration-- == 0;
    }
};

struct IncreasedArmor: public Modifier
{
    double factor;
    IncreasedArmor(double _factor, int _duration, int _number)
        : Modifier("increased armor", _duration, _number)
        , factor(_factor)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual std::string Name(const Mod *mod) const
    {
    	return strprintf("%s by %.1lf%%", name.c_str(), factor * 100);
    }
    virtual int Type() const override
    {
        return INCREASED_ARMOR;
    }
    virtual bool OutgoingAttack(Mod *mod) const override
    {
        return !--mod->number;
    }
    virtual bool OnEndOfTurn(Mod *mod) const override
    {
        return --mod->duration == 0;
    }
};

struct ReducedArmor: public Modifier
{
    double factor;
    ReducedArmor(double _factor, int _duration, int _number)
        : Modifier("reduced armor", _duration, _number)
        , factor(_factor)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual std::string Name(const Mod *mod) const
    {
    	return strprintf("%s by %.1lf%%", name.c_str(), mod->value * 100);
    }
    virtual int Type() const override
    {
        return REDUCED_ARMOR;
    }
    virtual bool OutgoingAttack(Mod *mod) const override
    {
        return !--mod->number;
    }
    virtual bool OnAction(Mod *mod) const override
    {
        return --mod->duration == 0;
    }
};

struct Affliction : public Modifier
{
    double factor;
    Affliction(double _factor, int _duration, int _number)
        : Modifier("affliction", _duration, _number)
        , factor(_factor)
    {}
    virtual void Impose(Dino &target, Mod *mod) const override;
    virtual void Dispose(Dino &target, Mod *mod) const override;
    virtual std::string Name(const Mod *mod) const
    {
    	return strprintf("%s by %.1lf%%", name.c_str(), factor * 100);
    }
    virtual int Type() const override
    {
        return AFFLICTION;
    }
    virtual bool OutgoingAttack(Mod *mod) const override
    {
        return !--mod->number;
    }
    virtual bool OnAction(Mod *mod) const override
    {
        return --mod->duration == 0;
    }
};

} // namespace modifiers

#include "unpack.h"

#endif // __JWA_CALC__MODIFIERS__H__
