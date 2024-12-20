#include "modifiers.h"
#include "dino.h"
#include "utils.h"

using namespace std;
using namespace modifiers;

void Vulnerability::Impose(Dino &target, Mod *mod) const
{
	mod->value = factor * target.ResistanceFactor(&Dino::vulnerability_resistance);
    target.vulnerability += mod->value;
}

void Vulnerability::Dispose(Dino &target, Mod *mod) const
{
    target.vulnerability -= mod->value;
}

void Taunt::Impose(Dino &target, Mod *) const
{
    target.taunt = true;
    ++target.n_positive_effects;
}

void Taunt::Dispose(Dino &target, Mod *) const
{
    target.taunt = false;
    --target.n_positive_effects;
}

void IncreasedCritChance::Impose(Dino &target, Mod *) const
{
    target.crit_chance_change += factor;
    ++target.n_positive_effects;
}

void IncreasedCritChance::Dispose(Dino &target, Mod *) const
{
    target.crit_chance_change -= factor;
    --target.n_positive_effects;
}

void IncreasedDamage::Impose(Dino &target, Mod *) const
{
    target.damage_factor += factor;
    ++target.n_positive_effects;
}

void IncreasedDamage::Dispose(Dino &target, Mod *) const
{
    target.damage_factor -= factor;
    --target.n_positive_effects;
}

void ReducedSpeed::Impose(Dino &target, Mod *mod) const
{
	mod->value = factor * target.ResistanceFactor(&Dino::speed_reduction_resistance);
    target.speed_factor -= mod->value;
}

void ReducedSpeed::Dispose(Dino &target, Mod *mod) const
{
    target.speed_factor += mod->value;
}

void ReducedDamage::Impose(Dino &target, Mod *mod) const
{
	mod->value = factor * target.ResistanceFactor(&Dino::damage_reduction_resistance);
    target.damage_factor -= mod->value;
}

void ReducedDamage::Dispose(Dino &target, Mod *mod) const
{
    target.damage_factor += mod->value;
}

void Dodge::Impose(Dino &target, Mod *) const
{
    target.dodge.insert(make_pair(chance, factor));
    ++target.n_positive_effects;
}

void Dodge::Dispose(Dino &target, Mod *) const
{
    target.dodge.erase(target.dodge.find(make_pair(chance, factor)));
    --target.n_positive_effects;
}

void IncreasedSpeed::Impose(Dino &target, Mod *) const
{
    target.speed_factor += factor;
    ++target.n_positive_effects;
}

void IncreasedSpeed::Dispose(Dino &target, Mod *) const
{
    target.speed_factor -= factor;
    --target.n_positive_effects;
}

void ReducedCritChance::Impose(Dino &target, Mod *mod) const
{
	mod->value = factor * target.ResistanceFactor(&Dino::crit_reduction_resistance);
    target.crit_chance_change -= mod->value;
}

void ReducedCritChance::Dispose(Dino &target, Mod *mod) const
{
    target.crit_chance_change += mod->value;
}

void Shield::Impose(Dino &target, Mod *) const
{
    target.shield.insert(factor);
    ++target.n_positive_effects;
}

void Shield::Dispose(Dino &target, Mod *) const
{
    target.shield.erase(target.shield.find(factor));
    --target.n_positive_effects;
}

void Revenge::Impose(Dino &target, Mod *) const
{
    ++target.revenge;
}

void Revenge::Dispose(Dino &target, Mod *) const
{
    --target.revenge;
    target.revenge_ready = false;
}

void DevourHeal::Impose(Dino &target, Mod *mod) const
{
    mod->value = Round(target.last_damage * factor / duration);
    target.devour_heal += (int)mod->value;
    ++target.n_positive_effects;
}

void DevourHeal::Dispose(Dino &target, Mod *mod) const
{
    target.devour_heal -= (int)mod->value;
    --target.n_positive_effects;
}

void DamageOverTime::Impose(Dino &target, Mod *mod) const
{
	mod->value = factor * target.ResistanceFactor(&Dino::damage_over_time_resistance);
    target.damage_over_time += mod->value;
}

void DamageOverTime::Dispose(Dino &target, Mod *mod) const
{
    target.damage_over_time -= mod->value;
}

void Stun::Impose(Dino &target, Mod *mod) const
{
    ++target.stun;
}

void Stun::Dispose(Dino &target, Mod *mod) const
{
    --target.stun;
}

void Cloak::Impose(Dino &target, Mod *mod) const
{
    target.dodge.insert(make_pair(dodge_chance, dodge_factor));
    target.cloak_factor.insert(attack_factor);
    ++target.n_positive_effects;
}

void Cloak::Dispose(Dino &target, Mod *mod) const
{
    target.dodge.erase(target.dodge.find(make_pair(dodge_chance, dodge_factor)));
    target.cloak_factor.erase(target.cloak_factor.find(attack_factor));
    --target.n_positive_effects;
}

void IncreasedArmor::Impose(Dino &target, Mod *) const
{
    target.armor_change += factor;
    ++target.n_positive_effects;
}

void IncreasedArmor::Dispose(Dino &target, Mod *) const
{
    target.armor_change -= factor;
    --target.n_positive_effects;
}

void ReducedArmor::Impose(Dino &target, Mod *mod) const
{
	mod->value = factor * target.ResistanceFactor(&Dino::armor_reduction_resistance);
    target.armor_change -= mod->value;
}

void ReducedArmor::Dispose(Dino &target, Mod *mod) const
{
    target.armor_change += mod->value;
}

void Affliction::Impose(Dino &target, Mod *mod) const
{
	mod->value = factor * (1 - target.affliction_resistance); // affliction doesn't affect itself
    target.affliction += mod->value;
    target.affliction_factor += mod->value;
}

void Affliction::Dispose(Dino &target, Mod *mod) const
{
	target.affliction -= mod->value * duration;
	target.affliction_factor -= mod->value;
}

void UnableToSwap::Impose(Dino &target, Mod *mod) const
{
}

void UnableToSwap::Dispose(Dino &target, Mod *mod) const
{
}

void IncreasedHealing::Impose(Dino &target, Mod *) const
{
    target.healing_factor += factor;
    ++target.n_positive_effects;
}

void IncreasedHealing::Dispose(Dino &target, Mod *) const
{
    target.healing_factor -= factor;
    --target.n_positive_effects;
}

void ReducedHealing::Impose(Dino &target, Mod *mod) const
{
    mod->value = factor * target.ResistanceFactor(&Dino::healing_reduction_resistance);
    target.healing_factor -= mod->value;
}

void ReducedHealing::Dispose(Dino &target, Mod *mod) const
{
    target.healing_factor += mod->value;
}

void CheatDeath::Impose(Dino &target, Mod *) const
{
    ++target.cheat_death;
    ++target.n_positive_effects;
}

void CheatDeath::Dispose(Dino &target, Mod *) const
{
    --target.cheat_death;
    --target.n_positive_effects;
}

