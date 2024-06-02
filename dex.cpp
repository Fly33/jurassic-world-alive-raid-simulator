#include "dex.h"
#include "actions.h"
#include "dino.h"

using namespace actions;

namespace boss {

Ability AcceleratedStrike19B5("Accelerated Strike", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        IncreaseSpeed(50.0, 3, 0)
    )
});

Ability AcceleratingEvasiveStance2AAF("Accelerating Evasive Stance", 0, 3, 1, {
    TargetTeam(
        IncreaseSpeed(50.0, 2, 0)
    ),
    TargetSelf(
        Dodge(75.0, 67.0, 0, 4)
    )
});

Ability AcceleratingGroupImpactAA7C("Accelerating Group Impact", 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(10.0, 2, 4)
    ),
    TargetAllOpponents(
        Attack(1.5)
    )
});

Ability AcceleratingGroupStrike581B("Accelerating Group Strike", 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(10.0, 2, 4)
    ),
    TargetAllOpponents(
        Attack(1.0)
    )
});

ThreatenedAbility AlertAdvance2251("Alert Advance", 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        Attack(2.0)
    )
}, 25, ThreatComparison::Lower, 0, 0, 0, {
    TargetAllOpponents(
        Attack(1.5)
    ),
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Shield(100.0, 2, 8)
    )
});

ThreatenedAbility AlertAssistBA90("Alert Assist", 0, 0, 1, {
    TargetSelf(
        Shield(100.0, 1, 4)
    ),
    TargetTeam(
        IncreaseDamage(50.0, 2, 2),
        Shield(50.0, 2, 4)
    )
}, 50, ThreatComparison::Lower, 0, 0, 1, {
    TargetSelf(
        Shield(100.0, 1, 4)
    ),
    TargetTeam(
        IncreaseDamage(50.0, 2, 2),
        FixedHeal(10.0),
        IncreaseSpeed(30.0, 2, 0),
        Shield(100.0, 2, 4)
    )
});

ThreatenedCounterAbility AlertCoil5A3C("Alert Coil", {
    TargetSelf(
        IncreaseDamage(5.0, 3, 3)
    )
}, 50, ThreatComparison::Lower, {
    TargetSelf(
        IncreaseDamage(10.0, 3, 3)
    )
});

ThreatenedCounterAbility AlertCounterDistraction2BF3("Alert Counter Distraction", {
    TargetAttacker(
        ReduceDamage(10.0, 2, 4)
    )
}, 50, ThreatComparison::Lower, {
    TargetAttacker(
        ReduceDamage(15.0, 2, 4)
    )
});

ThreatenedAbility AlertMimic58E4("Alert Mimic", 0, 0, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 4)
    ),
    TargetSelf(
        Dodge(100.0, 67.0, 0, 4),
        IncreaseSpeed(10.0, 2, 0),
        Taunt(2)
    )
}, 50, ThreatComparison::Lower, 0, 0, 1, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 4)
    ),
    TargetTeam(
        Dodge(100.0, 67.0, 0, 4),
        IncreaseSpeed(10.0, 2, 0)
    ),
    TargetSelf(
        Taunt(2)
    )
});

ThreatenedAbility AlertNullification3D09("Alert Nullification", 0, 2, 1, {
    TargetAllOpponents(
        Remove(POSITIVE_EFFECTS),
        ReduceDamage(50.0, 2, 4)
    )
}, 50, ThreatComparison::Lower, 0, 2, 1, {
    TargetAllOpponents(
        Remove(POSITIVE_EFFECTS),
        ReduceDamage(75.0, 2, 4)
    )
});

Ability AlertNullification7C0F("Alert Nullification", 0, 2, 1, {
    TargetAllOpponents(
        Remove(POSITIVE_EFFECTS),
        ReduceDamage(75.0, 2, 4)
    )
});

ThreatenedAbility AlertSlither23E3("Alert Slither", 0, 0, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(50.0, 67.0, 3, 4),
        IncreaseCritChance(50.0, 3, 3)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 3, 6)
    )
}, 50, ThreatComparison::Lower, 0, 0, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(75.0, 67.0, 0, 4),
        IncreaseCritChance(75.0, 3, 3)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 3, 6)
    )
});

CounterAbility ArmorPiercingCounterAEB5("Armor Piercing Counter", {
    TargetAttacker(
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability AvianGale57A6("Avian Gale", 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(20.0, 2, 4)
    ),
    TargetTeam(
        IncreaseDamage(30.0, 2, 4)
    ),
    TargetAllOpponents(
        Attack(1.5)
    )
});

Ability AvianGrazeC01A("Avian Graze", 0, 0, 0, {
    TargetAllOpponents(
        Attack(1.0)
    )
});

Ability AvianGust163C("Avian Gust", 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(20.0, 2, 4)
    ),
    TargetTeam(
        IncreaseDamage(30.0, 2, 4)
    ),
    TargetAllOpponents(
        Attack(1.0)
    )
});

Ability BellowDDD8("Bellow", 0, 0, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Shield(50.0, 0, 4)
    ),
    TargetAllOpponents(
        ReduceSpeed(50.0, 2, 0)
    ),
    TargetSelf(
        Taunt(1)
    )
});

Ability BlindRampage3285("Blind Rampage", 0, 0, 0, {
    TargetRandom(
        Attack(2.0, ALWAYS_CRITS)
    )
});

Ability BodingDistraction71C6("Boding Distraction", 0, 0, 1, {
    TargetSelf(
        IncreaseSpeed(30.0, 2, 0),
        Dodge(75.0, 66.69999, 2, 2)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2)
    ),
    TargetSelf(
        IncreaseCritChance(50.0, 2, 2)
    )
});

Ability BoldRendingAttackB856("Bold Rending Attack", 0, 0, 0, {
    TargetHighestHP(
        Remove(SHIELD),
        Rend(25.0, BYPASS_ARMOR)
    )
});

Ability BoomAA79("Boom", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(2.0),
        ImposeVulnerability(50.0, 2, 1)
    )
});

RevengeAbility BrakingRevenge9580("Braking Revenge", 0, 0, 0, {
    TargetFastest(
        ReduceSpeed(50.0, 2, 0),
        Attack(2.0),
        DamageOverTime(15.0, 2)
    )
}, 0, 0, 1, {
    TargetAllOpponents(
        ReduceSpeed(75.0, 2, 0),
        Attack(2.0),
        DamageOverTime(34.0, 2)
    )
});

Ability BreakthroughE0A1("Breakthrough", 1, 1, 1, {
    TargetHighestHP(
        Remove(SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability BullyImpact2F83("Bully Impact", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.5, ALWAYS_CRITS)
    )
});

Ability CautiousGroupStrike9753("Cautious Group Strike", 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(10.0, 1, 0),
        Dodge(75.0, 67.0, 1, 4)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 1, 2),
        Attack(1.0, PRECISE)
    )
});

Ability CautiousPrecisePounceEA3D("Cautious Precise Pounce", 0, 0, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseSpeed(10.0, 3, 0),
        Dodge(75.0, 67.0, 1, 2)
    ),
    TargetLowestHP(
        Attack(2.0, PRECISE),
        ReduceDamage(50.0, 1, 2)
    )
});

Ability ClawingRampageD228("Clawing Rampage", 0, 0, 1, {
    TargetHighestDamage(
        Attack(2.0)
    )
});

Ability CleansingEvasiveImpact41F1("Cleansing Evasive Impact", 0, 0, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(75.0, 67.0, 1, 2)
    ),
    TargetLowestHP(
        Attack(1.5)
    )
});

Ability CleansingGroupCunningStrike6087("Cleansing Group Cunning Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.0)
    )
});

Ability CleansingPrimalTailWhip0DFD("Cleansing Primal Tail Whip", 0, 0, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability CleansingRandomImpact2314("Cleansing Random Impact", 0, 0, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetRandom(
        Attack(1.5)
    )
});

Ability CleansingRandomImpactBCA7("Cleansing Random Impact", 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetRandom(
        Attack(1.5)
    )
});

Ability CleansingRandomPiercingRampageCA35("Cleansing Random Piercing Rampage", 0, 0, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetRandom(
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability CleansingRandomShatteringStrikeD4F0("Cleansing Random Shattering Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetRandom(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability CleverDodge660B("Clever Dodge", 0, 0, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(100.0, 67.0, 0, 4),
        IncreaseCritChance(100.0, 3, 3)
    ),
    TargetAllOpponents(
        Remove(SHIELD)
    )
});

Ability Cloak2513("Cloak", 0, 3, 1, {
    TargetSelf(
        Cloak(2.0, 75.0, 66.66659, 2, 0)
    )
});

Ability CoilingRampage31C8("Coiling Rampage", 0, 0, 1, {
    TargetSelf(
        Shield(75.0, 3, 12)
    ),
    TargetAllOpponents(
        ReduceDamage(75.0, 2, 4)
    ),
    TargetHighestDamage(
        Attack(2.0)
    )
});

Ability Cold_bloodedRampage0A01("Cold-Blooded Rampage", 0, 0, 0, {
    TargetLowestHP(
        Attack(2.0, PRECISE)
    )
});

CounterAbility CounterScratch7FAF("Counter Scratch", {
    TargetAttacker(
        DamageOverTime(17.0, 3)
    )
});

CounterAbility CounterSpike7A97("Counter Spike", {
    TargetAttacker(
        Remove(SHIELD),
        Attack(0.5, BYPASS_ARMOR)
    ),
    TargetTeam(
        IncreaseDamage(10.0, 2, 2)
    )
});

CounterAbility CounterVulnerabilityC8BA("Counter Vulnerability", {
    TargetAttacker(
        Attack(1.0),
        ImposeVulnerability(50.0, 2, 1)
    )
});

Ability CriticalGroupImpactAC56("Critical Group Impact", 0, 0, 0, {
    TargetAllOpponents(
        Attack(1.5, ALWAYS_CRITS)
    )
});

Ability CriticalShake0032("Critical Shake", 0, 0, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseSpeed(10.0, 2, 0),
        IncreaseCritChance(100.0, 2, 1),
        Dodge(100.0, 67.0, 0, 2)
    )
});

RevengeAbility CunningCleanseRevengeE931("Cunning Cleanse Revenge", 0, 0, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(2.0)
    )
}, 0, 0, 1, {
    TargetTeam(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(2.0)
    )
});

Ability CunningImpactEE79("Cunning Impact", 0, 1, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.5)
    )
});

Ability CunningRampage8AEB("Cunning Rampage", 1, 1, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(2.0)
    )
});

Ability DaringEvasionCDAC("Daring Evasion", 0, 0, 1, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseSpeed(10.0, 2, 0),
        IncreaseDamage(50.0, 2, 1),
        Dodge(100.0, 67.0, 0, 2)
    )
});

RevengeAbility DaringGroupRevenge489D("Daring Group Revenge", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY|DAMAGE_OVER_TIME)
    ),
    TargetAllOpponents(
        Remove(TAUNT),
        Attack(1.5, BYPASS_ARMOR),
        ReduceDamage(50.0, 1, 2)
    )
}, 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY|DAMAGE_OVER_TIME)
    ),
    TargetAllOpponents(
        Remove(TAUNT),
        Attack(2.0, BYPASS_ARMOR),
        ReduceDamage(50.0, 1, 2)
    )
});

Ability DaringGroupStrike7E0C("Daring Group Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY|DAMAGE_OVER_TIME)
    ),
    TargetAllOpponents(
        Attack(1.0, BYPASS_ARMOR),
        ReduceDamage(50.0, 1, 2)
    )
});

Ability DeadlyDistraction5F14("Deadly Distraction", 0, 0, 0, {
    TargetHighestDamage(
        Attack(2.0),
        Stun(75.0, 1),
        ReduceDamage(50.0, 2, 4)
    )
});

Ability DeceleratingRampageD0C5("Decelerating Rampage", 1, 1, 0, {
    TargetFastest(
        ReduceSpeed(50.0, 2, 0),
        Attack(2.0)
    )
});

Ability DefenseShatteringImpact85C0("Defense Shattering Impact", 0, 0, 0, {
    TargetLowestHP(
        Remove(SHIELD)
    ),
    TargetLowestHP(
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability DefenseShatteringRampage5E24("Defense Shattering Rampage", 0, 0, 0, {
    TargetHighestHP(
        Remove(SHIELD)
    ),
    TargetHighestHP(
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability DefensiveGroupTaunt64E9("Defensive Group Taunt", 0, 2, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        Attack(1.0)
    ),
    TargetSelf(
        Shield(50.0, 2, 4),
        Taunt(1)
    )
});

Ability DefinitePowerRampage3EE2("Definite Power Rampage", 0, 0, 0, {
    TargetSelf(
        IncreaseDamage(50.0, 4, 4)
    ),
    TargetHighestHP(
        Remove(SHIELD|CLOAK|DODGE),
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability DelayedCautiousRampageAB44("Delayed Cautious Rampage", 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(10.0, 1, 0),
        Dodge(75.0, 67.0, 1, 1)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        Attack(2.0, PRECISE)
    )
});

Ability DeterminedGroupImpact7887("Determined Group Impact", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE|DAMAGE_OVER_TIME)
    ),
    TargetAllOpponents(
        Remove(INCREASED_SPEED|INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.5, PRECISE),
        ImposeVulnerability(50.0, 2, 1),
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2)
    )
});

Ability DeterminedGroupRampageF0D0("Determined Group Rampage", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE|DAMAGE_OVER_TIME)
    ),
    TargetAllOpponents(
        Remove(INCREASED_SPEED|INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(2.0, PRECISE),
        ImposeVulnerability(50.0, 2, 1),
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2)
    )
});

Ability DeterminedGroupStrikeCDD7("Determined Group Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE|DAMAGE_OVER_TIME)
    ),
    TargetAllOpponents(
        Remove(INCREASED_SPEED|INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.0, PRECISE),
        ImposeVulnerability(50.0, 2, 1),
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2)
    )
});

Ability Devastation3723("Devastation", 2, 1, 0, {
    TargetHighestHP(
        Attack(3.0, PRECISE)
    ),
    TargetSelf(
        Taunt(1)
    )
});

Ability DeviousGroupStrike5A92("Devious Group Strike", 0, 0, 0, {
    TargetSelf(
        Dodge(75.0, 67.0, 1, 2),
        IncreaseCritChance(30.0, 2, 2)
    ),
    TargetAllOpponents(
        Attack(1.0),
        ReduceDamage(25.0, 2, 4)
    )
});

Ability DispersedCunningStrike7D4C("Dispersed Cunning Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.0)
    )
});

Ability DispersedDeceleratingImpactF2D9("Dispersed Decelerating Impact", 0, 0, 0, {
    TargetAllOpponents(
        ReduceSpeed(50.0, 2, 0),
        Attack(1.5)
    )
});

Ability DispersedSuperiorVulnerability8D77("Dispersed Superior Vulnerability", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        ReduceSpeed(50.0, 2, 0),
        Attack(1.0, PRECISE),
        ImposeVulnerability(50.0, 2, 1)
    )
});

Ability DistractingImpactD4D6("Distracting Impact", 0, 2, 0, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        Attack(1.5)
    )
});

Ability DistractingRampage5363("Distracting Rampage", 0, 0, 0, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        Attack(2.0)
    )
});

Ability Dragon_sBite8539("Dragon'S Bite", 0, 0, 0, {
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR),
        DamageOverTime(20.0, 2)
    )
});

Ability EmergencyRegroup5FAB("Emergency Regroup", 0, 0, 1, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(1.5),
        Shield(50.0, 2, 4)
    )
});

Ability EnfeeblingRakingImpactC1AB("Enfeebling Raking Impact", 0, 0, 0, {
    TargetMostPositiveEffects(
        Remove(DODGE|CLOAK),
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability EvasiveDrainDA22("Evasive Drain", 0, 0, 1, {
    TargetSelf(
        IncreaseSpeed(30.0, 2, 0),
        Dodge(75.0, 66.69999, 2, 2)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2)
    )
});

Ability EvasiveFierceStrike29E7("Evasive Fierce Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.0, BYPASS_ARMOR)
    ),
    TargetSelf(
        Dodge(75.0, 66.69998, 2, 8)
    )
});

Ability EvasiveGroupWoundingImpactB11F("Evasive Group Wounding Impact", 0, 0, 0, {
    TargetAllOpponents(
        DamageOverTime(33.41, 3),
        Attack(1.5)
    ),
    TargetSelf(
        Dodge(100.0, 67.0, 2, 8)
    )
});

Ability EvasivePiercingImpactBC9F("Evasive Piercing Impact", 0, 0, 0, {
    TargetLowestHP(
        Remove(SHIELD),
        Attack(1.5, BYPASS_ARMOR)
    ),
    TargetSelf(
        Dodge(75.0, 66.69998, 2, 8)
    )
});

Ability EvasiveRampage40C8("Evasive Rampage", 1, 2, 0, {
    TargetSelf(
        Dodge(75.0, 67.0, 2, 4)
    ),
    TargetLowestHP(
        Attack(2.0)
    )
});

Ability FearlessFlap6CE3("Fearless Flap", 0, 2, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(100.0, 67.0, 2, 4),
        IncreaseSpeed(10.0, 2, 0)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 2),
        Attack(1.0)
    )
});

Ability FerociousCunningStrike4818("Ferocious Cunning Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.0),
        IncreaseDamage(10.0, 2, 4)
    )
});

CounterAbility FerociousFeathers2BA7("Ferocious Feathers", {
    TargetSelf(
        IncreaseDamage(5.0, 3, 3)
    ),
    TargetTeam(
        IncreaseDamage(5.0, 3, 3)
    )
});

Ability FierceCleansingImpact026E("Fierce Cleansing Impact", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability FierceCleansingRampage705C("Fierce Cleansing Rampage", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability FierceCleansingStrike0B14("Fierce Cleansing Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability FierceDeceleratingRampage9C4C("Fierce Decelerating Rampage", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR),
        ReduceSpeed(50.0, 2, 0)
    )
});

Ability FierceImpactB3BE("Fierce Impact", 0, 1, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability FierceRampage95D1("Fierce Rampage", 1, 1, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetHighestHP(
        Remove(SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR)
    )
});

CounterAbility GradualCounterAccelerationAD4F("Gradual Counter Acceleration", {
    TargetSelf(
        IncreaseSpeed(10.0, 1, 2),
        IncreaseDamage(15.0, 1, 2)
    )
});

Ability GreaterEmergencyHeal456B("Greater Emergency Heal", 0, 2, 1, {
    TargetLowestHPTeammate(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(2.0)
    )
});

Ability GroupAcceleration6211("Group Acceleration", 0, 1, 1, {
    TargetTeam(
        Cleanse(REDUCED_SPEED),
        IncreaseSpeed(50.0, 3, 3)
    ),
    TargetLowestHP(
        Attack(1.5)
    )
});

Ability GroupCautiousImpactE0F0("Group Cautious Impact", 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(10.0, 1, 0),
        Dodge(75.0, 67.0, 1, 1)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 4),
        Attack(1.5, PRECISE)
    )
});

Ability GroupCleansingImpactE480("Group Cleansing Impact", 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        Attack(1.5)
    )
});

Ability GroupCleansingLethalWound6F87("Group Cleansing Lethal Wound", 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        Attack(1.0),
        DamageOverTime(33.41, 3)
    )
});

Ability GroupCunningImpact356E("Group Cunning Impact", 0, 0, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.5)
    )
});

Ability GroupCunningStrikeB5B4("Group Cunning Strike", 0, 0, 0, {
    TargetAllOpponents(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.0)
    )
});

Ability GroupDebilitatingDistractionImpact47B8("Group Debilitating Distraction Impact", 0, 0, 0, {
    TargetAllOpponents(
        ReduceDamage(75.0, 2, 4),
        Attack(1.5)
    )
});

Ability GroupDeceleratingRampageE77E("Group Decelerating Rampage", 0, 2, 0, {
    TargetAllOpponents(
        ReduceSpeed(50.0, 2, 0),
        Attack(2.0)
    )
});

Ability GroupDecelerationStrike3B22("Group Deceleration Strike", 0, 0, 0, {
    TargetAllOpponents(
        ReduceSpeed(50.0, 2, 0),
        Attack(1.0)
    )
});

Ability GroupDefenseShatteringStrikeF98B("Group Defense Shattering Strike", 0, 0, 0, {
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability GroupDefenseShatteringWound7024("Group Defense Shattering Wound", 0, 0, 1, {
    TargetAllOpponents(
        Remove(SHIELD),
        DamageOverTime(20.0, 2)
    )
});

Ability GroupDefiniteImpact4517("Group Definite Impact", 0, 0, 0, {
    TargetAllOpponents(
        Remove(CLOAK|DODGE|SHIELD|TAUNT),
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability GroupDefiniteStrike8D8F("Group Definite Strike", 0, 0, 0, {
    TargetAllOpponents(
        Remove(CLOAK|DODGE|SHIELD|TAUNT),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability GroupDevastationC704("Group Devastation", 0, 0, 0, {
    TargetAllOpponents(
        Attack(3.0, PRECISE)
    )
});

Ability GroupDistractingImpact194D("Group Distracting Impact", 0, 0, 0, {
    TargetAllOpponents(
        Attack(1.5),
        ReduceDamage(50.0, 1, 2)
    )
});

Ability GroupDistractingImpact2458("Group Distracting Impact", 0, 0, 0, {
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 2),
        Attack(1.5)
    )
});

Ability GroupDistractionFB00("Group Distraction", 0, 2, 1, {
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 3)
    )
});

Ability GroupDistractionStrike6170("Group Distraction Strike", 0, 0, 0, {
    TargetAllOpponents(
        ReduceDamage(75.0, 2, 4),
        Attack(1.0)
    )
});

Ability GroupFerociousImpactC869("Group Ferocious Impact", 0, 0, 0, {
    TargetTeam(
        IncreaseDamage(50.0, 2, 4)
    ),
    TargetMostPositiveEffects(
        Remove(DODGE|CLOAK),
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability GroupFerociousStrikeCB1D("Group Ferocious Strike", 0, 0, 0, {
    TargetTeam(
        IncreaseDamage(25.0, 2, 4)
    ),
    TargetHighestHP(
        Attack(1.0)
    )
});

Ability GroupFerocityStrike7A2D("Group Ferocity Strike", 0, 3, 0, {
    TargetTeam(
        IncreaseDamage(50.0, 2, 2)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability GroupFierceDeceleratingStrike1DAD("Group Fierce Decelerating Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetAllOpponents(
        Remove(SHIELD|TAUNT),
        Attack(1.0, BYPASS_ARMOR),
        ReduceSpeed(50.0, 2, 0)
    )
});

Ability GroupFierceImpactDF8C("Group Fierce Impact", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetAllOpponents(
        Remove(SHIELD|TAUNT),
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability GroupFierceRampageF4AC("Group Fierce Rampage", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetAllOpponents(
        Remove(SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability GroupFierceStrike3398("Group Fierce Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetAllOpponents(
        Remove(SHIELD|TAUNT),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability GroupInvincibility36D9("Group Invincibility", 0, 0, 1, {
    TargetTeam(
        Shield(100.0, 0, 2)
    ),
    TargetSelf(
        Taunt(1)
    )
});

Ability GroupNecroticStrike3464("Group Necrotic Strike", 0, 0, 0, {
    TargetAllOpponents(
        Remove(POSITIVE_EFFECTS),
        DevouringAttack(1.0, 50.0, 2, BYPASS_ARMOR)
    )
});

CounterAbility GroupNullifyingCounterB3BA("Group Nullifying Counter", {
    TargetAllOpponents(
        Remove(POSITIVE_EFFECTS)
    )
});

Ability GroupNullifyingImpact1A3F("Group Nullifying Impact", 0, 0, 0, {
    TargetLowestHP(
        Remove(POSITIVE_EFFECTS)
    ),
    TargetLowestHP(
        Attack(1.5)
    )
});

Ability GroupPowerStrikeD95F("Group Power Strike", 0, 0, 0, {
    TargetSelf(
        IncreaseDamage(50.0, 4, 4)
    ),
    TargetAllOpponents(
        Attack(1.0)
    )
});

Ability GroupResilientImpactAD66("Group Resilient Impact", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.5),
        ImposeVulnerability(50.0, 2, 2)
    )
});

Ability GroupResilientScratchingImpactCD17("Group Resilient Scratching Impact", 0, 0, 0, {
    TargetTeam(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.5),
        ImposeVulnerability(50.0, 2, 2),
        DamageOverTime(17.0, 6)
    )
});

Ability GroupResilientScratchingStrikeB447("Group Resilient Scratching Strike", 0, 0, 0, {
    TargetTeam(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.0),
        ImposeVulnerability(50.0, 2, 2),
        DamageOverTime(17.0, 6)
    )
});

Ability GroupResilientStrike7958("Group Resilient Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.0),
        ImposeVulnerability(50.0, 2, 2)
    )
});

Ability GroupShieldStrike43E5("Group Shield Strike", 0, 0, 1, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetTeam(
        Shield(50.0, 2, 4)
    )
});

Ability GroupShieldingRampage6FD2("Group Shielding Rampage", 0, 0, 0, {
    TargetTeam(
        Shield(50.0, 2, 4)
    ),
    TargetSelf(
        Taunt(1)
    ),
    TargetAllOpponents(
        Attack(2.0)
    )
});

Ability GroupSlowingImpact7712("Group Slowing Impact", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        ReduceSpeed(75.0, 2, 0),
        Attack(1.5, PRECISE),
        ImposeVulnerability(50.0, 2, 1)
    )
});

Ability GroupSuperiorVulnerability5DD7("Group Superior Vulnerability", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        ReduceSpeed(75.0, 2, 0),
        Attack(1.0, PRECISE),
        ImposeVulnerability(50.0, 2, 1)
    )
});

Ability GroupTauntingShieldStrikeEC50("Group Taunting Shield Strike", 0, 1, 0, {
    TargetTeam(
        Shield(50.0, 2, 2)
    ),
    TargetSelf(
        Taunt(1)
    ),
    TargetAllOpponents(
        Attack(1.0)
    )
});

Ability GroupTauntingShieldsEB4C("Group Taunting Shields", 0, 1, 1, {
    TargetTeam(
        Shield(50.0, 2, 2)
    ),
    TargetSelf(
        Taunt(1)
    )
});

Ability GroupTauntingShieldsStrikeDA58("Group Taunting Shields Strike", 0, 1, 0, {
    TargetTeam(
        Shield(50.0, 2, 2)
    ),
    TargetSelf(
        Taunt(1)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability HardSwallow862D("Hard Swallow", 0, 0, 0, {
    TargetLowestHP(
        Attack(2.0)
    ),
    TargetSelf(
        Heal(1.0)
    )
});

Ability HighPounceD062("High Pounce", 0, 1, 0, {
    TargetHighestDamage(
        Attack(2.0),
        ReduceDamage(50.0, 1, 2)
    )
});

RevengeAbility InfectiousRevengeF4AA("Infectious Revenge", 0, 0, 0, {
    TargetFastest(
        ReduceSpeed(50.0, 2, 0),
        Attack(1.5),
        DamageOverTime(15.0, 2)
    )
}, 0, 0, 0, {
    TargetAllOpponents(
        ReduceSpeed(75.0, 2, 0),
        Attack(1.5),
        DamageOverTime(20.0, 2)
    )
});

Ability InstantDefense89C1("Instant Defense", 0, 0, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(1.5),
        Shield(50.0, 2, 4)
    )
});

Ability InstantDefenseCharge57F5("Instant Defense Charge", 0, 0, 1, {
    TargetHighestDamage(
        Attack(1.0),
        Stun(75.0, 1)
    ),
    TargetSelf(
        Shield(50.0, 2, 4)
    )
});

Ability InstantDefenseShatteringWound262B("Instant Defense Shattering Wound", 0, 0, 1, {
    TargetHighestDamage(
        Remove(SHIELD),
        DamageOverTime(20.0, 2)
    )
});

Ability InstantGroupAccelerationStrikeBF5A("Instant Group Acceleration Strike", 0, 0, 1, {
    TargetTeam(
        IncreaseSpeed(50.0, 3, 0)
    ),
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        Remove(INCREASED_DAMAGE|INCREASED_CRIT_CHANCE),
        ReduceDamage(50.0, 2, 4),
        Attack(1.0),
        ReduceCritChance(100.0, 2, 0)
    )
});

Ability InstantGroupCloakFD16("Instant Group Cloak", 0, 3, 1, {
    TargetTeam(
        Cloak(2.0, 75.0, 66.66659, 2, 1)
    )
});

Ability InstantGroupDistractionAB01("Instant Group Distraction", 0, 0, 1, {
    TargetAllOpponents(
        ReduceDamage(100.0, 1, 2)
    )
});

Ability InstantMutualFury23AC("Instant Mutual Fury", 0, 0, 1, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseDamage(50.0, 3, 2),
        IncreaseSpeed(10.0, 2, 0)
    ),
    TargetAllOpponents(
        IncreaseDamage(25.0, 2, 1)
    )
});

Ability InstantPrecisePounceE31D("Instant Precise Pounce", 0, 1, 1, {
    TargetLowestHP(
        Attack(2.0, PRECISE),
        ReduceDamage(50.0, 1, 2)
    )
});

Ability InstantRendingStunDC5C("Instant Rending Stun", 0, 0, 1, {
    TargetHighestHP(
        Remove(SHIELD),
        Rend(40.0),
        Stun(75.0, 1)
    )
});

Ability InstantScratchingGroupInvincibility4AAF("Instant Scratching Group Invincibility", 1, 3, 1, {
    TargetSelf(
        Shield(100.0, 0, 2)
    ),
    TargetAllOpponents(
        DamageOverTime(17.0, 6)
    )
});

Ability InstantScratchingGroupInvincibility6408("Instant Scratching Group Invincibility", 1, 3, 1, {
    TargetTeam(
        Shield(100.0, 0, 1)
    ),
    TargetAllOpponents(
        DamageOverTime(17.0, 6)
    )
});

Ability InstantShieldedDeceleratingStrike6C3D("Instant Shielded Decelerating Strike", 0, 0, 1, {
    TargetSelf(
        Shield(50.0, 1, 4)
    ),
    TargetHighestHP(
        Attack(1.0),
        ReduceSpeed(50.0, 2, 0)
    )
});

Ability IntimidatingEchelonE447("Intimidating Echelon", 0, 0, 0, {
    TargetTeam(
        IncreaseSpeed(50.0, 2, 0)
    ),
    TargetAllOpponents(
        ReduceSpeed(50.0, 2, 0)
    )
});

Ability KillerInstinctF4B6("Killer Instinct", 1, 1, 1, {
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.5, BYPASS_ARMOR)
    )
});

CounterAbility MaximalCounter_attack5683("Maximal Counter-Attack", {
    TargetAttacker(
        Attack(1.0)
    )
});

CounterAbility MediumResilientCounter_attack3EB5("Medium Resilient Counter-Attack", {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAttacker(
        Remove(CLOAK|DODGE),
        Attack(0.5),
        ImposeVulnerability(50.0, 2, 1)
    )
});

CounterAbility MinimalCriticalCounterECF3("Minimal Critical Counter", {
    TargetSelf(
        IncreaseCritChance(5.0, 3, 3)
    )
});

Ability MinimalSpeedupStrike44A5("Minimal Speedup Strike", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        IncreaseSpeed(10.0, 3, 0)
    )
});

Ability OutOfTheBlue3721("Out Of The Blue", 0, 0, 1, {
    TargetRandom(
        Attack(2.0, PRECISE),
        ReduceDamage(100.0, 1, 2)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 1, 2),
        ReduceSpeed(50.0, 1, 0)
    )
});

Ability PersistentGroupImpact99C1("Persistent Group Impact", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE),
        IncreaseDamage(50.0, 4, 4)
    ),
    TargetAllOpponents(
        Attack(1.5)
    )
});

Ability PiercingDestructionF653("Piercing Destruction", 0, 0, 1, {
    TargetMostPositiveEffects(
        Remove(POSITIVE_EFFECTS),
        Rend(100.0, BYPASS_ARMOR)
    )
});

Ability PiercingScreechB4D7("Piercing Screech", 0, 3, 1, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseSpeed(10.0, 1, 0),
        IncreaseCritChance(20.0, 2, 4)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 4),
        ReduceArmor(20.0, 2, 4)
    )
});

Ability PoisonousImpact6F8F("Poisonous Impact", 0, 0, 0, {
    TargetHighestDamage(
        Attack(1.5),
        Stun(75.0, 1),
        DamageOverTime(33.41, 3)
    )
});

Ability PounceDA88("Pounce", 0, 1, 0, {
    TargetLowestHP(
        Attack(2.0),
        ReduceDamage(50.0, 1, 2)
    )
});

CounterAbility PowerHeal0329("Power Heal", {
    TargetSelf(
        Heal(0.3)
    )
});

Ability PreciseDevastationA6DB("Precise Devastation", 0, 0, 0, {
    TargetHighestHP(
        Attack(3.0, PRECISE)
    ),
    TargetSelf(
        Taunt(1)
    )
});

Ability PreciseGroupStrikeF8C6("Precise Group Strike", 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(10.0, 1, 0),
        Dodge(75.0, 67.0, 1, 2)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 4),
        Attack(1.0, PRECISE)
    )
});

Ability PrecisePiercingRampageCB46("Precise Piercing Rampage", 0, 0, 0, {
    TargetLowestHP(
        Attack(2.0, BYPASS_ARMOR|PRECISE)
    )
});

CounterAbility PrecisePiercingStrike5679("Precise Piercing Strike", {
    TargetAttacker(
        Attack(1.0, BYPASS_ARMOR|PRECISE)
    )
});

Ability PrecisePounceA125("Precise Pounce", 0, 0, 0, {
    TargetLowestHP(
        Attack(2.0, PRECISE),
        ReduceDamage(50.0, 1, 2)
    )
});

Ability PrecisePounceF675("Precise Pounce", 0, 1, 0, {
    TargetLowestHP(
        Attack(2.0, PRECISE),
        ReduceDamage(50.0, 1, 2)
    )
});

Ability PrimalBraceF81C("Primal Brace", 0, 0, 1, {
    TargetSelf(
        Shield(50.0, 0, 2),
        IncreaseDamage(50.0, 2, 2)
    )
});

Ability PrimalDigIn6188("Primal Dig In", 0, 0, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseSpeed(10.0, 2, 0),
        Shield(50.0, 0, 4),
        Heal(1.0)
    )
});

Ability PrimalInstantChargeDA5D("Primal Instant Charge", 0, 0, 1, {
    TargetHighestDamage(
        Attack(1.0, BYPASS_ARMOR),
        Stun(75.0, 1)
    )
});

Ability PrimalProwlC087("Primal Prowl", 0, 0, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(75.0, 67.0, 2, 4),
        IncreaseCritChance(50.0, 2, 2)
    )
});

Ability PrimalTailWhip7185("Primal Tail Whip", 0, 0, 0, {
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability ProtectiveStrike7615("Protective Strike", 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseSpeed(10.0, 2, 0)
    ),
    TargetLowestHPTeammate(
        Heal(2.0)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability ProwlingShields41A1("Prowling Shields", 0, 0, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(75.0, 67.0, 2, 4),
        IncreaseCritChance(50.0, 2, 2),
        Shield(50.0, 4, 4)
    )
});

Ability QuickAndCautiousGroupStrike9DE9("Quick And Cautious Group Strike", 0, 0, 0, {
    TargetTeam(
        IncreaseSpeed(50.0, 2, 0)
    ),
    TargetSelf(
        Dodge(75.0, 67.0, 1, 4)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 1, 2),
        Attack(1.0, PRECISE)
    )
});

Ability RakingPiercingStrikeA643("Raking Piercing Strike", 0, 0, 0, {
    TargetMostPositiveEffects(
        Remove(DODGE|CLOAK),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability RampageB9EA("Rampage", 0, 1, 0, {
    TargetLowestHP(
        Attack(2.0)
    )
});

Ability RandomArmorPiercingImpactE10A("Random Armor Piercing Impact", 0, 0, 0, {
    TargetRandom(
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability RandomCautiousAcceleratedImpactDF77("Random Cautious Accelerated Impact", 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(50.0, 2, 0),
        Dodge(75.0, 67.0, 1, 4)
    ),
    TargetRandom(
        Attack(1.5, PRECISE),
        ReduceDamage(50.0, 1, 2)
    )
});

Ability RandomCautiousImpact3C97("Random Cautious Impact", 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(10.0, 1, 0),
        Dodge(75.0, 67.0, 1, 2)
    ),
    TargetRandom(
        Attack(1.5, PRECISE),
        ReduceDamage(50.0, 2, 4)
    )
});

Ability RandomCunningImpactD332("Random Cunning Impact", 0, 0, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetRandom(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.5)
    )
});

Ability RandomCunningRampageE711("Random Cunning Rampage", 0, 0, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetRandom(
        Remove(INCREASED_CRIT_CHANCE),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_DAMAGE),
        ReduceDamage(50.0, 1, 2),
        Attack(2.0)
    )
});

Ability RandomCunningStrike3E81("Random Cunning Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetRandom(
        Remove(INCREASED_CRIT_CHANCE),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_DAMAGE),
        ReduceDamage(50.0, 1, 2),
        Attack(1.0)
    )
});

Ability RandomDaringRampageFCFA("Random Daring Rampage", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY|DAMAGE_OVER_TIME)
    ),
    TargetRandom(
        Attack(2.0, BYPASS_ARMOR),
        ReduceDamage(50.0, 1, 2)
    )
});

Ability RandomDeterminedRampage025D("Random Determined Rampage", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE|DAMAGE_OVER_TIME)
    ),
    TargetRandom(
        Remove(INCREASED_SPEED|INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(2.0, PRECISE),
        ImposeVulnerability(50.0, 2, 1),
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2)
    )
});

Ability RandomFierceRampageF724("Random Fierce Rampage", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetRandom(
        Remove(SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability RandomFierceStrike9BC6("Random Fierce Strike", 0, 0, 0, {
    TargetSelf(
        IncreaseDamage(50.0, 3, 6)
    ),
    TargetRandom(
        Attack(1.0)
    )
});

Ability RandomLethalImpact6141("Random Lethal Impact", 0, 0, 0, {
    TargetRandom(
        Attack(1.5),
        DamageOverTime(33.41, 3)
    )
});

Ability RandomPiercingRampage4581("Random Piercing Rampage", 0, 0, 0, {
    TargetRandom(
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability RandomScratchingResilientRampageEC8B("Random Scratching Resilient Rampage", 1, 1, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetRandom(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(2.0),
        ImposeVulnerability(50.0, 2, 2)
    ),
    TargetAllOpponents(
        DamageOverTime(17.0, 6)
    )
});

Ability RavenousRampage476D("Ravenous Rampage", 1, 2, 1, {
    TargetHighestDamage(
        Remove(DODGE|CLOAK),
        Attack(2.5)
    )
});

Ability Regroup29BC("Regroup", 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(2.0),
        Shield(50.0, 2, 4)
    )
});

CounterAbility RendingCounter_attack24B1("Rending Counter-Attack", {
    TargetAttacker(
        Remove(SHIELD),
        Rend(25.0, BYPASS_ARMOR)
    )
});

Ability RendingStun659E("Rending Stun", 0, 0, 0, {
    TargetHighestHP(
        Remove(SHIELD),
        Rend(40.0),
        Stun(75.0, 1)
    )
});

RevengeAbility ResilientCleanseRevengeB848("Resilient Cleanse Revenge", 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetRandom(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(2.0),
        ImposeVulnerability(50.0, 2, 2)
    )
}, 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(2.0),
        ImposeVulnerability(50.0, 2, 2)
    )
});

Ability ResilientGroupImpactBD7D("Resilient Group Impact", 0, 0, 0, {
    TargetTeam(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.5),
        ImposeVulnerability(50.0, 2, 2)
    )
});

Ability ResilientGroupStrikeAEE3("Resilient Group Strike", 0, 0, 0, {
    TargetTeam(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.0),
        ImposeVulnerability(50.0, 2, 2)
    )
});

Ability ResilientHealingStrike2A27("Resilient Healing Strike", 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetHighestDamage(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.0),
        ImposeVulnerability(50.0, 2, 2)
    ),
    TargetTeam(
        Heal(1.0)
    )
});

Ability ResilientImpact7BB4("Resilient Impact", 0, 1, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.5),
        ImposeVulnerability(50.0, 2, 2)
    )
});

Ability ResilientImpactB55D("Resilient Impact", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.5),
        ImposeVulnerability(50.0, 2, 2)
    )
});

RevengeAbility ResilientImpactRevengeEA75("Resilient Impact Revenge", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.5),
        ImposeVulnerability(50.0, 2, 2)
    )
}, 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.5),
        ImposeVulnerability(50.0, 2, 2)
    )
});

Ability ResilientRampageB23D("Resilient Rampage", 1, 1, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(2.0),
        ImposeVulnerability(50.0, 2, 2)
    )
});

RevengeAbility ResilientRampageRevengeBD64("Resilient Rampage Revenge", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(2.0),
        ImposeVulnerability(50.0, 2, 2)
    )
}, 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(2.0),
        ImposeVulnerability(50.0, 2, 2)
    )
});

Ability ResilientVulnerabilityRampage2D5B("Resilient Vulnerability Rampage", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(2.0),
        ImposeVulnerability(50.0, 2, 2)
    )
});

Ability RevengeCloakB52A("Revenge Cloak", 0, 3, 1, {
    TargetSelf(
        Cloak(3.0, 75.0, 66.66659, 2, 0)
    )
});

RevengeAbility RevengeCunningImpact7960("Revenge Cunning Impact", 0, 0, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetRandom(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.5)
    ),
    TargetSelf(
        Dodge(75.0, 67.0, 2, 4),
        Taunt(2)
    )
}, 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(1.5, BYPASS_ARMOR)
    ),
    TargetSelf(
        Dodge(75.0, 67.0, 0, 4),
        Taunt(2)
    )
});

RevengeAbility RevengeCunningRampageAEC1("Revenge Cunning Rampage", 0, 0, 0, {
    TargetHighestDamage(
        Remove(INCREASED_DAMAGE|INCREASED_CRIT_CHANCE),
        ReduceDamage(50.0, 2, 4),
        Attack(2.0),
        ReduceCritChance(100.0, 2, 0)
    ),
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    )
}, 0, 0, 0, {
    TargetAllOpponents(
        Remove(INCREASED_DAMAGE|INCREASED_CRIT_CHANCE),
        ReduceDamage(50.0, 2, 3),
        Attack(2.0),
        ReduceCritChance(100.0, 2, 0)
    ),
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    )
});

RevengeAbility RevengeDebilitatingDistractionC608("Revenge Debilitating Distraction", 0, 0, 1, {
    TargetAllOpponents(
        ReduceDamage(75.0, 2, 4)
    )
}, 0, 0, 1, {
    TargetAllOpponents(
        ReduceDamage(50.0, 1, 2)
    )
});

RevengeAbility RevengeDistractingRampage0014("Revenge Distracting Rampage", 0, 0, 0, {
    TargetHighestDamage(
        Attack(2.0),
        ReduceDamage(50.0, 2, 4)
    )
}, 0, 0, 0, {
    TargetAllOpponents(
        Attack(2.0),
        ReduceDamage(50.0, 2, 4)
    )
});

RevengeAbility RevengeGroupCunningStrikeA081("Revenge Group Cunning Strike", 0, 0, 0, {
    TargetAllOpponents(
        Remove(INCREASED_DAMAGE|INCREASED_CRIT_CHANCE),
        ReduceDamage(50.0, 2, 3),
        Attack(1.0),
        ReduceCritChance(100.0, 2, 0)
    ),
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    )
}, 0, 0, 0, {
    TargetAllOpponents(
        Remove(INCREASED_DAMAGE|INCREASED_CRIT_CHANCE),
        ReduceDamage(50.0, 2, 3),
        Attack(1.5),
        ReduceCritChance(100.0, 2, 0)
    ),
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    )
});

RevengeAbility RevengeGroupCunningStrikeAD1D("Revenge Group Cunning Strike", 0, 0, 0, {
    TargetAllOpponents(
        Remove(INCREASED_DAMAGE|INCREASED_CRIT_CHANCE),
        ReduceDamage(50.0, 2, 3),
        Attack(1.5),
        ReduceCritChance(100.0, 2, 0)
    ),
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    )
}, 0, 0, 0, {
    TargetAllOpponents(
        Remove(INCREASED_DAMAGE|INCREASED_CRIT_CHANCE),
        ReduceDamage(50.0, 2, 3),
        Attack(1.0),
        ReduceCritChance(100.0, 2, 0)
    ),
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    )
});

RevengeAbility RevengeGroupThwartingImpact3F91("Revenge Group Thwarting Impact", 0, 0, 0, {
    TargetAllOpponents(
        Remove(INCREASED_DAMAGE|INCREASED_CRIT_CHANCE),
        ReduceDamage(50.0, 2, 3),
        Attack(1.5),
        ReduceCritChance(100.0, 2, 0)
    ),
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    )
}, 0, 0, 0, {
    TargetAllOpponents(
        Remove(INCREASED_DAMAGE|INCREASED_CRIT_CHANCE),
        ReduceDamage(50.0, 2, 3),
        Attack(2.0),
        ReduceCritChance(100.0, 2, 0)
    ),
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    )
});

RevengeAbility RevengeNullifyingImpact07EE("Revenge Nullifying Impact", 0, 0, 0, {
    TargetMostPositiveEffects(
        Remove(POSITIVE_EFFECTS),
        Attack(1.5)
    )
}, 0, 0, 0, {
    TargetAllOpponents(
        Remove(POSITIVE_EFFECTS),
        Attack(1.5)
    )
});

RevengeAbility RevengeNullifyingRampage44D0("Revenge Nullifying Rampage", 0, 0, 0, {
    TargetMostPositiveEffects(
        Remove(POSITIVE_EFFECTS),
        Attack(2.0)
    )
}, 0, 0, 0, {
    TargetAllOpponents(
        Remove(POSITIVE_EFFECTS),
        Attack(2.0)
    )
});

RevengeAbility RevengeRandomCautiousStrike0238("Revenge Random Cautious Strike", 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(50.0, 2, 0),
        Dodge(75.0, 67.0, 1, 4)
    ),
    TargetRandom(
        Attack(1.0, PRECISE),
        ReduceDamage(50.0, 1, 2)
    )
}, 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(50.0, 2, 0),
        Dodge(75.0, 67.0, 1, 4)
    ),
    TargetAllOpponents(
        Attack(1.5, PRECISE),
        ReduceDamage(50.0, 1, 2)
    )
});

RevengeAbility RevengeRandomDistractingImpact4DD2("Revenge Random Distracting Impact", 0, 0, 0, {
    TargetRandom(
        Attack(1.5),
        ReduceDamage(50.0, 1, 2)
    )
}, 0, 0, 0, {
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 2),
        Attack(1.5)
    )
});

ThreatenedCounterAbility RocketAlert60C3("Rocket Alert", {
    TargetSelf(
        Cleanse(REDUCED_SPEED),
        IncreaseSpeed(10.0, 2, 0),
        IncreaseCritChance(20.0, 2, 2)
    )
}, 50, ThreatComparison::Higher, {
    TargetSelf(
        Cleanse(REDUCED_SPEED),
        IncreaseSpeed(10.0, 2, 0),
        IncreaseCritChance(20.0, 2, 2)
    )
});

Ability RuthlessRampage1302("Ruthless Rampage", 0, 0, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(2.0)
    )
});

CounterAbility SharpCounterACA0("Sharp Counter", {
    TargetAttacker(
        Rend(10.0)
    )
});

Ability ShatteringDevourImpactC35B("Shattering Devour Impact", 0, 0, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetHighestHP(
        Remove(SHIELD),
        DevouringAttack(1.5, 40.0, 2, BYPASS_ARMOR)
    )
});

ThreatenedAbility ShieldedAlertImpact7250("Shielded Alert Impact", 0, 0, 0, {
    TargetHighestDamage(
        Remove(SHIELD),
        Attack(1.5, BYPASS_ARMOR),
        DamageOverTime(25.0, 2),
        Stun(75.0, 1)
    ),
    TargetSelf(
        Shield(100.0, 2, 8)
    )
}, 50, ThreatComparison::Lower, 0, 0, 0, {
    TargetHighestDamage(
        Remove(SHIELD),
        Attack(2.0, BYPASS_ARMOR),
        DamageOverTime(34.0, 2),
        Stun(75.0, 1)
    ),
    TargetSelf(
        Shield(100.0, 1, 4)
    )
});

Ability ShieldedGroupStrike424D("Shielded Group Strike", 0, 0, 0, {
    TargetSelf(
        Shield(50.0, 4, 4)
    ),
    TargetAllOpponents(
        Attack(1.0)
    )
});

Ability ShieldedGroupStrike9401("Shielded Group Strike", 0, 0, 1, {
    TargetAllOpponents(
        Attack(1.0)
    ),
    TargetTeam(
        Shield(50.0, 2, 4)
    )
});

Ability ShieldedResilientStrike3702("Shielded Resilient Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.0),
        ImposeVulnerability(50.0, 2, 2)
    ),
    TargetSelf(
        Shield(50.0, 2, 4)
    )
});

Ability ShieldingStrength2193("Shielding Strength", 0, 0, 0, {
    TargetSelf(
        Shield(50.0, 2, 8),
        IncreaseDamage(50.0, 2, 4)
    )
});

RevengeAbility SlowPiercingRevenge0252("Slow Piercing Revenge", 0, 0, 0, {
    TargetHighestHP(
        Remove(SHIELD),
        Rend(40.0, BYPASS_ARMOR),
        ReduceSpeed(50.0, 2, 0)
    )
}, 0, 0, 0, {
    TargetAllOpponents(
        Remove(SHIELD),
        Rend(40.0, BYPASS_ARMOR),
        ReduceSpeed(50.0, 2, 0)
    )
});

Ability SprayOfQuillsF93D("Spray Of Quills", 0, 0, 0, {
    TargetAllOpponents(
        Attack(1.5),
        ReduceDamage(50.0, 2, 4),
        DamageOverTime(25.0, 2)
    )
});

Ability SqueezeAndStrike84FE("Squeeze And Strike", 0, 0, 0, {
    TargetAllOpponents(
        Remove(POSITIVE_EFFECTS),
        Attack(1.0)
    )
});

Ability SteadyGroupVulnerabilityStrike28DF("Steady Group Vulnerability Strike", 0, 0, 0, {
    TargetAllOpponents(
        Attack(1.0),
        ImposeVulnerability(50.0, 1, 2)
    )
});

Ability Stun_PierceAndImpact31DA("Stun, Pierce And Impact", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.5, BYPASS_ARMOR),
        Stun(75.0, 1)
    )
});

Ability StunningRoar0488("Stunning Roar", 0, 0, 1, {
    TargetAllOpponents(
        Stun(100.0, 1),
        ReduceDamage(50.0, 2, 4),
        Remove(SHIELD),
        Attack(1.0)
    )
});

Ability StunningShields67AD("Stunning Shields", 0, 0, 0, {
    TargetSelf(
        Shield(50.0, 4, 4)
    ),
    TargetHighestDamage(
        Stun(100.0, 1)
    )
});

Ability SuperDistractionEC4A("Super Distraction", 0, 0, 1, {
    TargetHighestDamage(
        Remove(DODGE)
    ),
    TargetAllOpponents(
        Attack(1.0)
    ),
    TargetLast(
        Stun(25.0, 1),
        DamageOverTime(25.0, 2),
        ReduceDamage(50.0, 1, 2)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 1, 2)
    )
});

Ability TargetedCleansingImpact232A("Targeted Cleansing Impact", 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetHighestDamage(
        Attack(1.5)
    )
});

Ability TargetedCleansingImpact487D("Targeted Cleansing Impact", 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetHighestDamage(
        Attack(2.0)
    )
});

Ability TargetedCleansingStrike1B35("Targeted Cleansing Strike", 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetHighestDamage(
        Attack(1.0)
    )
});

Ability TargetedCunningStrikeF441("Targeted Cunning Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.0)
    ),
    TargetSelf(
        IncreaseDamage(10.0, 2, 4)
    )
});

Ability TaxingStrike0412("Taxing Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY|REDUCED_DAMAGE)
    ),
    TargetLowestHP(
        Attack(1.0, BYPASS_ARMOR|PRECISE)
    ),
    TargetFastest(
        Remove(INCREASED_SPEED)
    )
});

Ability TotalCleanseAndStrikeD7F0("Total Cleanse And Strike", 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        Attack(1.0)
    )
});

Ability VenomousBite83AA("Venomous Bite", 0, 0, 1, {
    TargetHighestDamage(
        Attack(1.5, PRECISE),
        DamageOverTime(40.0, 2)
    )
});

Ability VulnerabilityImpact2DAA("Vulnerability Impact", 0, 1, 0, {
    TargetHighestHP(
        Attack(1.5),
        ImposeVulnerability(50.0, 2, 2)
    )
});

Ability VulnerabilityRampageD44C("Vulnerability Rampage", 0, 0, 0, {
    TargetHighestHP(
        Attack(2.0),
        ImposeVulnerability(50.0, 3, 4)
    )
});

RevengeAbility WaningRevenge0554("Waning Revenge", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR),
        ReduceSpeed(50.0, 2, 0)
    )
}, 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT)
    ),
    TargetAllOpponents(
        Attack(2.0, BYPASS_ARMOR),
        ReduceSpeed(50.0, 2, 0)
    )
});


DinoKind AlacranixBoss("Alacranix Boss", APEX, 1, {
    DinoRound(15000, 1550, 116, 40.0, 20.0, 125.0, 50.0, 100.0, 50.0, 89.99999, 20.0, 100.0, 0.0, 100.0, 15.0, 0.0, 80.0, {
        &EvasiveFierceStrike29E7,
        &GroupFierceDeceleratingStrike1DAD,
        &EnfeeblingRakingImpactC1AB,
        &PiercingDestructionF653
    }, nullptr),
    DinoRound(15000, 1550, 116, 40.0, 20.0, 125.0, 50.0, 100.0, 50.0, 89.99999, 20.0, 100.0, 0.0, 100.0, 15.0, 0.0, 80.0, {
        &EvasivePiercingImpactBC9F,
        &DispersedDeceleratingImpactF2D9,
        &PiercingDestructionF653,
        &GroupNecroticStrike3464
    }, nullptr),
    DinoRound(15000, 1550, 116, 40.0, 20.0, 125.0, 50.0, 100.0, 50.0, 89.99999, 20.0, 100.0, 0.0, 100.0, 15.0, 0.0, 80.0, {
        &GroupNecroticStrike3464,
        &PiercingDestructionF653,
        &Cold_bloodedRampage0A01
    }, nullptr)
});

DinoKind AlbertospinosBoss("Albertospinos Boss", UNIQUE, 1, {
    DinoRound(14500, 1600, 125, 0.0, 10.0, 125.0, 100.0, 94.99999, 55.0, 75.0, 100.0, 100.0, 0.0, 0.0, 25.0, 0.0, 80.0, {
        &FierceCleansingImpact026E,
        &Dragon_sBite8539,
        &KillerInstinctF4B6
    }, &MinimalCriticalCounterECF3),
    DinoRound(14500, 1600, 125, 0.0, 10.0, 125.0, 100.0, 94.99999, 55.0, 75.0, 100.0, 100.0, 0.0, 0.0, 25.0, 0.0, 80.0, {
        &EvasiveGroupWoundingImpactB11F,
        &InstantDefenseShatteringWound262B,
        &Dragon_sBite8539,
        &BreakthroughE0A1
    }, &MinimalCriticalCounterECF3),
    DinoRound(14500, 1600, 125, 0.0, 10.0, 125.0, 100.0, 94.99999, 55.0, 75.0, 100.0, 100.0, 0.0, 0.0, 25.0, 0.0, 80.0, {
        &EvasiveGroupWoundingImpactB11F,
        &KillerInstinctF4B6,
        &Dragon_sBite8539,
        &BreakthroughE0A1
    }, &MinimalCriticalCounterECF3)
});

DinoKind AndrewtopsBoss("Andrewtops Boss", UNIQUE, 1, {
    DinoRound(11000, 1350, 122, 15.0, 20.0, 125.0, 0.0, 80.0, 44.99998, 85.0, 50.0, 94.99999, 0.0, 0.0, 40.0, 0.0, 80.0, {
        &DaringGroupStrike7E0C,
        &RevengeDistractingRampage0014,
        &CleansingRandomImpact2314
    }, &CounterVulnerabilityC8BA),
    DinoRound(11000, 1350, 122, 15.0, 20.0, 125.0, 0.0, 80.0, 44.99998, 85.0, 50.0, 94.99999, 0.0, 0.0, 40.0, 0.0, 80.0, {
        &GroupCleansingImpactE480,
        &SlowPiercingRevenge0252,
        &DaringGroupRevenge489D
    }, &CounterVulnerabilityC8BA),
    DinoRound(11000, 1350, 122, 15.0, 20.0, 125.0, 0.0, 80.0, 44.99998, 85.0, 50.0, 94.99999, 0.0, 0.0, 40.0, 0.0, 80.0, {
        &GroupCleansingImpactE480,
        &SlowPiercingRevenge0252,
        &RevengeDistractingRampage0014,
        &RandomDaringRampageFCFA
    }, &CounterVulnerabilityC8BA)
});

DinoKind ArctodusBoss("Arctodus Boss", RARE, 1, {
    DinoRound(12500, 1050, 108, 10.0, 5.0, 125.0, 50.0, 20.0, 50.0, 66.0, 100.0, 89.99999, 0.0, 0.0, 100.0, 50.0, 80.0, {
        &DispersedDeceleratingImpactF2D9,
        &ShieldingStrength2193,
        &TaxingStrike0412
    }, nullptr),
    DinoRound(12500, 1050, 108, 10.0, 5.0, 125.0, 50.0, 20.0, 50.0, 66.0, 100.0, 89.99999, 0.0, 0.0, 100.0, 50.0, 80.0, {
        &ShieldingStrength2193,
        &TaxingStrike0412,
        &DispersedDeceleratingImpactF2D9
    }, nullptr)
});

DinoKind BajadasaurusBoss("Bajadasaurus Boss", RARE, 1, {
    DinoRound(10500, 800, 110, 0.0, 5.0, 125.0, 50.0, 80.0, 44.99998, 80.0, 60.0, 75.0, 0.0, 0.0, 44.99998, 0.0, 80.0, {
        &BellowDDD8,
        &GroupSuperiorVulnerability5DD7,
        &TotalCleanseAndStrikeD7F0
    }, &PowerHeal0329),
    DinoRound(10500, 800, 110, 0.0, 5.0, 125.0, 50.0, 80.0, 44.99998, 80.0, 60.0, 75.0, 0.0, 0.0, 44.99998, 0.0, 80.0, {
        &BellowDDD8,
        &GroupSlowingImpact7712,
        &PreciseDevastationA6DB
    }, &PowerHeal0329)
});

DinoKind BeelzebufoBoss("Beelzebufo Boss", EPIC, 1, {
    DinoRound(16000, 1450, 115, 15.0, 5.0, 125.0, 75.0, 89.99999, 75.0, 85.0, 80.0, 100.0, 0.0, 0.0, 60.0, 50.0, 80.0, {
        &AlertAssistBA90,
        &GroupFierceDeceleratingStrike1DAD,
        &FierceCleansingImpact026E
    }, &CounterSpike7A97),
    DinoRound(16000, 1450, 115, 15.0, 5.0, 125.0, 75.0, 89.99999, 75.0, 85.0, 80.0, 100.0, 0.0, 0.0, 60.0, 50.0, 80.0, {
        &AlertAssistBA90,
        &InfectiousRevengeF4AA,
        &GroupFierceDeceleratingStrike1DAD,
        &FierceDeceleratingRampage9C4C
    }, &CounterSpike7A97),
    DinoRound(16000, 1450, 115, 15.0, 5.0, 125.0, 75.0, 89.99999, 75.0, 85.0, 80.0, 100.0, 0.0, 0.0, 60.0, 50.0, 80.0, {
        &AlertAssistBA90,
        &BrakingRevenge9580,
        &WaningRevenge0554,
        &GroupFierceDeceleratingStrike1DAD
    }, &CounterSpike7A97)
});

DinoKind BlueBoss("Blue Boss", EPIC, 1, {
    DinoRound(12400, 1350, 135, 0.0, 10.0, 125.0, 50.0, 89.99999, 75.0, 89.99999, 75.0, 100.0, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &PrecisePounceA125,
        &GroupCunningStrikeB5B4,
        &CleansingEvasiveImpact41F1
    }, nullptr),
    DinoRound(12400, 1350, 135, 0.0, 10.0, 125.0, 50.0, 89.99999, 75.0, 89.99999, 75.0, 100.0, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &CleverDodge660B,
        &OutOfTheBlue3721,
        &CleansingGroupCunningStrike6087,
        &PrecisePounceA125
    }, nullptr)
});

DinoKind BrachiosaurusBoss("Brachiosaurus Boss", EPIC, 1, {
    DinoRound(24000, 1350, 109, 0.0, 15.0, 125.0, 50.0, 85.0, 100.0, 80.0, 100.0, 100.0, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &GroupShieldStrike43E5,
        &GroupResilientStrike7958,
        &ResilientVulnerabilityRampage2D5B
    }, nullptr),
    DinoRound(24000, 1350, 109, 0.0, 15.0, 125.0, 50.0, 85.0, 100.0, 80.0, 100.0, 100.0, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &ShieldedGroupStrike9401,
        &GroupResilientImpactAD66
    }, nullptr),
    DinoRound(24000, 1350, 109, 0.0, 15.0, 125.0, 50.0, 85.0, 100.0, 80.0, 100.0, 100.0, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &GroupShieldStrike43E5,
        &BoomAA79,
        &ShieldedResilientStrike3702,
        &ResilientImpactB55D
    }, nullptr)
});

DinoKind CarnotaurusBoss("Carnotaurus Boss", RARE, 1, {
    DinoRound(8500, 655, 105, 0.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 50.0, 89.99999, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &DefensiveGroupTaunt64E9,
        &VulnerabilityImpact2DAA,
        &BoldRendingAttackB856
    }, &SharpCounterACA0),
    DinoRound(8500, 655, 105, 0.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 50.0, 89.99999, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &VulnerabilityRampageD44C,
        &DefensiveGroupTaunt64E9,
        &BoldRendingAttackB856
    }, &SharpCounterACA0)
});

DinoKind CeramagnusBoss("Ceramagnus Boss", APEX, 1, {
    DinoRound(11500, 1600, 114, 30.0, 20.0, 125.0, 50.0, 80.0, 50.0, 80.0, 100.0, 100.0, 0.0, 0.0, 0.0, 50.0, 80.0, {
        &GroupAcceleration6211,
        &RandomPiercingRampage4581,
        &PrimalInstantChargeDA5D,
        &RandomPiercingRampage4581
    }, nullptr),
    DinoRound(11500, 1600, 114, 30.0, 20.0, 125.0, 50.0, 80.0, 50.0, 80.0, 100.0, 100.0, 0.0, 0.0, 0.0, 50.0, 80.0, {
        &GroupAcceleration6211,
        &Stun_PierceAndImpact31DA,
        &CleansingRandomPiercingRampageCA35,
        &PrimalInstantChargeDA5D
    }, nullptr),
    DinoRound(11500, 1600, 114, 30.0, 20.0, 125.0, 50.0, 80.0, 50.0, 80.0, 100.0, 100.0, 0.0, 0.0, 0.0, 50.0, 80.0, {
        &Stun_PierceAndImpact31DA,
        &CleansingRandomPiercingRampageCA35,
        &PrimalInstantChargeDA5D
    }, nullptr)
});

DinoKind DreadnoughtusBoss("Dreadnoughtus Boss", RARE, 1, {
    DinoRound(11500, 850, 121, 10.0, 5.0, 125.0, 0.0, 89.99999, 50.0, 75.0, 100.0, 89.99999, 0.0, 50.0, 10.0, 50.0, 80.0, {
        &DispersedSuperiorVulnerability8D77,
        &GroupInvincibility36D9,
        &DeceleratingRampageD0C5
    }, nullptr),
    DinoRound(11500, 850, 121, 10.0, 5.0, 125.0, 0.0, 89.99999, 50.0, 75.0, 100.0, 89.99999, 0.0, 50.0, 10.0, 50.0, 80.0, {
        &GroupTauntingShieldStrikeEC50,
        &DispersedDeceleratingImpactF2D9,
        &GroupShieldingRampage6FD2
    }, nullptr)
});

DinoKind ErlikogammaBoss("Erlikogamma Boss", EPIC, 1, {
    DinoRound(15500, 1600, 131, 0.0, 10.0, 125.0, 100.0, 80.0, 100.0, 80.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 80.0, {
        &AcceleratedStrike19B5,
        &GroupDistractingImpact2458,
        &PrecisePounceF675
    }, nullptr),
    DinoRound(15500, 1600, 131, 0.0, 10.0, 125.0, 100.0, 80.0, 100.0, 80.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 80.0, {
        &AcceleratedStrike19B5,
        &GroupDebilitatingDistractionImpact47B8,
        &MinimalSpeedupStrike44A5,
        &InstantPrecisePounceE31D
    }, nullptr)
});

DinoKind FukuimimusBoss("Fukuimimus Boss", LEGENDARY, 1, {
    DinoRound(15000, 1500, 123, 0.0, 25.0, 125.0, 100.0, 89.99999, 50.0, 85.0, 75.0, 94.99999, 0.0, 0.0, 15.0, 0.0, 80.0, {
        &AlertMimic58E4,
        &ProtectiveStrike7615,
        &RandomCunningRampageE711
    }, &FerociousFeathers2BA7),
    DinoRound(15000, 1500, 123, 0.0, 25.0, 125.0, 100.0, 89.99999, 50.0, 85.0, 75.0, 94.99999, 0.0, 0.0, 15.0, 0.0, 80.0, {
        &AlertMimic58E4,
        &CunningCleanseRevengeE931,
        &ResilientCleanseRevengeB848
    }, &FerociousFeathers2BA7),
    DinoRound(15000, 1500, 123, 0.0, 25.0, 125.0, 100.0, 89.99999, 50.0, 85.0, 75.0, 94.99999, 0.0, 0.0, 15.0, 0.0, 80.0, {
        &AlertMimic58E4,
        &ProtectiveStrike7615,
        &RevengeCunningImpact7960,
        &DeterminedGroupRampageF0D0
    }, &FerociousFeathers2BA7)
});

DinoKind GiganotosaurusBoss("Giganotosaurus Boss", EPIC, 1, {
    DinoRound(25000, 2000, 108, 0.0, 40.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 100.0, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &PrimalTailWhip7185,
        &DefenseShatteringRampage5E24,
        &CleansingRandomShatteringStrikeD4F0
    }, nullptr),
    DinoRound(25000, 2000, 108, 0.0, 40.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 100.0, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &CleansingPrimalTailWhip0DFD,
        &DefenseShatteringRampage5E24,
        &DefenseShatteringImpact85C0
    }, nullptr)
});

DinoKind GlyptocerasBoss("Glyptoceras Boss", LEGENDARY, 1, {
    DinoRound(13000, 1350, 110, 15.0, 15.0, 125.0, 25.0, 80.0, 75.0, 69.99999, 50.0, 94.99999, 0.0, 0.0, 25.0, 50.0, 80.0, {
        &PrimalInstantChargeDA5D,
        &ResilientGroupImpactBD7D,
        &BlindRampage3285
    }, nullptr),
    DinoRound(13000, 1350, 110, 15.0, 15.0, 125.0, 25.0, 80.0, 75.0, 69.99999, 50.0, 94.99999, 0.0, 0.0, 25.0, 50.0, 80.0, {
        &InstantDefenseCharge57F5,
        &ResilientGroupStrikeAEE3,
        &RandomCunningRampageE711,
        &CriticalGroupImpactAC56
    }, nullptr),
    DinoRound(13000, 1350, 110, 15.0, 15.0, 125.0, 25.0, 80.0, 75.0, 69.99999, 50.0, 94.99999, 0.0, 0.0, 25.0, 50.0, 80.0, {
        &PrimalInstantChargeDA5D,
        &ResilientGroupImpactBD7D,
        &InstantDefenseCharge57F5,
        &BullyImpact2F83
    }, nullptr)
});

DinoKind GorgotrebaxBoss("Gorgotrebax Boss", APEX, 1, {
    DinoRound(13000, 1550, 113, 0.0, 20.0, 125.0, 50.0, 80.0, 75.0, 80.0, 50.0, 100.0, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &InstantGroupAccelerationStrikeBF5A,
        &RevengeRandomDistractingImpact4DD2,
        &RevengeCunningRampageAEC1
    }, nullptr),
    DinoRound(13000, 1550, 113, 0.0, 20.0, 125.0, 50.0, 80.0, 75.0, 80.0, 50.0, 100.0, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &InstantGroupDistractionAB01,
        &RevengeNullifyingImpact07EE,
        &RevengeGroupThwartingImpact3F91,
        &RandomCautiousAcceleratedImpactDF77
    }, nullptr),
    DinoRound(13000, 1550, 113, 0.0, 20.0, 125.0, 50.0, 80.0, 75.0, 80.0, 50.0, 100.0, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &InstantGroupDistractionAB01,
        &RevengeGroupCunningStrikeA081,
        &RevengeNullifyingImpact07EE
    }, nullptr),
    DinoRound(13000, 1550, 113, 0.0, 20.0, 125.0, 50.0, 80.0, 75.0, 80.0, 50.0, 100.0, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &RevengeRandomCautiousStrike0238,
        &RevengeNullifyingRampage44D0
    }, nullptr)
});

DinoKind GrypolythBoss("Grypolyth Boss", UNIQUE, 1, {
    DinoRound(14000, 1500, 106, 20.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 100.0, 0.0, 0.0, 50.0, 50.0, 80.0, {
        &PrimalTailWhip7185,
        &GreaterEmergencyHeal456B,
        &StunningShields67AD
    }, &RendingCounter_attack24B1),
    DinoRound(14000, 1500, 106, 20.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 100.0, 0.0, 0.0, 50.0, 50.0, 80.0, {
        &PrimalTailWhip7185,
        &GreaterEmergencyHeal456B,
        &Stun_PierceAndImpact31DA
    }, &RendingCounter_attack24B1),
    DinoRound(14000, 1500, 106, 20.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 100.0, 0.0, 0.0, 50.0, 50.0, 80.0, {
        &CleansingPrimalTailWhip0DFD,
        &GreaterEmergencyHeal456B,
        &Stun_PierceAndImpact31DA
    }, &RendingCounter_attack24B1)
});

DinoKind HaastMaximusBoss("Haast Maximus Boss", APEX, 1, {
    DinoRound(11000, 1500, 129, 0.0, 34.99999, 125.0, 50.0, 80.0, 50.0, 80.0, 25.0, 80.0, 0.0, 0.0, 30.0, 0.0, 80.0, {
        &FearlessFlap6CE3,
        &GroupCunningImpact356E,
        &EvasiveRampage40C8
    }, &RocketAlert60C3),
    DinoRound(11000, 1500, 129, 0.0, 34.99999, 125.0, 50.0, 80.0, 50.0, 80.0, 25.0, 80.0, 0.0, 0.0, 30.0, 0.0, 80.0, {
        &GroupCunningImpact356E,
        &PiercingScreechB4D7,
        &RavenousRampage476D,
        &FearlessFlap6CE3
    }, &RocketAlert60C3),
    DinoRound(11000, 1500, 129, 0.0, 34.99999, 125.0, 50.0, 80.0, 50.0, 80.0, 25.0, 80.0, 0.0, 0.0, 30.0, 0.0, 80.0, {
        &RavenousRampage476D,
        &PiercingScreechB4D7,
        &GroupCunningImpact356E,
        &FearlessFlap6CE3
    }, &RocketAlert60C3)
});

DinoKind HadrosLuxBoss("Hadros Lux Boss", APEX, 1, {
    DinoRound(15000, 1000, 106, 20.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 100.0, 0.0, 0.0, 50.0, 50.0, 80.0, {
        &GroupTauntingShieldsEB4C,
        &GreaterEmergencyHeal456B,
        &ResilientImpact7BB4
    }, &MediumResilientCounter_attack3EB5),
    DinoRound(15000, 1000, 106, 20.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 100.0, 0.0, 0.0, 50.0, 50.0, 80.0, {
        &GroupDistractionFB00,
        &GroupTauntingShieldsStrikeDA58,
        &ResilientRampageB23D
    }, &MediumResilientCounter_attack3EB5),
    DinoRound(15000, 1000, 106, 20.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 100.0, 0.0, 0.0, 50.0, 50.0, 80.0, {
        &GroupTauntingShieldsEB4C,
        &ResilientRampageB23D,
        &RampageB9EA
    }, &MediumResilientCounter_attack3EB5),
    DinoRound(15000, 1000, 106, 20.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 100.0, 0.0, 0.0, 50.0, 50.0, 80.0, {
        &GroupDistractionFB00,
        &ResilientRampageB23D,
        &RampageB9EA
    }, &MediumResilientCounter_attack3EB5)
});

DinoKind HydraBoaBoss("Hydra Boa Boss", APEX, 1, {
    DinoRound(14000, 1500, 118, 10.0, 25.0, 125.0, 75.0, 80.0, 80.0, 85.0, 75.0, 94.99999, 0.0, 0.0, 34.99999, 50.0, 80.0, {
        &GroupCunningImpact356E,
        &SqueezeAndStrike84FE,
        &Cold_bloodedRampage0A01
    }, &AlertCoil5A3C),
    DinoRound(14000, 1500, 118, 10.0, 25.0, 125.0, 75.0, 80.0, 80.0, 85.0, 75.0, 94.99999, 0.0, 0.0, 34.99999, 50.0, 80.0, {
        &AlertSlither23E3,
        &SqueezeAndStrike84FE,
        &HardSwallow862D
    }, &AlertCoil5A3C),
    DinoRound(14000, 1500, 118, 10.0, 25.0, 125.0, 75.0, 80.0, 80.0, 85.0, 75.0, 94.99999, 0.0, 0.0, 34.99999, 50.0, 80.0, {
        &AlertSlither23E3,
        &SqueezeAndStrike84FE,
        &VenomousBite83AA,
        &TotalCleanseAndStrikeD7F0
    }, &AlertCoil5A3C)
});

DinoKind ImperatosuchusBoss("Imperatosuchus Boss", APEX, 1, {
    DinoRound(16000, 1450, 115, 15.0, 5.0, 125.0, 75.0, 89.99999, 75.0, 85.0, 80.0, 100.0, 0.0, 0.0, 60.0, 50.0, 80.0, {
        &AlertAssistBA90,
        &GroupFierceDeceleratingStrike1DAD,
        &FierceCleansingImpact026E
    }, &CounterSpike7A97),
    DinoRound(16000, 1450, 115, 15.0, 5.0, 125.0, 75.0, 89.99999, 75.0, 85.0, 80.0, 100.0, 0.0, 0.0, 60.0, 50.0, 80.0, {
        &AlertAssistBA90,
        &InfectiousRevengeF4AA,
        &GroupFierceDeceleratingStrike1DAD,
        &FierceDeceleratingRampage9C4C
    }, &CounterSpike7A97),
    DinoRound(16000, 1450, 115, 15.0, 5.0, 125.0, 75.0, 89.99999, 75.0, 85.0, 80.0, 100.0, 0.0, 0.0, 60.0, 50.0, 80.0, {
        &AlertAssistBA90,
        &BrakingRevenge9580,
        &WaningRevenge0554,
        &GroupFierceDeceleratingStrike1DAD
    }, &CounterSpike7A97)
});

DinoKind IndominusRexBoss("Indominus Rex Boss", LEGENDARY, 1, {
    DinoRound(16000, 1550, 112, 0.0, 40.0, 125.0, 0.0, 80.0, 50.0, 89.99999, 0.0, 100.0, 0.0, 0.0, 75.0, 0.0, 80.0, {
        &GroupDefiniteStrike8D8F,
        &InstantMutualFury23AC,
        &RandomArmorPiercingImpactE10A
    }, nullptr),
    DinoRound(16000, 1550, 112, 0.0, 40.0, 125.0, 0.0, 80.0, 50.0, 89.99999, 0.0, 100.0, 0.0, 0.0, 75.0, 0.0, 80.0, {
        &InstantMutualFury23AC,
        &RandomPiercingRampage4581,
        &Cloak2513,
        &GroupFierceStrike3398
    }, nullptr),
    DinoRound(16000, 1550, 112, 0.0, 40.0, 125.0, 0.0, 80.0, 50.0, 89.99999, 0.0, 100.0, 0.0, 0.0, 75.0, 0.0, 80.0, {
        &InstantGroupCloakFD16,
        &RandomPiercingRampage4581,
        &RevengeCloakB52A,
        &GroupDefiniteImpact4517
    }, nullptr)
});

DinoKind IndoraptorBoss("Indoraptor Boss", UNIQUE, 1, {
    DinoRound(15000, 1550, 112, 0.0, 30.0, 125.0, 0.0, 80.0, 50.0, 89.99999, 0.0, 100.0, 0.0, 0.0, 75.0, 0.0, 80.0, {
        &AcceleratingEvasiveStance2AAF,
        &CautiousGroupStrike9753,
        &PrecisePiercingRampageCB46,
        &GroupDistractingImpact2458
    }, nullptr),
    DinoRound(15000, 1550, 112, 0.0, 30.0, 125.0, 0.0, 80.0, 50.0, 89.99999, 0.0, 100.0, 0.0, 0.0, 75.0, 0.0, 80.0, {
        &QuickAndCautiousGroupStrike9DE9,
        &PrecisePiercingRampageCB46,
        &GroupDistractingImpact2458
    }, nullptr),
    DinoRound(15000, 1550, 112, 0.0, 30.0, 125.0, 0.0, 80.0, 50.0, 89.99999, 0.0, 100.0, 0.0, 0.0, 75.0, 0.0, 80.0, {
        &QuickAndCautiousGroupStrike9DE9,
        &PrecisePiercingRampageCB46,
        &GroupDistractingImpact2458
    }, nullptr)
});

DinoKind MammotheriumBoss("Mammotherium Boss", LEGENDARY, 1, {
    DinoRound(22500, 1200, 115, 30.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 70.01, 0.0, 0.0, 0.0, 50.0, 80.0, {
        &GroupPowerStrikeD95F,
        &BellowDDD8,
        &DefinitePowerRampage3EE2,
        &PrimalDigIn6188
    }, nullptr),
    DinoRound(22500, 1200, 115, 30.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 70.01, 0.0, 0.0, 0.0, 50.0, 80.0, {
        &GroupPowerStrikeD95F,
        &BellowDDD8,
        &ResilientImpactB55D,
        &PrimalDigIn6188
    }, nullptr)
});

DinoKind MegalonyxBoss("Megalonyx Boss", RARE, 1, {
    DinoRound(9250, 950, 101, 0.0, 10.0, 125.0, 0.0, 89.99999, 50.0, 85.0, 100.0, 89.99999, 0.0, 50.0, 0.0, 0.0, 80.0, {
        &BodingDistraction71C6,
        &GroupCunningStrikeB5B4,
        &EvasiveDrainDA22,
        &GroupCautiousImpactE0F0
    }, &MaximalCounter_attack5683),
    DinoRound(9250, 950, 101, 0.0, 10.0, 125.0, 0.0, 89.99999, 50.0, 85.0, 100.0, 89.99999, 0.0, 50.0, 0.0, 0.0, 80.0, {
        &EvasiveDrainDA22,
        &GroupCunningImpact356E,
        &BodingDistraction71C6,
        &DelayedCautiousRampageAB44
    }, &MaximalCounter_attack5683)
});

DinoKind MegalosuchusBoss("Megalosuchus Boss", LEGENDARY, 1, {
    DinoRound(13333, 1500, 109, 0.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 100.0, 89.99999, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &GroupFerocityStrike7A2D,
        &GreaterEmergencyHeal456B,
        &FierceImpactB3BE
    }, &PrecisePiercingStrike5679),
    DinoRound(13333, 1500, 109, 0.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 100.0, 89.99999, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &GroupFerocityStrike7A2D,
        &FierceImpactB3BE
    }, &PrecisePiercingStrike5679),
    DinoRound(13333, 1500, 109, 0.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 100.0, 89.99999, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &GroupFerocityStrike7A2D,
        &GreaterEmergencyHeal456B,
        &PrecisePiercingRampageCB46
    }, &PrecisePiercingStrike5679)
});

DinoKind MegalotopsBoss("Megalotops Boss", EPIC, 1, {
    DinoRound(12000, 1250, 105, 25.0, 15.0, 125.0, 0.0, 80.0, 50.0, 80.0, 55.0, 94.99999, 0.0, 0.0, 50.0, 50.0, 80.0, {
        &PrimalInstantChargeDA5D,
        &DeterminedGroupStrikeCDD7,
        &EvasiveDrainDA22,
        &DistractingRampage5363
    }, &ArmorPiercingCounterAEB5),
    DinoRound(12000, 1250, 105, 25.0, 15.0, 125.0, 0.0, 80.0, 50.0, 80.0, 55.0, 94.99999, 0.0, 0.0, 50.0, 50.0, 80.0, {
        &BodingDistraction71C6,
        &GroupDistractingImpact194D,
        &DeterminedGroupImpact7887,
        &RandomCautiousImpact3C97
    }, &ArmorPiercingCounterAEB5),
    DinoRound(12000, 1250, 105, 25.0, 15.0, 125.0, 0.0, 80.0, 50.0, 80.0, 55.0, 94.99999, 0.0, 0.0, 50.0, 50.0, 80.0, {
        &BodingDistraction71C6,
        &RandomDeterminedRampage025D,
        &PreciseGroupStrikeF8C6,
        &DistractingRampage5363
    }, &ArmorPiercingCounterAEB5)
});

DinoKind MeiolaniaBoss("Meiolania Boss", RARE, 1, {
    DinoRound(9500, 825, 105, 50.0, 5.0, 125.0, 0.0, 69.99999, 50.0, 69.99999, 80.0, 100.0, 0.0, 0.0, 50.0, 85.0, 80.0, {
        &SteadyGroupVulnerabilityStrike28DF,
        &ResilientImpact7BB4,
        &Devastation3723
    }, nullptr),
    DinoRound(9500, 825, 105, 50.0, 5.0, 125.0, 0.0, 69.99999, 50.0, 69.99999, 80.0, 100.0, 0.0, 0.0, 50.0, 85.0, 80.0, {
        &VulnerabilityImpact2DAA,
        &GroupSuperiorVulnerability5DD7,
        &GroupDevastationC704
    }, nullptr)
});

DinoKind MiniMortem("Mini Mortem", APEX, 1, {
    DinoRound(10000, 2000, 108, 10.0, 40.0, 150.0, 0.0, 100.0, 50.0, 80.0, 0.0, 94.99999, 0.0, 0.0, 100.0, 0.0, 80.0, {
        &StunningRoar0488,
        &FierceRampage95D1,
        &GroupNullifyingImpact1A3F,
        &CleansingRandomShatteringStrikeD4F0
    }, nullptr)
});

DinoKind MortemRexBoss("Mortem Rex Boss", APEX, 1, {
    DinoRound(25000, 2000, 108, 0.0, 40.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 100.0, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &PrimalTailWhip7185,
        &DefenseShatteringRampage5E24,
        &CleansingRandomShatteringStrikeD4F0
    }, nullptr),
    DinoRound(25000, 2000, 108, 0.0, 40.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 100.0, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &CleansingPrimalTailWhip0DFD,
        &DefenseShatteringRampage5E24,
        &DefenseShatteringImpact85C0
    }, nullptr)
});

DinoKind ParasauthopsBoss("Parasauthops Boss", UNIQUE, 1, {
    DinoRound(14500, 1500, 112, 0.0, 20.0, 125.0, 0.0, 69.99999, 75.0, 80.0, 50.0, 100.0, 0.0, 0.0, 34.99999, 0.0, 80.0, {
        &RandomCunningImpactD332,
        &ResilientImpactRevengeEA75,
        &EmergencyRegroup5FAB,
        &FierceCleansingStrike0B14
    }, &PowerHeal0329),
    DinoRound(14500, 1500, 112, 0.0, 20.0, 125.0, 0.0, 69.99999, 75.0, 80.0, 50.0, 100.0, 0.0, 0.0, 34.99999, 0.0, 80.0, {
        &GroupFierceImpactDF8C,
        &EmergencyRegroup5FAB,
        &RevengeGroupCunningStrikeAD1D,
        &ResilientVulnerabilityRampage2D5B
    }, &PowerHeal0329),
    DinoRound(14500, 1500, 112, 0.0, 20.0, 125.0, 0.0, 69.99999, 75.0, 80.0, 50.0, 100.0, 0.0, 0.0, 34.99999, 0.0, 80.0, {
        &Regroup29BC,
        &ResilientRampageRevengeBD64,
        &GroupFierceImpactDF8C,
        &RandomCunningStrike3E81
    }, &PowerHeal0329)
});

DinoKind PhorurexBoss("Phorurex Boss", UNIQUE, 1, {
    DinoRound(11500, 1750, 124, 5.0, 15.0, 125.0, 75.0, 80.0, 50.0, 89.99999, 25.0, 100.0, 0.0, 0.0, 25.0, 50.0, 80.0, {
        &RendingStun659E,
        &CriticalShake0032,
        &DaringGroupStrike7E0C,
        &RuthlessRampage1302
    }, nullptr),
    DinoRound(11500, 1750, 124, 5.0, 15.0, 125.0, 75.0, 80.0, 50.0, 89.99999, 25.0, 100.0, 0.0, 0.0, 25.0, 50.0, 80.0, {
        &DaringGroupStrike7E0C,
        &ShieldedAlertImpact7250,
        &CriticalShake0032
    }, nullptr),
    DinoRound(11500, 1750, 124, 5.0, 15.0, 125.0, 75.0, 80.0, 50.0, 89.99999, 25.0, 100.0, 0.0, 0.0, 25.0, 50.0, 80.0, {
        &InstantRendingStunDC5C,
        &DaringGroupStrike7E0C,
        &ShieldedAlertImpact7250,
        &CriticalShake0032
    }, nullptr)
});

DinoKind PostimetrodonBoss("Postimetrodon Boss", EPIC, 1, {
    DinoRound(15000, 1250, 125, 5.0, 5.0, 125.0, 0.0, 80.0, 34.99999, 85.0, 100.0, 100.0, 0.0, 0.0, 64.99999, 50.0, 80.0, {
        &RandomFierceStrike9BC6,
        &FierceCleansingRampage705C,
        &FierceCleansingImpact026E,
        &InstantDefense89C1
    }, nullptr),
    DinoRound(15000, 1250, 125, 5.0, 5.0, 125.0, 0.0, 80.0, 34.99999, 85.0, 100.0, 100.0, 0.0, 0.0, 64.99999, 50.0, 80.0, {
        &PersistentGroupImpact99C1,
        &InstantDefense89C1,
        &RandomFierceRampageF724,
        &GroupFierceImpactDF8C
    }, nullptr)
});

DinoKind PteranokyrieBoss("Pteranokyrie Boss", APEX, 1, {
    DinoRound(18333, 1400, 125, 0.0, 10.0, 125.0, 50.0, 89.99999, 50.0, 85.0, 100.0, 89.99999, 0.0, 0.0, 20.0, 0.0, 80.0, {
        &IntimidatingEchelonE447,
        &ShatteringDevourImpactC35B,
        &FierceCleansingStrike0B14,
        &AvianGrazeC01A
    }, nullptr),
    DinoRound(18333, 1400, 125, 0.0, 10.0, 125.0, 50.0, 89.99999, 50.0, 85.0, 100.0, 89.99999, 0.0, 0.0, 20.0, 0.0, 80.0, {
        &IntimidatingEchelonE447,
        &ResilientHealingStrike2A27,
        &ResilientImpactRevengeEA75,
        &AvianGust163C
    }, nullptr),
    DinoRound(18333, 1400, 125, 0.0, 10.0, 125.0, 50.0, 89.99999, 50.0, 85.0, 100.0, 89.99999, 0.0, 0.0, 20.0, 0.0, 80.0, {
        &IntimidatingEchelonE447,
        &DispersedCunningStrike7D4C,
        &RevengeDebilitatingDistractionC608,
        &AvianGale57A6
    }, nullptr)
});

DinoKind PyrritatorBoss("Pyrritator Boss", LEGENDARY, 1, {
    DinoRound(17500, 1300, 129, 0.0, 20.0, 125.0, 0.0, 80.0, 67.0, 67.0, 0.0, 69.99999, 0.0, 0.0, 0.0, 0.0, 80.0, {
        &HighPounceD062,
        &GroupCunningStrikeB5B4,
        &DistractingImpactD4D6
    }, nullptr),
    DinoRound(17500, 1300, 129, 0.0, 20.0, 125.0, 0.0, 80.0, 67.0, 67.0, 0.0, 69.99999, 0.0, 0.0, 0.0, 0.0, 80.0, {
        &PounceDA88,
        &GroupDefenseShatteringStrikeF98B,
        &DistractingImpactD4D6,
        &GroupCunningStrikeB5B4
    }, nullptr)
});

DinoKind RefrenantemBoss("Refrenantem Boss", APEX, 1, {
    DinoRound(15000, 1400, 125, 0.0, 10.0, 125.0, 75.0, 85.0, 89.99999, 80.0, 50.0, 89.99999, 0.0, 0.0, 34.99999, 0.0, 80.0, {
        &GroupDistractionStrike6170,
        &CunningImpactEE79,
        &SuperDistractionEC4A
    }, &AlertCounterDistraction2BF3),
    DinoRound(15000, 1400, 125, 0.0, 10.0, 125.0, 75.0, 85.0, 89.99999, 80.0, 50.0, 89.99999, 0.0, 0.0, 34.99999, 0.0, 80.0, {
        &CunningRampage8AEB,
        &AlertNullification3D09,
        &SuperDistractionEC4A
    }, &AlertCounterDistraction2BF3),
    DinoRound(15000, 1400, 125, 0.0, 10.0, 125.0, 75.0, 85.0, 89.99999, 80.0, 50.0, 89.99999, 0.0, 0.0, 34.99999, 0.0, 80.0, {
        &AlertNullification7C0F,
        &SuperDistractionEC4A,
        &GroupCunningImpact356E
    }, &AlertCounterDistraction2BF3)
});

DinoKind RinchicyonBoss("Rinchicyon Boss", LEGENDARY, 1, {
    DinoRound(14500, 1450, 128, 0.0, 20.0, 125.0, 75.0, 80.0, 50.0, 80.0, 80.0, 94.99999, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &DeviousGroupStrike5A92,
        &DaringEvasionCDAC,
        &BlindRampage3285
    }, nullptr),
    DinoRound(14500, 1450, 128, 0.0, 20.0, 125.0, 75.0, 80.0, 50.0, 80.0, 80.0, 94.99999, 0.0, 0.0, 50.0, 0.0, 80.0, {
        &AlertAdvance2251,
        &DaringEvasionCDAC,
        &GroupFierceRampageF4AC,
        &CleansingRandomImpactBCA7
    }, nullptr)
});

DinoKind ScorpiosRexBoss("Scorpios Rex Boss", LEGENDARY, 1, {
    DinoRound(12500, 1650, 112, 0.0, 20.0, 125.0, 50.0, 80.0, 44.99998, 80.0, 60.0, 75.0, 0.0, 0.0, 44.99998, 0.0, 80.0, {
        &DeadlyDistraction5F14,
        &EvasiveDrainDA22,
        &PrecisePounceA125,
        &GroupCunningImpact356E
    }, nullptr),
    DinoRound(12500, 1650, 112, 0.0, 20.0, 125.0, 50.0, 80.0, 44.99998, 80.0, 60.0, 75.0, 0.0, 0.0, 44.99998, 0.0, 80.0, {
        &BodingDistraction71C6,
        &SprayOfQuillsF93D,
        &GroupCunningStrikeB5B4,
        &PrecisePounceA125
    }, nullptr),
    DinoRound(12500, 1650, 112, 0.0, 20.0, 125.0, 50.0, 80.0, 44.99998, 80.0, 60.0, 75.0, 0.0, 0.0, 44.99998, 0.0, 80.0, {
        &PoisonousImpact6F8F,
        &BodingDistraction71C6,
        &RuthlessRampage1302,
        &CautiousGroupStrike9753
    }, nullptr)
});

DinoKind SinoceratopsBoss("Sinoceratops Boss", EPIC, 1, {
    DinoRound(17500, 1200, 111, 25.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 89.99999, 0.0, 0.0, 0.0, 50.0, 80.0, {
        &GroupDecelerationStrike3B22,
        &PrimalInstantChargeDA5D,
        &PrimalDigIn6188,
        &RandomPiercingRampage4581
    }, nullptr),
    DinoRound(17500, 1200, 111, 25.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 89.99999, 0.0, 0.0, 0.0, 50.0, 80.0, {
        &Stun_PierceAndImpact31DA,
        &GroupDecelerationStrike3B22,
        &CleansingRandomPiercingRampageCA35
    }, nullptr)
});

DinoKind SmilonemysBoss("Smilonemys Boss", UNIQUE, 1, {
    DinoRound(20000, 1500, 127, 50.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 50.0, 100.0, 0.0, 0.0, 50.0, 80.0, 80.0, {
        &ShieldedGroupStrike424D,
        &PrimalProwlC087,
        &PrecisePounceA125
    }, nullptr),
    DinoRound(20000, 1500, 127, 50.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 50.0, 100.0, 0.0, 0.0, 50.0, 80.0, 80.0, {
        &ShieldedGroupStrike424D,
        &ProwlingShields41A1,
        &CautiousPrecisePounceEA3D
    }, nullptr)
});

DinoKind SpinosaurusAegyptiacusBoss("Spinosaurus Aegyptiacus Boss", OMEGA, 1, {
    DinoRound(20000, 2350, 126, 5.0, 40.0, 150.0, 0.0, 80.0, 75.0, 66.0, 100.0, 100.0, 0.0, 100.0, 75.0, 0.0, 89.99999, {
        &GroupFierceRampageF4AC,
        &KillerInstinctF4B6,
        &BullyImpact2F83,
        &PiercingDestructionF653
    }, nullptr),
    DinoRound(20000, 2350, 126, 5.0, 40.0, 150.0, 0.0, 80.0, 75.0, 66.0, 100.0, 100.0, 0.0, 100.0, 75.0, 0.0, 89.99999, {
        &GroupDefenseShatteringWound7024,
        &ProtectiveStrike7615,
        &InstantRendingStunDC5C,
        &RandomFierceRampageF724
    }, &GroupNullifyingCounterB3BA),
    DinoRound(20000, 2350, 126, 5.0, 40.0, 150.0, 0.0, 80.0, 75.0, 66.0, 100.0, 100.0, 0.0, 100.0, 75.0, 0.0, 89.99999, {
        &PiercingDestructionF653,
        &GroupFierceRampageF4AC,
        &BullyImpact2F83,
        &BreakthroughE0A1
    }, &PowerHeal0329),
    DinoRound(20000, 2350, 126, 5.0, 40.0, 150.0, 0.0, 80.0, 75.0, 66.0, 100.0, 100.0, 0.0, 100.0, 75.0, 0.0, 89.99999, {
        &GroupFierceRampageF4AC,
        &ProtectiveStrike7615,
        &KillerInstinctF4B6,
        &GroupFierceRampageF4AC
    }, &GradualCounterAccelerationAD4F)
});

DinoKind StygidaryxBoss("Stygidaryx Boss", UNIQUE, 1, {
    DinoRound(12000, 1300, 128, 0.0, 5.0, 125.0, 0.0, 100.0, 50.0, 80.0, 100.0, 80.0, 0.0, 0.0, 0.0, 0.0, 80.0, {
        &GroupResilientScratchingStrikeB447,
        &InstantScratchingGroupInvincibility4AAF,
        &RandomLethalImpact6141
    }, &CounterScratch7FAF),
    DinoRound(12000, 1300, 128, 0.0, 5.0, 125.0, 0.0, 100.0, 50.0, 80.0, 100.0, 80.0, 0.0, 0.0, 0.0, 0.0, 80.0, {
        &InstantScratchingGroupInvincibility6408,
        &GroupCleansingLethalWound6F87,
        &RandomScratchingResilientRampageEC8B,
        &GroupResilientScratchingImpactCD17
    }, &CounterScratch7FAF),
    DinoRound(12000, 1300, 128, 0.0, 5.0, 125.0, 0.0, 100.0, 50.0, 80.0, 100.0, 80.0, 0.0, 0.0, 0.0, 0.0, 80.0, {
        &InstantScratchingGroupInvincibility6408,
        &GroupCleansingLethalWound6F87
    }, &CounterScratch7FAF)
});

DinoKind TherizinosaurusBoss("Therizinosaurus Boss", RARE, 1, {
    DinoRound(17000, 800, 130, 0.0, 5.0, 125.0, 50.0, 80.0, 50.0, 80.0, 0.0, 89.99999, 0.0, 0.0, 15.0, 0.0, 80.0, {
        &TargetedCunningStrikeF441,
        &AcceleratingGroupStrike581B,
        &ClawingRampageD228
    }, &GradualCounterAccelerationAD4F),
    DinoRound(17000, 800, 130, 0.0, 5.0, 125.0, 50.0, 80.0, 50.0, 80.0, 0.0, 89.99999, 0.0, 0.0, 15.0, 0.0, 80.0, {
        &FerociousCunningStrike4818,
        &AcceleratingGroupImpactAA7C,
        &ClawingRampageD228
    }, &GradualCounterAccelerationAD4F)
});

DinoKind TroodoboaBoss("Troodoboa Boss", UNIQUE, 1, {
    DinoRound(16666, 1300, 120, 0.0, 10.0, 125.0, 0.0, 89.99999, 60.0, 80.0, 75.0, 100.0, 0.0, 100.0, 15.0, 0.0, 80.0, {
        &InstantShieldedDeceleratingStrike6C3D,
        &TargetedCleansingStrike1B35,
        &GroupFerociousStrikeCB1D
    }, nullptr),
    DinoRound(16666, 1300, 120, 0.0, 10.0, 125.0, 0.0, 89.99999, 60.0, 80.0, 75.0, 100.0, 0.0, 100.0, 15.0, 0.0, 80.0, {
        &InstantShieldedDeceleratingStrike6C3D,
        &CoilingRampage31C8,
        &TargetedCleansingImpact232A,
        &RakingPiercingStrikeA643
    }, nullptr),
    DinoRound(16666, 1300, 120, 0.0, 10.0, 125.0, 0.0, 89.99999, 60.0, 80.0, 75.0, 100.0, 0.0, 100.0, 15.0, 0.0, 80.0, {
        &InstantShieldedDeceleratingStrike6C3D,
        &CoilingRampage31C8,
        &TargetedCleansingImpact487D,
        &GroupFerociousImpactC869
    }, nullptr)
});

DinoKind TyrannosaurusRexBoss("Tyrannosaurus Rex Boss", EPIC, 1, {
    DinoRound(20000, 1900, 102, 0.0, 30.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 89.99999, 0.0, 0.0, 0.0, 0.0, 80.0, {
        &PrimalTailWhip7185,
        &DefenseShatteringImpact85C0
    }, nullptr),
    DinoRound(20000, 1900, 102, 0.0, 30.0, 125.0, 0.0, 80.0, 50.0, 80.0, 0.0, 89.99999, 0.0, 0.0, 0.0, 0.0, 80.0, {
        &PrimalBraceF81C,
        &PrimalTailWhip7185,
        &DefenseShatteringImpact85C0
    }, nullptr)
});

DinoKind WoollyMammothBoss("Woolly Mammoth Boss", EPIC, 1, {
    DinoRound(15000, 1200, 115, 10.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 100.0, 69.99999, 0.0, 0.0, 50.0, 50.0, 80.0, {
        &GroupPowerStrikeD95F,
        &GroupDeceleratingRampageE77E,
        &BellowDDD8
    }, nullptr),
    DinoRound(15000, 1200, 115, 10.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 100.0, 69.99999, 0.0, 0.0, 50.0, 50.0, 80.0, {
        &GroupDeceleratingRampageE77E,
        &BellowDDD8,
        &GroupPowerStrikeD95F
    }, nullptr),
    DinoRound(15000, 1200, 115, 10.0, 5.0, 125.0, 0.0, 80.0, 50.0, 80.0, 100.0, 69.99999, 0.0, 0.0, 50.0, 50.0, 80.0, {
        &GroupPowerStrikeD95F,
        &GroupDeceleratingRampageE77E
    }, nullptr)
});


} // namespace boss

Ability AcceleratingFerociousStrike1E8B("Accelerating Ferocious Strike", 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(10.0, 2, 0),
        IncreaseDamage(20.0, 2, 4)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability AcceleratingShieldedDistraction80B6("Accelerating Shielded Distraction", 0, 2, 1, {
    TargetHighestHP(
        ReduceDamage(50.0, 2, 4)
    ),
    TargetSelf(
        Shield(50.0, 2, 4),
        IncreaseSpeed(50.0, 2, 4)
    )
});

Ability AcceleratingTeamHealEAF5("Accelerating Team Heal", 0, 2, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(1.0),
        IncreaseSpeed(25.0, 2, 2)
    )
});

Ability AcuteStun1F1E("Acute Stun", 0, 2, 0, {
    TargetHighestDamage(
        Stun(100.0, 1)
    )
});

Ability AdrenalinePulse2BA5("Adrenaline Pulse", 0, 3, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(1.0)
    )
});

Ability AerialDominance7897("Aerial Dominance", 1, 2, 1, {
    TargetHighestHP(
        Attack(2.0)
    ),
    TargetSelf(
        Dodge(100.0, 67.0, 1, 2)
    )
});

ThreatenedAbility AfflictingAlertStun7106("Afflicting Alert Stun", 0, 1, 1, {
    TargetSelf(
        Shield(100.0, 1, 2)
    ),
    TargetHighestHP(
        Remove(POSITIVE_EFFECTS),
        Attack(1.0)
    )
}, 50, ThreatComparison::Lower, 0, 1, 1, {
    TargetHighestHP(
        Affliction(25.0, 2, 4),
        Stun(100.0, 1),
        Attack(1.0)
    )
});

Ability AfflictingHorn91AA("Afflicting Horn", 0, 2, 1, {
    TargetMostPositiveEffects(
        Affliction(50.0, 2, 4)
    ),
    TargetMostPositiveEffects(
        Stun(75.0, 1)
    ),
    TargetHighestHP(
        DamageOverTime(34.0, 2)
    ),
    TargetMostPositiveEffects(
        Attack(1.5)
    )
});

Ability AfflictingLockdownImpact2EFB("Afflicting Lockdown Impact", 0, 3, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.5, BYPASS_ARMOR)
    ),
    TargetEveryone(
        Affliction(100.0, 0, 1),
        UnableToSwap(2)
    )
});

Ability AfflictingStrike3614("Afflicting Strike", 0, 1, 0, {
    TargetMostPositiveEffects(
        Affliction(15.0, 2, 4)
    ),
    TargetMostPositiveEffects(
        Attack(1.0)
    )
});

Ability AfflictingTrap30DA("Afflicting Trap", 0, 2, 1, {
    TargetHighestDamage(
        Affliction(100.0, 1, 1)
    ),
    TargetHighestDamage(
        ReduceDamage(100.0, 2, 2),
        ReduceSpeed(100.0, 2, 2),
        UnableToSwap(2)
    )
});

RevengeAbility AfflictingVengefulSwoop46D1("Afflicting Vengeful Swoop", 1, 2, 0, {
    TargetHighestDamage(
        Affliction(50.0, 2, 4)
    ),
    TargetHighestHP(
        DamageOverTime(34.0, 2)
    ),
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Swap()
    )
}, 0, 2, 1, {
    TargetHighestHP(
        Remove(SHIELD),
        Affliction(33.0, 2, 4),
        Attack(1.0)
    ),
    TargetHighestHP(
        DamageOverTime(25.0, 2)
    )
});

ThreatenedAbility AlertArcticBlast801B("Alert Arctic Blast", 0, 1, 0, {
    TargetHighestDamage(
        Attack(1.5),
        ReduceSpeed(50.0, 1, 0),
        ImposeVulnerability(50.0, 2, 1)
    )
}, 50, ThreatComparison::Lower, 0, 1, 0, {
    TargetAllOpponents(
        Attack(1.5),
        Stun(66.71, 1),
        ReduceSpeed(50.0, 1, 0),
        ImposeVulnerability(50.0, 2, 1),
        ReduceArmor(30.0, 2, 4)
    )
});

ThreatenedAbility AlertBuffAndStrike79FE("Alert Buff And Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_SPEED|REDUCED_CRIT_CHANCE),
        IncreaseCritChance(25.0, 3, 2)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
}, 33, ThreatComparison::Lower, 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_SPEED|REDUCED_CRIT_CHANCE),
        IncreaseCritChance(50.0, 3, 2)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

ThreatenedCounterAbility AlertCleanseFBF7("Alert Cleanse", {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE|REDUCED_SPEED)
    )
}, 50, ThreatComparison::Lower, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAttacker(
        Attack(1.0)
    )
});

ThreatenedCounterAbility AlertCounterDistractionBE9B("Alert Counter Distraction", {
    TargetAttacker(
        ReduceDamage(10.0, 2, 4)
    )
}, 50, ThreatComparison::Lower, {
    TargetAttacker(
        ReduceDamage(15.0, 2, 4)
    )
});

ThreatenedCounterAbility AlertCounterEF7D("Alert Counter", {
    TargetAttacker(
        Attack(0.5, PRECISE)
    )
}, 50, ThreatComparison::Higher, {
    TargetAttacker(
        Remove(SHIELD),
        Attack(0.5)
    )
});

ThreatenedAbility AlertDeceleratingImpact5396("Alert Decelerating Impact", 0, 1, 0, {
    TargetHighestDamage(
        Attack(1.5),
        ReduceSpeed(50.0, 1, 0),
        ImposeVulnerability(50.0, 2, 1)
    )
}, 50, ThreatComparison::Lower, 0, 1, 0, {
    TargetHighestDamage(
        Attack(1.5),
        Stun(75.0, 1),
        ImposeVulnerability(50.0, 2, 1)
    )
});

ThreatenedCounterAbility AlertDeception0644("Alert Deception", {
    TargetSelf(
        IncreaseDamage(15.0, 2, 2)
    )
}, 50, ThreatComparison::Lower, {
    TargetSelf(
        IncreaseDamage(25.0, 2, 4)
    )
});

ThreatenedAbility AlertDefenseF5F7("Alert Defense", 0, 2, 1, {
    TargetHighestHP(
        DevouringAttack(2.0, 80.0, 4, BYPASS_ARMOR)
    )
}, 50, ThreatComparison::Higher, 0, 2, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Shield(50.0, 2, 4),
        IncreaseArmor(25.0, 2, 4)
    ),
    TargetHighestHP(
        ImposeVulnerability(50.0, 4, 2)
    )
});

ThreatenedAbility AlertDistractingImpact85F8("Alert Distracting Impact", 0, 2, 0, {
    TargetHighestDamage(
        Attack(1.5, ALWAYS_CRITS),
        ReduceDamage(50.0, 1, 2)
    )
}, 33, ThreatComparison::Lower, 0, 2, 0, {
    TargetHighestDamage(
        Attack(1.5, ALWAYS_CRITS),
        ReduceDamage(100.0, 1, 2)
    )
});

ThreatenedAbility AlertFatalStrikeE0D9("Alert Fatal Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR)
    )
}, 50, ThreatComparison::Lower, 0, 0, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetLowestHP(
        Remove(SHIELD),
        Rend(60.0, BYPASS_ARMOR)
    )
});

ThreatenedAbility AlertFierceRampage151A("Alert Fierce Rampage", 0, 2, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetHighestHP(
        Remove(SHIELD)
    ),
    TargetHighestHP(
        Remove(TAUNT)
    ),
    TargetHighestHP(
        Attack(2.0, BYPASS_ARMOR)
    )
}, 33, ThreatComparison::Lower, 0, 2, 0, {
    TargetSelf(
        Heal(1.0)
    ),
    TargetHighestHP(
        Remove(SHIELD)
    ),
    TargetHighestHP(
        Attack(1.6599998, BYPASS_ARMOR)
    ),
    TargetSelf(
        Swap()
    )
});

ThreatenedAbility AlertFierceRampage5308("Alert Fierce Rampage", 0, 2, 0, {
    TargetSelf(
        Heal(1.0)
    ),
    TargetHighestHP(
        Remove(SHIELD)
    ),
    TargetHighestHP(
        Attack(1.6599998, BYPASS_ARMOR)
    ),
    TargetSelf(
        Swap()
    )
}, 50, ThreatComparison::Higher, 0, 2, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetHighestHP(
        Remove(SHIELD)
    ),
    TargetHighestHP(
        Remove(TAUNT)
    ),
    TargetHighestHP(
        Attack(2.0, BYPASS_ARMOR)
    )
});

ThreatenedAbility AlertFierceStrikeF86F("Alert Fierce Strike", 0, 0, 0, {
    TargetLowestHP(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR),
        Remove(TAUNT)
    ),
    TargetSelf(
        Cleanse(VULNERABILITY)
    )
}, 50, ThreatComparison::Higher, 0, 0, 0, {
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR),
        Remove(TAUNT)
    ),
    TargetSelf(
        Cleanse(VULNERABILITY)
    )
});

ThreatenedAbility AlertFrenzy3343("Alert Frenzy", 1, 2, 0, {
    TargetSlowest(
        Attack(1.5),
        Attack(1.5)
    ),
    TargetSelf(
        IncreaseSpeed(10.0, 2, 0)
    )
}, 66, ThreatComparison::Lower, 1, 2, 0, {
    TargetSelf(
        RallyHeal(33.33333)
    ),
    TargetSlowest(
        Attack(1.5),
        Attack(1.5)
    ),
    TargetSelf(
        IncreaseSpeed(30.0, 2, 0)
    )
});

ThreatenedAbility AlertHarpyD23C("Alert Harpy", 0, 2, 0, {
    TargetHighestHP(
        Attack(2.0)
    ),
    TargetHighestHP(
        ReduceSpeed(50.0, 2, 4)
    ),
    TargetHighestHP(
        DamageOverTime(20.0, 2)
    )
}, 50, ThreatComparison::Lower, 0, 2, 1, {
    TargetSelf(
        FixedHeal(50.0),
        IncreaseArmor(25.0, 2, 4),
        IncreaseCritChance(50.0, 2, 1)
    )
});

ThreatenedAbility AlertImpactDA02("Alert Impact", 0, 1, 0, {
    TargetAllOpponents(
        Remove(SHIELD),
        DevouringAttack(1.75, 50.0, 2, BYPASS_ARMOR)
    )
}, 50, ThreatComparison::Higher, 0, 1, 0, {
    TargetAllOpponents(
        ReduceSpeed(50.0, 2, 4),
        Attack(1.75, PRECISE)
    )
});

ThreatenedAbility AlertInstantHeal6BB9("Alert Instant Heal", 1, 2, 1, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(1.5)
    )
}, 33, ThreatComparison::Lower, 1, 2, 1, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(2.0)
    )
});

ThreatenedAbility AlertInstantShieldedStrikeF2E8("Alert Instant Shielded Strike", 1, 3, 1, {
    TargetHighestDamage(
        Attack(1.0),
        Stun(75.0, 1)
    ),
    TargetSelf(
        Taunt(2),
        Shield(50.0, 2, 4)
    )
}, 50, ThreatComparison::Lower, 1, 3, 1, {
    TargetHighestDamage(
        Attack(1.0),
        Stun(66.71, 1)
    ),
    TargetSelf(
        Taunt(2),
        Shield(100.0, 2, 4)
    )
});

ThreatenedAbility AlertNullification3D09("Alert Nullification", 0, 2, 1, {
    TargetAllOpponents(
        Remove(POSITIVE_EFFECTS),
        ReduceDamage(50.0, 2, 4)
    )
}, 50, ThreatComparison::Lower, 0, 2, 1, {
    TargetAllOpponents(
        Remove(POSITIVE_EFFECTS),
        ReduceDamage(75.0, 2, 4)
    )
});

ThreatenedAbility AlertPeck3B22("Alert Peck", 0, 2, 0, {
    TargetLowestHP(
        Remove(SHIELD),
        Rend(60.0, BYPASS_ARMOR),
        Remove(INCREASED_DAMAGE|INCREASED_CRIT_CHANCE)
    )
}, 33, ThreatComparison::Lower, 1, 2, 0, {
    TargetLowestHP(
        Remove(SHIELD),
        Rend(40.0, BYPASS_ARMOR),
        Remove(INCREASED_DAMAGE|INCREASED_CRIT_CHANCE)
    )
});

ThreatenedAbility AlertPersistentGroupShields2A85("Alert Persistent Group Shields", 0, 2, 0, {
    TargetAllOpponents(
        Remove(SHIELD)
    ),
    TargetTeam(
        IncreaseDamage(50.0, 2, 2),
        Shield(50.0, 2, 2)
    )
}, 50, ThreatComparison::Lower, 0, 2, 1, {
    TargetAllOpponents(
        Remove(SHIELD)
    ),
    TargetTeam(
        IncreaseDamage(50.0, 2, 2),
        IncreaseCritChance(100.0, 2, 1),
        Shield(100.0, 2, 2),
        Taunt(2)
    )
});

ThreatenedAbility AlertRampageOverthrow7EE6("Alert Rampage Overthrow", 1, 2, 0, {
    TargetFastest(
        Attack(2.0, BYPASS_ARMOR|PRECISE)
    )
}, 33, ThreatComparison::Lower, 1, 2, 0, {
    TargetFastest(
        DevouringAttack(2.0, 50.0, 3, BYPASS_ARMOR|PRECISE)
    )
});

ThreatenedAbility AlertSafetyRampage24DB("Alert Safety Rampage", 1, 2, 0, {
    TargetHighestDamage(
        Attack(1.5)
    ),
    TargetSelf(
        Swap()
    )
}, 50, ThreatComparison::Higher, 1, 2, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetHighestDamage(
        Attack(2.0)
    )
});

ThreatenedAbility AlertScurry6808("Alert Scurry", 0, 3, 0, {
    TargetHighestDamage(
        Attack(2.0),
        ReduceDamage(50.0, 1, 2)
    )
}, 66, ThreatComparison::Lower, 0, 3, 0, {
    TargetHighestDamage(
        Attack(1.5),
        ReduceDamage(25.0, 1, 2)
    ),
    TargetSelf(
        RallyHeal(33.33333)
    )
});

ThreatenedAbility AlertShatteringImpact9D9B("Alert Shattering Impact", 0, 2, 0, {
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        ReduceDamage(50.0, 1, 2),
        Attack(1.5, BYPASS_ARMOR)
    )
}, 33, ThreatComparison::Lower, 0, 2, 0, {
    TargetLowestHP(
        Remove(SHIELD|TAUNT)
    ),
    TargetSelf(
        RallyHeal(33.33333)
    ),
    TargetLast(
        Attack(1.5, BYPASS_ARMOR)
    )
});

ThreatenedAbility AlertSquall6E68("Alert Squall", 0, 3, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseSpeed(50.0, 2, 0),
        IncreaseCritChance(100.0, 2, 4)
    ),
    TargetLowestHP(
        Swap()
    )
}, 33, ThreatComparison::Lower, 0, 3, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseSpeed(50.0, 2, 4),
        Heal(1.0)
    ),
    TargetLowestHP(
        Swap()
    )
});

ThreatenedAbility AlertStrike9EBE("Alert Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        DevouringAttack(1.0, 40.0, 2, BYPASS_ARMOR)
    )
}, 50, ThreatComparison::Higher, 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE),
        IncreaseArmor(15.0, 1, 2)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.0),
        ImposeVulnerability(50.0, 2, 1)
    )
});

ThreatenedAbility AlertSurge82DA("Alert Surge", 0, 0, 1, {
    TargetLowestHP(
        Attack(1.0, ALWAYS_CRITS)
    )
}, 33, ThreatComparison::Lower, 0, 0, 1, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        Dodge(50.0, 66.69998, 1, 2)
    )
});

Ability AlphaIntimidation8FBA("Alpha Intimidation", 0, 2, 1, {
    TargetSelf(
        IncreaseDamage(25.0, 2, 4),
        IncreaseArmor(25.0, 2, 4)
    ),
    TargetLowestHP(
        ReduceSpeed(50.0, 2, 4),
        ReduceDamage(25.0, 2, 4)
    )
});

Ability AngryEndurance8CB4("Angry Endurance", 0, 2, 1, {
    TargetSelf(
        IncreaseArmor(20.0, 2, 2),
        Dodge(75.0, 67.0, 2, 4),
        IncreaseDamage(25.0, 2, 4)
    )
});

Ability Anticipation4EF9("Anticipation", 0, 1, 1, {
    TargetSelf(
        Dodge(75.0, 67.0, 2, 4),
        IncreaseArmor(50.0, 1, 1)
    )
});

CounterAbility ArmorPiercingCounterAEB5("Armor Piercing Counter", {
    TargetAttacker(
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability ArmorPiercingImpactB10F("Armor Piercing Impact", 0, 1, 0, {
    TargetLowestHP(
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability ArmorPiercingRampage4328("Armor Piercing Rampage", 1, 1, 0, {
    TargetHighestHP(
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability ArmorPiercingStrike69E0("Armor Piercing Strike", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.0, BYPASS_ARMOR)
    )
});

CounterAbility BaitAD47("Bait", {
    TargetSelf(
        IncreaseDamage(25.0, 1, 1)
    ),
    TargetAttacker(
        ReduceDamage(25.0, 1, 1)
    )
});

Ability BaredTeeth5269("Bared Teeth", 1, 3, 1, {
    TargetLowestHP(
        Cleanse(NEGATIVE_EFFECTS),
        Swap()
    )
});

Ability Bask359E("Bask", 0, 2, 1, {
    TargetFastest(
        Stun(100.0, 1),
        UnableToSwap(2)
    ),
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(1.5),
        IncreaseDamage(50.0, 2, 2)
    )
});

ThreatenedAbility BattleReadyE24E("Battle Ready", 0, 1, 1, {
    TargetSelf(
        FixedHeal(75.0),
        Remove(POSITIVE_EFFECTS),
        Shield(100.0, 1, 1)
    )
}, 50, ThreatComparison::Higher, 0, 0, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetTeam(
        IncreaseDamage(25.0, 3, 0),
        IncreaseSpeed(25.0, 3, 0)
    ),
    TargetSelf(
        IncreaseDamage(25.0, 3, 0),
        IncreaseSpeed(25.0, 3, 0),
        Sacrifice(50.99999)
    ),
    TargetAllOpponents(
        ReduceDamage(100.0, 1, 2)
    )
});

Ability Bellow866E("Bellow", 0, 2, 1, {
    TargetSelf(
        Shield(50.0, 0, 4)
    ),
    TargetFastest(
        ReduceSpeed(50.0, 2, 0)
    )
});

Ability BellowingImpact7163("Bellowing Impact", 0, 1, 0, {
    TargetSelf(
        Shield(50.0, 0, 4),
        Taunt(1)
    ),
    TargetFastest(
        ReduceSpeed(50.0, 2, 0)
    ),
    TargetFastest(
        Attack(1.5)
    )
});

ThreatenedAbility BerserkAlertDecoy8557("Berserk Alert Decoy", 1, 3, 0, {
    TargetLowestHP(
        Attack(2.0, ALWAYS_CRITS)
    ),
    TargetSelf(
        Sacrifice(33.33333),
        Swap()
    )
}, 33, ThreatComparison::Lower, 0, 0, false, {
});

RevengeAbility BerserkBitingRevenge5D5E("Berserk Biting Revenge", 0, 2, 0, {
    TargetHighestHP(
        Remove(SHIELD),
        Attack(2.5, BYPASS_ARMOR)
    ),
    TargetSelf(
        UnableToSwap(1),
        Sacrifice(33.33333)
    )
}, 0, 2, 1, {
    TargetHighestHP(
        Remove(SHIELD),
        Attack(2.5, BYPASS_ARMOR)
    )
});

RevengeAbility BerserkClawedRevenge111B("Berserk Clawed Revenge", 0, 2, 0, {
    TargetAllOpponents(
        Attack(2.5, PRECISE)
    ),
    TargetSelf(
        UnableToSwap(1),
        Sacrifice(33.33333)
    )
}, 0, 2, 1, {
    TargetAllOpponents(
        Attack(2.5, PRECISE)
    )
});

Ability BerserkDecimatingWound9D0A("Berserk Decimating Wound", 0, 2, -1, {
    TargetSelf(
        Sacrifice(33.33333)
    ),
    TargetHighestHP(
        DamageOverTime(25.0, 2),
        Remove(SHIELD),
        Attack(2.5, BYPASS_ARMOR)
    ),
    TargetSelf(
        UnableToSwap(1)
    )
});

Ability BerserkDecimation51AD("Berserk Decimation", 1, 2, 0, {
    TargetLowestHP(
        Remove(SHIELD),
        Attack(2.5, BYPASS_ARMOR)
    ),
    TargetSelf(
        Sacrifice(33.33333),
        Cleanse(VULNERABILITY),
        UnableToSwap(1)
    )
});

Ability BerserkRampagingCloak51AA("Berserk Rampaging Cloak", 0, 2, 0, {
    TargetLowestHP(
        Attack(2.0)
    ),
    TargetSelf(
        UnableToSwap(1),
        Sacrifice(33.33333),
        Cloak(2.0, 75.0, 66.66659, 2, 0)
    )
});

Ability BerserkResilientRampageD249("Berserk Resilient Rampage", 0, 2, 0, {
    TargetAllOpponents(
        Remove(DODGE|CLOAK|INCREASED_SPEED)
    ),
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Remove(INCREASED_DAMAGE),
        Attack(2.0),
        ImposeVulnerability(50.0, 1, 1)
    ),
    TargetSelf(
        Sacrifice(33.33333),
        UnableToSwap(1)
    )
});

Ability BindingImpactA742("Binding Impact", 0, 1, 0, {
    TargetFastest(
        Attack(1.5),
        UnableToSwap(2)
    )
});

Ability BraceB9A2("Brace", 0, 2, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseArmor(50.0, 1, 1),
        Heal(1.0)
    )
});

Ability BracingTauntAndImpactB08C("Bracing Taunt And Impact", 0, 1, 0, {
    TargetSelf(
        Taunt(1),
        Shield(50.0, 2, 4),
        IncreaseArmor(25.0, 2, 4),
        Heal(1.0)
    ),
    TargetHighestDamage(
        Attack(1.5)
    )
});

Ability BristlingStun38A2("Bristling Stun", 0, 2, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetHighestDamage(
        Remove(INCREASED_DAMAGE|INCREASED_CRIT_CHANCE),
        ReduceDamage(75.0, 2, 4),
        ReduceCritChance(100.0, 2, 4),
        Stun(100.0, 1)
    ),
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    )
});

Ability BruisingStrikeC7B7("Bruising Strike", 0, 0, 0, {
    TargetHighestHP(
        Remove(SHIELD)
    ),
    TargetHighestHP(
        Attack(1.0),
        ReduceArmor(15.0, 2, 2),
        Remove(INCREASED_DAMAGE|INCREASED_CRIT_CHANCE)
    )
});

Ability Bulwark2D7E("Bulwark", 0, 0, 1, {
    TargetSelf(
        IncreaseArmor(25.0, 2, 4),
        Shield(75.0, 2, 4),
        Cleanse(REDUCED_SPEED|REDUCED_DAMAGE)
    )
});

Ability Camouflage03BB("Camouflage", 0, 0, 1, {
    TargetSelf(
        IncreaseSpeed(30.0, 2, 0),
        Dodge(75.0, 66.69999, 2, 2)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2)
    )
});

Ability Camouflage8414("Camouflage", 0, 0, 1, {
    TargetSelf(
        IncreaseSpeed(30.0, 2, 0),
        Dodge(75.0, 66.69999, 2, 2)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2)
    )
});

Ability CautiousCunningRampage8C7B("Cautious Cunning Rampage", 0, 2, 1, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(2.0)
    )
});

Ability CautiousDisarmingStrikeBCD2("Cautious Disarming Strike", 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(10.0, 1, 1),
        Dodge(75.0, 67.0, 1, 1)
    ),
    TargetHighestHP(
        ReduceDamage(50.0, 1, 1),
        Attack(1.0, PRECISE),
        ReduceArmor(30.0, 2, 4)
    )
});

Ability CautiousDoubleImpactE21D("Cautious Double Impact", 0, 2, 0, {
    TargetSelf(
        IncreaseSpeed(10.0, 1, 0),
        Dodge(75.0, 67.0, 1, 1)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 1),
        Attack(1.25, PRECISE),
        Attack(1.25, PRECISE)
    )
});

Ability CautiousImpact0569("Cautious Impact", 0, 1, 0, {
    TargetSelf(
        IncreaseSpeed(10.0, 1, 0),
        Dodge(75.0, 67.0, 1, 1)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        Attack(1.5, PRECISE)
    )
});

Ability CautiousRampage36B3("Cautious Rampage", 1, 2, 0, {
    TargetSelf(
        IncreaseSpeed(10.0, 1, 0),
        Dodge(75.0, 67.0, 1, 1)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        Attack(2.0, PRECISE)
    )
});

Ability CautiousRetreat5570("Cautious Retreat", 0, 0, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(100.0, 67.0, 1, 1),
        Swap()
    )
});

Ability CautiousStrike3CE4("Cautious Strike", 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(10.0, 1, 0),
        Dodge(75.0, 67.0, 1, 1)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        Attack(1.0, PRECISE)
    )
});

Ability CenozoicSmack8DC9("Cenozoic Smack", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY|REDUCED_DAMAGE)
    ),
    TargetLowestHP(
        Remove(SHIELD)
    ),
    TargetLowestHP(
        Remove(DODGE)
    ),
    TargetLowestHP(
        Attack(1.0, BYPASS_ARMOR|PRECISE)
    ),
    TargetFastest(
        Remove(INCREASED_SPEED),
        ImposeVulnerability(50.0, 1, 2)
    )
});

ThreatenedAbility ChallengingAlertImpact0839("Challenging Alert Impact", 0, 1, 0, {
    TargetHighestHP(
        Remove(SHIELD),
        Attack(1.5, BYPASS_ARMOR)
    )
}, 33, ThreatComparison::Lower, 0, 1, 0, {
    TargetHighestHP(
        Attack(2.0, BYPASS_ARMOR)
    )
});

ThreatenedAbility ChallengingAlertImpact703E("Challenging Alert Impact", 0, 1, 0, {
    TargetHighestHP(
        Attack(2.0, BYPASS_ARMOR)
    )
}, 50, ThreatComparison::Higher, 0, 1, 0, {
    TargetHighestHP(
        Remove(SHIELD),
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability ClawSleight8F2A("Claw Sleight", 1, 2, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetHighestHP(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetSelf(
        Shield(50.0, 1, 1)
    ),
    TargetHighestHP(
        Swap()
    ),
    TargetSelf(
        Swap()
    )
});

Ability CleansingDeceleratingImpact66A0("Cleansing Decelerating Impact", 0, 2, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetFastest(
        ReduceSpeed(50.0, 2, 0),
        Attack(1.5)
    )
});

Ability CleansingGroupDestroyer66E8("Cleansing Group Destroyer", 0, 1, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        Remove(SHIELD|TAUNT),
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability CleansingGroupShieldD4D3("Cleansing Group Shield", 0, 2, 0, {
    TargetTeam(
        Shield(50.0, 2, 4),
        IncreaseArmor(25.0, 2, 4),
        Cleanse(NEGATIVE_EFFECTS),
        Heal(0.5)
    ),
    TargetSelf(
        Taunt(1)
    ),
    TargetAllOpponents(
        Attack(1.0)
    )
});

Ability CleansingImpact351E("Cleansing Impact", 0, 2, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetLowestHP(
        Attack(1.5)
    )
});

Ability CleansingRampageC8DB("Cleansing Rampage", 1, 2, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetHighestHP(
        Attack(2.0)
    )
});

Ability CleansingRoar4A67("Cleansing Roar", 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        Remove(POSITIVE_EFFECTS),
        Attack(1.0)
    )
});

Ability CleansingShatteringStrikeA6B1("Cleansing Shattering Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetLowestHP(
        Remove(SHIELD)
    ),
    TargetLowestHP(
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability CleansingStrike541F("Cleansing Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability CleansingSwoopB410("Cleansing Swoop", 0, 2, 0, {
    TargetHighestHP(
        DamageOverTime(25.0, 2)
    ),
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Swap()
    )
});

CounterAbility CleverCounter3298("Clever Counter", {
    TargetAttacker(
        ReduceSpeed(50.0, 1, 1),
        Remove(CLOAK|DODGE)
    )
});

RevengeAbility Cloak2513("Cloak", 0, 3, 1, {
    TargetSelf(
        Cloak(2.0, 75.0, 66.66659, 2, 0)
    )
}, 0, 1, 1, {
    TargetSelf(
        Cloak(3.0, 75.0, 66.66659, 2, 0)
    )
});

Ability CloakOfRage7990("Cloak Of Rage", 0, 3, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseDamage(50.0, 3, 2),
        IncreaseSpeed(10.0, 2, 2)
    ),
    TargetAllOpponents(
        IncreaseDamage(50.0, 2, 1)
    ),
    TargetTeam(
        Cloak(2.0, 75.0, 66.66659, 2, 1)
    ),
    TargetAllOpponents(
        ReduceArmor(100.0, 2, 4)
    )
});

ThreatenedAbility CloakedRampageAlert9A3E("Cloaked Rampage Alert", 1, 2, 0, {
    TargetLowestHP(
        ReduceDamage(50.0, 2, 4)
    ),
    TargetLowestHP(
        Attack(2.0)
    ),
    TargetSelf(
        Cloak(2.0, 75.0, 66.66659, 2, 0)
    )
}, 33, ThreatComparison::Lower, 1, 2, 0, {
    TargetLowestHP(
        ReduceDamage(50.0, 2, 4)
    ),
    TargetLowestHP(
        Attack(2.0)
    ),
    TargetSelf(
        Cloak(2.0, 75.0, 66.66659, 2, 0),
        Swap()
    )
});

CounterAbility CounterDualPeckA28F("Counter Dual Peck", {
    TargetAttacker(
        ReduceArmor(15.0, 2, 4),
        Attack(0.75),
        Attack(0.75)
    )
});

CounterAbility CounterFerocity85EF("Counter Ferocity", {
    TargetSelf(
        IncreaseDamage(20.0, 2, 4)
    )
});

CounterAbility CounterPowerHeal1300("Counter Power Heal", {
    TargetSelf(
        FixedHeal(5.99999)
    ),
    TargetAttacker(
        ReduceSpeed(25.0, 1, 2)
    )
});

CounterAbility CounterPowerHeal4DD2("Counter Power Heal", {
    TargetSelf(
        FixedHeal(5.99999)
    )
});

CounterAbility CounterPowerHealA54F("Counter Power Heal", {
    TargetSelf(
        FixedHeal(10.0)
    )
});

CounterAbility CounterSpikes5965("Counter Spikes", {
    TargetAttacker(
        Attack(0.33, PRECISE),
        Attack(0.33, PRECISE)
    )
});

CounterAbility CounterVulnerability02E9("Counter Vulnerability", {
    TargetAttacker(
        Attack(0.5),
        ImposeVulnerability(50.0, 2, 1)
    )
});

CounterAbility CounterVulnerabilityC8BA("Counter Vulnerability", {
    TargetAttacker(
        Attack(1.0),
        ImposeVulnerability(50.0, 2, 1)
    )
});

CounterAbility CounterVulnerabilityStrikeEE02("Counter Vulnerability Strike", {
    TargetAttacker(
        ImposeVulnerability(50.0, 2, 4),
        Attack(1.0)
    )
});

Ability CraftyStrike1DFE("Crafty Strike", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.0, BYPASS_ARMOR|PRECISE),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE)
    )
});

CounterAbility CriticalCounterStrikeA142("Critical Counter Strike", {
    TargetSelf(
        IncreaseCritChance(100.0, 1, 1)
    ),
    TargetAttacker(
        Attack(1.0)
    )
});

Ability CriticalImpactD735("Critical Impact", 0, 2, 0, {
    TargetLowestHP(
        Attack(1.5, ALWAYS_CRITS)
    )
});

Ability CriticalRampageA0F6("Critical Rampage", 1, 2, 0, {
    TargetLowestHP(
        Attack(2.0, ALWAYS_CRITS)
    )
});

Ability CriticalSidestep78B0("Critical Sidestep", 0, 1, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseSpeed(10.0, 2, 0),
        IncreaseCritChance(100.0, 2, 1),
        Dodge(100.0, 67.0, 0, 2)
    )
});

Ability CriticalStrike8706("Critical Strike", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.0, ALWAYS_CRITS)
    )
});

Ability CrushingProwl3FF5("Crushing Prowl", 0, 2, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseCritChance(75.0, 2, 2),
        Dodge(75.0, 67.0, 1, 2)
    ),
    TargetTeam(
        IncreaseDamage(50.0, 4, 2),
        Cleanse(REDUCED_DAMAGE|REDUCED_CRIT_CHANCE)
    )
});

Ability CunningDecimateC992("Cunning Decimate", 1, 2, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(2.5)
    )
});

Ability CunningDeviousImpactC699("Cunning Devious Impact", 0, 1, 0, {
    TargetSelf(
        Dodge(75.0, 66.69998, 2, 4),
        IncreaseCritChance(30.0, 2, 4)
    ),
    TargetLowestHP(
        Attack(1.5)
    ),
    TargetLowestHP(
        ReduceDamage(50.0, 2, 4)
    )
});

Ability CunningFerociousStrike6867("Cunning Ferocious Strike", 0, 3, 0, {
    TargetSelf(
        IncreaseDamage(50.0, 3, 6),
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetLowestHP(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability CunningFierceStrike9D6C("Cunning Fierce Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        Remove(SHIELD)
    ),
    TargetHighestDamage(
        Remove(TAUNT)
    ),
    TargetHighestDamage(
        Attack(1.0, BYPASS_ARMOR),
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE)
    )
});

Ability CunningHeavyStrike5DC6("Cunning Heavy Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE|VULNERABILITY|DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        Remove(INCREASED_SPEED)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Attack(1.0, BYPASS_ARMOR|PRECISE)
    )
});

Ability CunningImpactEE79("Cunning Impact", 0, 1, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.5)
    )
});

Ability CunningRampage8AEB("Cunning Rampage", 1, 1, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(2.0)
    )
});

Ability CunningStrike75A8("Cunning Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetLowestHP(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.0)
    )
});

Ability DaringStrikeE486("Daring Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY|DAMAGE_OVER_TIME)
    ),
    TargetLowestHP(
        Attack(1.0, BYPASS_ARMOR),
        ReduceDamage(50.0, 1, 2)
    )
});

CounterAbility DartingCounter6039("Darting Counter", {
    TargetAttacker(
        Attack(1.0)
    ),
    TargetSelf(
        IncreaseSpeed(20.0, 1, 0)
    )
});

Ability DeathRollD52C("Death Roll", 0, 1, 0, {
    TargetHighestHP(
        Attack(1.5, BYPASS_ARMOR),
        DamageOverTime(15.0, 2),
        ReduceSpeed(75.0, 3, 0)
    )
});

Ability DebilitatingDistraction3695("Debilitating Distraction", 0, 3, 0, {
    TargetHighestDamage(
        ReduceDamage(75.0, 2, 4),
        Attack(1.0)
    )
});

Ability DebilitatingRampageAndRun5304("Debilitating Rampage And Run", 1, 1, 0, {
    TargetLowestHP(
        Attack(2.0),
        ReduceDamage(100.0, 2, 4)
    ),
    TargetSelf(
        Swap()
    )
});

Ability DebilitatingStrike1814("Debilitating Strike", 0, 0, 0, {
    TargetHighestDamage(
        ReduceDamage(75.0, 1, 2),
        Attack(1.0)
    )
});

Ability DeceleratingCleanse6E7E("Decelerating Cleanse", 0, 0, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetLowestHP(
        Attack(1.0),
        ReduceSpeed(25.0, 2, 2)
    )
});

CounterAbility DeceleratingCounterD9D3("Decelerating Counter", {
    TargetAttacker(
        ReduceSpeed(50.0, 1, 1),
        Attack(1.0)
    )
});

Ability DeceleratingGroupHealD700("Decelerating Group Heal", 0, 2, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        FixedHeal(40.0)
    ),
    TargetFastest(
        ReduceSpeed(50.0, 2, 4)
    )
});

Ability DeceleratingImpact5016("Decelerating Impact", 0, 1, 0, {
    TargetFastest(
        ReduceSpeed(50.0, 2, 0),
        Attack(1.5)
    )
});

Ability DeceleratingRampageAndRun2D5A("Decelerating Rampage And Run", 1, 2, 0, {
    TargetFastest(
        ReduceSpeed(50.0, 2, 0),
        Attack(2.0)
    ),
    TargetSelf(
        Swap()
    )
});

Ability DeceleratingRampageD0C5("Decelerating Rampage", 1, 1, 0, {
    TargetFastest(
        ReduceSpeed(50.0, 2, 0),
        Attack(2.0)
    )
});

Ability DeceleratingSideflap5BCD("Decelerating Sideflap", 0, 1, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(100.0, 67.0, 0, 2),
        IncreaseSpeed(10.0, 2, 0),
        Taunt(1)
    ),
    TargetAllOpponents(
        ReduceSpeed(50.0, 1, 0)
    )
});

Ability DecimatingHunger9FEA("Decimating Hunger", 1, 3, 0, {
    TargetHighestHP(
        Remove(SHIELD)
    ),
    TargetHighestHP(
        DevouringAttack(2.5, 50.0, 2, BYPASS_ARMOR)
    )
});

Ability DecimatingTelsonBAD4("Decimating Telson", 1, 3, 0, {
    TargetLowestHP(
        Remove(SHIELD),
        Attack(2.5, BYPASS_ARMOR|PRECISE|ALWAYS_CRITS)
    )
});

ThreatenedAbility DefenseShatteringAlert459B("Defense Shattering Alert", 0, 0, 0, {
    TargetLowestHP(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR)
    )
}, 50, ThreatComparison::Lower, 0, 0, 0, {
    TargetMostPositiveEffects(
        Remove(TAUNT)
    ),
    TargetLowestHP(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR)
    ),
    TargetSelf(
        Cleanse(VULNERABILITY)
    )
});

CounterAbility DefenseShatteringCounterCA13("Defense Shattering Counter", {
    TargetAttacker(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR)
    )
});

CounterAbility DefenseShatteringCounter_attackD663("Defense Shattering Counter-Attack", {
    TargetAttacker(
        Remove(SHIELD),
        Attack(0.5, BYPASS_ARMOR)
    )
});

Ability DefenseShatteringImpact25E3("Defense Shattering Impact", 0, 1, 0, {
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability DefenseShatteringRampageC9FF("Defense Shattering Rampage", 1, 1, 0, {
    TargetHighestHP(
        Remove(SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR)
    )
});

RevengeAbility DefenseShatteringRevengeFFF1("Defense Shattering Revenge", 0, 1, 0, {
    TargetLowestHP(
        Remove(SHIELD),
        Attack(1.5, BYPASS_ARMOR),
        Remove(TAUNT)
    ),
    TargetSelf(
        Cleanse(VULNERABILITY)
    )
}, 0, 1, 0, {
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(1.5, BYPASS_ARMOR),
        Remove(TAUNT)
    ),
    TargetSelf(
        Cleanse(VULNERABILITY)
    )
});

Ability DefenseShatteringStrike1CA6("Defense Shattering Strike", 0, 0, 0, {
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability DefenseShatteringWound1735("Defense Shattering Wound", 0, 0, 0, {
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.0, BYPASS_ARMOR),
        DamageOverTime(20.0, 3)
    )
});

CounterAbility DefensiveCounterStrike801C("Defensive Counter Strike", {
    TargetSelf(
        Shield(50.0, 2, 4),
        IncreaseSpeed(25.0, 2, 4)
    ),
    TargetAttacker(
        Attack(0.5)
    )
});

Ability DefensiveEdgeF83D("Defensive Edge", 0, 2, 0, {
    TargetAllOpponents(
        Remove(SHIELD)
    ),
    TargetSelf(
        IncreaseDamage(50.0, 3, 2)
    )
});

Ability DefensiveRampageFA24("Defensive Rampage", 1, 1, 1, {
    TargetSelf(
        Shield(50.0, 2, 4),
        Heal(2.0)
    ),
    TargetFastest(
        Attack(2.0),
        Remove(CLOAK|DODGE)
    )
});

Ability DefensiveRendingAttack54CB("Defensive Rending Attack", 1, 2, 0, {
    TargetHighestHP(
        Remove(SHIELD),
        Rend(40.0, BYPASS_ARMOR)
    ),
    TargetSelf(
        Shield(50.0, 1, 2)
    )
});

ThreatenedAbility DefiniteAlertFrenzy84C4("Definite Alert Frenzy", 1, 2, 0, {
    TargetSlowest(
        Attack(1.5, BYPASS_ARMOR),
        Attack(1.5, BYPASS_ARMOR)
    ),
    TargetSelf(
        IncreaseSpeed(10.0, 2, 0)
    )
}, 66, ThreatComparison::Lower, 1, 2, 0, {
    TargetSelf(
        RallyHeal(33.33333)
    ),
    TargetSlowest(
        Attack(1.0, BYPASS_ARMOR),
        Attack(1.0, BYPASS_ARMOR)
    ),
    TargetSelf(
        IncreaseSpeed(30.0, 2, 0)
    )
});

Ability DefiniteImpactE2FE("Definite Impact", 1, 1, 0, {
    TargetMostPositiveEffects(
        Remove(CLOAK|DODGE|SHIELD|TAUNT),
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability DefiniteRampageD45A("Definite Rampage", 1, 2, 0, {
    TargetMostPositiveEffects(
        Remove(CLOAK|DODGE|SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability DefiniteShieldAdvantageED59("Definite Shield Advantage", 0, 2, 0, {
    TargetMostPositiveEffects(
        Remove(CLOAK|DODGE|SHIELD)
    ),
    TargetSelf(
        Shield(50.0, 1, 4)
    ),
    TargetLast(
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability DefiniteStrike51A6("Definite Strike", 0, 0, 0, {
    TargetMostPositiveEffects(
        Remove(CLOAK|DODGE|SHIELD),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability DegeneratingStrikeBC83("Degenerating Strike", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetLowestHP(
        Affliction(20.0, 3, 6)
    )
});

Ability DelayedCunningRampage5557("Delayed Cunning Rampage", 2, 1, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(2.0)
    )
});

ThreatenedAbility DelayedPreciseRampage5DFE("Delayed Precise Rampage", 1, 1, 0, {
    TargetHighestDamage(
        Attack(2.0, PRECISE)
    )
}, 33, ThreatComparison::Lower, 1, 1, 1, {
    TargetHighestDamage(
        Attack(2.0, PRECISE)
    )
});

Ability DelayedRampageAndRun7020("Delayed Rampage And Run", 2, 1, 0, {
    TargetLowestHP(
        Attack(2.0)
    ),
    TargetSelf(
        Swap()
    )
});

RevengeAbility DelayedRevengeDistractingRampage99EB("Delayed Revenge Distracting Rampage", 1, 1, 0, {
    TargetHighestDamage(
        Attack(2.0),
        ReduceDamage(50.0, 2, 4)
    )
}, 0, 1, 0, {
    TargetHighestDamage(
        Attack(2.0),
        ReduceDamage(50.0, 2, 4)
    )
});

Ability DeliberateProwlDF39("Deliberate Prowl", 0, 0, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(75.0, 67.0, 1, 2),
        IncreaseCritChance(50.0, 3, 2)
    )
});

Ability DemolitionClaws9934("Demolition Claws", 1, 2, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetLowestHP(
        ImposeVulnerability(50.0, 2, 4)
    ),
    TargetLowestHP(
        ReduceDamage(50.0, 2, 4)
    ),
    TargetLowestHP(
        ReduceSpeed(50.0, 2, 4)
    ),
    TargetLowestHP(
        Remove(DODGE)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability DeterminedStrike3D79("Determined Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE|DAMAGE_OVER_TIME)
    ),
    TargetFastest(
        Remove(INCREASED_SPEED|INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.0, PRECISE),
        ImposeVulnerability(50.0, 2, 1),
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2)
    )
});

Ability DevastateAndRun2D50("Devastate And Run", 2, 2, 0, {
    TargetLowestHP(
        Attack(3.0)
    ),
    TargetSelf(
        Swap()
    )
});

Ability Devastation3723("Devastation", 2, 1, 0, {
    TargetHighestHP(
        Attack(3.0, PRECISE)
    ),
    TargetSelf(
        Taunt(1)
    )
});

Ability DeviousImpactAED3("Devious Impact", 0, 1, 0, {
    TargetLowestHP(
        Attack(1.5, BYPASS_ARMOR)
    ),
    TargetLowestHP(
        Affliction(40.0, 1, 2),
        DamageOverTime(33.41, 3),
        ReduceDamage(50.0, 2, 4)
    )
});

Ability DeviousStrike53F7("Devious Strike", 0, 0, 0, {
    TargetSelf(
        Dodge(75.0, 67.0, 1, 2),
        IncreaseCritChance(30.0, 2, 2)
    ),
    TargetLowestHP(
        Attack(1.0),
        ReduceDamage(25.0, 2, 4)
    )
});

Ability DevouringImpact0320("Devouring Impact", 0, 2, 0, {
    TargetHighestHP(
        DevouringAttack(1.5, 50.0, 2)
    )
});

RevengeAbility DevouringRevenge88AA("Devouring Revenge", 1, 3, 1, {
    TargetLowestHP(
        DevouringAttack(2.0, 40.0, 3, BYPASS_ARMOR)
    ),
    TargetSelf(
        Shield(50.0, 2, 4),
        IncreaseArmor(25.0, 2, 4)
    )
}, 0, 2, 0, {
    TargetLowestHP(
        DevouringAttack(2.0, 60.0, 3, BYPASS_ARMOR)
    ),
    TargetSelf(
        Shield(50.0, 3, 4),
        IncreaseArmor(50.0, 2, 4)
    )
});

Ability DevouringStinger965B("Devouring Stinger", 0, 0, 0, {
    TargetMostPositiveEffects(
        Remove(SHIELD),
        DevouringAttack(0.5, 50.0, 1, BYPASS_ARMOR),
        DamageOverTime(15.0, 1)
    )
});

Ability DevouringWound32A1("Devouring Wound", 0, 1, 0, {
    TargetHighestHP(
        Remove(SHIELD)
    ),
    TargetHighestHP(
        DevouringAttack(1.5, 60.0, 4, BYPASS_ARMOR)
    ),
    TargetHighestHP(
        DamageOverTime(20.0, 2)
    )
});

Ability DigIn6DFE("Dig In", 0, 2, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseSpeed(10.0, 2, 0),
        Shield(50.0, 0, 8),
        Heal(1.0)
    )
});

Ability DigInTaunt1BB1("Dig In Taunt", 0, 2, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseSpeed(10.0, 2, 0),
        Shield(50.0, 0, 8),
        Heal(1.0),
        Taunt(1)
    )
});

CounterAbility DisarmingCounterStrike8AAD("Disarming Counter Strike", {
    TargetAttacker(
        Attack(1.0, BYPASS_ARMOR),
        ReduceArmor(25.0, 2, 2)
    )
});

Ability DisarmingDecimateAndRunB62E("Disarming Decimate And Run", 2, 1, 0, {
    TargetHighestHP(
        Attack(2.5)
    ),
    TargetHighestHP(
        ReduceArmor(100.0, 2, 4)
    ),
    TargetSelf(
        Swap()
    )
});

Ability DisarmingImpactAndRunC0BA("Disarming Impact And Run", 1, 1, 0, {
    TargetHighestHP(
        Attack(1.5)
    ),
    TargetHighestHP(
        ReduceArmor(30.0, 2, 4)
    ),
    TargetSelf(
        Swap()
    )
});

Ability DisarmingStrike7427("Disarming Strike", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetLowestHP(
        ReduceArmor(50.0, 1, 2)
    )
});

Ability DispersedCautiousStrikeDD1C("Dispersed Cautious Strike", 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(10.0, 1, 0),
        Dodge(75.0, 67.0, 1, 1)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 1, 2),
        Attack(1.0, PRECISE)
    )
});

Ability DispersedCunningStrike30D1("Dispersed Cunning Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.0)
    )
});

Ability DispersedFerociousImpact78DD("Dispersed Ferocious Impact", 0, 3, 0, {
    TargetAllOpponents(
        Attack(1.5)
    ),
    TargetTeam(
        IncreaseDamage(50.0, 3, 6)
    )
});

Ability DispersedFierceImpact938B("Dispersed Fierce Impact", 0, 1, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetAllOpponents(
        Remove(SHIELD|TAUNT),
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability DispersedRakingImpact1D47("Dispersed Raking Impact", 0, 2, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        Remove(CLOAK|DODGE),
        Attack(1.5)
    )
});

Ability DispersedSuperiorVulnerability5AC2("Dispersed Superior Vulnerability", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        ReduceSpeed(50.0, 2, 0),
        Attack(1.0, PRECISE),
        ImposeVulnerability(50.0, 2, 1)
    )
});

CounterAbility DistractingCounterA897("Distracting Counter", {
    TargetAttacker(
        ReduceDamage(25.0, 2, 4)
    )
});

Ability DistractingDevourImpactF535("Distracting Devour Impact", 0, 3, 0, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        DevouringAttack(1.5, 50.0, 2)
    )
});

Ability DistractingImpactAndRunBB70("Distracting Impact And Run", 1, 1, 0, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        Attack(1.5)
    ),
    TargetSelf(
        Swap()
    )
});

Ability DistractingImpactD4D6("Distracting Impact", 0, 2, 0, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        Attack(1.5)
    )
});

Ability DistractingRampageBD0D("Distracting Rampage", 1, 2, 0, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        Attack(2.0)
    )
});

RevengeAbility DistractingRevengeBlow7BE8("Distracting Revenge Blow", 0, 2, 0, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        Attack(1.5)
    )
}, 0, 2, 0, {
    TargetHighestDamage(
        ReduceDamage(100.0, 2, 4),
        Attack(2.0)
    )
});

Ability DistractingSidestep6F60("Distracting Sidestep", 0, 0, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(100.0, 67.0, 0, 2),
        IncreaseSpeed(10.0, 2, 2)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2)
    )
});

Ability DistractingStrikeD81E("Distracting Strike", 0, 2, 0, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        Attack(1.0)
    )
});

Ability DistractingTeamHeal41AD("Distracting Team Heal", 0, 2, 1, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(2.0)
    ),
    TargetHighestDamage(
        ReduceDamage(25.0, 2, 2)
    )
});

Ability DistractingTripleStrike777F("Distracting Triple Strike", 1, 2, 0, {
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        Attack(1.0),
        Attack(1.0),
        Attack(1.0)
    )
});

CounterAbility DistractingVulnerabilityCounterBBA8("Distracting Vulnerability Counter", {
    TargetAttacker(
        ReduceDamage(25.0, 2, 4),
        ImposeVulnerability(50.0, 1, 2)
    )
});

Ability Distraction2717("Distraction", 0, 0, 0, {
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        Attack(1.0)
    )
});

Ability Distraction8FE1("Distraction", 0, 0, 0, {
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        Attack(1.0)
    )
});

Ability DivebombBE13("Divebomb", 0, 3, -1, {
    TargetHighestHP(
        Remove(SHIELD)
    ),
    TargetHighestHP(
        ReduceArmor(50.0, 2, 4)
    ),
    TargetHighestHP(
        Attack(2.5, BYPASS_ARMOR)
    ),
    TargetHighestHP(
        Stun(50.0, 1)
    ),
    TargetSelf(
        UnableToSwap(2)
    )
});

Ability DominantPounceDBBD("Dominant Pounce", 0, 1, 0, {
    TargetHighestDamage(
        Attack(2.0, PRECISE),
        ReduceDamage(100.0, 1, 2),
        ReduceCritChance(100.0, 2, 4)
    )
});

Ability DominantRoar01DF("Dominant Roar", 0, 2, 1, {
    TargetTeam(
        IncreaseDamage(50.0, 2, 2)
    ),
    TargetAllOpponents(
        Attack(1.0)
    ),
    TargetTeam(
        IncreaseSpeed(25.0, 2, 2)
    )
});

Ability DoubleImpactBulwark0442("Double Impact Bulwark", 1, 2, 0, {
    TargetSelf(
        Taunt(1),
        IncreaseArmor(50.0, 2, 4),
        Shield(75.0, 2, 4)
    ),
    TargetHighestDamage(
        Attack(1.25)
    ),
    TargetHighestDamage(
        Attack(1.25)
    )
});

Ability Dragon_sFlightB1E0("Dragon'S Flight", 0, 2, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        Attack(1.0),
        DamageOverTime(25.0, 2)
    ),
    TargetSelf(
        Shield(75.0, 2, 4),
        Heal(1.0)
    )
});

Ability DualClawC2BD("Dual Claw", 0, 1, 0, {
    TargetSelf(
        Dodge(50.0, 67.0, 2, 4)
    ),
    TargetMostPositiveEffects(
        Remove(DODGE),
        Attack(0.75),
        Attack(0.75)
    )
});

Ability DualRendingAssaultC57D("Dual Rending Assault", 0, 2, 0, {
    TargetHighestHP(
        Remove(SHIELD),
        Rend(40.0, BYPASS_ARMOR),
        Rend(40.0, BYPASS_ARMOR)
    )
});

Ability EliminationStrike093B("Elimination Strike", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.25)
    )
});

Ability Embolden90A1("Embolden", 0, 2, 1, {
    TargetTeam(
        IncreaseSpeed(25.0, 2, 4),
        FixedHeal(25.0),
        IncreaseDamage(25.0, 2, 4),
        IncreaseCritChance(50.0, 2, 4)
    ),
    TargetSelf(
        IncreaseArmor(25.0, 2, 4)
    ),
    TargetTeam(
        Shield(25.0, 2, 4)
    )
});

ThreatenedAbility EmboldeningAlertBAC9("Emboldening Alert", 0, 0, 0, {
    TargetSelf(
        IncreaseDamage(25.0, 2, 4),
        IncreaseSpeed(25.0, 2, 4),
        IncreaseCritChance(25.0, 2, 4)
    )
}, 50, ThreatComparison::Lower, 0, 0, 0, {
    TargetSelf(
        IncreaseDamage(25.0, 2, 4),
        IncreaseSpeed(25.0, 2, 4),
        IncreaseCritChance(25.0, 2, 4),
        FixedHeal(25.0)
    )
});

Ability EmergencyGroupHealC79B("Emergency Group Heal", 1, 2, 1, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(1.5)
    )
});

Ability EmergencyHeal679C("Emergency Heal", 0, 2, 1, {
    TargetLowestHPTeammate(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(1.5)
    )
});

Ability EnfeeblingImpact9D6C("Enfeebling Impact", 0, 2, 0, {
    TargetMostPositiveEffects(
        Attack(1.5),
        Remove(POSITIVE_EFFECTS),
        DamageOverTime(25.0, 2),
        UnableToSwap(1),
        Stun(100.0, 1)
    )
});

Ability EnfeeblingRampage8631("Enfeebling Rampage", 0, 3, 0, {
    TargetMostPositiveEffects(
        Attack(2.0),
        Remove(POSITIVE_EFFECTS),
        DamageOverTime(25.0, 2),
        UnableToSwap(1),
        Stun(100.0, 1)
    )
});

Ability EnfeeblingStinger5E49("Enfeebling Stinger", 0, 0, 0, {
    TargetMostPositiveEffects(
        Remove(SHIELD),
        Attack(0.5, BYPASS_ARMOR),
        DamageOverTime(15.0, 1)
    )
});

ThreatenedAbility EvasiveAlertRampageF230("Evasive Alert Rampage", 1, 2, 0, {
    TargetHighestDamage(
        Attack(2.0)
    ),
    TargetSelf(
        Dodge(100.0, 67.0, 1, 2)
    )
}, 33, ThreatComparison::Lower, 1, 2, 0, {
    TargetHighestDamage(
        Attack(2.0)
    ),
    TargetHighestDamage(
        Stun(66.71, 1)
    ),
    TargetSelf(
        Swap()
    )
});

Ability EvasiveFerociousRampageFFBB("Evasive Ferocious Rampage", 1, 2, 0, {
    TargetHighestHP(
        Attack(2.0)
    ),
    TargetSelf(
        IncreaseDamage(50.0, 2, 4),
        Dodge(100.0, 67.0, 2, 4)
    )
});

Ability EvasiveHunt089A("Evasive Hunt", 0, 2, 1, {
    TargetSelf(
        IncreaseSpeed(25.0, 1, 2),
        IncreaseDamage(50.0, 2, 4),
        Dodge(100.0, 100.0, 1, 2)
    )
});

Ability EvasiveImpact7999("Evasive Impact", 0, 2, 0, {
    TargetSelf(
        Dodge(75.0, 67.0, 2, 4)
    ),
    TargetLowestHP(
        Attack(1.5)
    )
});

Ability EvasiveImpactBA40("Evasive Impact", 0, 2, 0, {
    TargetAllOpponents(
        Attack(1.5)
    ),
    TargetSelf(
        Dodge(75.0, 67.0, 2, 4)
    ),
    TargetTeam(
        Cleanse(REDUCED_SPEED|REDUCED_DAMAGE|VULNERABILITY)
    )
});

Ability EvasiveRampage40C8("Evasive Rampage", 1, 2, 0, {
    TargetSelf(
        Dodge(75.0, 67.0, 2, 4)
    ),
    TargetLowestHP(
        Attack(2.0)
    )
});

Ability EvasiveResilientImpactBCAB("Evasive Resilient Impact", 0, 1, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetLowestHP(
        Remove(DODGE|INCREASED_SPEED|CLOAK),
        Attack(1.5),
        ImposeVulnerability(50.0, 1, 2)
    ),
    TargetSelf(
        Dodge(75.0, 67.0, 1, 2)
    )
});

Ability EvasiveRestore11D0("Evasive Restore", 1, 3, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseSpeed(10.0, 2, 0),
        Dodge(75.0, 67.0, 0, 2),
        RallyHeal(33.33333)
    )
});

Ability EvasiveStanceF473("Evasive Stance", 0, 3, 1, {
    TargetSelf(
        Dodge(75.0, 67.0, 0, 4)
    )
});

Ability EvasiveStrikeA8EB("Evasive Strike", 0, 0, 0, {
    TargetSelf(
        Dodge(75.0, 67.0, 1, 1)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability EvasiveWoundingStrikeC8F8("Evasive Wounding Strike", 0, 2, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetHighestHP(
        DamageOverTime(20.0, 2)
    ),
    TargetSelf(
        Dodge(50.0, 67.0, 2, 4)
    )
});

Ability Exhaust71B8("Exhaust", 0, 1, 0, {
    TargetMostPositiveEffects(
        Remove(POSITIVE_EFFECTS),
        Affliction(50.0, 2, 4),
        Attack(1.25)
    )
});

Ability ExposeWeakSpot7AA2("Expose Weak Spot", 0, 2, 0, {
    TargetLowestHP(
        Attack(1.0),
        ImposeVulnerability(50.0, 3, 4)
    )
});

Ability ExposeWeakness6777("Expose Weakness", 0, 2, 0, {
    TargetFastest(
        ImposeVulnerability(50.0, 2, 2)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK)
    ),
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Attack(2.0)
    ),
    TargetSelf(
        IncreaseArmor(25.0, 2, 4)
    )
});

CounterAbility ExposingCounterA5BA("Exposing Counter", {
    TargetAttacker(
        ImposeVulnerability(50.0, 1, 2)
    )
});

Ability ExtendedCriticalStrike7DFE("Extended Critical Strike", 0, 3, 0, {
    TargetTeam(
        IncreaseCritChance(60.0, 2, 2)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability FabledFangs9083("Fabled Fangs", 0, 3, 1, {
    TargetHighestDamage(
        Attack(1.5, PRECISE),
        DamageOverTime(40.0, 2)
    )
});

Ability Fade8650("Fade", 0, 2, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME),
        Heal(1.0),
        Cloak(2.0, 75.0, 66.66659, 2, 0)
    )
});

ThreatenedAbility FearlessAlertCC50("Fearless Alert", 0, 2, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        RallyHeal(33.33333),
        Dodge(75.0, 66.69999, 2, 2),
        IncreaseSpeed(10.0, 2, 0)
    ),
    TargetAllOpponents(
        Attack(1.0, PRECISE)
    )
}, 33, ThreatComparison::Higher, 0, 2, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(75.0, 66.69999, 2, 2),
        IncreaseSpeed(10.0, 2, 0)
    ),
    TargetAllOpponents(
        Attack(1.0, PRECISE),
        ReduceDamage(50.0, 2, 2)
    )
});

Ability FearlessFlap6CE3("Fearless Flap", 0, 2, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(100.0, 67.0, 2, 4),
        IncreaseSpeed(10.0, 2, 0)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 2),
        Attack(1.0)
    )
});

Ability FeastDEF6("Feast", 1, 2, 0, {
    TargetAllOpponents(
        Attack(1.75)
    ),
    TargetSelf(
        RallyHeal(33.0)
    )
});

Ability FerociousAssistedRampage8974("Ferocious Assisted Rampage", 0, 2, 0, {
    TargetTeam(
        IncreaseDamage(25.0, 2, 4)
    ),
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(2.0)
    )
});

Ability FerociousCleansingStrike120F("Ferocious Cleansing Strike", 0, 0, 0, {
    TargetHighestHP(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR),
        Remove(TAUNT)
    ),
    TargetSelf(
        IncreaseDamage(20.0, 2, 4),
        Cleanse(NEGATIVE_EFFECTS)
    )
});

CounterAbility FerociousCounterHealingStrikeD730("Ferocious Counter Healing Strike", {
    TargetTeam(
        IncreaseDamage(15.0, 1, 1)
    ),
    TargetSelf(
        Heal(0.5)
    ),
    TargetAttacker(
        Remove(SHIELD),
        Attack(1.0, PRECISE)
    )
});

CounterAbility FerociousCounterStunE8A6("Ferocious Counter Stun", {
    TargetSelf(
        IncreaseDamage(25.0, 1, 1)
    ),
    TargetAttacker(
        Stun(66.0, 1)
    )
});

Ability FerociousCunningImpact683F("Ferocious Cunning Impact", 0, 3, 0, {
    TargetSelf(
        IncreaseDamage(50.0, 3, 6),
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetLowestHP(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.5)
    )
});

Ability FerociousDefense7932("Ferocious Defense", 0, 3, 1, {
    TargetSelf(
        IncreaseDamage(50.0, 3, 6),
        Shield(50.0, 2, 4)
    ),
    TargetHighestHP(
        DamageOverTime(34.0, 2)
    )
});

Ability FerociousFlyingStrike4452("Ferocious Flying Strike", 0, 0, 0, {
    TargetTeam(
        Dodge(50.0, 66.69998, 2, 4),
        IncreaseArmor(25.0, 2, 4),
        IncreaseDamage(25.0, 2, 4)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability FerociousImpactA5CC("Ferocious Impact", 0, 3, 0, {
    TargetSelf(
        IncreaseDamage(50.0, 3, 6)
    ),
    TargetHighestHP(
        Attack(1.5)
    )
});

Ability FerociousRampage7FD3("Ferocious Rampage", 1, 2, 0, {
    TargetHighestHP(
        Attack(2.0)
    ),
    TargetSelf(
        IncreaseDamage(50.0, 2, 4)
    )
});

Ability FerociousResilientStrike4855("Ferocious Resilient Strike", 0, 0, 0, {
    TargetSelf(
        IncreaseDamage(10.0, 2, 4),
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_DAMAGE),
        Attack(1.0),
        ImposeVulnerability(50.0, 1, 1)
    )
});

Ability FerociousRestoreD2AB("Ferocious Restore", 0, 3, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseSpeed(10.0, 2, 0)
    ),
    TargetTeam(
        IncreaseCritChance(30.0, 4, 2),
        IncreaseDamage(50.0, 4, 2)
    ),
    TargetSelf(
        Heal(1.0)
    )
});

Ability FerociousShieldedHeal2912("Ferocious Shielded Heal", 0, 0, 0, {
    TargetSelf(
        IncreaseDamage(50.0, 2, 2),
        Shield(50.0, 1, 2),
        FixedHeal(50.0)
    )
});

Ability FerociousStrike71CC("Ferocious Strike", 0, 3, 0, {
    TargetSelf(
        IncreaseDamage(50.0, 3, 6)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

CounterAbility FierceCounter4FB7("Fierce Counter", {
    TargetAttacker(
        Remove(SHIELD),
        Attack(0.25, BYPASS_ARMOR)
    ),
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetAttacker(
        Remove(TAUNT)
    )
});

Ability FierceCriticalImpact8120("Fierce Critical Impact", 0, 2, 0, {
    TargetLowestHP(
        Remove(SHIELD)
    ),
    TargetLowestHP(
        Remove(TAUNT)
    ),
    TargetLowestHP(
        Attack(1.5, BYPASS_ARMOR|ALWAYS_CRITS)
    )
});

Ability FierceDeceleratingStrike401B("Fierce Decelerating Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.0, BYPASS_ARMOR),
        ReduceSpeed(50.0, 2, 0)
    )
});

Ability FierceDevouringCleanse4BB9("Fierce Devouring Cleanse", 0, 0, 0, {
    TargetLowestHP(
        Remove(SHIELD),
        DevouringAttack(1.0, 20.0, 1, BYPASS_ARMOR),
        Remove(TAUNT)
    ),
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    )
});

Ability FierceDevouringImpactB728("Fierce Devouring Impact", 0, 2, 0, {
    TargetLowestHP(
        Remove(SHIELD),
        DevouringAttack(1.5, 60.0, 2, BYPASS_ARMOR),
        Remove(TAUNT)
    ),
    TargetSelf(
        Cleanse(VULNERABILITY)
    )
});

Ability FierceDevouringRampage6CE7("Fierce Devouring Rampage", 1, 1, 0, {
    TargetLowestHP(
        Remove(SHIELD),
        DevouringAttack(2.0, 60.0, 4, BYPASS_ARMOR),
        Remove(TAUNT)
    ),
    TargetSelf(
        Cleanse(VULNERABILITY)
    )
});

Ability FierceDoubleStrike700F("Fierce Double Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD),
        Attack(0.66, BYPASS_ARMOR),
        Remove(TAUNT),
        Attack(0.66, BYPASS_ARMOR)
    )
});

Ability FierceImpactB3BE("Fierce Impact", 0, 1, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability FierceRampage95D1("Fierce Rampage", 1, 1, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetHighestHP(
        Remove(SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability FierceRampageDC31("Fierce Rampage", 1, 1, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetHighestHP(
        Remove(SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability FierceStrike106A("Fierce Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability FierceStrikeAA4B("Fierce Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability FlightlessStrikeCC17("Flightless Strike", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.0, BYPASS_ARMOR),
        Remove(INCREASED_DAMAGE),
        ReduceCritChance(100.0, 1, 2)
    )
});

Ability FloatingDualClaw4DF9("Floating Dual Claw", 1, 1, 0, {
    TargetSelf(
        Dodge(50.0, 67.0, 2, 4)
    ),
    TargetMostPositiveEffects(
        Remove(DODGE),
        Attack(1.0),
        Attack(1.0),
        ReduceDamage(50.0, 2, 4)
    )
});

ThreatenedAbility FlockOfOneBDDA("Flock Of One", 1, 1, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 4),
        Remove(SHIELD|INCREASED_DAMAGE|INCREASED_CRIT_CHANCE),
        Rend(60.0, BYPASS_ARMOR),
        ImposeVulnerability(50.0, 2, 1)
    )
}, 50, ThreatComparison::Lower, 0, 2, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(1.0)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 4),
        Remove(SHIELD|INCREASED_DAMAGE|INCREASED_CRIT_CHANCE),
        Rend(40.0, BYPASS_ARMOR)
    )
});

Ability FoulRakingClaws91FC("Foul Raking Claws", 0, 2, 0, {
    TargetMostPositiveEffects(
        Remove(CLOAK|DODGE|INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(2.0)
    )
});

Ability FrustratingRendingTakedown4D3A("Frustrating Rending Takedown", 1, 1, 0, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4)
    ),
    TargetHighestDamage(
        Remove(SHIELD)
    ),
    TargetHighestDamage(
        Rend(60.0, BYPASS_ARMOR)
    )
});

Ability GashingWound4BC2("Gashing Wound", 0, 1, 0, {
    TargetHighestHP(
        Attack(1.0),
        DamageOverTime(30.0, 2)
    )
});

Ability GnawingRampage1D95("Gnawing Rampage", 0, 2, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetLowestHP(
        Remove(SHIELD),
        ReduceArmor(50.0, 2, 4),
        DevouringAttack(2.0, 20.0, 3, BYPASS_ARMOR)
    )
});

Ability GoringChargeD8A9("Goring Charge", 0, 2, 0, {
    TargetHighestHP(
        Stun(75.0, 1),
        Attack(1.25, PRECISE),
        DamageOverTime(34.0, 2)
    )
});

Ability GreaterEmergencyHeal456B("Greater Emergency Heal", 0, 2, 1, {
    TargetLowestHPTeammate(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(2.0)
    )
});

Ability GreaterGroupHeal566D("Greater Group Heal", 0, 2, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(2.0)
    )
});

Ability GreaterNullification593D("Greater Nullification", 0, 1, 1, {
    TargetMostPositiveEffects(
        Remove(POSITIVE_EFFECTS),
        ReduceDamage(50.0, 2, 4)
    )
});

Ability GreaterRegeneratingStrike64EC("Greater Regenerating Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE),
        IncreaseDamage(20.0, 2, 4)
    ),
    TargetHighestDamage(
        Attack(1.0)
    ),
    TargetSelf(
        Heal(0.5)
    )
});

CounterAbility GreaterRendingCounter_attackD5C2("Greater Rending Counter-Attack", {
    TargetAttacker(
        Remove(SHIELD),
        Rend(33.41, BYPASS_ARMOR)
    )
});

Ability GreaterStunningImpact2966("Greater Stunning Impact", 1, 2, 0, {
    TargetHighestHP(
        Attack(1.5),
        Stun(75.0, 1)
    )
});

Ability GreaterStunningRampageAC0D("Greater Stunning Rampage", 1, 2, 0, {
    TargetHighestHP(
        Attack(2.0),
        Stun(75.0, 1),
        ReduceDamage(50.0, 2, 4)
    )
});

Ability GreaterStunningStrikeBAEF("Greater Stunning Strike", 1, 2, 0, {
    TargetHighestDamage(
        Attack(1.0),
        Stun(75.0, 1)
    )
});

Ability GroupAccelerateCunningStrikeF6AA("Group Accelerate Cunning Strike", 0, 0, 0, {
    TargetTeam(
        IncreaseSpeed(10.0, 2, 0)
    ),
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        Remove(INCREASED_DAMAGE|INCREASED_CRIT_CHANCE),
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Attack(1.0)
    )
});

Ability GroupAcceleration6211("Group Acceleration", 0, 1, 1, {
    TargetTeam(
        Cleanse(REDUCED_SPEED),
        IncreaseSpeed(50.0, 3, 3)
    ),
    TargetLowestHP(
        Attack(1.5)
    )
});

Ability GroupAfflictingImpact189F("Group Afflicting Impact", 0, 2, 0, {
    TargetAllOpponents(
        Attack(1.5),
        Affliction(33.0, 2, 4)
    )
});

Ability GroupAfflictingStrike1956("Group Afflicting Strike", 0, 0, 0, {
    TargetAllOpponents(
        Attack(1.0),
        Affliction(25.0, 2, 4)
    )
});

Ability GroupCleansingFatalStrike3DBD("Group Cleansing Fatal Strike", 0, 3, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseDamage(50.0, 3, 6)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability GroupCleansingStrike4EEA("Group Cleansing Strike", 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability GroupCleansingStrike8B0C("Group Cleansing Strike", 0, 0, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        Attack(1.0)
    )
});

ThreatenedAbility GroupCriticalAlertF371("Group Critical Alert", 0, 2, 1, {
    TargetTeam(
        IncreaseCritChance(100.0, 2, 4)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 4)
    )
}, 50, ThreatComparison::Lower, 0, 2, 1, {
    TargetTeam(
        IncreaseCritChance(50.0, 2, 4)
    ),
    TargetAllOpponents(
        ReduceDamage(100.0, 1, 2)
    )
});

Ability GroupCunningImpact436E("Group Cunning Impact", 0, 1, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.5)
    )
});

Ability GroupCunningRampageA204("Group Cunning Rampage", 2, 1, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(2.0)
    )
});

Ability GroupDeceleratingImpact9451("Group Decelerating Impact", 0, 1, 0, {
    TargetAllOpponents(
        ReduceSpeed(50.0, 2, 0),
        Attack(1.5)
    )
});

Ability GroupDeceleratingRampageE77E("Group Decelerating Rampage", 0, 2, 0, {
    TargetAllOpponents(
        ReduceSpeed(50.0, 2, 0),
        Attack(2.0)
    )
});

Ability GroupDeceleratingStrikeBAC6("Group Decelerating Strike", 0, 0, 0, {
    TargetAllOpponents(
        ReduceSpeed(50.0, 2, 0),
        Attack(1.0)
    )
});

Ability GroupDefenseShatteringImpact0C66("Group Defense Shattering Impact", 0, 2, 0, {
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability GroupDefenseShatteringStrikeAE98("Group Defense Shattering Strike", 0, 0, 0, {
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability GroupDefenseShatteringStrikeF98B("Group Defense Shattering Strike", 0, 0, 0, {
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability GroupDefensiveEdge19D2("Group Defensive Edge", 0, 2, 0, {
    TargetAllOpponents(
        Remove(SHIELD)
    ),
    TargetSelf(
        IncreaseDamage(50.0, 3, 2)
    ),
    TargetTeam(
        Shield(50.0, 2, 2)
    )
});

Ability GroupDefiniteStrike14BB("Group Definite Strike", 0, 0, 0, {
    TargetAllOpponents(
        Remove(CLOAK|DODGE|SHIELD),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability GroupDevouringImpactC9D9("Group Devouring Impact", 0, 2, 0, {
    TargetAllOpponents(
        Remove(SHIELD),
        DevouringAttack(1.5, 60.0, 2, BYPASS_ARMOR),
        Remove(TAUNT)
    ),
    TargetSelf(
        Cleanse(VULNERABILITY)
    )
});

Ability GroupDisarmingRampage7FC1("Group Disarming Rampage", 0, 2, 0, {
    TargetAllOpponents(
        Attack(2.0),
        ReduceArmor(15.0, 1, 2),
        ReduceDamage(33.0, 2, 4),
        ReduceSpeed(33.0, 2, 4)
    )
});

Ability GroupDistractingRampageA326("Group Distracting Rampage", 1, 2, 0, {
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 4),
        Attack(2.0)
    )
});

Ability GroupDistractionFB00("Group Distraction", 0, 2, 1, {
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 3)
    )
});

Ability GroupFerociousResilientImpact29C3("Group Ferocious Resilient Impact", 0, 1, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetTeam(
        IncreaseDamage(25.0, 1, 2)
    ),
    TargetAllOpponents(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.5),
        ImposeVulnerability(50.0, 2, 1)
    )
});

Ability GroupFerocityC6F7("Group Ferocity", 0, 2, 1, {
    TargetTeam(
        Cleanse(REDUCED_DAMAGE|REDUCED_CRIT_CHANCE),
        IncreaseDamage(50.0, 2, 2)
    )
});

Ability GroupFerocityStrike7A2D("Group Ferocity Strike", 0, 3, 0, {
    TargetTeam(
        IncreaseDamage(50.0, 2, 2)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability GroupFierceStrikeA254("Group Fierce Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetAllOpponents(
        Remove(SHIELD|TAUNT),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability GroupFortifyingImpact9551("Group Fortifying Impact", 0, 2, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(0.5)
    ),
    TargetHighestHP(
        Attack(1.5)
    )
});

Ability GroupHasteningPreciseImpact3620("Group Hastening Precise Impact", 0, 2, 0, {
    TargetTeam(
        IncreaseSpeed(25.0, 2, 4)
    ),
    TargetAllOpponents(
        ReduceSpeed(25.0, 2, 4),
        Attack(1.5, PRECISE)
    )
});

Ability GroupHeal0723("Group Heal", 0, 2, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(1.5)
    )
});

Ability GroupHeavyStrike4F13("Group Heavy Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY|REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Attack(1.0, BYPASS_ARMOR|PRECISE),
        Remove(INCREASED_SPEED)
    )
});

Ability GroupInstantDistractionA5D4("Group Instant Distraction", 0, 2, 1, {
    TargetAllOpponents(
        ReduceDamage(100.0, 1, 2)
    )
});

Ability GroupInstantInvincibility82CC("Group Instant Invincibility", 1, 3, 1, {
    TargetTeam(
        Shield(100.0, 0, 1)
    )
});

Ability GroupMock_BlockAndSockD0AE("Group Mock, Block And Sock", 0, 1, 0, {
    TargetTeam(
        Shield(50.0, 2, 2)
    ),
    TargetSelf(
        Taunt(1)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability GroupPersistenceStrike0246("Group Persistence Strike", 0, 0, 0, {
    TargetTeam(
        IncreaseDamage(25.0, 2, 2)
    ),
    TargetHighestHP(
        Attack(1.0)
    )
});

Ability GroupRampage4077("Group Rampage", 1, 2, 0, {
    TargetAllOpponents(
        Attack(2.0)
    )
});

Ability GroupResilientImpact3AE3("Group Resilient Impact", 0, 1, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.5),
        ImposeVulnerability(50.0, 2, 1)
    )
});

Ability GroupResilientStrike74A6("Group Resilient Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.0),
        ImposeVulnerability(50.0, 2, 1)
    )
});

RevengeAbility GroupRevengeShatteringRampageFCB6("Group Revenge Shattering Rampage", 1, 2, 0, {
    TargetHighestHP(
        Remove(SHIELD)
    ),
    TargetHighestHP(
        Attack(2.0, BYPASS_ARMOR)
    )
}, 0, 2, 0, {
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability GroupShatteringImpact7EAE("Group Shattering Impact", 0, 1, 0, {
    TargetAllOpponents(
        Remove(SHIELD|TAUNT),
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability GroupShatteringRampageA42F("Group Shattering Rampage", 1, 2, 0, {
    TargetAllOpponents(
        Remove(SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability GroupShatteringRegeneratingImpact1CE9("Group Shattering Regenerating Impact", 0, 1, 0, {
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(1.5, BYPASS_ARMOR)
    ),
    TargetSelf(
        Heal(0.5)
    )
});

Ability GroupShatteringStrikeF634("Group Shattering Strike", 0, 0, 0, {
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(1.0),
        ImposeVulnerability(50.0, 2, 2)
    )
});

Ability GroupShield54BA("Group Shield", 0, 1, 1, {
    TargetTeam(
        Shield(50.0, 2, 2)
    )
});

Ability GroupStrikeC21E("Group Strike", 0, 0, 0, {
    TargetAllOpponents(
        Attack(1.0)
    )
});

Ability GroupStunningSlowingImpactBC3F("Group Stunning Slowing Impact", 0, 1, 0, {
    TargetAllOpponents(
        Attack(1.75),
        ReduceSpeed(50.0, 2, 4),
        Stun(100.0, 1)
    )
});

Ability GroupTakedown066E("Group Takedown", 1, 2, 1, {
    TargetTeam(
        Cleanse(REDUCED_DAMAGE|REDUCED_CRIT_CHANCE),
        IncreaseDamage(50.0, 2, 1)
    )
});

Ability GroupTauntingShieldsEB4C("Group Taunting Shields", 0, 1, 1, {
    TargetTeam(
        Shield(50.0, 2, 2)
    ),
    TargetSelf(
        Taunt(1)
    )
});

Ability GroupTauntingShieldsStrikeDA58("Group Taunting Shields Strike", 0, 1, 0, {
    TargetTeam(
        Shield(50.0, 2, 2)
    ),
    TargetSelf(
        Taunt(1)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability GroupWarningSqueal0E5A("Group Warning Squeal", 0, 3, 1, {
    TargetTeam(
        Shield(50.0, 2, 4),
        IncreaseCritChance(20.0, 2, 2),
        IncreaseDamage(25.0, 2, 4)
    ),
    TargetFastest(
        ReduceSpeed(50.0, 2, 0)
    )
});

Ability Harden1485("Harden", 0, 2, 0, {
    TargetHighestHP(
        Attack(1.5)
    ),
    TargetTeam(
        IncreaseArmor(50.0, 2, 4)
    ),
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    )
});

Ability HasteningShelter3D24("Hastening Shelter", 0, 2, 1, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        FixedHeal(66.0),
        IncreaseSpeed(50.0, 2, 4),
        Shield(75.0, 2, 2)
    )
});

Ability HeadToHead1ABD("Head To Head", 2, 1, 0, {
    TargetFastest(
        ReduceSpeed(50.0, 2, 4)
    ),
    TargetFastest(
        Attack(2.5, PRECISE)
    ),
    TargetSelf(
        ReduceSpeed(50.0, 2, 2),
        Stun(25.0, 1)
    )
});

Ability HealA906("Heal", 0, 3, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(1.5)
    )
});

Ability HealingBellow73D3("Healing Bellow", 0, 2, 1, {
    TargetTeam(
        Cleanse(REDUCED_SPEED),
        Heal(0.5),
        Shield(50.0, 2, 4)
    ),
    TargetSelf(
        Taunt(1)
    ),
    TargetFastest(
        ReduceSpeed(50.0, 2, 0)
    )
});

Ability HealingDecimationCED6("Healing Decimation", 1, 2, 0, {
    TargetSelf(
        RallyHeal(10.0)
    ),
    TargetFastest(
        Remove(DODGE)
    ),
    TargetFastest(
        Remove(CLOAK)
    ),
    TargetFastest(
        ReduceArmor(10.0, 2, 4)
    ),
    TargetFastest(
        Attack(2.5)
    )
});

Ability HealingFierceStrike4869("Healing Fierce Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.0, BYPASS_ARMOR)
    ),
    TargetSelf(
        Heal(0.5)
    )
});

Ability HealingSuperiorityStrike0C0B("Healing Superiority Strike", 0, 0, 0, {
    TargetTeam(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        ReduceSpeed(50.0, 1, 0),
        Attack(1.0, PRECISE)
    ),
    TargetTeam(
        Heal(1.0)
    )
});

Ability HeavyClawsFFF3("Heavy Claws", 0, 2, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY|REDUCED_DAMAGE)
    ),
    TargetLowestHP(
        Attack(1.0, BYPASS_ARMOR|PRECISE),
        Attack(1.0, BYPASS_ARMOR|PRECISE),
        Remove(INCREASED_SPEED)
    )
});

Ability HeavyStrike5748("Heavy Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY|REDUCED_DAMAGE)
    ),
    TargetLowestHP(
        Attack(1.0, BYPASS_ARMOR|PRECISE),
        Remove(INCREASED_SPEED)
    )
});

Ability HerdSentinelB67B("Herd Sentinel", 0, 3, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        FixedHeal(50.0)
    ),
    TargetAllOpponents(
        Remove(CLOAK|INCREASED_DAMAGE),
        ReduceSpeed(50.0, 2, 4)
    )
});

Ability HighPounceD062("High Pounce", 0, 1, 0, {
    TargetHighestDamage(
        Attack(2.0),
        ReduceDamage(50.0, 1, 2)
    )
});

Ability HopAndMockD6D1("Hop And Mock", 0, 1, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(75.0, 67.0, 0, 2)
    ),
    TargetMostPositiveEffects(
        Remove(POSITIVE_EFFECTS)
    ),
    TargetSelf(
        Taunt(1)
    )
});

Ability HornedDevour10A1("Horned Devour", 0, 2, 0, {
    TargetLowestHP(
        DevouringAttack(2.0, 50.0, 4, BYPASS_ARMOR|PRECISE)
    ),
    TargetSelf(
        Shield(50.0, 2, 4)
    )
});

Ability HostileGlow1021("Hostile Glow", 0, 2, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        ImposeVulnerability(50.0, 2, 1),
        Attack(1.5)
    ),
    TargetTeam(
        Shield(50.0, 2, 2)
    ),
    TargetSelf(
        Taunt(2)
    )
});

Ability HowlEBEA("Howl", 0, 3, 1, {
    TargetTeam(
        IncreaseDamage(30.0, 3, 6),
        IncreaseSpeed(20.0, 3, 6)
    )
});

Ability ImminentStampede7426("Imminent Stampede", 0, 2, 1, {
    TargetTeam(
        Cleanse(REDUCED_SPEED),
        IncreaseSpeed(50.0, 2, 0)
    ),
    TargetSelf(
        IncreaseDamage(50.0, 2, 2)
    )
});

Ability ImmobilizeEA4E("Immobilize", 0, 2, 1, {
    TargetFastest(
        Stun(100.0, 1),
        UnableToSwap(2),
        Attack(1.5)
    )
});

Ability ImmobilizingImpact43FC("Immobilizing Impact", 0, 1, 1, {
    TargetFastest(
        ReduceSpeed(75.0, 2, 4),
        Remove(SHIELD),
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability ImpactA82F("Impact", 0, 1, 0, {
    TargetLowestHP(
        Attack(1.5)
    )
});

Ability ImpactAndRun738D("Impact And Run", 1, 1, 0, {
    TargetLowestHP(
        Attack(1.5)
    ),
    TargetSelf(
        Swap()
    )
});

Ability InstantAfflictingDistractionFDA3("Instant Afflicting Distraction", 0, 2, 1, {
    TargetHighestDamage(
        Affliction(50.0, 2, 4)
    ),
    TargetHighestDamage(
        ReduceDamage(100.0, 1, 2)
    )
});

Ability InstantAmbushD57D("Instant Ambush", 0, 2, 1, {
    TargetSelf(
        IncreaseSpeed(30.0, 2, 0),
        Dodge(75.0, 67.0, 1, 2)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2)
    ),
    TargetSelf(
        IncreaseCritChance(50.0, 2, 2)
    )
});

Ability InstantArmoredDeflection6FB3("Instant Armored Deflection", 0, 1, 1, {
    TargetSelf(
        Shield(75.0, 1, 2),
        IncreaseArmor(25.0, 2, 4)
    )
});

Ability InstantBuff41DC("Instant Buff", 0, 1, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseSpeed(10.0, 2, 0),
        IncreaseDamage(50.0, 2, 1),
        Dodge(100.0, 67.0, 0, 2)
    )
});

Ability InstantCharge0917("Instant Charge", 1, 2, 1, {
    TargetHighestDamage(
        Attack(1.0),
        Stun(75.0, 1)
    )
});

Ability InstantChargingImpact7672("Instant Charging Impact", 1, 2, 1, {
    TargetHighestDamage(
        Attack(1.5),
        Stun(75.0, 1)
    )
});

Ability InstantCriticalImpact7F22("Instant Critical Impact", 0, 2, 1, {
    TargetLowestHP(
        Attack(1.5, ALWAYS_CRITS)
    )
});

Ability InstantCrush1C8F("Instant Crush", 1, 3, 1, {
    TargetAllOpponents(
        ImposeVulnerability(50.0, 2, 4),
        Attack(2.5, PRECISE),
        ReduceSpeed(50.0, 2, 4)
    )
});

Ability InstantDebilitatingShieldImpactC185("Instant Debilitating Shield Impact", 0, 2, 1, {
    TargetHighestDamage(
        ReduceDamage(75.0, 2, 4),
        Attack(1.5)
    ),
    TargetSelf(
        Shield(50.0, 2, 4)
    )
});

Ability InstantDeceleratingDistraction2B7F("Instant Decelerating Distraction", 0, 1, 1, {
    TargetHighestDamage(
        ReduceDamage(100.0, 1, 2),
        ReduceSpeed(50.0, 1, 0)
    )
});

Ability InstantDeceleratingPrecision323A("Instant Decelerating Precision", 0, 0, 1, {
    TargetSelf(
        Shield(50.0, 1, 4)
    ),
    TargetFastest(
        ReduceSpeed(50.0, 3, 3)
    ),
    TargetFastest(
        Attack(1.0, PRECISE)
    )
});

Ability InstantDefenseShatteringStrikeB62F("Instant Defense Shattering Strike", 0, 0, 1, {
    TargetHighestHP(
        Remove(SHIELD)
    ),
    TargetHighestHP(
        Attack(1.0)
    )
});

Ability InstantDeviousStrike33EA("Instant Devious Strike", 0, 0, 1, {
    TargetSelf(
        Dodge(75.0, 67.0, 1, 2),
        IncreaseCritChance(30.0, 2, 2)
    ),
    TargetLowestHP(
        Attack(1.0),
        ReduceDamage(25.0, 2, 4)
    )
});

Ability InstantDistractingStrikeF18F("Instant Distracting Strike", 0, 0, 1, {
    TargetHighestDamage(
        ReduceDamage(33.0, 1, 2),
        Attack(1.0)
    )
});

Ability InstantDistractionF5AC("Instant Distraction", 0, 1, 1, {
    TargetHighestDamage(
        ReduceDamage(100.0, 1, 2)
    )
});

Ability InstantDodgeImpact4070("Instant Dodge Impact", 0, 1, 1, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        Attack(1.5),
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE)
    ),
    TargetSelf(
        Dodge(75.0, 67.0, 0, 2)
    )
});

RevengeAbility InstantFerociousRevenge3D5C("Instant Ferocious Revenge", 1, 2, 1, {
    TargetSelf(
        IncreaseDamage(50.0, 2, 2)
    ),
    TargetLowestHP(
        Attack(1.5)
    )
}, 0, 2, 1, {
    TargetSelf(
        IncreaseDamage(50.0, 2, 2)
    ),
    TargetLowestHP(
        Attack(1.5)
    )
});

Ability InstantFierceRampage6114("Instant Fierce Rampage", 1, 1, 1, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetHighestHP(
        Remove(SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability InstantGroupDistractionImpactC757("Instant Group Distraction Impact", 1, 2, 1, {
    TargetAllOpponents(
        Attack(1.5),
        ReduceDamage(50.0, 1, 2)
    )
});

Ability InstantInvincibility9B21("Instant Invincibility", 1, 3, 1, {
    TargetSelf(
        Shield(100.0, 0, 2)
    )
});

Ability InstantInvincibilityTaunt6C65("Instant Invincibility Taunt", 1, 2, 1, {
    TargetSelf(
        Shield(100.0, 0, 2),
        Taunt(1)
    )
});

Ability InstantNullifyingStrike1708("Instant Nullifying Strike", 0, 0, 1, {
    TargetMostPositiveEffects(
        Remove(POSITIVE_EFFECTS),
        Attack(1.0)
    )
});

Ability InstantPreciseImpact5A71("Instant Precise Impact", 0, 1, 1, {
    TargetFastest(
        Attack(1.5, BYPASS_ARMOR|PRECISE)
    )
});

Ability InstantRampageC258("Instant Rampage", 0, 2, 1, {
    TargetLowestHP(
        Attack(2.0)
    )
});

Ability InstantRend0585("Instant Rend", 1, 1, 1, {
    TargetMostPositiveEffects(
        Remove(SHIELD),
        Rend(60.0, BYPASS_ARMOR)
    )
});

Ability InstantResilientStrikeB7E8("Instant Resilient Strike", 0, 0, 1, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.0),
        ImposeVulnerability(50.0, 2, 1)
    )
});

Ability InstantRumble2784("Instant Rumble", 0, 3, 1, {
    TargetSelf(
        Shield(50.0, 0, 4),
        IncreaseCritChance(20.0, 2, 2),
        IncreaseDamage(25.0, 2, 4)
    ),
    TargetFastest(
        ReduceSpeed(50.0, 2, 0)
    )
});

Ability InstantShieldedFerocityAD15("Instant Shielded Ferocity", 0, 0, 1, {
    TargetSelf(
        IncreaseDamage(50.0, 2, 2),
        Shield(50.0, 2, 4)
    ),
    TargetFastest(
        Attack(1.0)
    )
});

Ability InstantShieldedStrike3368("Instant Shielded Strike", 0, 0, 1, {
    TargetHighestDamage(
        Attack(1.0)
    ),
    TargetSelf(
        Shield(50.0, 1, 2),
        FixedHeal(10.0)
    )
});

Ability InstantStunningImpact4833("Instant Stunning Impact", 1, 2, 1, {
    TargetHighestDamage(
        Attack(1.5),
        Stun(75.0, 1)
    )
});

RevengeAbility InstantStunningRevengeImpactCFDA("Instant Stunning Revenge Impact", 0, 1, 1, {
    TargetHighestDamage(
        Attack(1.75, PRECISE),
        Stun(100.0, 1)
    )
}, 0, 1, 1, {
    TargetAllOpponents(
        Attack(1.75, PRECISE),
        Stun(100.0, 1)
    ),
    TargetSelf(
        Shield(100.0, 1, 2)
    )
});

Ability InstantStunningStrikeEA34("Instant Stunning Strike", 0, 3, 1, {
    TargetHighestDamage(
        Attack(1.0),
        Stun(75.0, 1)
    )
});

Ability InterruptingImpact42F9("Interrupting Impact", 0, 1, 0, {
    TargetMostPositiveEffects(
        Remove(CLOAK)
    ),
    TargetMostPositiveEffects(
        Remove(DODGE)
    ),
    TargetMostPositiveEffects(
        Attack(1.5),
        ReduceSpeed(25.0, 2, 2)
    )
});

Ability Intimidate52C1("Intimidate", 1, 2, 1, {
    TargetFastest(
        ReduceSpeed(50.0, 2, 0)
    ),
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseDamage(25.0, 2, 4),
        IncreaseArmor(25.0, 2, 4)
    )
});

Ability IntimidatingImpact50F9("Intimidating Impact", 0, 1, 0, {
    TargetLowestHP(
        Remove(SHIELD),
        Attack(1.5, BYPASS_ARMOR),
        ImposeVulnerability(50.0, 1, 2)
    )
});

ThreatenedAbility InvincibleAlert449E("Invincible Alert", 0, 2, 0, {
    TargetSelf(
        Shield(100.0, 1, 8)
    ),
    TargetFastest(
        Remove(DODGE|INCREASED_SPEED|CLOAK)
    ),
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    )
}, 50, ThreatComparison::Lower, 0, 3, 0, {
    TargetSelf(
        Shield(100.0, 2, 8)
    ),
    TargetFastest(
        ReduceSpeed(50.0, 1, 2),
        ImposeVulnerability(50.0, 1, 2)
    )
});

Ability InvulnerableDevourImpactAB87("Invulnerable Devour Impact", 0, 1, 0, {
    TargetAllOpponents(
        Remove(SHIELD),
        DevouringAttack(1.5, 60.0, 2, BYPASS_ARMOR),
        Remove(TAUNT)
    ),
    TargetSelf(
        Cleanse(VULNERABILITY)
    )
});

Ability JabAndWeaveF9E7("Jab And Weave", 0, 1, 1, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        ReduceSpeed(50.0, 2, 4),
        Attack(1.0),
        Attack(1.0)
    ),
    TargetSelf(
        Dodge(75.0, 67.0, 0, 4)
    )
});

Ability KillerInstinct3E33("Killer Instinct", 0, 1, 1, {
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.5, BYPASS_ARMOR)
    )
});

Ability Lacerate372D("Lacerate", 0, 3, 0, {
    TargetHighestHP(
        Attack(1.33),
        DamageOverTime(25.0, 4)
    )
});

Ability LeadingChargeF1FA("Leading Charge", 0, 2, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Attack(2.0)
    ),
    TargetTeam(
        IncreaseSpeed(25.0, 2, 4),
        IncreaseDamage(25.0, 2, 4),
        Shield(25.0, 2, 4)
    )
});

Ability LesserEmergencyHealE329("Lesser Emergency Heal", 0, 2, 1, {
    TargetLowestHPTeammate(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(1.0)
    )
});

Ability LesserFierceDeceleratingStrike2F7B("Lesser Fierce Decelerating Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.0, BYPASS_ARMOR),
        ReduceSpeed(50.0, 1, 2)
    )
});

Ability LesserGroupDeceleratingRampage52DB("Lesser Group Decelerating Rampage", 0, 2, 0, {
    TargetAllOpponents(
        ReduceSpeed(50.0, 2, 2),
        Attack(2.0)
    )
});

Ability LesserGroupHeal5491("Lesser Group Heal", 0, 2, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(1.0)
    )
});

Ability LesserRendingAttack85FA("Lesser Rending Attack", 0, 0, 0, {
    TargetHighestHP(
        Remove(SHIELD),
        Rend(25.0, BYPASS_ARMOR)
    )
});

CounterAbility LesserWoundingCounter7BC3("Lesser Wounding Counter", {
    TargetAttacker(
        DamageOverTime(20.0, 1),
        ImposeVulnerability(50.0, 2, 4)
    )
});

Ability LethalQuillShotF007("Lethal Quill Shot", 1, 2, 0, {
    TargetHighestDamage(
        Attack(1.5),
        ReduceDamage(50.0, 2, 4),
        DamageOverTime(25.0, 2)
    )
});

Ability LethalRampageAndRun204F("Lethal Rampage And Run", 2, 2, 0, {
    TargetHighestDamage(
        Remove(SHIELD),
        Attack(2.0, BYPASS_ARMOR),
        DamageOverTime(33.41, 2)
    ),
    TargetSelf(
        Swap()
    )
});

Ability LethalWound98A0("Lethal Wound", 0, 2, 0, {
    TargetHighestHP(
        Attack(1.0),
        DamageOverTime(33.41, 3)
    )
});

Ability LightspeedChargeAndRun96DD("Lightspeed Charge And Run", 1, 3, 0, {
    TargetSlowest(
        ReduceDamage(50.0, 2, 4)
    ),
    TargetSlowest(
        Stun(75.0, 1),
        DamageOverTime(34.0, 2)
    ),
    TargetSlowest(
        Attack(1.5)
    ),
    TargetSelf(
        Shield(100.0, 1, 2),
        Swap()
    )
});

Ability LimitedEvasiveStrike6F07("Limited Evasive Strike", 0, 1, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        Dodge(75.0, 67.0, 2, 4)
    )
});

Ability LingeringFerociousStrike7A11("Lingering Ferocious Strike", 0, 1, 0, {
    TargetSelf(
        IncreaseDamage(20.0, 2, 4),
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(TAUNT)
    ),
    TargetLowestHP(
        Remove(SHIELD)
    ),
    TargetLowestHP(
        Attack(1.0, BYPASS_ARMOR)
    ),
    TargetLowestHP(
        DamageOverTime(15.0, 1)
    )
});

Ability LingeringFerocityD91F("Lingering Ferocity", 0, 2, 0, {
    TargetSelf(
        IncreaseDamage(100.0, 3, 6),
        IncreaseArmor(30.0, 2, 4)
    ),
    TargetHighestHP(
        UnableToSwap(2)
    )
});

Ability LingeringResilientImpact1971("Lingering Resilient Impact", 0, 2, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE)
    ),
    TargetFastest(
        Remove(CLOAK)
    ),
    TargetFastest(
        Remove(INCREASED_SPEED)
    ),
    TargetFastest(
        Attack(1.5)
    ),
    TargetFastest(
        ImposeVulnerability(50.0, 2, 2),
        DamageOverTime(33.41, 1)
    )
});

Ability LockdownDefiniteStrikeC9F1("Lockdown Definite Strike", 0, 0, 0, {
    TargetMostPositiveEffects(
        Remove(CLOAK|DODGE|SHIELD),
        Attack(1.0, BYPASS_ARMOR)
    ),
    TargetMostPositiveEffects(
        UnableToSwap(1)
    )
});

Ability LockdownPressure62CB("Lockdown Pressure", 0, 2, 0, {
    TargetLowestHP(
        Affliction(40.0, 1, 2)
    ),
    TargetLowestHP(
        Remove(INCREASED_DAMAGE)
    ),
    TargetLowestHP(
        Remove(INCREASED_SPEED)
    ),
    TargetLowestHP(
        ReduceDamage(50.0, 2, 4)
    ),
    TargetLowestHP(
        ReduceSpeed(50.0, 2, 0)
    ),
    TargetLowestHP(
        UnableToSwap(2)
    ),
    TargetSelf(
        UnableToSwap(2)
    )
});

Ability LongDeceleratingStrike7953("Long Decelerating Strike", 0, 0, 0, {
    TargetFastest(
        ReduceSpeed(50.0, 2, 0),
        Attack(1.0)
    )
});

Ability LongDefenseStrike1237("Long Defense Strike", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        Shield(50.0, 2, 2)
    )
});

Ability LongInvincibilityBB2D("Long Invincibility", 0, 3, 0, {
    TargetSelf(
        Shield(100.0, 3, 2)
    )
});

Ability LongProtection8331("Long Protection", 0, 3, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        Shield(50.0, 4, 4)
    )
});

CounterAbility LuringCounterStrike24B8("Luring Counter Strike", {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE),
        IncreaseDamage(25.0, 1, 1)
    ),
    TargetAttacker(
        Remove(DODGE),
        Attack(1.0)
    )
});

Ability MagnaImpact79A2("Magna Impact", 0, 2, 0, {
    TargetMostPositiveEffects(
        Remove(POSITIVE_EFFECTS)
    ),
    TargetMostPositiveEffects(
        ReduceDamage(50.0, 1, 2),
        Attack(1.5, BYPASS_ARMOR|ALWAYS_CRITS)
    )
});

Ability MaimingWoundFC48("Maiming Wound", 0, 2, 0, {
    TargetHighestHP(
        Attack(1.0),
        DamageOverTime(40.0, 2)
    )
});

Ability MaternalRoar86DC("Maternal Roar", 0, 2, 0, {
    TargetTeam(
        IncreaseCritChance(75.0, 2, 2)
    ),
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(2.0)
    )
});

CounterAbility MaximalCounter_attack5683("Maximal Counter-Attack", {
    TargetAttacker(
        Attack(1.0)
    )
});

Ability MaximumFerocity2FCC("Maximum Ferocity", 1, 2, 1, {
    TargetSelf(
        IncreaseDamage(75.0, 2, 4),
        Shield(50.0, 2, 2)
    ),
    TargetHighestHP(
        DamageOverTime(40.0, 2)
    ),
    TargetSelf(
        Cleanse(REDUCED_DAMAGE),
        Heal(1.5)
    )
});

CounterAbility MediumCounter_attackE4A7("Medium Counter-Attack", {
    TargetAttacker(
        Attack(0.5)
    )
});

CounterAbility MediumNullifyingCounter4816("Medium Nullifying Counter", {
    TargetAttacker(
        Remove(POSITIVE_EFFECTS),
        Attack(0.5)
    )
});

CounterAbility MediumResilientCounter_attack3EB5("Medium Resilient Counter-Attack", {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAttacker(
        Remove(CLOAK|DODGE),
        Attack(0.5),
        ImposeVulnerability(50.0, 2, 1)
    )
});

ThreatenedAbility MercilessAlert571C("Merciless Alert", 0, 1, 0, {
    TargetHighestHP(
        Attack(1.5, BYPASS_ARMOR),
        DamageOverTime(15.0, 3)
    )
}, 50, ThreatComparison::Lower, 0, 1, 0, {
    TargetLowestHP(
        Attack(1.0, BYPASS_ARMOR),
        DamageOverTime(30.0, 3)
    ),
    TargetSelf(
        Swap()
    )
});

CounterAbility MinimalCounterStrikeFFAB("Minimal Counter Strike", {
    TargetAttacker(
        Attack(0.5),
        ImposeVulnerability(50.0, 2, 4),
        ReduceSpeed(50.0, 2, 4)
    )
});

CounterAbility MinimalCriticalCounterECF3("Minimal Critical Counter", {
    TargetSelf(
        IncreaseCritChance(5.0, 3, 3)
    )
});

Ability MinimalSpeedupStrike44A5("Minimal Speedup Strike", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        IncreaseSpeed(10.0, 3, 0)
    )
});

CounterAbility MinorCriticalCounterE7FC("Minor Critical Counter", {
    TargetSelf(
        IncreaseCritChance(30.0, 3, 3)
    )
});

CounterAbility MinorDeceleratingCounter076E("Minor Decelerating Counter", {
    TargetAttacker(
        Attack(0.25),
        ReduceSpeed(50.0, 1, 2)
    )
});

CounterAbility MinorFerociourCounter76B6("Minor Ferociour Counter", {
    TargetSelf(
        Cleanse(VULNERABILITY),
        IncreaseDamage(25.0, 2, 4)
    ),
    TargetAttacker(
        Remove(TAUNT|SHIELD),
        Attack(0.25, BYPASS_ARMOR)
    )
});

ThreatenedCounterAbility MinorHealingCounter5330("Minor Healing Counter", {
    TargetAttacker(
        Attack(0.5)
    ),
    TargetSelf(
        FixedHeal(5.0)
    )
}, 33, ThreatComparison::Lower, {
    TargetAttacker(
        Attack(0.5)
    ),
    TargetSelf(
        RallyHeal(10.0)
    )
});

CounterAbility MinorPreciseCounterA27F("Minor Precise Counter", {
    TargetAttacker(
        Attack(0.25, PRECISE)
    )
});

Ability MinorRendingAttackEE1F("Minor Rending Attack", 0, 0, 0, {
    TargetLowestHP(
        Remove(SHIELD),
        Rend(34.0, BYPASS_ARMOR)
    )
});

Ability MinorRendingLockdown18B8("Minor Rending Lockdown", 0, 0, 0, {
    TargetLowestHP(
        Remove(SHIELD),
        Rend(34.0, BYPASS_ARMOR),
        UnableToSwap(1)
    )
});

Ability MinorSwoop6A00("Minor Swoop", 1, 2, 0, {
    TargetHighestHP(
        DamageOverTime(20.0, 3)
    ),
    TargetSelf(
        Swap()
    )
});

Ability MutualFury2752("Mutual Fury", 0, 1, 0, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseDamage(50.0, 3, 2),
        IncreaseSpeed(10.0, 2, 0)
    ),
    TargetAllOpponents(
        IncreaseDamage(50.0, 2, 1)
    )
});

Ability NecroticImpactBA62("Necrotic Impact", 0, 2, 0, {
    TargetLowestHP(
        Remove(POSITIVE_EFFECTS),
        DevouringAttack(1.5, 50.0, 2, BYPASS_ARMOR)
    )
});

CounterAbility NullifyingCounter3724("Nullifying Counter", {
    TargetAttacker(
        Remove(POSITIVE_EFFECTS)
    )
});

Ability NullifyingGroupImpactBA4B("Nullifying Group Impact", 0, 2, 0, {
    TargetSelf(
        IncreaseArmor(25.0, 2, 4)
    ),
    TargetAllOpponents(
        Remove(POSITIVE_EFFECTS),
        Attack(1.5)
    )
});

Ability NullifyingImpact65A2("Nullifying Impact", 0, 2, 0, {
    TargetMostPositiveEffects(
        Remove(POSITIVE_EFFECTS),
        Attack(1.5)
    )
});

Ability NullifyingRampage11B6("Nullifying Rampage", 1, 2, 0, {
    TargetMostPositiveEffects(
        Remove(POSITIVE_EFFECTS),
        Attack(2.0)
    )
});

Ability NullifyingStrike38B2("Nullifying Strike", 0, 0, 0, {
    TargetMostPositiveEffects(
        Remove(POSITIVE_EFFECTS),
        Attack(1.0)
    )
});

Ability ObstructingFierceImpact9462("Obstructing Fierce Impact", 0, 1, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD),
        Attack(1.5, BYPASS_ARMOR),
        Remove(TAUNT),
        UnableToSwap(1)
    )
});

Ability OffensiveStance5250("Offensive Stance", 0, 0, 1, {
    TargetSelf(
        Cleanse(VULNERABILITY|REDUCED_DAMAGE|REDUCED_SPEED),
        Dodge(75.0, 66.69998, 2, 4),
        IncreaseDamage(25.0, 2, 4),
        IncreaseCritChance(33.0, 2, 4)
    )
});

Ability OverwhelmingImpact226E("Overwhelming Impact", 0, 2, 0, {
    TargetLowestHP(
        Remove(SHIELD)
    ),
    TargetLowestHP(
        DevouringAttack(1.5, 60.0, 2, BYPASS_ARMOR)
    ),
    TargetLowestHP(
        Affliction(40.0, 1, 2)
    ),
    TargetLowestHP(
        Stun(75.0, 1)
    ),
    TargetLowestHP(
        DamageOverTime(20.0, 2)
    )
});

Ability PaybackRampage4545("Payback Rampage", 0, 2, -1, {
    TargetHighestHP(
        Attack(2.5)
    ),
    TargetSelf(
        IncreaseArmor(50.0, 2, 4),
        Heal(1.0),
        UnableToSwap(1)
    )
});

CounterAbility PersistentCounter25A1("Persistent Counter", {
    TargetTeam(
        IncreaseDamage(10.0, 2, 2)
    )
});

Ability PersistentFerociousStrikeAF52("Persistent Ferocious Strike", 0, 0, 0, {
    TargetSelf(
        IncreaseDamage(50.0, 2, 2)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

CounterAbility PiercingCounterNullification55E0("Piercing Counter Nullification", {
    TargetAttacker(
        Remove(POSITIVE_EFFECTS),
        Attack(0.666, BYPASS_ARMOR)
    )
});

CounterAbility PiercingCounterStrikeA03C("Piercing Counter Strike", {
    TargetSelf(
        IncreaseDamage(25.0, 2, 4)
    ),
    TargetAttacker(
        Attack(1.0, BYPASS_ARMOR|PRECISE)
    )
});

CounterAbility PiercingHeadbuttF80E("Piercing Headbutt", {
    TargetNone(
        Attack(1.0, BYPASS_ARMOR|PRECISE)
    ),
    TargetSelf(
        IncreaseArmor(10.0, 1, 2),
        IncreaseDamage(10.0, 2, 2)
    )
});

RevengeAbility PiercingRevengeD39D("Piercing Revenge", 1, 1, 0, {
    TargetHighestHP(
        Remove(SHIELD),
        Rend(40.0, BYPASS_ARMOR),
        UnableToSwap(2)
    )
}, 0, 1, 1, {
    TargetHighestHP(
        Remove(SHIELD),
        Rend(40.0, BYPASS_ARMOR),
        UnableToSwap(2)
    )
});

Ability PiercingScreechB4D7("Piercing Screech", 0, 3, 1, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        IncreaseSpeed(10.0, 1, 0),
        IncreaseCritChance(20.0, 2, 4)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 4),
        ReduceArmor(20.0, 2, 4)
    )
});

Ability PinningStrike3832("Pinning Strike", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.0),
        UnableToSwap(2)
    )
});

Ability PlayfulPounce7B7E("Playful Pounce", 0, 2, 0, {
    TargetSelf(
        IncreaseSpeed(20.0, 2, 0),
        Dodge(50.0, 66.69998, 1, 1),
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetLowestHP(
        Attack(2.0),
        ReduceDamage(50.0, 1, 2)
    )
});

CounterAbility PoisonCounterFC4D("Poison Counter", {
    TargetAttacker(
        DamageOverTime(20.0, 1)
    )
});

Ability PounceAndBite8E57("Pounce And Bite", 0, 1, 0, {
    TargetLowestHP(
        Attack(1.5)
    ),
    TargetLowestHP(
        Attack(1.5),
        ReduceDamage(50.0, 1, 2)
    )
});

CounterAbility PowerfulCounterHeal16F3("Powerful Counter Heal", {
    TargetSelf(
        Heal(1.0)
    )
});

Ability PreciseAfflictingRampageC6D1("Precise Afflicting Rampage", 0, 1, 0, {
    TargetMostPositiveEffects(
        Affliction(15.0, 2, 4),
        Attack(2.0, PRECISE)
    )
});

CounterAbility PreciseCounterDFAC("Precise Counter", {
    TargetAttacker(
        Attack(1.0, PRECISE)
    )
});

Ability PreciseDeceleratingRampageB02E("Precise Decelerating Rampage", 0, 1, 0, {
    TargetLowestHP(
        ReduceSpeed(50.0, 2, 4),
        Attack(2.0, PRECISE)
    )
});

Ability PreciseDevouringRampage3852("Precise Devouring Rampage", 0, 2, 0, {
    TargetAllOpponents(
        ReduceDamage(25.0, 2, 4),
        ReduceSpeed(25.0, 2, 4)
    ),
    TargetHighestDamage(
        DevouringAttack(2.0, 50.0, 2, PRECISE)
    )
});

Ability PreciseDispiritingRampage0073("Precise Dispiriting Rampage", 0, 2, 0, {
    TargetLowestHP(
        Attack(2.0, PRECISE)
    ),
    TargetAllOpponents(
        ReduceDamage(25.0, 2, 4),
        ReduceSpeed(25.0, 2, 4)
    )
});

Ability PreciseDistractingImpact90A3("Precise Distracting Impact", 0, 1, 0, {
    TargetLowestHP(
        Attack(1.5, PRECISE),
        ReduceDamage(50.0, 1, 2)
    )
});

Ability PreciseDoubleStrike2357("Precise Double Strike", 0, 1, 0, {
    TargetMostPositiveEffects(
        Attack(1.0, PRECISE),
        Attack(1.0, PRECISE)
    )
});

CounterAbility PreciseGroupCounter7420("Precise Group Counter", {
    TargetAllOpponents(
        Attack(1.0, PRECISE)
    ),
    TargetSelf(
        IncreaseArmor(10.0, 2, 4)
    )
});

Ability PreciseGroupDistractingImpact6DF1("Precise Group Distracting Impact", 0, 2, 0, {
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 4),
        Attack(1.5, PRECISE)
    )
});

Ability PreciseGroupSlowingImpact7F84("Precise Group Slowing Impact", 0, 1, 0, {
    TargetAllOpponents(
        Attack(1.5, PRECISE),
        ReduceSpeed(50.0, 3, 0)
    )
});

Ability PreciseImpact9D87("Precise Impact", 0, 1, 0, {
    TargetLowestHP(
        Attack(1.5, PRECISE)
    )
});

Ability PreciseImpactAndRunF059("Precise Impact And Run", 1, 1, 0, {
    TargetLowestHP(
        Attack(1.5, PRECISE)
    ),
    TargetSelf(
        Swap()
    )
});

CounterAbility PrecisePiercingStrike5679("Precise Piercing Strike", {
    TargetAttacker(
        Attack(1.0, BYPASS_ARMOR|PRECISE)
    )
});

Ability PrecisePiercingStrike93AA("Precise Piercing Strike", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.0, BYPASS_ARMOR|PRECISE)
    )
});

Ability PrecisePounceF675("Precise Pounce", 0, 1, 0, {
    TargetLowestHP(
        Attack(2.0, PRECISE),
        ReduceDamage(50.0, 1, 2)
    )
});

Ability PreciseRampageA036("Precise Rampage", 0, 1, 0, {
    TargetLowestHP(
        Attack(2.0, PRECISE)
    )
});

RevengeAbility PreciseRevenge51B4("Precise Revenge", 0, 1, 0, {
    TargetLowestHP(
        Attack(2.0, PRECISE)
    )
}, 0, 1, 0, {
    TargetAllOpponents(
        Attack(2.0, PRECISE)
    )
});

CounterAbility PreciseShatteringCounter4D03("Precise Shattering Counter", {
    TargetAttacker(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR|PRECISE)
    )
});

Ability PredatoryPeck7590("Predatory Peck", 0, 0, 0, {
    TargetSelf(
        IncreaseSpeed(10.0, 2, 0)
    ),
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        Dodge(75.0, 67.0, 1, 2)
    )
});

Ability PrimalBraceF81C("Primal Brace", 0, 0, 1, {
    TargetSelf(
        Shield(50.0, 0, 2),
        IncreaseDamage(50.0, 2, 2)
    )
});

Ability ProtectTheHerdC716("Protect The Herd", 0, 0, 0, {
    TargetTeam(
        Dodge(75.0, 66.69998, 2, 4),
        IncreaseArmor(25.0, 2, 0),
        Shield(25.0, 2, 4),
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability ProtectiveAdvanceCA82("Protective Advance", 0, 0, 1, {
    TargetFastest(
        Attack(1.0)
    ),
    TargetSelf(
        Shield(50.0, 1, 2),
        IncreaseArmor(15.0, 1, 2)
    )
});

ThreatenedAbility ProtectiveAlert2FA4("Protective Alert", 0, 3, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetAllOpponents(
        ImposeVulnerability(50.0, 2, 4),
        ReduceDamage(50.0, 2, 4)
    )
}, 66, ThreatComparison::Lower, 0, 3, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        RallyHeal(33.33333)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 4)
    )
});

Ability Prowl38DE("Prowl", 0, 0, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(75.0, 67.0, 0, 2),
        IncreaseCritChance(50.0, 3, 2)
    )
});

RevengeAbility ProwlingRevengeCloakC144("Prowling Revenge Cloak", 0, 3, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Cloak(2.0, 75.0, 66.66659, 2, 0)
    ),
    TargetFastest(
        ReduceSpeed(50.0, 2, 0)
    )
}, 0, 1, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Cloak(3.0, 75.0, 66.66659, 2, 0),
        IncreaseCritChance(100.0, 2, 1)
    ),
    TargetFastest(
        ReduceSpeed(50.0, 2, 0)
    )
});

Ability QuickeningPreciseImpact1087("Quickening Precise Impact", 0, 1, 0, {
    TargetSelf(
        IncreaseSpeed(25.0, 2, 4)
    ),
    TargetFastest(
        ReduceSpeed(25.0, 2, 4)
    ),
    TargetFastest(
        Attack(1.5, PRECISE)
    )
});

Ability QuillImpact2A70("Quill Impact", 0, 2, 0, {
    TargetHighestDamage(
        Attack(1.5),
        Stun(75.0, 1),
        ReduceDamage(50.0, 2, 4)
    )
});

Ability RakingClawsF16C("Raking Claws", 1, 1, 0, {
    TargetMostPositiveEffects(
        Remove(CLOAK|DODGE),
        Attack(2.0)
    )
});

CounterAbility RakingCounter_attackC77B("Raking Counter-Attack", {
    TargetAttacker(
        Remove(CLOAK|DODGE),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability RampageAndRunB223("Rampage And Run", 1, 1, 0, {
    TargetLowestHP(
        Attack(2.0)
    ),
    TargetSelf(
        Swap()
    )
});

Ability RampageB9EA("Rampage", 0, 1, 0, {
    TargetLowestHP(
        Attack(2.0)
    )
});

Ability RampageInterventionE0F0("Rampage Intervention", 0, 2, 0, {
    TargetTeam(
        Heal(0.5),
        Shield(25.0, 2, 4)
    ),
    TargetHighestDamage(
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability RavenousRampage476D("Ravenous Rampage", 1, 2, 1, {
    TargetHighestDamage(
        Remove(DODGE|CLOAK),
        Attack(2.5)
    )
});

Ability RazorBeakCE11("Razor Beak", 0, 0, 0, {
    TargetHighestHP(
        Attack(0.66, BYPASS_ARMOR),
        Attack(0.66, BYPASS_ARMOR)
    )
});

Ability ReadyToCrush43AE("Ready To Crush", 0, 2, 0, {
    TargetTeam(
        Cleanse(REDUCED_CRIT_CHANCE|REDUCED_DAMAGE),
        IncreaseCritChance(30.0, 4, 2),
        IncreaseDamage(50.0, 4, 2)
    )
});

Ability Refresh8EAD("Refresh", 0, 2, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(1.0),
        IncreaseSpeed(10.0, 2, 0)
    )
});

ThreatenedAbility RegeneratingAlertDominance73EA("Regenerating Alert Dominance", 0, 2, 0, {
    TargetTeam(
        IncreaseDamage(25.0, 2, 4),
        IncreaseArmor(25.0, 2, 4)
    ),
    TargetHighestDamage(
        ReduceArmor(25.0, 2, 4)
    ),
    TargetTeam(
        Heal(0.5)
    )
}, 33, ThreatComparison::Lower, 1, 2, 0, {
    TargetSelf(
        IncreaseDamage(50.0, 2, 4),
        IncreaseArmor(50.0, 2, 4),
        Heal(2.0),
        UnableToSwap(2)
    )
});

Ability RegeneratingBulwark1162("Regenerating Bulwark", 0, 2, 0, {
    TargetSelf(
        FixedHeal(20.0),
        Shield(50.0, 2, 4),
        IncreaseArmor(50.0, 2, 4)
    ),
    TargetFastest(
        ImposeVulnerability(50.0, 2, 1)
    )
});

Ability Rejuvenate381D("Rejuvenate", 1, 3, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        FixedHeal(100.0),
        ReduceSpeed(50.0, 2, 0)
    )
});

Ability Remedy4769("Remedy", 0, 2, 1, {
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(1.5)
    ),
    TargetSelf(
        Dodge(100.0, 67.0, 0, 2)
    )
});

Ability RendingAttack9BF1("Rending Attack", 0, 1, 0, {
    TargetHighestHP(
        Remove(SHIELD),
        Rend(40.0, BYPASS_ARMOR)
    )
});

CounterAbility RendingCounter_attack24B1("Rending Counter-Attack", {
    TargetAttacker(
        Remove(SHIELD),
        Rend(25.0, BYPASS_ARMOR)
    )
});

Ability RendingTakedown1CED("Rending Takedown", 1, 1, 0, {
    TargetHighestHP(
        Remove(SHIELD),
        Rend(60.0, BYPASS_ARMOR)
    )
});

Ability ResilientDevastationF536("Resilient Devastation", 2, 1, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(3.0)
    ),
    TargetSelf(
        Taunt(1)
    ),
    TargetLast(
        ImposeVulnerability(50.0, 2, 1)
    )
});

Ability ResilientDoubleStrike8E1A("Resilient Double Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(INCREASED_SPEED)
    ),
    TargetFastest(
        Remove(DODGE)
    ),
    TargetFastest(
        Remove(CLOAK)
    ),
    TargetFastest(
        ImposeVulnerability(50.0, 2, 1)
    ),
    TargetFastest(
        Attack(0.75)
    ),
    TargetFastest(
        Attack(0.75)
    )
});

Ability ResilientGroupRampage9B37("Resilient Group Rampage", 1, 2, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(2.0),
        ImposeVulnerability(50.0, 2, 1)
    )
});

Ability ResilientImpact7BB4("Resilient Impact", 0, 1, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.5),
        ImposeVulnerability(50.0, 2, 2)
    )
});

Ability ResilientRampageAndRun6933("Resilient Rampage And Run", 1, 2, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(2.0),
        ImposeVulnerability(50.0, 2, 2)
    ),
    TargetSelf(
        Swap()
    )
});

Ability ResilientRampageB23D("Resilient Rampage", 1, 1, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(2.0),
        ImposeVulnerability(50.0, 2, 2)
    )
});

RevengeAbility ResilientRampageRevenge6F80("Resilient Rampage Revenge", 1, 1, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(INCREASED_SPEED|CLOAK|DODGE),
        Attack(2.0),
        ImposeVulnerability(50.0, 2, 2)
    )
}, 0, 1, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Remove(INCREASED_SPEED|CLOAK|DODGE),
        Attack(2.0),
        ImposeVulnerability(50.0, 2, 1)
    )
});

Ability ResilientShieldedRampageAndRun1618("Resilient Shielded Rampage And Run", 1, 2, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(2.0),
        ImposeVulnerability(50.0, 2, 1)
    ),
    TargetSelf(
        Swap(),
        Shield(50.0, 1, 1)
    )
});

Ability ResilientStrikeFEDE("Resilient Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.0),
        ImposeVulnerability(50.0, 2, 1)
    )
});

Ability RestrictedGroupDistraction08AC("Restricted Group Distraction", 0, 1, 0, {
    TargetAllOpponents(
        Attack(1.5),
        ReduceDamage(50.0, 1, 2)
    )
});

Ability Retreat5950("Retreat", 0, 0, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Swap()
    )
});

RevengeAbility RevengeCunningRampage422C("Revenge Cunning Rampage", 1, 1, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        Remove(INCREASED_DAMAGE|INCREASED_CRIT_CHANCE),
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Attack(2.0)
    )
}, 0, 1, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        Remove(INCREASED_DAMAGE|INCREASED_CRIT_CHANCE),
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Attack(2.0)
    )
});

RevengeAbility RevengeDeceleratingImpact6A2C("Revenge Decelerating Impact", 0, 1, 0, {
    TargetFastest(
        ReduceSpeed(50.0, 2, 0),
        Attack(1.5)
    )
}, 0, 1, 0, {
    TargetFastest(
        ReduceSpeed(50.0, 2, 0),
        Attack(2.0)
    )
});

RevengeAbility RevengeDefiniteRampageED72("Revenge Definite Rampage", 1, 2, 0, {
    TargetMostPositiveEffects(
        Remove(CLOAK|DODGE|SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR)
    )
}, 0, 2, 0, {
    TargetMostPositiveEffects(
        Remove(CLOAK|DODGE|SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR)
    )
});

RevengeAbility RevengeDistractingImpact25D1("Revenge Distracting Impact", 0, 1, 0, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        Attack(1.5)
    )
}, 0, 1, 0, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        Attack(2.0)
    )
});

RevengeAbility RevengeDistractingStrike50E9("Revenge Distracting Strike", 0, 2, 0, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        Attack(1.0)
    )
}, 0, 2, 0, {
    TargetHighestDamage(
        ReduceDamage(75.0, 2, 4),
        Attack(1.0)
    )
});

RevengeAbility RevengeFierceImpact9788("Revenge Fierce Impact", 0, 1, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetLowestHP(
        Remove(SHIELD|TAUNT),
        Attack(1.5, BYPASS_ARMOR)
    )
}, 0, 1, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetHighestHP(
        Remove(SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR)
    )
});

RevengeAbility RevengeGroupDisablingImpact2C08("Revenge Group Disabling Impact", 0, 2, 0, {
    TargetAllOpponents(
        ReduceDamage(50.0, 2, 4),
        ReduceSpeed(50.0, 2, 4),
        Attack(1.5)
    )
}, 0, 0, 1, {
    TargetAllOpponents(
        ReduceDamage(100.0, 1, 2),
        ReduceSpeed(50.0, 2, 4),
        Attack(1.5)
    )
});

RevengeAbility RevengeImpact0707("Revenge Impact", 0, 1, 0, {
    TargetLowestHP(
        Attack(1.5)
    )
}, 0, 1, 0, {
    TargetLowestHP(
        Attack(2.0)
    )
});

RevengeAbility RevengeImpactAndRun0730("Revenge Impact And Run", 0, 2, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.5)
    )
}, 0, 2, 0, {
    TargetSelf(
        Cleanse(DAMAGE_OVER_TIME)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 1, 2),
        ReduceCritChance(100.0, 1, 2),
        Remove(INCREASED_CRIT_CHANCE|INCREASED_DAMAGE),
        Attack(1.5),
        Attack(1.5)
    ),
    TargetSelf(
        Swap()
    )
});

RevengeAbility RevengeInstantFerocity9F5A("Revenge Instant Ferocity", 0, 2, 1, {
    TargetSelf(
        IncreaseDamage(50.0, 2, 4)
    )
}, 0, 2, 1, {
    TargetSelf(
        IncreaseDamage(50.0, 3, 6)
    )
});

RevengeAbility RevengeInstinct98BC("Revenge Instinct", 0, 2, 1, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4)
    ),
    TargetSelf(
        Shield(50.0, 2, 4),
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetHighestDamage(
        Attack(1.5)
    )
}, 0, 2, 0, {
    TargetSelf(
        IncreaseDamage(50.0, 2, 2),
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Attack(1.5)
    )
});

RevengeAbility RevengeNullifyingRampage9284("Revenge Nullifying Rampage", 0, 2, 0, {
    TargetMostPositiveEffects(
        Remove(POSITIVE_EFFECTS),
        Attack(2.0)
    )
}, 0, 1, 0, {
    TargetMostPositiveEffects(
        Remove(POSITIVE_EFFECTS),
        Attack(2.0)
    )
});

RevengeAbility RevengeProtection914E("Revenge Protection", 0, 1, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        Shield(50.0, 2, 2)
    )
}, 0, 1, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        Shield(50.0, 4, 4)
    )
});

RevengeAbility RevengeRampageACBE("Revenge Rampage", 0, 1, 0, {
    TargetLowestHP(
        Attack(2.0)
    )
}, 0, 0, 0, {
    TargetLowestHP(
        Attack(2.0)
    )
});

RevengeAbility RevengeShatteringRampageD874("Revenge Shattering Rampage", 1, 1, 0, {
    TargetHighestHP(
        Remove(SHIELD)
    ),
    TargetHighestHP(
        Attack(2.0, BYPASS_ARMOR)
    )
}, 0, 1, 0, {
    TargetHighestHP(
        Remove(SHIELD)
    ),
    TargetHighestHP(
        Attack(2.0, BYPASS_ARMOR)
    )
});

RevengeAbility RevengeTauntingCloak02DA("Revenge Taunting Cloak", 0, 3, 1, {
    TargetSelf(
        Cloak(2.0, 75.0, 66.66659, 2, 0),
        Taunt(1)
    )
}, 0, 3, 1, {
    TargetSelf(
        Cloak(2.5, 75.0, 66.66659, 2, 0),
        Taunt(1)
    )
});

Ability Roar3648("Roar", 0, 2, 1, {
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR)
    ),
    TargetTeam(
        IncreaseDamage(50.0, 3, 2)
    )
});

CounterAbility RobbingWing33B1("Robbing Wing", {
    TargetSelf(
        IncreaseSpeed(20.0, 1, 2),
        Shield(50.0, 1, 1)
    ),
    TargetAttacker(
        ReduceSpeed(20.0, 1, 2),
        Remove(SHIELD)
    )
});

Ability SecureTaunt7C74("Secure Taunt", 0, 1, 1, {
    TargetTeam(
        Shield(50.0, 2, 2)
    ),
    TargetSelf(
        IncreaseArmor(20.0, 2, 2),
        Taunt(1)
    )
});

CounterAbility ShatteringAntidoteF861("Shattering Antidote", {
    TargetAttacker(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR),
        ReduceSpeed(10.0, 2, 2)
    ),
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    )
});

CounterAbility ShatteringDevourCounterStrike544B("Shattering Devour Counter Strike", {
    TargetAttacker(
        Remove(SHIELD),
        DevouringAttack(1.0, 40.0, 2, BYPASS_ARMOR)
    )
});

Ability ShatteringTripleJabF0E0("Shattering Triple Jab", 0, 0, 0, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        Remove(SHIELD),
        Attack(0.5),
        Attack(0.5),
        Attack(0.5)
    )
});

Ability Shelter12ED("Shelter", 0, 2, 0, {
    TargetLowestHPTeammate(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(2.0),
        IncreaseSpeed(30.0, 2, 0)
    )
});

Ability ShelteringImpact6881("Sheltering Impact", 0, 2, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Heal(2.0),
        IncreaseSpeed(10.0, 2, 2)
    ),
    TargetHighestDamage(
        Attack(1.5)
    )
});

Ability ShieldAdvantage90B9("Shield Advantage", 0, 1, 0, {
    TargetSelf(
        Shield(50.0, 1, 4)
    ),
    TargetHighestHP(
        Remove(SHIELD),
        Attack(1.0, BYPASS_ARMOR)
    )
});

Ability ShieldedCleansingRampageF75B("Shielded Cleansing Rampage", 1, 2, 0, {
    TargetSelf(
        Shield(50.0, 1, 4),
        Cleanse(REDUCED_DAMAGE),
        Taunt(1)
    ),
    TargetHighestHP(
        Attack(2.0)
    )
});

Ability ShieldedDeceleratingImpact426C("Shielded Decelerating Impact", 0, 1, 0, {
    TargetSelf(
        Shield(50.0, 1, 4)
    ),
    TargetLowestHP(
        Attack(1.5, PRECISE),
        ReduceSpeed(50.0, 2, 2)
    )
});

Ability ShieldedDeceleratingStrike627F("Shielded Decelerating Strike", 0, 0, 0, {
    TargetSelf(
        Shield(50.0, 1, 4)
    ),
    TargetLowestHP(
        ReduceSpeed(50.0, 2, 4),
        Attack(1.0, PRECISE)
    )
});

Ability ShieldedDevastation403E("Shielded Devastation", 2, 2, 0, {
    TargetHighestHP(
        Attack(3.0, PRECISE)
    ),
    TargetSelf(
        Shield(50.0, 2, 4),
        Taunt(1)
    )
});

Ability ShieldedDoubleHeal9DEE("Shielded Double Heal", 0, 2, 1, {
    TargetSelf(
        Shield(50.0, 2, 2),
        Cleanse(NEGATIVE_EFFECTS),
        Heal(2.0)
    )
});

Ability ShieldedEvasiveStrike4571("Shielded Evasive Strike", 0, 1, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        Dodge(75.0, 67.0, 2, 4),
        Shield(50.0, 1, 2)
    )
});

Ability ShieldedHeavyStrike02CB("Shielded Heavy Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY|REDUCED_DAMAGE)
    ),
    TargetLowestHP(
        Attack(1.0, BYPASS_ARMOR|PRECISE)
    ),
    TargetFastest(
        Remove(INCREASED_SPEED)
    ),
    TargetSelf(
        Shield(50.0, 2, 2)
    )
});

Ability ShieldedLockdown6EE2("Shielded Lockdown", 0, 2, 1, {
    TargetSelf(
        Shield(75.0, 1, 2)
    ),
    TargetRandom(
        UnableToSwap(2)
    )
});

Ability ShieldedTauntingStrike73D4("Shielded Taunting Strike", 0, 0, 0, {
    TargetSelf(
        Shield(50.0, 1, 4)
    ),
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        Taunt(1)
    )
});

ThreatenedAbility ShieldingAlertRampage3625("Shielding Alert Rampage", 0, 2, 0, {
    TargetAllOpponents(
        Remove(CLOAK|DODGE|SHIELD)
    ),
    TargetSelf(
        Shield(50.0, 1, 4)
    ),
    TargetAllOpponents(
        Attack(2.0, BYPASS_ARMOR)
    )
}, 50, ThreatComparison::Lower, 0, 2, 1, {
    TargetAllOpponents(
        Remove(CLOAK|DODGE|SHIELD)
    ),
    TargetTeam(
        Shield(100.0, 1, 8)
    ),
    TargetAllOpponents(
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability ShieldingStrikeEDCA("Shielding Strike", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        Shield(50.0, 1, 2)
    )
});

Ability ShortDefense7ED4("Short Defense", 0, 2, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        Shield(50.0, 2, 2)
    )
});

Ability ShreddingWound5EC6("Shredding Wound", 1, 2, 0, {
    TargetHighestDamage(
        Rend(50.0),
        DamageOverTime(40.0, 2)
    )
});

Ability Sideflap66AF("Sideflap", 0, 0, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(100.0, 67.0, 0, 2),
        IncreaseSpeed(10.0, 2, 0),
        Taunt(1)
    )
});

Ability Sidestep5439("Sidestep", 0, 0, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(100.0, 67.0, 0, 2),
        IncreaseSpeed(10.0, 2, 0)
    )
});

Ability SkewerB3B7("Skewer", 0, 2, 0, {
    TargetAllOpponents(
        Attack(1.5, BYPASS_ARMOR),
        Stun(100.0, 1),
        UnableToSwap(1)
    )
});

Ability Skirmish0914("Skirmish", 1, 1, 0, {
    TargetSelf(
        Cleanse(VULNERABILITY)
    ),
    TargetAllOpponents(
        Remove(SHIELD|TAUNT),
        Attack(2.0, BYPASS_ARMOR)
    )
});

ThreatenedAbility SlipperyAlertB2DD("Slippery Alert", 0, 2, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(50.0, 66.69999, 2, 2),
        IncreaseCritChance(50.0, 2, 2)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4)
    ),
    TargetMostPositiveEffects(
        Affliction(33.0, 2, 4)
    )
}, 50, ThreatComparison::Lower, 0, 2, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(75.0, 66.69999, 2, 2),
        IncreaseCritChance(75.0, 2, 2)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4)
    )
});

CounterAbility SlowingCounterPowerHeal6A69("Slowing Counter Power Heal", {
    TargetSelf(
        RallyHeal(10.0)
    ),
    TargetAttacker(
        ReduceSpeed(50.0, 2, 2)
    )
});

Ability SlowingImpact145F("Slowing Impact", 0, 1, 0, {
    TargetFastest(
        ReduceSpeed(50.0, 3, 0),
        Attack(1.5)
    )
});

Ability SlowingResilientStrikeB132("Slowing Resilient Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.0),
        ImposeVulnerability(50.0, 2, 1),
        ReduceSpeed(50.0, 2, 4)
    )
});

Ability SlyRampageAndRun367D("Sly Rampage And Run", 1, 2, 0, {
    TargetHighestDamage(
        Attack(2.0),
        ReduceDamage(50.0, 2, 2)
    ),
    TargetSelf(
        Swap(),
        Shield(50.0, 2, 1)
    )
});

Ability SpikedProtection8FA1("Spiked Protection", 0, 2, 1, {
    TargetTeam(
        Shield(25.0, 2, 4)
    ),
    TargetSelf(
        IncreaseArmor(25.0, 2, 4)
    ),
    TargetHighestHP(
        Affliction(25.0, 2, 4)
    ),
    TargetHighestHP(
        DamageOverTime(20.0, 3)
    )
});

Ability Stall897E("Stall", 1, 3, 1, {
    TargetMostPositiveEffects(
        Remove(POSITIVE_EFFECTS)
    ),
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Dodge(66.69998, 66.69998, 0, 1),
        IncreaseSpeed(50.0, 1, 1)
    )
});

Ability StrikeAndRun11DF("Strike And Run", 1, 1, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        Swap()
    )
});

Ability StrikeBE64("Strike", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.0)
    )
});

Ability StunningDistractionB884("Stunning Distraction", 0, 2, 0, {
    TargetFastest(
        Attack(1.0),
        Stun(50.0, 1),
        ReduceDamage(50.0, 2, 4)
    )
});

Ability StunningImpactAndRun3EB7("Stunning Impact And Run", 1, 1, 0, {
    TargetLowestHP(
        Attack(1.5),
        Stun(75.0, 1)
    ),
    TargetSelf(
        Swap()
    )
});

Ability StunningRampageAndRun9FFA("Stunning Rampage And Run", 1, 1, 0, {
    TargetHighestDamage(
        Stun(100.0, 1)
    ),
    TargetLowestHP(
        Attack(2.0)
    ),
    TargetSelf(
        Swap()
    )
});

Ability StunningRampageBD06("Stunning Rampage", 1, 2, 0, {
    TargetHighestHP(
        Stun(75.0, 1),
        Attack(2.0)
    )
});

Ability StunningVulnerabilityRampageA9E3("Stunning Vulnerability Rampage", 1, 2, 0, {
    TargetFastest(
        Attack(2.0, PRECISE),
        Stun(100.0, 1),
        ImposeVulnerability(50.0, 2, 1)
    )
});

Ability SuperDistractionDE40("Super Distraction", 0, 3, 1, {
    TargetHighestDamage(
        Remove(DODGE)
    ),
    TargetAllOpponents(
        Attack(1.5)
    ),
    TargetLast(
        DamageOverTime(25.0, 2),
        ReduceDamage(50.0, 1, 2)
    ),
    TargetAllOpponents(
        ReduceDamage(50.0, 1, 2)
    )
});

Ability SuperiorAfflictingStrike2A2C("Superior Afflicting Strike", 0, 0, 0, {
    TargetMostPositiveEffects(
        Affliction(33.0, 2, 4)
    ),
    TargetMostPositiveEffects(
        Attack(1.0)
    )
});

Ability SuperiorVulnerability7C25("Superior Vulnerability", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        ReduceSpeed(50.0, 2, 0),
        Attack(1.0, PRECISE),
        ImposeVulnerability(50.0, 2, 1)
    )
});

Ability SuperiorityImpact5FE3("Superiority Impact", 0, 1, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Attack(1.5, PRECISE),
        ReduceSpeed(50.0, 1, 0)
    )
});

Ability SuperiorityRampageE910("Superiority Rampage", 1, 1, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        Attack(2.0, PRECISE),
        ReduceSpeed(50.0, 1, 0)
    )
});

Ability SuperiorityStrike2549("Superiority Strike", 0, 0, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetFastest(
        ReduceSpeed(50.0, 1, 0),
        Attack(1.0, PRECISE)
    )
});

ThreatenedCounterAbility SurvivalInstinct12CC("Survival Instinct", {
    TargetSelf(
        IncreaseArmor(15.0, 2, 2)
    )
}, 50, ThreatComparison::Lower, {
    TargetSelf(
        IncreaseArmor(34.99999, 2, 4)
    )
});

ThreatenedCounterAbility SurvivalInstinctB690("Survival Instinct", {
    TargetSelf(
        IncreaseArmor(34.99999, 2, 4)
    )
}, 50, ThreatComparison::Higher, {
    TargetSelf(
        IncreaseArmor(15.0, 2, 2)
    )
});

Ability TauntShatteringRampageDE3B("Taunt Shattering Rampage", 1, 2, 0, {
    TargetSelf(
        Taunt(1)
    ),
    TargetHighestHP(
        Remove(SHIELD)
    ),
    TargetHighestHP(
        Remove(TAUNT)
    ),
    TargetHighestHP(
        Attack(2.0, BYPASS_ARMOR)
    )
});

Ability TauntingBellow3BBD("Taunting Bellow", 0, 2, 1, {
    TargetSelf(
        Shield(50.0, 0, 4),
        Taunt(1)
    ),
    TargetFastest(
        ReduceSpeed(50.0, 2, 0)
    )
});

Ability TauntingDefense72E3("Taunting Defense", 0, 2, 1, {
    TargetSelf(
        Shield(50.0, 2, 4),
        Taunt(1),
        IncreaseArmor(50.0, 2, 4)
    )
});

Ability TauntingHealBellow5344("Taunting Heal Bellow", 0, 3, 1, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS),
        Shield(50.0, 0, 4),
        Taunt(1)
    ),
    TargetFastest(
        ReduceSpeed(50.0, 2, 0)
    ),
    TargetSelf(
        FixedHeal(20.0)
    )
});

Ability TauntingRampage3362("Taunting Rampage", 1, 1, 0, {
    TargetLowestHP(
        Attack(2.0)
    ),
    TargetSelf(
        Taunt(1)
    )
});

Ability TauntingResilientGroupImpact240C("Taunting Resilient Group Impact", 0, 2, 0, {
    TargetSelf(
        Cleanse(REDUCED_DAMAGE)
    ),
    TargetAllOpponents(
        Remove(DODGE|CLOAK|INCREASED_SPEED),
        Attack(1.5),
        ImposeVulnerability(50.0, 2, 1)
    ),
    TargetTeam(
        Shield(50.0, 2, 2)
    ),
    TargetSelf(
        Taunt(2)
    )
});

Ability TauntingShieldRampageE20B("Taunting Shield Rampage", 1, 1, 0, {
    TargetSelf(
        Shield(50.0, 1, 4),
        Taunt(1)
    ),
    TargetLowestHP(
        Attack(2.0)
    )
});

Ability TauntingShieldedHealFDB6("Taunting Shielded Heal", 0, 2, 0, {
    TargetSelf(
        Shield(50.0, 2, 4),
        Heal(1.5),
        Taunt(1)
    ),
    TargetHighestDamage(
        Attack(1.0)
    )
});

Ability TauntingShields1CF6("Taunting Shields", 0, 1, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        Shield(50.0, 2, 4),
        Taunt(1)
    )
});

Ability TauntingShieldsB07B("Taunting Shields", 0, 0, 0, {
    TargetLowestHP(
        Attack(1.0)
    ),
    TargetSelf(
        Shield(50.0, 2, 4),
        Taunt(1)
    )
});

Ability TeamFortificationB18F("Team Fortification", 0, 3, 0, {
    TargetTeam(
        Shield(50.0, 1, 4),
        IncreaseDamage(25.0, 2, 4)
    ),
    TargetAllOpponents(
        Remove(SHIELD),
        ReduceSpeed(50.0, 2, 0)
    )
});

Ability TerritorialStrikeFC54("Territorial Strike", 0, 0, 0, {
    TargetAllOpponents(
        Attack(1.0, BYPASS_ARMOR),
        DamageOverTime(10.0, 2)
    ),
    TargetSelf(
        IncreaseArmor(10.0, 2, 4)
    )
});

Ability ThievishStrikeBD4A("Thievish Strike", 0, 0, 0, {
    TargetHighestDamage(
        Remove(INCREASED_DAMAGE)
    ),
    TargetHighestDamage(
        Remove(INCREASED_CRIT_CHANCE)
    ),
    TargetHighestDamage(
        Attack(1.0)
    ),
    TargetSelf(
        IncreaseDamage(25.0, 2, 4),
        IncreaseCritChance(25.0, 2, 4)
    )
});

Ability ThrashingImpactAndRun9E6F("Thrashing Impact And Run", 0, 2, 0, {
    TargetSelf(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetLowestHP(
        Attack(1.5, BYPASS_ARMOR)
    ),
    TargetSelf(
        Swap()
    )
});

Ability TipTheScales61DD("Tip The Scales", 0, 1, 1, {
    TargetAllOpponents(
        Remove(POSITIVE_EFFECTS)
    ),
    TargetTeam(
        Cleanse(NEGATIVE_EFFECTS)
    ),
    TargetMostPositiveEffects(
        Attack(1.5)
    )
});

Ability TitanicTakedown07BC("Titanic Takedown", 0, 2, 0, {
    TargetHighestDamage(
        Attack(2.0, PRECISE)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4)
    ),
    TargetHighestDamage(
        ReduceCritChance(50.0, 2, 4),
        ReduceSpeed(50.0, 2, 4)
    ),
    TargetHighestDamage(
        Stun(75.0, 1)
    )
});

Ability ToxicQuills1E91("Toxic Quills", 0, 3, 0, {
    TargetHighestDamage(
        Attack(1.5),
        Stun(75.0, 1),
        DamageOverTime(33.41, 3)
    )
});

ThreatenedAbility Tyrant_sRoarD436("Tyrant'S Roar", 0, 2, 0, {
    TargetHighestHP(
        Attack(1.0, BYPASS_ARMOR)
    ),
    TargetSelf(
        IncreaseDamage(50.0, 2, 2),
        IncreaseSpeed(25.0, 1, 2)
    )
}, 50, ThreatComparison::Lower, 0, 2, 1, {
    TargetAllOpponents(
        Attack(1.5, BYPASS_ARMOR)
    ),
    TargetTeam(
        IncreaseDamage(50.0, 2, 2),
        IncreaseSpeed(25.0, 1, 0)
    ),
    TargetSelf(
        FixedHeal(25.0)
    )
});

Ability UnstoppableForce55F5("Unstoppable Force", 2, 2, 0, {
    TargetAllOpponents(
        Remove(SHIELD),
        Attack(2.5, PRECISE),
        Stun(50.0, 1)
    )
});

Ability UpperClawA90A("Upper Claw", 0, 1, 1, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4),
        Attack(1.33)
    ),
    TargetSelf(
        IncreaseCritChance(25.0, 2, 4)
    )
});

RevengeAbility VengefulDevouringRampage8CE5("Vengeful Devouring Rampage", 1, 2, 0, {
    TargetHighestHP(
        Remove(SHIELD)
    ),
    TargetHighestHP(
        DevouringAttack(2.0, 33.0, 2, BYPASS_ARMOR)
    )
}, 0, 2, 1, {
    TargetHighestHP(
        Remove(SHIELD)
    ),
    TargetHighestHP(
        DevouringAttack(2.5, 66.0, 2, BYPASS_ARMOR)
    )
});

RevengeAbility VengefulDoublePiercingStrike4149("Vengeful Double Piercing Strike", 0, 2, 0, {
    TargetLowestHP(
        Attack(0.75, BYPASS_ARMOR)
    ),
    TargetLowestHP(
        Attack(0.75, BYPASS_ARMOR)
    )
}, 0, 2, 0, {
    TargetLowestHP(
        Attack(1.0, BYPASS_ARMOR|PRECISE)
    ),
    TargetLowestHP(
        Attack(1.0, BYPASS_ARMOR|PRECISE)
    )
});

RevengeAbility VengefulDoubleStrikeEF0B("Vengeful Double Strike", 0, 2, 0, {
    TargetHighestDamage(
        Attack(1.0, PRECISE)
    ),
    TargetHighestDamage(
        Attack(1.0, PRECISE)
    ),
    TargetSelf(
        Dodge(33.0, 66.69998, 2, 4),
        Shield(33.0, 2, 4)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4)
    )
}, 0, 2, 1, {
    TargetHighestDamage(
        Attack(1.25, PRECISE)
    ),
    TargetHighestDamage(
        Attack(1.25, PRECISE)
    ),
    TargetSelf(
        Dodge(50.0, 67.0, 2, 4),
        Shield(50.0, 2, 4)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4)
    )
});

RevengeAbility VengefulFerociousDistraction5645("Vengeful Ferocious Distraction", 0, 2, 1, {
    TargetSelf(
        IncreaseDamage(50.0, 2, 4)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4)
    )
}, 0, 2, 1, {
    TargetSelf(
        IncreaseDamage(50.0, 3, 6)
    ),
    TargetHighestDamage(
        Affliction(75.0, 1, 2)
    ),
    TargetHighestDamage(
        ReduceDamage(50.0, 3, 6)
    )
});

CounterAbility VenomousCounter4C31("Venomous Counter", {
    TargetAttacker(
        UnableToSwap(1),
        ReduceDamage(50.0, 1, 2)
    )
});

CounterAbility VenomousCounter56D1("Venomous Counter", {
    TargetAttacker(
        UnableToSwap(1),
        ReduceDamage(50.0, 1, 2)
    )
});

Ability VulnerabilityImpact2DAA("Vulnerability Impact", 0, 1, 0, {
    TargetHighestHP(
        Attack(1.5),
        ImposeVulnerability(50.0, 2, 2)
    )
});

Ability VulnerabilityRampage46FB("Vulnerability Rampage", 1, 2, 0, {
    TargetHighestHP(
        Attack(2.0),
        ImposeVulnerability(50.0, 2, 2)
    )
});

Ability VulnerabilityStrike1E04("Vulnerability Strike", 0, 0, 0, {
    TargetHighestHP(
        Attack(1.0),
        ImposeVulnerability(50.0, 1, 2)
    )
});

Ability WeakeningDecimateAndRun76AD("Weakening Decimate And Run", 2, 1, -1, {
    TargetHighestDamage(
        ReduceDamage(50.0, 2, 4)
    ),
    TargetHighestDamage(
        ReduceSpeed(50.0, 2, 4)
    ),
    TargetHighestDamage(
        Attack(2.5)
    ),
    TargetSelf(
        Cleanse(SWAP_PREVENTION),
        Swap()
    )
});

Ability WildTripleStrikeF0C6("Wild Triple Strike", 1, 3, 0, {
    TargetMostPositiveEffects(
        ReduceDamage(50.0, 1, 2)
    ),
    TargetMostPositiveEffects(
        Remove(SHIELD),
        Attack(1.0),
        Attack(1.0, BYPASS_ARMOR),
        Attack(1.0, PRECISE)
    )
});

CounterAbility WoundingCounterA785("Wounding Counter", {
    TargetAttacker(
        DamageOverTime(33.41, 1)
    )
});

Ability WoundingDevourRampage4191("Wounding Devour Rampage", 1, 2, 0, {
    TargetLowestHP(
        Remove(SHIELD),
        DevouringAttack(2.0, 60.0, 4, BYPASS_ARMOR),
        Remove(TAUNT),
        DamageOverTime(20.0, 2)
    ),
    TargetSelf(
        Cleanse(VULNERABILITY)
    )
});


DinoKind AlanqaMinion("Alanqa Minion", EPIC, 1, {
    DinoRound(5000, 1000, 115, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &RampageB9EA,
        &GroupTauntingShieldsEB4C
    }, nullptr)
});

DinoKind AllosaurusMinion("Allosaurus Minion", COMMON, 1, {
    DinoRound(4620, 1750, 104, 0.0, 20.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &DefenseShatteringRampageC9FF
    }, nullptr)
});

DinoKind ArambourgianiaMinion("Arambourgiania Minion", RARE, 1, {
    DinoRound(4500, 1000, 115, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupTauntingShieldsEB4C,
        &ResilientRampageB23D
    }, nullptr)
});

DinoKind ArchaeotheriumMinion("Archaeotherium Minion", COMMON, 1, {
    DinoRound(3000, 1000, 121, 15.0, 20.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1e-05, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupDefenseShatteringStrikeAE98,
        &GroupShatteringImpact7EAE
    }, nullptr)
});

DinoKind BaryonyxMinion("Baryonyx Minion", EPIC, 1, {
    DinoRound(4200, 1300, 126, 0.0, 30.0, 125.0, 0.0, 0.0, 0.0, 0.0, 1e-05, 0.0, 0.0, 0.0, 1e-05, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &GroupTakedown066E,
        &DefenseShatteringRampageC9FF
    }, nullptr)
});

DinoKind CarnotaurusMinion("Carnotaurus Minion", RARE, 1, {
    DinoRound(4500, 1000, 104, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupTauntingShieldsEB4C,
        &CleansingImpact351E
    }, &GreaterRendingCounter_attackD5C2)
});

DinoKind CharlieMinion("Charlie Minion", RARE, 1, {
    DinoRound(2400, 1300, 131, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &HighPounceD062,
        &CunningImpactEE79
    }, nullptr)
});

DinoKind DilophosaurusMinion("Dilophosaurus Minion", RARE, 1, {
    DinoRound(3600, 1250, 129, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &DistractingImpactD4D6,
        &CunningRampage8AEB
    }, nullptr)
});

DinoKind DoedicurusMinion("Doedicurus Minion", RARE, 1, {
    DinoRound(4200, 1200, 111, 50.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &DeceleratingRampageD0C5,
        &GroupTauntingShieldsEB4C
    }, nullptr)
});

DinoKind EchoMinion("Echo Minion", RARE, 1, {
    DinoRound(2500, 1500, 129, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupStrikeC21E,
        &HighPounceD062,
        &CunningImpactEE79
    }, nullptr)
});

DinoKind EntelodonMinion("Entelodon Minion", RARE, 1, {
    DinoRound(3600, 1000, 122, 0.0, 30.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupDefenseShatteringStrikeAE98,
        &GroupFerocityC6F7,
        &GroupShatteringImpact7EAE
    }, nullptr)
});

DinoKind GallimimusMinion("Gallimimus Minion", COMMON, 1, {
    DinoRound(2700, 1400, 130, 0.0, 5.0, 125.0, 100.0, 100.0, 100.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &EvasiveStrikeA8EB,
        &InstantDistractionF5AC
    }, nullptr)
});

DinoKind GorgosaurusMinion("Gorgosaurus Minion", RARE, 1, {
    DinoRound(4500, 1750, 103, 0.0, 20.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &DefenseShatteringImpact25E3,
        &DefenseShatteringRampageC9FF
    }, nullptr)
});

DinoKind IrritatorMinion("Irritator Minion", RARE, 1, {
    DinoRound(4500, 1100, 126, 0.0, 30.0, 125.0, 0.0, 0.0, 0.0, 0.0, 1e-05, 0.0, 0.0, 0.0, 1e-05, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &ReadyToCrush43AE,
        &GroupTakedown066E
    }, nullptr)
});

DinoKind KoolasuchusGen2Minion("Koolasuchus Gen 2 Minion", RARE, 1, {
    DinoRound(4500, 1100, 127, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &NullifyingStrike38B2,
        &NullifyingImpact65A2,
        &GroupDistractionFB00
    }, nullptr)
});

DinoKind MajungasaurusMinion("Majungasaurus Minion", COMMON, 1, {
    DinoRound(3450, 1300, 105, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupMock_BlockAndSockD0AE
    }, &ArmorPiercingCounterAEB5)
});

DinoKind MiragaiaMinion("Miragaia Minion", COMMON, 1, {
    DinoRound(4050, 1000, 112, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ShieldedDeceleratingStrike627F,
        &GroupDeceleratingStrikeBAC6
    }, &DeceleratingCounterD9D3)
});

DinoKind MonolophosaurusGen2Minion("Monolophosaurus Gen 2 Minion", COMMON, 1, {
    DinoRound(3000, 1350, 129, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &Distraction2717,
        &CunningImpactEE79
    }, nullptr)
});

DinoKind NodosaurusMinion("Nodosaurus Minion", RARE, 1, {
    DinoRound(6000, 1000, 116, 30.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &TauntingShieldsB07B,
        &GroupTauntingShieldsEB4C,
        &InstantInvincibilityTaunt6C65
    }, nullptr)
});

DinoKind PteranodonMinion("Pteranodon Minion", EPIC, 1, {
    DinoRound(3500, 1200, 120, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &FierceStrike106A,
        &FerociousStrike71CC,
        &FierceRampageDC31
    }, nullptr)
});

DinoKind ScolosaurusMinion("Scolosaurus Minion", COMMON, 1, {
    DinoRound(5500, 1000, 110, 25.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &TauntingShieldsB07B,
        &GroupTauntingShieldsEB4C
    }, nullptr)
});

DinoKind SuchomimusMinion("Suchomimus Minion", COMMON, 1, {
    DinoRound(3900, 900, 104, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &FierceStrikeAA4B,
        &LethalWound98A0
    }, nullptr)
});

DinoKind TenontosaurusMinion("Tenontosaurus Minion", RARE, 1, {
    DinoRound(4500, 1100, 110, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupCleansingStrike4EEA,
        &LesserGroupHeal5491,
        &GreaterEmergencyHeal456B
    }, nullptr)
});

DinoKind TinyT_Rex("Tiny T. Rex", UNIQUE, 1, {
    DinoRound(8000, 1900, 102, 0.0, 30.0, 150.0, 0.0, 80.0, 50.0, 80.0, 0.0, 89.99999, 0.0, 0.0, 0.0, 0.0, 80.0, {
        &DispersedFierceImpact938B,
        &CleansingRoar4A67,
        &GroupDevouringImpactC9D9,
        &FierceRampageDC31
    }, nullptr)
});

DinoKind TinyT_RexTwin("Tiny T. Rex Twin", EPIC, 1, {
    DinoRound(5000, 1800, 104, 0.0, 20.0, 150.0, 0.0, 80.0, 50.0, 80.0, 0.0, 89.99999, 0.0, 0.0, 0.0, 0.0, 80.0, {
        &FierceStrikeAA4B,
        &FierceImpactB3BE,
        &FierceRampageDC31,
        &PrimalBraceF81C
    }, &MinimalCounterStrikeFFAB)
});

DinoKind VelociraptorMinion("Velociraptor Minion", COMMON, 1, {
    DinoRound(2500, 1500, 131, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupStrikeC21E,
        &HighPounceD062
    }, nullptr)
});

DinoKind WuerhosaurusMinion("Wuerhosaurus Minion", RARE, 1, {
    DinoRound(4800, 1000, 115, 25.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupDeceleratingRampageE77E,
        &TauntingBellow3BBD
    }, nullptr)
});


DinoKind Acrocanthops("Acrocanthops", LEGENDARY, 1, {
    DinoRound(4500, 1800, 112, 0.0, 20.0, 125.0, 0.0, 50.0, 0.0, 0.0, 0.0, 34.0, 0.0, 100.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &FierceImpactB3BE,
        &RevengeDistractingStrike50E9,
        &RevengeRampageACBE
    }, nullptr)
});

DinoKind Acrocanthosaurus("Acrocanthosaurus", EPIC, 1, {
    DinoRound(4800, 1700, 110, 0.0, 30.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupCleansingStrike8B0C,
        &GroupDefenseShatteringImpact0C66,
        &FierceRampageDC31
    }, nullptr)
});

DinoKind Aenocyonyx("Aenocyonyx", UNIQUE, 1, {
    DinoRound(4800, 1500, 128, 0.0, 25.0, 125.0, 100.0, 50.0, 0.0, 75.0, 100.0, 50.0, 100.0, 0.0, 100.0, 0.0, 0.0, {
        &InstantDefenseShatteringStrikeB62F,
        &CrushingProwl3FF5,
        &DevouringWound32A1,
        &DisarmingDecimateAndRunB62E
    }, &DefenseShatteringCounter_attackD663)
});

DinoKind Ailurarctos("Ailurarctos", EPIC, 1, {
    DinoRound(3900, 1350, 106, 10.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 75.0, 0.0, 0.0, 0.0, 75.0, 0.0, 0.0, {
        &FerociousShieldedHeal2912,
        &AlertDeceleratingImpact5396,
        &FierceRampageDC31
    }, &CounterPowerHeal4DD2)
});

DinoKind Alacranix("Alacranix", APEX, 1, {
    DinoRound(4250, 1650, 115, 40.0, 15.0, 125.0, 0.0, 100.0, 25.0, 75.0, 100.0, 75.0, 0.0, 100.0, 50.0, 0.0, 0.0, {
        &MinorRendingLockdown18B8,
        &NecroticImpactBA62,
        &PreciseDeceleratingRampageB02E,
        &DecimatingTelsonBAD4
    }, &FierceCounter4FB7)
});

DinoKind Alankyloceratops("Alankyloceratops", UNIQUE, 1, {
    DinoRound(5400, 1200, 113, 40.0, 5.0, 125.0, 0.0, 50.0, 50.0, 25.0, 100.0, 50.0, 0.0, 0.0, 25.0, 0.0, 0.0, {
        &GroupResilientStrike74A6,
        &StunningRampageBD06,
        &Dragon_sFlightB1E0,
        &InvincibleAlert449E
    }, nullptr)
});

DinoKind Alankylosaurus("Alankylosaurus", LEGENDARY, 1, {
    DinoRound(4800, 1000, 114, 30.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &ResilientRampageB23D,
        &ShortDefense7ED4,
        &LongInvincibilityBB2D
    }, nullptr)
});

DinoKind Alanqa("Alanqa", EPIC, 1, {
    DinoRound(4050, 1200, 125, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &RampageB9EA,
        &LongInvincibilityBB2D
    }, nullptr)
});

DinoKind Albertocevia("Albertocevia", UNIQUE, 1, {
    DinoRound(4650, 1600, 121, 0.0, 10.0, 125.0, 100.0, 50.0, 0.0, 50.0, 100.0, 75.0, 0.0, 0.0, 75.0, 0.0, 0.0, {
        &DefenseShatteringAlert459B,
        &DistractingRevengeBlow7BE8,
        &InstantFerociousRevenge3D5C,
        &PreciseRevenge51B4
    }, &FierceCounter4FB7)
});

DinoKind Albertosaurus("Albertosaurus", RARE, 1, {
    DinoRound(4350, 1750, 106, 0.0, 30.0, 125.0, 100.0, 50.0, 0.0, 0.0, 100.0, 0.0, 100.0, 0.0, 25.0, 0.0, 0.0, {
        &FierceStrike106A,
        &KillerInstinct3E33,
        &FierceImpactB3BE
    }, nullptr)
});

DinoKind Albertospinos("Albertospinos", UNIQUE, 1, {
    DinoRound(4500, 1550, 128, 0.0, 15.0, 125.0, 100.0, 75.0, 25.0, 0.0, 100.0, 0.0, 100.0, 0.0, 75.0, 0.0, 0.0, {
        &DefenseShatteringWound1735,
        &MercilessAlert571C,
        &KillerInstinct3E33,
        &FierceRampageDC31
    }, &MinorCriticalCounterE7FC)
});

DinoKind Allodrigues("Allodrigues", UNIQUE, 3, {
    DinoRound(3300, 1750, 130, 0.0, 15.0, 125.0, 0.0, 50.0, 75.0, 66.0, 100.0, 67.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &FierceStrike106A,
        &ProtectiveAlert2FA4,
        &CunningRampage8AEB,
        &AlertPeck3B22
    }, nullptr)
});

DinoKind Alloraptor("Alloraptor", LEGENDARY, 1, {
    DinoRound(3300, 1700, 130, 0.0, 40.0, 125.0, 0.0, 0.0, 50.0, 0.0, 100.0, 0.0, 100.0, 0.0, 50.0, 0.0, 0.0, {
        &LesserRendingAttack85FA,
        &DistractingRampageBD0D,
        &CunningFerociousStrike6867,
        &CleansingRampageC8DB
    }, nullptr)
});

DinoKind Allosaurus("Allosaurus", COMMON, 1, {
    DinoRound(4650, 1750, 104, 0.0, 20.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &FierceStrike106A,
        &FierceImpactB3BE
    }, nullptr)
});

DinoKind AllosaurusGen2("Allosaurus Gen2", EPIC, 1, {
    DinoRound(4500, 1800, 105, 0.0, 40.0, 125.0, 0.0, 100.0, 0.0, 0.0, 50.0, 0.0, 100.0, 0.0, 50.0, 0.0, 0.0, {
        &CleansingShatteringStrikeA6B1,
        &FierceImpactB3BE,
        &InstantRend0585
    }, nullptr)
});

DinoKind Allosinosaurus("Allosinosaurus", LEGENDARY, 1, {
    DinoRound(4500, 1800, 106, 15.0, 20.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &FierceStrike106A,
        &ArmorPiercingImpactB10F,
        &FierceImpactB3BE,
        &InstantCharge0917
    }, nullptr)
});

DinoKind Amargasaurus("Amargasaurus", RARE, 1, {
    DinoRound(5250, 1000, 103, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupDeceleratingImpact9451,
        &SlowingImpact145F
    }, nullptr)
});

DinoKind Amargocephalus("Amargocephalus", EPIC, 1, {
    DinoRound(3600, 900, 104, 40.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &GroupDeceleratingImpact9451,
        &InstantInvincibilityTaunt6C65,
        &DeceleratingImpact5016
    }, &MediumCounter_attackE4A7)
});

DinoKind Amphicyon("Amphicyon", COMMON, 1, {
    DinoRound(3150, 1300, 122, 0.0, 40.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupCleansingStrike8B0C,
        &FierceImpactB3BE
    }, nullptr)
});

DinoKind Andrewsarchus("Andrewsarchus", RARE, 1, {
    DinoRound(3300, 1400, 125, 0.0, 40.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CleansingStrike541F,
        &FierceImpactB3BE,
        &RendingTakedown1CED
    }, nullptr)
});

DinoKind Andrewtherium("Andrewtherium", EPIC, 1, {
    DinoRound(3600, 1300, 119, 5.0, 25.0, 125.0, 100.0, 0.0, 50.0, 0.0, 50.0, 50.0, 100.0, 0.0, 50.0, 0.0, 0.0, {
        &GroupCleansingStrike8B0C,
        &FerociousStrike71CC,
        &GroupWarningSqueal0E5A,
        &RendingAttack9BF1
    }, nullptr)
});

DinoKind Andrewtodon("Andrewtodon", EPIC, 1, {
    DinoRound(3450, 1300, 112, 15.0, 25.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &FierceStrike106A,
        &ArmorPiercingImpactB10F,
        &CleansingImpact351E,
        &RendingTakedown1CED
    }, &ExposingCounterA5BA)
});

DinoKind Andrewtops("Andrewtops", UNIQUE, 1, {
    DinoRound(3900, 1600, 126, 10.0, 20.0, 125.0, 100.0, 0.0, 100.0, 0.0, 75.0, 75.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DaringStrikeE486,
        &DelayedRevengeDistractingRampage99EB,
        &CleansingImpact351E,
        &PiercingRevengeD39D
    }, &CounterVulnerabilityC8BA)
});

DinoKind Ankylocodon("Ankylocodon", RARE, 1, {
    DinoRound(4500, 1000, 107, 25.0, 20.0, 125.0, 0.0, 100.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupDeceleratingImpact9451,
        &GroupShield54BA,
        &DefenseShatteringImpact25E3
    }, nullptr)
});

DinoKind Ankylodactylus("Ankylodactylus", LEGENDARY, 3, {
    DinoRound(3150, 1200, 126, 15.0, 5.0, 125.0, 0.0, 0.0, 100.0, 33.0, 75.0, 100.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &Sideflap66AF,
        &ShieldedEvasiveStrike4571,
        &InstantDodgeImpact4070,
        &SuperiorityRampageE910
    }, nullptr)
});

DinoKind Ankylodicurus("Ankylodicurus", EPIC, 1, {
    DinoRound(4200, 1150, 108, 34.99999, 15.0, 125.0, 0.0, 50.0, 50.0, 0.0, 50.0, 100.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &GroupTauntingShieldsEB4C,
        &ResilientImpact7BB4,
        &SuperiorityRampageE910
    }, nullptr)
});

DinoKind Ankylomoloch("Ankylomoloch", LEGENDARY, 1, {
    DinoRound(4050, 1150, 118, 20.0, 10.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 50.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &TauntingResilientGroupImpact240C,
        &AlertInstantShieldedStrikeF2E8,
        &DeceleratingRampageAndRun2D5A
    }, nullptr)
});

DinoKind AnkylosLux("Ankylos Lux", APEX, 1, {
    DinoRound(4200, 1100, 110, 34.99999, 5.0, 125.0, 0.0, 0.0, 100.0, 0.0, 50.0, 0.0, 100.0, 100.0, 100.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &HostileGlow1021,
        &AlertInstantShieldedStrikeF2E8,
        &ResilientShieldedRampageAndRun1618
    }, &RakingCounter_attackC77B)
});

DinoKind Ankylosaurus("Ankylosaurus", EPIC, 1, {
    DinoRound(4650, 1000, 116, 30.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &GroupTauntingShieldsEB4C,
        &InstantInvincibilityTaunt6C65
    }, nullptr)
});

DinoKind AnkylosaurusGen2("Ankylosaurus Gen 2", COMMON, 1, {
    DinoRound(4200, 1000, 111, 25.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &GroupTauntingShieldsEB4C
    }, nullptr)
});

DinoKind Ankyntrosaurus("Ankyntrosaurus", LEGENDARY, 1, {
    DinoRound(3900, 900, 109, 40.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &GroupTauntingShieldsStrikeDA58,
        &InstantInvincibilityTaunt6C65,
        &TauntingRampage3362
    }, &MediumResilientCounter_attack3EB5)
});

DinoKind Antarctopelta("Antarctopelta", EPIC, 1, {
    DinoRound(3750, 1000, 111, 30.0, 10.0, 125.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &TauntingResilientGroupImpact240C,
        &RevengeInstantFerocity9F5A
    }, &DeceleratingCounterD9D3)
});

DinoKind Antarctovenator("Antarctovenator", UNIQUE, 1, {
    DinoRound(4200, 1300, 113, 20.0, 10.0, 125.0, 0.0, 0.0, 100.0, 0.0, 50.0, 75.0, 100.0, 0.0, 100.0, 0.0, 0.0, {
        &DispersedCunningStrike30D1,
        &VengefulFerociousDistraction5645,
        &VulnerabilityImpact2DAA,
        &RevengeDefiniteRampageED72
    }, &MediumNullifyingCounter4816)
});

DinoKind Anurognathus("Anurognathus", EPIC, 3, {
    DinoRound(2550, 1150, 131, 0.0, 10.0, 125.0, 0.0, 0.0, 0.0, 33.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &LimitedEvasiveStrike6F07,
        &AlertFrenzy3343
    }, &MinimalCriticalCounterECF3)
});

DinoKind Apatosaurus("Apatosaurus", COMMON, 1, {
    DinoRound(6000, 1100, 101, 0.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupDeceleratingImpact9451
    }, nullptr)
});

DinoKind Aquilamimus("Aquilamimus", EPIC, 1, {
    DinoRound(2850, 1150, 130, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &EvasiveStrikeA8EB,
        &DistractingImpactD4D6,
        &GroupDistractionFB00,
        &EvasiveRampage40C8
    }, nullptr)
});

DinoKind Arambourgiania("Arambourgiania", RARE, 1, {
    DinoRound(4350, 1000, 115, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupTauntingShieldsStrikeDA58,
        &RampageAndRunB223
    }, nullptr)
});

DinoKind Archaeopteryx("Archaeopteryx", RARE, 3, {
    DinoRound(3300, 1250, 127, 0.0, 10.0, 125.0, 0.0, 0.0, 0.0, 33.0, 0.0, 0.0, 75.0, 100.0, 0.0, 0.0, 0.0, {
        &AlertBuffAndStrike79FE,
        &EvasiveImpact7999,
        &DelayedCunningRampage5557
    }, nullptr)
});

DinoKind Archaeotherium("Archaeotherium", COMMON, 1, {
    DinoRound(4650, 1000, 123, 10.0, 20.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &GroupDefenseShatteringStrikeF98B,
        &MutualFury2752
    }, nullptr)
});

DinoKind Arctalces("Arctalces", LEGENDARY, 1, {
    DinoRound(3750, 1150, 113, 15.0, 5.0, 125.0, 0.0, 0.0, 0.0, 50.0, 100.0, 0.0, 33.0, 0.0, 50.0, 0.0, 0.0, {
        &ShieldedHeavyStrike02CB,
        &AlertDeceleratingImpact5396,
        &GroupDefensiveEdge19D2,
        &DigIn6DFE
    }, nullptr)
});

DinoKind Arctodus("Arctodus", RARE, 1, {
    DinoRound(4200, 1250, 107, 10.0, 5.0, 125.0, 0.0, 0.0, 0.0, 50.0, 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &HeavyStrike5748,
        &AlertDeceleratingImpact5396,
        &DefensiveEdgeF83D
    }, nullptr)
});

DinoKind Arctops("Arctops", RARE, 1, {
    DinoRound(3000, 1400, 131, 0.0, 5.0, 125.0, 100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &RevengeDistractingStrike50E9,
        &RampageB9EA
    }, nullptr)
});

DinoKind Arctovasilas("Arctovasilas", APEX, 1, {
    DinoRound(4800, 1400, 117, 34.99999, 5.0, 125.0, 0.0, 25.0, 50.0, 0.0, 75.0, 67.0, 33.0, 0.0, 100.0, 0.0, 0.0, {
        &CenozoicSmack8DC9,
        &AlertArcticBlast801B,
        &AlertPersistentGroupShields2A85,
        &ShieldedDevastation403E
    }, &CounterPowerHealA54F)
});

DinoKind Ardentismaxima("Ardentismaxima", UNIQUE, 1, {
    DinoRound(6000, 1300, 109, 10.0, 30.0, 125.0, 100.0, 25.0, 0.0, 0.0, 100.0, 100.0, 100.0, 100.0, 100.0, 0.0, 0.0, {
        &GroupResilientStrike74A6,
        &GroupDeceleratingRampageE77E,
        &TauntShatteringRampageDE3B,
        &InstantInvincibilityTaunt6C65
    }, nullptr)
});

DinoKind Ardontognathus("Ardontognathus", UNIQUE, 3, {
    DinoRound(3300, 1300, 123, 0.0, 25.0, 125.0, 100.0, 0.0, 75.0, 33.0, 0.0, 75.0, 67.0, 0.0, 50.0, 0.0, 0.0, {
        &CunningFierceStrike9D6C,
        &DeceleratingSideflap5BCD,
        &DefiniteAlertFrenzy84C4,
        &DefenseShatteringRampageC9FF
    }, &MinimalCriticalCounterECF3)
});

DinoKind Ardontosaurus("Ardontosaurus", LEGENDARY, 1, {
    DinoRound(4500, 1500, 108, 0.0, 20.0, 125.0, 100.0, 10.0, 50.0, 0.0, 100.0, 100.0, 75.0, 75.0, 50.0, 0.0, 0.0, {
        &FierceStrike106A,
        &GroupDeceleratingImpact9451,
        &TauntShatteringRampageDE3B,
        &InstantInvincibilityTaunt6C65
    }, nullptr)
});

DinoKind Argentavis("Argentavis", RARE, 1, {
    DinoRound(4050, 1050, 128, 0.0, 10.0, 125.0, 100.0, 0.0, 0.0, 50.0, 50.0, 50.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &Distraction2717,
        &FearlessFlap6CE3,
        &EvasiveImpact7999
    }, nullptr)
});

DinoKind Argenteryx("Argenteryx", EPIC, 3, {
    DinoRound(3750, 1150, 127, 0.0, 10.0, 125.0, 100.0, 0.0, 0.0, 33.0, 0.0, 0.0, 75.0, 100.0, 0.0, 0.0, 0.0, {
        &AlertBuffAndStrike79FE,
        &EvasiveRampage40C8,
        &FearlessAlertCC50,
        &DelayedCunningRampage5557
    }, nullptr)
});

DinoKind Argentinosaurus("Argentinosaurus", RARE, 1, {
    DinoRound(5400, 1100, 102, 0.0, 20.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupDeceleratingStrikeBAC6,
        &ExtendedCriticalStrike7DFE
    }, nullptr)
});

DinoKind Atrocimoloch("Atrocimoloch", UNIQUE, 1, {
    DinoRound(4500, 1450, 124, 15.0, 5.0, 125.0, 0.0, 33.0, 50.0, 0.0, 0.0, 50.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &ShieldedHeavyStrike02CB,
        &DeceleratingGroupHealD700,
        &InstantStunningImpact4833,
        &BerserkRampagingCloak51AA
    }, &PreciseShatteringCounter4D03)
});

DinoKind Atrocodistis("Atrocodistis", UNIQUE, 1, {
    DinoRound(4000, 1300, 123, 20.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 100.0, 100.0, 100.0, 0.0, 100.0, 0.0, 0.0, {
        &DispersedCunningStrike30D1,
        &AcceleratingShieldedDistraction80B6,
        &ShelteringImpact6881,
        &BerserkResilientRampageD249
    }, &PreciseCounterDFAC)
});

DinoKind Australotitan("Australotitan", OMEGA, 1, 50, 15, 1, 0.99999, 0.99999, 0.99999, 119, 74, 27, 20, 10, 25,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {6, RestrictionType::Ability, 3},
    {11, RestrictionType::Counter, 1},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(1150, 780, 86, 5.0, 0.0, 125.0, 0.0, 100.0, 50.0, 75.0, 50.0, 0.0, 0.0, 0.0, 50.0, 100.0, 0.0, {
        &GreaterRegeneratingStrike64EC,
        &GroupShatteringRegeneratingImpact1CE9,
        &TitanicTakedown07BC,
        &RegeneratingAlertDominance73EA
    }, &DistractingVulnerabilityCounterBBA8)
});

DinoKind Bajadasaurus("Bajadasaurus", RARE, 1, {
    DinoRound(4350, 900, 108, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &TauntingBellow3BBD,
        &Devastation3723
    }, nullptr)
});

DinoKind Bajatonodon("Bajatonodon", LEGENDARY, 1, {
    DinoRound(4500, 1500, 106, 0.0, 5.0, 125.0, 0.0, 50.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &LesserGroupHeal5491,
        &GroupInstantInvincibility82CC,
        &GreaterEmergencyHeal456B
    }, nullptr)
});

DinoKind Baryonyx("Baryonyx", EPIC, 1, {
    DinoRound(4200, 1400, 126, 0.0, 30.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 75.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &GroupTakedown066E,
        &FierceRampageDC31
    }, nullptr)
});

DinoKind BaryonyxGen2("Baryonyx Gen 2", RARE, 1, {
    DinoRound(4350, 1000, 123, 0.0, 20.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &ReadyToCrush43AE,
        &DefenseShatteringImpact25E3
    }, nullptr)
});

DinoKind Beelzebufo("Beelzebufo", EPIC, 3, {
    DinoRound(3600, 1550, 125, 0.0, 10.0, 125.0, 0.0, 100.0, 0.0, 33.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &FeastDEF6,
        &AfflictingStrike3614
    }, nullptr)
});

DinoKind Beta("Beta", EPIC, 1, {
    DinoRound(2400, 1200, 133, 0.0, 5.0, 125.0, 0.0, 0.0, 25.0, 0.0, 100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &EvasiveStrikeA8EB,
        &ImpactAndRun738D,
        &PlayfulPounce7B7E
    }, nullptr)
});

DinoKind Blue("Blue", EPIC, 1, {
    DinoRound(2400, 1300, 131, 0.0, 5.0, 125.0, 0.0, 0.0, 100.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &PrecisePounceF675,
        &EvasiveImpact7999
    }, nullptr)
});

DinoKind Borealopelta("Borealopelta", OMEGA, 1, 55, 15, 1, 0.99999, 1.99999, 1.99999, 124, 87, 12, 30, 10, 25,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {6, RestrictionType::Counter, 1},
    {11, RestrictionType::Ability, 3},
    {11, RestrictionType::DamageOverTimeResistance, 25.0},
    {11, RestrictionType::SpeedReductionResistance, 100.0},
    {11, RestrictionType::ArmorReductionResistance, 75.0},
    {16, RestrictionType::RendResistance, 66.0},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(1200, 375, 101, 0.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 0.0, 100.0, 0.0, 50.0, 50.0, 0.0, 0.0, {
        &GroupResilientStrike74A6,
        &ShieldedDeceleratingImpact426C,
        &ShieldedCleansingRampageF75B,
        &InstantStunningRevengeImpactCFDA
    }, &CounterSpikes5965)
});

DinoKind Brachiosaurus("Brachiosaurus", EPIC, 1, {
    DinoRound(6000, 1000, 111, 10.0, 30.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 67.0, 67.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupTauntingShieldsStrikeDA58,
        &ResilientRampageB23D
    }, nullptr)
});

DinoKind Brontolasmus("Brontolasmus", EPIC, 1, {
    DinoRound(3900, 1300, 108, 30.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ShieldedTauntingStrike73D4,
        &ResilientImpact7BB4,
        &TauntingRampage3362,
        &GroupDeceleratingRampageE77E
    }, nullptr)
});

DinoKind Brontotherium("Brontotherium", COMMON, 1, {
    DinoRound(4200, 1200, 108, 20.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ShieldedTauntingStrike73D4,
        &ResilientImpact7BB4
    }, nullptr)
});

DinoKind Bumpy("Bumpy", EPIC, 1, {
    DinoRound(4400, 1100, 113, 25.0, 10.0, 125.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &InstantInvincibilityTaunt6C65,
        &TauntingResilientGroupImpact240C
    }, nullptr)
});

DinoKind Carbonemys("Carbonemys", EPIC, 1, {
    DinoRound(3300, 900, 103, 60.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 50.0, 75.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &DigInTaunt1BB1,
        &Devastation3723
    }, nullptr)
});

DinoKind Carbotoceratops("Carbotoceratops", LEGENDARY, 1, {
    DinoRound(4350, 1000, 104, 50.0, 5.0, 125.0, 0.0, 50.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &Distraction2717,
        &DigInTaunt1BB1,
        &Devastation3723,
        &ExposeWeakSpot7AA2
    }, nullptr)
});

DinoKind Carcharodontosaurus("Carcharodontosaurus", OMEGA, 1, 40, 25, 1, 0.99999, 0.99999, 0.99999, 132, 54, 20, 0, 10, 50,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {11, RestrictionType::Ability, 3},
    {11, RestrictionType::CritReductionResistance, 50.0},
    {11, RestrictionType::DamageOverTimeResistance, 100.0},
    {11, RestrictionType::SpeedReductionResistance, 25.0},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(1150, 400, 110, 0.0, 30.0, 125.0, 0.0, 0.0, 75.0, 0.0, 0.0, 0.0, 100.0, 50.0, 0.0, 0.0, 0.0, {
        &BruisingStrikeC7B7,
        &PreciseGroupDistractingImpact6DF1,
        &InterruptingImpact42F9,
        &InstantFierceRampage6114
    }, nullptr)
});

DinoKind Carnotarkus("Carnotarkus", LEGENDARY, 1, {
    DinoRound(3600, 1000, 110, 20.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &SuperiorityStrike2549,
        &GroupDeceleratingRampageE77E,
        &LongProtection8331,
        &InstantDistractionF5AC
    }, &GreaterRendingCounter_attackD5C2)
});

DinoKind Carnotaurus("Carnotaurus", RARE, 1, {
    DinoRound(3600, 1000, 104, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &VulnerabilityStrike1E04,
        &TauntingShields1CF6,
        &CleansingImpact351E
    }, &GreaterRendingCounter_attackD5C2)
});

DinoKind Ceramagnus("Ceramagnus", APEX, 1, {
    DinoRound(4800, 1300, 113, 25.0, 10.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 100.0, 50.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupResilientStrike74A6,
        &ImminentStampede7426,
        &InstantChargingImpact7672,
        &PreciseRampageA036
    }, nullptr)
});

DinoKind Ceratosaurus("Ceratosaurus", UNIQUE, 1, {
    DinoRound(5350, 1650, 119, 15.0, 15.0, 125.0, 0.0, 100.0, 75.0, 50.0, 100.0, 100.0, 0.0, 0.0, 33.0, 50.0, 0.0, {
        &GroupHeavyStrike4F13,
        &ResilientRampageB23D,
        &Lacerate372D,
        &Intimidate52C1
    }, &PiercingHeadbuttF80E)
});

DinoKind CeratosaurusGen2("Ceratosaurus Gen 2", OMEGA, 1, 45, 20, 1, 0.0, 0.99999, 0.99999, 110, 87, 11, 0, 36, 10,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {6, RestrictionType::Ability, 3},
    {16, RestrictionType::Ability, 4},
    {16, RestrictionType::RendResistance, 67.0},
    {16, RestrictionType::DamageReductionResistance, 33.0},
    {16, RestrictionType::DamageOverTimeResistance, 50.0}
}, {
    DinoRound(1400, 410, 106, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 100.0, 50.0, 0.0, 0.0, {
        &GroupFierceStrikeA254,
        &ChallengingAlertImpact703E,
        &AlertFierceRampage5308,
        &BaredTeeth5269
    }, nullptr)
});

DinoKind Cervalces("Cervalces", RARE, 1, {
    DinoRound(3300, 1250, 128, 5.0, 10.0, 125.0, 0.0, 0.0, 100.0, 0.0, 100.0, 0.0, 33.0, 100.0, 50.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &DigIn6DFE,
        &ShieldedDeceleratingImpact426C
    }, nullptr)
});

DinoKind Charlie("Charlie", RARE, 1, {
    DinoRound(2100, 1450, 130, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &StrikeBE64,
        &HighPounceD062,
        &CunningImpactEE79
    }, nullptr)
});

DinoKind CleverGirl("Clever Girl", OMEGA, 1, 50, 20, 1, 0.99999, 0.99999, 0.99999, 84, 85, 18, 0, 70, 25,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {6, RestrictionType::Counter, 1},
    {11, RestrictionType::Ability, 3},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(1300, 500, 119, 0.0, 30.0, 125.0, 100.0, 33.0, 75.0, 0.0, 100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &DispersedCunningStrike30D1,
        &UpperClawA90A,
        &EvasiveHunt089A,
        &CautiousDoubleImpactE21D
    }, &CleverCounter3298)
});

DinoKind Coelhaast("Coelhaast", LEGENDARY, 3, {
    DinoRound(3150, 1250, 130, 0.0, 10.0, 125.0, 0.0, 0.0, 0.0, 33.0, 0.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &PrecisePiercingStrike93AA,
        &FearlessAlertCC50,
        &PreciseImpactAndRunF059,
        &RestrictedGroupDistraction08AC
    }, nullptr)
});

DinoKind Coelurosauravus("Coelurosauravus", COMMON, 3, {
    DinoRound(3450, 1050, 126, 0.0, 15.0, 125.0, 0.0, 0.0, 0.0, 33.0, 0.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &Distraction2717,
        &ImpactAndRun738D
    }, nullptr)
});

DinoKind Compsocaulus("Compsocaulus", UNIQUE, 3, {
    DinoRound(3750, 1350, 127, 0.0, 10.0, 125.0, 0.0, 0.0, 33.0, 33.0, 100.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &HopAndMockD6D1,
        &RestrictedGroupDistraction08AC,
        &AlertScurry6808
    }, nullptr)
});

DinoKind Compsognathus("Compsognathus", EPIC, 3, {
    DinoRound(3600, 1200, 128, 0.0, 5.0, 125.0, 0.0, 0.0, 66.0, 33.0, 0.0, 100.0, 50.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &HopAndMockD6D1,
        &AlertScurry6808
    }, nullptr)
});

DinoKind CompsognathusGen2("Compsognathus Gen 2", RARE, 3, {
    DinoRound(3750, 1100, 127, 0.0, 10.0, 125.0, 0.0, 0.0, 66.0, 33.0, 0.0, 100.0, 25.0, 0.0, 0.0, 0.0, 0.0, {
        &AlertSurge82DA,
        &HopAndMockD6D1,
        &ImpactAndRun738D
    }, nullptr)
});

DinoKind Compsoraptor("Compsoraptor", UNIQUE, 3, {
    DinoRound(3350, 1350, 130, 0.0, 30.0, 125.0, 0.0, 0.0, 100.0, 33.0, 100.0, 0.0, 0.0, 100.0, 50.0, 0.0, 0.0, {
        &AlertSurge82DA,
        &AlertShatteringImpact9D9B,
        &RampageAndRunB223,
        &PlayfulPounce7B7E
    }, nullptr)
});

DinoKind Concakuisaurus("Concakuisaurus", LEGENDARY, 1, {
    DinoRound(4800, 1150, 125, 0.0, 10.0, 125.0, 0.0, 0.0, 75.0, 33.0, 100.0, 50.0, 0.0, 100.0, 25.0, 0.0, 0.0, {
        &FerociousResilientStrike4855,
        &TauntingShieldedHealFDB6,
        &FierceRampage95D1,
        &GroupHasteningPreciseImpact3620
    }, &ShatteringDevourCounterStrike544B)
});

DinoKind Concatoloch("Concatoloch", APEX, 1, {
    DinoRound(4600, 1200, 112, 30.0, 5.0, 125.0, 0.0, 0.0, 75.0, 0.0, 100.0, 0.0, 100.0, 0.0, 50.0, 50.0, 0.0, {
        &InstantShieldedFerocityAD15,
        &GroupStunningSlowingImpactBC3F,
        &HasteningShelter3D24,
        &ExposeWeakness6777
    }, &PiercingCounterStrikeA03C)
});

DinoKind Concatosaurus("Concatosaurus", UNIQUE, 1, {
    DinoRound(5150, 1400, 115, 15.0, 10.0, 125.0, 0.0, 0.0, 75.0, 50.0, 25.0, 50.0, 50.0, 50.0, 50.0, 50.0, 0.0, {
        &FerociousResilientStrike4855,
        &CleansingGroupShieldD4D3,
        &RampageInterventionE0F0,
        &NullifyingGroupImpactBA4B
    }, &FerociousCounterHealingStrikeD730)
});

DinoKind Concavenator("Concavenator", EPIC, 1, {
    DinoRound(3750, 1150, 106, 0.0, 10.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 25.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &TauntingShields1CF6,
        &DefenseShatteringImpact25E3
    }, &DefenseShatteringCounterCA13)
});

DinoKind Constrictoraptor("Constrictoraptor", UNIQUE, 1, {
    DinoRound(4100, 1350, 125, 5.0, 10.0, 125.0, 100.0, 0.0, 75.0, 0.0, 100.0, 50.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &CautiousRetreat5570,
        &BerserkClawedRevenge111B,
        &BerserkBitingRevenge5D5E,
        &Stall897E
    }, &VenomousCounter4C31)
});

DinoKind Crichtomoloch("Crichtomoloch", UNIQUE, 1, {
    DinoRound(4650, 1450, 115, 15.0, 20.0, 125.0, 0.0, 33.0, 50.0, 66.0, 100.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupResilientStrike74A6,
        &InstantDodgeImpact4070,
        &AfflictingAlertStun7106,
        &SlyRampageAndRun367D
    }, &SurvivalInstinct12CC)
});

DinoKind Crichtonsaurus("Crichtonsaurus", RARE, 1, {
    DinoRound(4450, 1350, 118, 10.0, 20.0, 125.0, 0.0, 33.0, 50.0, 33.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupResilientStrike74A6,
        &Exhaust71B8,
        &CunningRampage8AEB
    }, nullptr)
});

DinoKind Cryolophosaurus("Cryolophosaurus", OMEGA, 1, 40, 20, 1, 0.99999, 0.99999, 0.99999, 128, 86, 8, 15, 20, 0,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {11, RestrictionType::Ability, 3},
    {11, RestrictionType::DamageOverTimeResistance, 75.0},
    {11, RestrictionType::DamageReductionResistance, 50.0},
    {11, RestrictionType::RendResistance, 50.0},
    {16, RestrictionType::Ability, 4}
}, {
    DinoRound(1000, 490, 101, 5.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 100.0, 0.0, 25.0, 0.0, 0.0, {
        &SuperiorAfflictingStrike2A2C,
        &GroupResilientImpact3AE3,
        &GreaterGroupHeal566D,
        &InstantDebilitatingShieldImpactC185
    }, &DeceleratingCounterD9D3)
});

DinoKind Dakotanops("Dakotanops", LEGENDARY, 1, {
    DinoRound(3300, 1200, 131, 0.0, 10.0, 125.0, 100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &Distraction2717,
        &PreciseImpact9D87,
        &DistractingImpactD4D6,
        &RevengeCunningRampage422C
    }, nullptr)
});

DinoKind Dakotaraptor("Dakotaraptor", EPIC, 1, {
    DinoRound(3300, 1350, 129, 0.0, 5.0, 125.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &Sidestep5439,
        &PrecisePounceF675,
        &GroupDistractingRampageA326
    }, &CounterFerocity85EF)
});

DinoKind Darwezopteryx("Darwezopteryx", LEGENDARY, 1, {
    DinoRound(4200, 1000, 127, 0.0, 5.0, 125.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &MinorSwoop6A00,
        &FierceImpactB3BE,
        &InstantInvincibility9B21
    }, nullptr)
});

DinoKind Darwinopterus("Darwinopterus", EPIC, 1, {
    DinoRound(2700, 1000, 129, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &PinningStrike3832,
        &MinorSwoop6A00,
        &FierceImpactB3BE
    }, nullptr)
});

DinoKind Deinocheirus("Deinocheirus", COMMON, 1, {
    DinoRound(2700, 1350, 131, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &MinimalSpeedupStrike44A5,
        &RevengeRampageACBE
    }, nullptr)
});

DinoKind Deinonychus("Deinonychus", COMMON, 1, {
    DinoRound(2100, 1200, 132, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &EvasiveStrikeA8EB,
        &HighPounceD062
    }, nullptr)
});

DinoKind Deinotherium("Deinotherium", RARE, 1, {
    DinoRound(3900, 1050, 115, 5.0, 10.0, 125.0, 100.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &SuperiorityStrike2549,
        &FerociousImpactA5CC,
        &InstantRumble2784
    }, nullptr)
});

DinoKind Delta("Delta", RARE, 1, {
    DinoRound(2400, 1300, 131, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &StrikeBE64,
        &HighPounceD062,
        &ImpactAndRun738D
    }, nullptr)
});

DinoKind Diabloceratops("Diabloceratops", OMEGA, 1, 50, 10, 1, 1.99999, 0.99999, 0.99999, 140, 140, 5, 17, 20, 5,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {11, RestrictionType::Ability, 3},
    {16, RestrictionType::Counter, 1},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(1500, 400, 104, 5.99999, 5.0, 125.0, 0.0, 50.0, 0.0, 60.0, 0.0, 100.0, 100.0, 0.0, 100.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GreaterStunningImpact2966,
        &LeadingChargeF1FA,
        &InstantCrush1C8F
    }, &SurvivalInstinctB690)
});

DinoKind Dilophoboa("Dilophoboa", LEGENDARY, 1, {
    DinoRound(3600, 1100, 124, 0.0, 10.0, 125.0, 100.0, 0.0, 100.0, 0.0, 50.0, 67.0, 75.0, 100.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &PreciseRampageA036,
        &NullifyingImpact65A2,
        &Sidestep5439
    }, &VenomousCounter56D1)
});

DinoKind Dilophosaurus("Dilophosaurus", RARE, 1, {
    DinoRound(3600, 1300, 124, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &DistractingImpactD4D6,
        &CunningRampage8AEB
    }, nullptr)
});

DinoKind DilophosaurusGen2("Dilophosaurus Gen 2", COMMON, 1, {
    DinoRound(2550, 1850, 121, 0.0, 5.0, 125.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &ImpactA82F
    }, nullptr)
});

DinoKind Diloracheirus("Diloracheirus", UNIQUE, 1, {
    DinoRound(4470, 1650, 128, 0.0, 10.0, 125.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DispersedCunningStrike30D1,
        &AcceleratingTeamHealEAF5,
        &DistractingTeamHeal41AD,
        &RevengeCunningRampage422C
    }, &DartingCounter6039)
});

DinoKind Diloranosaurus("Diloranosaurus", LEGENDARY, 1, {
    DinoRound(4200, 1500, 116, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 67.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &CunningImpactEE79,
        &LesserGroupHeal5491,
        &GreaterEmergencyHeal456B
    }, nullptr)
});

DinoKind Dimetrodon("Dimetrodon", RARE, 1, {
    DinoRound(4200, 1400, 113, 0.0, 5.0, 125.0, 0.0, 100.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &DefenseShatteringImpact25E3,
        &CriticalImpactD735
    }, nullptr)
});

DinoKind DimetrodonGen2("Dimetrodon Gen 2", COMMON, 1, {
    DinoRound(4500, 1200, 112, 0.0, 5.0, 125.0, 0.0, 100.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &ArmorPiercingRampage4328
    }, nullptr)
});

DinoKind Dimodactylus("Dimodactylus", EPIC, 1, {
    DinoRound(3750, 1150, 127, 0.0, 15.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &DisarmingStrike7427,
        &CleansingSwoopB410,
        &ShortDefense7ED4,
        &DisarmingImpactAndRunC0BA
    }, &DisarmingCounterStrike8AAD)
});

DinoKind Dimorphodon("Dimorphodon", COMMON, 1, {
    DinoRound(2700, 500, 128, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 50.0, 0.0, 0.0, {
        &StrikeBE64,
        &GashingWound4BC2
    }, nullptr)
});

DinoKind Diorajasaur("Diorajasaur", UNIQUE, 1, {
    DinoRound(4800, 1200, 108, 30.0, 30.0, 125.0, 100.0, 0.0, 75.0, 0.0, 100.0, 50.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &ResilientRampageB23D,
        &SecureTaunt7C74,
        &InstantInvincibilityTaunt6C65
    }, &RakingCounter_attackC77B)
});

DinoKind Diplocaulus("Diplocaulus", COMMON, 1, {
    DinoRound(2850, 1600, 125, 0.0, 5.0, 125.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &Distraction2717,
        &NullifyingImpact65A2
    }, nullptr)
});

DinoKind DiplocaulusGen2("Diplocaulus Gen 2", RARE, 1, {
    DinoRound(4050, 1000, 125, 0.0, 5.0, 125.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &DistractingImpactD4D6,
        &InstantDistractionF5AC
    }, nullptr)
});

DinoKind Diplodocus("Diplodocus", EPIC, 1, {
    DinoRound(6000, 1500, 104, 0.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupDeceleratingRampageE77E,
        &ShieldAdvantage90B9
    }, nullptr)
});

DinoKind Diplotator("Diplotator", RARE, 1, {
    DinoRound(3000, 1400, 127, 0.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &FerociousStrike71CC,
        &DistractingStrikeD81E,
        &DefenseShatteringImpact25E3
    }, nullptr)
});

DinoKind Diplovenator("Diplovenator", LEGENDARY, 1, {
    DinoRound(4050, 1000, 110, 0.0, 5.0, 125.0, 0.0, 0.0, 100.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DefiniteStrike51A6,
        &InstantDistractionF5AC,
        &DistractingImpactD4D6,
        &CunningRampage8AEB
    }, &PreciseShatteringCounter4D03)
});

DinoKind DireWolf("Dire Wolf", RARE, 1, {
    DinoRound(3600, 1450, 127, 0.0, 20.0, 125.0, 100.0, 50.0, 0.0, 0.0, 50.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &DisarmingStrike7427,
        &HowlEBEA,
        &DevouringImpact0320
    }, nullptr)
});

DinoKind Dodo("Dodo", EPIC, 3, {
    DinoRound(3900, 1200, 123, 0.0, 5.0, 125.0, 100.0, 0.0, 0.0, 33.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &FlightlessStrikeCC17,
        &ProtectiveAlert2FA4,
        &BerserkAlertDecoy8557
    }, nullptr)
});

DinoKind Dodocevia("Dodocevia", LEGENDARY, 3, {
    DinoRound(4050, 1400, 126, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 33.0, 50.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &FlightlessStrikeCC17,
        &ProtectiveAlert2FA4,
        &RevengeDistractingImpact25D1,
        &BerserkAlertDecoy8557
    }, nullptr)
});

DinoKind Doedicurus("Doedicurus", RARE, 1, {
    DinoRound(4200, 1200, 111, 50.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &DeceleratingRampageD0C5,
        &GroupTauntingShieldsEB4C
    }, nullptr)
});

DinoKind DracoLux("Draco Lux", APEX, 1, {
    DinoRound(4950, 1700, 128, 15.0, 15.0, 125.0, 0.0, 50.0, 50.0, 0.0, 50.0, 100.0, 100.0, 0.0, 50.0, 0.0, 0.0, {
        &CunningHeavyStrike5DC6,
        &QuickeningPreciseImpact1087,
        &AfflictingHorn91AA,
        &LightspeedChargeAndRun96DD
    }, nullptr)
});

DinoKind Dracoceratops("Dracoceratops", LEGENDARY, 1, {
    DinoRound(4200, 1500, 115, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &FierceStrike106A,
        &FierceImpactB3BE,
        &AcuteStun1F1E,
        &CleansingImpact351E
    }, nullptr)
});

DinoKind Dracoceratosaurus("Dracoceratosaurus", UNIQUE, 1, {
    DinoRound(4500, 1600, 120, 20.0, 5.0, 125.0, 100.0, 25.0, 75.0, 0.0, 100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &DebilitatingStrike1814,
        &CleansingImpact351E,
        &BristlingStun38A2,
        &CunningRampage8AEB
    }, nullptr)
});

DinoKind Dracorex("Dracorex", RARE, 1, {
    DinoRound(4800, 1100, 124, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &SuperiorityStrike2549,
        &ResilientImpact7BB4,
        &InstantCharge0917
    }, nullptr)
});

DinoKind DracorexGen2("Dracorex Gen 2", COMMON, 1, {
    DinoRound(3600, 1500, 108, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ArmorPiercingStrike69E0,
        &FierceImpactB3BE
    }, nullptr)
});

DinoKind Dracovenator("Dracovenator", UNIQUE, 1, {
    DinoRound(4500, 1750, 128, 0.0, 20.0, 125.0, 0.0, 100.0, 100.0, 75.0, 0.0, 100.0, 50.0, 0.0, 0.0, 0.0, 0.0, {
        &DispersedCunningStrike30D1,
        &InstantDodgeImpact4070,
        &NullifyingImpact65A2,
        &CloakedRampageAlert9A3E
    }, nullptr)
});

DinoKind Dreadactylus("Dreadactylus", LEGENDARY, 3, {
    DinoRound(4200, 1000, 112, 5.0, 5.0, 125.0, 0.0, 0.0, 0.0, 33.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &GroupDeceleratingStrikeBAC6,
        &CunningImpactEE79,
        &TauntingRampage3362
    }, &CounterVulnerability02E9)
});

DinoKind Dreadnoughtus("Dreadnoughtus", RARE, 1, {
    DinoRound(6000, 1000, 107, 10.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &GroupDeceleratingImpact9451,
        &TauntingShieldRampageE20B
    }, nullptr)
});

DinoKind Dsungaia("Dsungaia", LEGENDARY, 1, {
    DinoRound(4200, 1050, 117, 20.0, 5.0, 125.0, 0.0, 25.0, 100.0, 25.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &ShieldedDeceleratingStrike627F,
        &GroupDeceleratingImpact9451,
        &GroupFerocityC6F7,
        &GreaterEmergencyHeal456B
    }, &DeceleratingCounterD9D3)
});

DinoKind Dsungaripterus("Dsungaripterus", RARE, 1, {
    DinoRound(3450, 1000, 125, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &FerociousStrike71CC,
        &FierceImpactB3BE
    }, &ArmorPiercingCounterAEB5)
});

DinoKind Dsungascorpios("Dsungascorpios", UNIQUE, 3, {
    DinoRound(3300, 1100, 116, 30.0, 15.0, 125.0, 100.0, 100.0, 0.0, 33.0, 0.0, 100.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &DevouringStinger965B,
        &ShieldedLockdown6EE2,
        &DispersedFerociousImpact78DD,
        &EnfeeblingRampage8631
    }, &ShatteringAntidoteF861)
});

DinoKind Echo("Echo", RARE, 1, {
    DinoRound(2100, 1350, 129, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &PrecisePounceF675,
        &CleansingImpact351E
    }, nullptr)
});

DinoKind Edaphocevia("Edaphocevia", LEGENDARY, 1, {
    DinoRound(4400, 1250, 127, 0.0, 5.0, 125.0, 100.0, 75.0, 50.0, 50.0, 75.0, 75.0, 75.0, 0.0, 50.0, 0.0, 0.0, {
        &PersistentFerociousStrikeAF52,
        &PreciseRampageA036,
        &GroupRevengeShatteringRampageFCB6,
        &RevengeDistractingImpact25D1
    }, nullptr)
});

DinoKind Edaphosaurus("Edaphosaurus", EPIC, 1, {
    DinoRound(4500, 1000, 115, 0.0, 20.0, 125.0, 0.0, 100.0, 50.0, 50.0, 100.0, 100.0, 75.0, 0.0, 100.0, 0.0, 0.0, {
        &PersistentFerociousStrikeAF52,
        &FierceImpactB3BE,
        &FierceRampageDC31
    }, nullptr)
});

DinoKind Edmontoguanodon("Edmontoguanodon", EPIC, 1, {
    DinoRound(4500, 1200, 110, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupCleansingStrike8B0C,
        &LesserGroupHeal5491,
        &GroupResilientImpact3AE3,
        &GreaterEmergencyHeal456B
    }, nullptr)
});

DinoKind Edmontosaurus("Edmontosaurus", RARE, 1, {
    DinoRound(4800, 1000, 113, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupCleansingStrike8B0C,
        &LesserGroupHeal5491,
        &ResilientImpact7BB4
    }, nullptr)
});

DinoKind Einiasuchus("Einiasuchus", RARE, 1, {
    DinoRound(3600, 1000, 111, 20.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &DigIn6DFE,
        &GreaterStunningStrikeBAEF,
        &ResilientImpact7BB4
    }, nullptr)
});

DinoKind Einiosaurus("Einiosaurus", COMMON, 1, {
    DinoRound(3600, 1000, 110, 15.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &HealA906
    }, nullptr)
});

DinoKind Elasmotherium("Elasmotherium", RARE, 1, {
    DinoRound(4500, 1250, 108, 30.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ShieldedTauntingStrike73D4,
        &ResilientImpact7BB4,
        &TauntingRampage3362
    }, nullptr)
});

DinoKind Enteloceros("Enteloceros", LEGENDARY, 1, {
    DinoRound(4500, 1300, 126, 20.0, 10.0, 125.0, 0.0, 0.0, 0.0, 50.0, 50.0, 100.0, 67.0, 0.0, 100.0, 0.0, 0.0, {
        &SuperiorityStrike2549,
        &MutualFury2752,
        &DigIn6DFE,
        &GroupRevengeShatteringRampageFCB6
    }, nullptr)
});

DinoKind Entelochops("Entelochops", EPIC, 1, {
    DinoRound(4200, 1100, 126, 20.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 25.0, 0.0, 0.0, {
        &SuperiorityStrike2549,
        &RevengeDeceleratingImpact6A2C,
        &MutualFury2752,
        &RevengeShatteringRampageD874
    }, nullptr)
});

DinoKind Entelodon("Entelodon", RARE, 1, {
    DinoRound(3600, 1200, 122, 0.0, 30.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &MutualFury2752,
        &GroupShatteringImpact7EAE
    }, nullptr)
});

DinoKind Entelolania("Entelolania", UNIQUE, 1, {
    DinoRound(4200, 1400, 107, 55.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &PersistentFerociousStrikeAF52,
        &DigIn6DFE,
        &GroupResilientImpact3AE3,
        &ResilientDevastationF536
    }, &MinorDeceleratingCounter076E)
});

DinoKind Entelomoth("Entelomoth", LEGENDARY, 1, {
    DinoRound(4200, 1000, 120, 20.0, 5.0, 125.0, 0.0, 50.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &PersistentFerociousStrikeAF52,
        &MutualFury2752,
        &GroupShatteringImpact7EAE,
        &Bellow866E
    }, nullptr)
});

DinoKind Eremoceros("Eremoceros", LEGENDARY, 1, {
    DinoRound(3900, 1300, 126, 10.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 50.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &ShieldedDeceleratingStrike627F,
        &Camouflage03BB,
        &DigIn6DFE,
        &CunningRampage8AEB
    }, nullptr)
});

DinoKind Eremotherium("Eremotherium", COMMON, 1, {
    DinoRound(3150, 1050, 102, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &Camouflage03BB,
        &CunningRampage8AEB
    }, &MaximalCounter_attack5683)
});

DinoKind Erlidominus("Erlidominus", UNIQUE, 1, {
    DinoRound(3600, 1600, 131, 0.0, 50.0, 125.0, 100.0, 100.0, 100.0, 50.0, 50.0, 100.0, 100.0, 0.0, 25.0, 0.0, 0.0, {
        &MinimalSpeedupStrike44A5,
        &DistractingRampageBD0D,
        &FerociousCunningImpact683F,
        &Cloak2513
    }, nullptr)
});

DinoKind Erlikogamma("Erlikogamma", EPIC, 1, {
    DinoRound(3000, 1450, 130, 0.0, 5.0, 125.0, 100.0, 50.0, 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &MinimalSpeedupStrike44A5,
        &PrecisePounceF675,
        &DebilitatingDistraction3695,
        &StrikeAndRun11DF
    }, nullptr)
});

DinoKind Erlikosaurus("Erlikosaurus", EPIC, 1, {
    DinoRound(3000, 1400, 129, 0.0, 5.0, 125.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &MinimalSpeedupStrike44A5,
        &PreciseRampageA036,
        &DistractingStrikeD81E
    }, nullptr)
});

DinoKind ErlikosaurusGen2("Erlikosaurus Gen 2", RARE, 1, {
    DinoRound(3000, 1350, 129, 0.0, 5.0, 125.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &MinimalSpeedupStrike44A5,
        &PreciseRampageA036,
        &DebilitatingDistraction3695
    }, nullptr)
});

DinoKind Erlikospyx("Erlikospyx", UNIQUE, 1, {
    DinoRound(4650, 1650, 128, 0.0, 20.0, 125.0, 100.0, 100.0, 100.0, 0.0, 75.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &InstantDeceleratingDistraction2B7F,
        &RevengeDistractingImpact25D1,
        &PrecisePounceF675
    }, nullptr)
});

DinoKind Eucladoceros("Eucladoceros", EPIC, 1, {
    DinoRound(3300, 1000, 128, 10.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 75.0, 0.0, 100.0, 0.0, 75.0, 0.0, 0.0, {
        &ShieldedDeceleratingStrike627F,
        &SuperiorityImpact5FE3,
        &DigIn6DFE
    }, nullptr)
});

DinoKind Euoplocephalus("Euoplocephalus", COMMON, 1, {
    DinoRound(3600, 900, 112, 40.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &RampageB9EA
    }, nullptr)
});

DinoKind Fukuimimus("Fukuimimus", LEGENDARY, 1, {
    DinoRound(4800, 1250, 121, 0.0, 15.0, 125.0, 100.0, 0.0, 100.0, 0.0, 50.0, 50.0, 75.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupCleansingStrike8B0C,
        &Shelter12ED,
        &Remedy4769,
        &GroupCunningRampageA204
    }, &PersistentCounter25A1)
});

DinoKind Fukuiraptor("Fukuiraptor", OMEGA, 1, 40, 20, 1, 0.99999, 0.99999, 0.99999, 89, 79, 15, 10, 80, 25,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {6, RestrictionType::Ability, 3},
    {11, RestrictionType::Counter, 1},
    {16, RestrictionType::Ability, 4}
}, {
    DinoRound(1150, 530, 117, 10.0, 20.0, 125.0, 75.0, 0.0, 50.0, 25.0, 100.0, 25.0, 0.0, 100.0, 50.0, 0.0, 0.0, {
        &EliminationStrike093B,
        &PounceAndBite8E57,
        &Anticipation4EF9,
        &EvasiveImpactBA40
    }, &PersistentCounter25A1)
});

DinoKind Fukuisaurus("Fukuisaurus", RARE, 1, {
    DinoRound(4650, 1050, 115, 0.0, 5.0, 125.0, 100.0, 0.0, 50.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupCleansingStrike8B0C,
        &Shelter12ED,
        &GroupResilientImpact3AE3
    }, &PersistentCounter25A1)
});

DinoKind Gallimimus("Gallimimus", COMMON, 1, {
    DinoRound(2700, 1300, 130, 0.0, 5.0, 125.0, 0.0, 0.0, 100.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &EvasiveStrikeA8EB,
        &ImpactAndRun738D
    }, nullptr)
});

DinoKind Geminideus("Geminideus", APEX, 1, {
    DinoRound(6600, 1200, 110, 30.0, 5.0, 125.0, 100.0, 25.0, 50.0, 0.0, 0.0, 100.0, 0.0, 100.0, 75.0, 75.0, 0.0, {
        &SlowingResilientStrikeB132,
        &GroupDisarmingRampage7FC1,
        &ShieldingAlertRampage3625,
        &Harden1485
    }, &PreciseGroupCounter7420)
});

DinoKind Geminititan("Geminititan", UNIQUE, 1, {
    DinoRound(5600, 1300, 110, 0.0, 5.0, 125.0, 100.0, 0.0, 50.0, 0.0, 100.0, 100.0, 100.0, 67.0, 50.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupDeceleratingRampageE77E,
        &DefiniteShieldAdvantageED59,
        &GroupInstantInvincibility82CC
    }, &DistractingCounterA897)
});

DinoKind Geosternbergia("Geosternbergia", OMEGA, 1, 40, 25, 1, 0.99999, 0.99999, 0.99999, 109, 63, 23, 10, 15, 25,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {11, RestrictionType::Ability, 3},
    {16, RestrictionType::Ability, 4}
}, {
    DinoRound(1320, 575, 96, 5.0, 0.0, 125.0, 25.0, 75.0, 25.0, 0.0, 0.0, 50.0, 0.0, 0.0, 100.0, 75.0, 0.0, {
        &FerociousFlyingStrike4452,
        &DispersedFierceImpact938B,
        &GnawingRampage1D95,
        &DivebombBE13
    }, nullptr)
});

DinoKind Ghost("Ghost", EPIC, 1, {
    DinoRound(3000, 1350, 130, 0.0, 10.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &CautiousStrike3CE4,
        &FierceImpactB3BE,
        &BerserkDecimation51AD
    }, nullptr)
});

DinoKind Giganotosaurus("Giganotosaurus", EPIC, 1, {
    DinoRound(5400, 1700, 102, 0.0, 30.0, 125.0, 0.0, 50.0, 0.0, 50.0, 100.0, 0.0, 50.0, 0.0, 50.0, 0.0, 0.0, {
        &FierceDevouringCleanse4BB9,
        &GroupDefenseShatteringImpact0C66,
        &FierceRampageDC31
    }, nullptr)
});

DinoKind Giganspinoceratops("Giganspinoceratops", UNIQUE, 1, {
    DinoRound(4750, 1350, 114, 15.0, 5.0, 125.0, 0.0, 0.0, 50.0, 66.0, 100.0, 100.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &ProtectiveAdvanceCA82,
        &BracingTauntAndImpactB08C,
        &NullifyingRampage11B6,
        &FerociousImpactA5CC
    }, &MediumResilientCounter_attack3EB5)
});

DinoKind Gigantspinosaurus("Gigantspinosaurus", EPIC, 1, {
    DinoRound(4980, 1350, 112, 15.0, 15.0, 125.0, 0.0, 0.0, 75.0, 50.0, 50.0, 100.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &GroupResilientStrike74A6,
        &BracingTauntAndImpactB08C,
        &NullifyingRampage11B6
    }, &LuringCounterStrike24B8)
});

DinoKind Giganyx("Giganyx", UNIQUE, 1, {
    DinoRound(5100, 1650, 125, 0.0, 25.0, 125.0, 0.0, 50.0, 50.0, 50.0, 100.0, 75.0, 50.0, 0.0, 50.0, 0.0, 0.0, {
        &FierceDevouringCleanse4BB9,
        &ObstructingFierceImpact9462,
        &FierceDevouringRampage6CE7,
        &FerociousRestoreD2AB
    }, nullptr)
});

DinoKind Gigaspikasaur("Gigaspikasaur", LEGENDARY, 1, {
    DinoRound(4650, 1200, 108, 40.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupDeceleratingStrikeBAC6,
        &GroupRampage4077,
        &ShortDefense7ED4
    }, &PreciseCounterDFAC)
});

DinoKind Giraffatitan("Giraffatitan", RARE, 1, {
    DinoRound(5700, 1000, 107, 10.0, 20.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 75.0, 75.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &TauntingBellow3BBD,
        &RampageB9EA
    }, nullptr)
});

DinoKind Glyptoceras("Glyptoceras", LEGENDARY, 1, {
    DinoRound(3750, 1300, 113, 25.0, 10.0, 125.0, 100.0, 0.0, 75.0, 0.0, 50.0, 0.0, 0.0, 0.0, 25.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &InstantCharge0917,
        &ResilientImpact7BB4,
        &CriticalRampageA0F6
    }, nullptr)
});

DinoKind Glyptodon("Glyptodon", COMMON, 1, {
    DinoRound(3900, 1000, 103, 40.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &ResilientRampageB23D
    }, nullptr)
});

DinoKind Gorgonops("Gorgonops", RARE, 1, {
    DinoRound(3150, 1100, 132, 0.0, 10.0, 125.0, 100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &Distraction2717,
        &CunningImpactEE79,
        &RevengeRampageACBE
    }, nullptr)
});

DinoKind Gorgosaurus("Gorgosaurus", RARE, 1, {
    DinoRound(4200, 1700, 102, 0.0, 20.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &FierceStrike106A,
        &DefenseShatteringImpact25E3,
        &FerociousStrike71CC
    }, nullptr)
});

DinoKind Gorgosuchus("Gorgosuchus", EPIC, 1, {
    DinoRound(4500, 1000, 120, 0.0, 30.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &FierceStrike106A,
        &GroupFerocityStrike7A2D,
        &FierceRampageDC31,
        &CleansingImpact351E
    }, nullptr)
});

DinoKind Gorgotrebax("Gorgotrebax", APEX, 1, {
    DinoRound(4800, 1600, 113, 5.0, 20.0, 125.0, 100.0, 75.0, 100.0, 75.0, 0.0, 100.0, 75.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupAccelerateCunningStrikeF6AA,
        &CautiousImpact0569,
        &RevengeNullifyingRampage9284,
        &RevengeGroupDisablingImpact2C08
    }, &DistractingCounterA897)
});

DinoKind Gryganyth("Gryganyth", APEX, 1, {
    DinoRound(5200, 1750, 123, 10.0, 20.0, 125.0, 0.0, 100.0, 33.0, 33.0, 50.0, 50.0, 100.0, 0.0, 75.0, 0.0, 0.0, {
        &HealingFierceStrike4869,
        &SkewerB3B7,
        &FierceDevouringRampage6CE7,
        &MaximumFerocity2FCC
    }, &GreaterRendingCounter_attackD5C2)
});

DinoKind Grylenken("Grylenken", LEGENDARY, 1, {
    DinoRound(3600, 1500, 129, 10.0, 30.0, 150.0, 50.0, 100.0, 50.0, 0.0, 50.0, 0.0, 75.0, 0.0, 0.0, 0.0, 0.0, {
        &DeviousStrike53F7,
        &FoulRakingClaws91FC,
        &DisarmingDecimateAndRunB62E,
        &InstantBuff41DC
    }, &MinorCriticalCounterE7FC)
});

DinoKind Grypolyth("Grypolyth", UNIQUE, 1, {
    DinoRound(4380, 1400, 106, 20.0, 5.0, 125.0, 0.0, 33.0, 0.0, 75.0, 0.0, 100.0, 67.0, 0.0, 0.0, 0.0, 0.0, {
        &FierceStrike106A,
        &ImmobilizeEA4E,
        &EmergencyHeal679C,
        &FerociousDefense7932
    }, &RendingCounter_attack24B1)
});

DinoKind Gryposuchus("Gryposuchus", EPIC, 1, {
    DinoRound(4200, 1200, 116, 20.0, 20.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &ImmobilizeEA4E,
        &FerociousStrike71CC
    }, nullptr)
});

DinoKind HaastEagle("Haast Eagle", EPIC, 1, {
    DinoRound(2700, 1150, 132, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &FearlessFlap6CE3,
        &DistractingImpactD4D6
    }, nullptr)
});

DinoKind HaastEagleGen2("Haast Eagle Gen 2", RARE, 1, {
    DinoRound(3000, 1000, 130, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &Distraction2717,
        &FearlessFlap6CE3,
        &InstantDistractionF5AC
    }, nullptr)
});

DinoKind HaastMaximus("Haast Maximus", APEX, 1, {
    DinoRound(4950, 1550, 128, 0.0, 25.0, 125.0, 100.0, 50.0, 75.0, 50.0, 0.0, 75.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &PredatoryPeck7590,
        &FearlessFlap6CE3,
        &PiercingScreechB4D7,
        &RavenousRampage476D
    }, nullptr)
});

DinoKind HadrosLux("Hadros Lux", APEX, 1, {
    DinoRound(5100, 1450, 108, 10.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 100.0, 100.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &ProtectiveAdvanceCA82,
        &ResilientRampageB23D,
        &GreaterEmergencyHeal456B,
        &ShieldedDeceleratingImpact426C
    }, &MediumResilientCounter_attack3EB5)
});

DinoKind Hatzegopteryx("Hatzegopteryx", COMMON, 1, {
    DinoRound(4500, 1150, 114, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &ImpactAndRun738D
    }, nullptr)
});

DinoKind Homalocephale("Homalocephale", OMEGA, 1, 40, 15, 1, 0.99999, 0.99999, 0.99999, 134, 102, 16, 15, 20, 15,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {11, RestrictionType::Ability, 3},
    {16, RestrictionType::Ability, 4}
}, {
    DinoRound(1350, 420, 102, 5.0, 5.0, 125.0, 0.0, 25.0, 50.0, 100.0, 0.0, 0.0, 0.0, 0.0, 100.0, 50.0, 0.0, {
        &Bulwark2D7E,
        &GroupResilientImpact3AE3,
        &BellowingImpact7163,
        &HeadToHead1ABD
    }, nullptr)
});

DinoKind HydraBoa("Hydra Boa", APEX, 1, {
    DinoRound(4200, 1450, 122, 15.0, 30.0, 125.0, 0.0, 50.0, 100.0, 50.0, 100.0, 75.0, 75.0, 0.0, 0.0, 0.0, 0.0, {
        &InstantNullifyingStrike1708,
        &SlipperyAlertB2DD,
        &PreciseDistractingImpact90A3,
        &FabledFangs9083
    }, &AlertDeception0644)
});

DinoKind Ichthyovenator("Ichthyovenator", OMEGA, 1, 30, 35, 1, 0.0, 0.99999, 0.99999, 122, 35, 13, 0, 65, 50,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {11, RestrictionType::Ability, 3},
    {16, RestrictionType::Counter, 1},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(1350, 440, 118, 0.0, 10.0, 125.0, 25.0, 50.0, 100.0, 0.0, 100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupDefiniteStrike14BB,
        &DevouringImpact0320,
        &CunningFerociousStrike6867,
        &CautiousCunningRampage8C7B
    }, &BaitAD47)
});

DinoKind Iguanodon("Iguanodon", COMMON, 1, {
    DinoRound(4500, 1200, 112, 0.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ProtectTheHerdC716,
        &ShelteringImpact6881
    }, nullptr)
});

DinoKind Imperatosuchus("Imperatosuchus", APEX, 1, {
    DinoRound(4650, 1350, 112, 25.0, 15.0, 125.0, 0.0, 67.0, 0.0, 33.0, 100.0, 100.0, 67.0, 50.0, 100.0, 0.0, 0.0, {
        &FierceDeceleratingStrike401B,
        &DeathRollD52C,
        &Bask359E,
        &VulnerabilityRampage46FB
    }, &DefenseShatteringCounter_attackD663)
});

DinoKind Indolycan("Indolycan", APEX, 1, {
    DinoRound(4500, 1700, 130, 0.0, 30.0, 125.0, 100.0, 0.0, 50.0, 50.0, 100.0, 75.0, 100.0, 0.0, 100.0, 0.0, 0.0, {
        &CautiousDisarmingStrikeBCD2,
        &DistractingDevourImpactF535,
        &EvasiveFerociousRampageFFBB,
        &CloakOfRage7990
    }, &MinorPreciseCounterA27F)
});

DinoKind IndominusRex("Indominus Rex", LEGENDARY, 1, {
    DinoRound(4500, 1500, 107, 0.0, 30.0, 125.0, 0.0, 100.0, 50.0, 50.0, 100.0, 100.0, 100.0, 0.0, 50.0, 0.0, 0.0, {
        &FierceStrike106A,
        &ArmorPiercingImpactB10F,
        &ArmorPiercingRampage4328,
        &Cloak2513
    }, nullptr)
});

DinoKind IndominusRexGen2("Indominus Rex Gen 2", EPIC, 1, {
    DinoRound(4200, 1400, 108, 0.0, 20.0, 125.0, 0.0, 100.0, 50.0, 34.0, 100.0, 100.0, 100.0, 0.0, 100.0, 0.0, 0.0, {
        &GroupDefiniteStrike14BB,
        &MutualFury2752,
        &FierceRampageDC31,
        &Cloak2513
    }, nullptr)
});

DinoKind Indonemys("Indonemys", APEX, 1, {
    DinoRound(4500, 1550, 119, 30.0, 20.0, 125.0, 0.0, 50.0, 25.0, 25.0, 75.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &LesserFierceDeceleratingStrike2F7B,
        &FierceDevouringImpactB728,
        &DebilitatingRampageAndRun5304,
        &ProwlingRevengeCloakC144
    }, &BaitAD47)
});

DinoKind Indoraptor("Indoraptor", UNIQUE, 1, {
    DinoRound(4200, 1400, 128, 0.0, 20.0, 125.0, 100.0, 0.0, 75.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &CleansingImpact351E,
        &FierceRampageDC31,
        &EvasiveStanceF473
    }, &BaitAD47)
});

DinoKind IndoraptorGen2("Indoraptor Gen 2", LEGENDARY, 1, {
    DinoRound(3900, 1450, 128, 0.0, 20.0, 125.0, 100.0, 0.0, 75.0, 0.0, 0.0, 75.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CautiousStrike3CE4,
        &MutualFury2752,
        &DistractingImpactD4D6,
        &EvasiveStanceF473
    }, nullptr)
});

DinoKind Indotaurus("Indotaurus", UNIQUE, 1, {
    DinoRound(4650, 1600, 106, 0.0, 20.0, 125.0, 0.0, 0.0, 0.0, 34.0, 75.0, 50.0, 67.0, 0.0, 50.0, 0.0, 0.0, {
        &FierceStrike106A,
        &IntimidatingImpact50F9,
        &CleansingRampageC8DB,
        &RevengeTauntingCloak02DA
    }, &GreaterRendingCounter_attackD5C2)
});

DinoKind Inostherium("Inostherium", RARE, 1, {
    DinoRound(3000, 1400, 131, 0.0, 5.0, 125.0, 0.0, 50.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &MutualFury2752,
        &GroupDistractionFB00,
        &RevengeImpact0707
    }, nullptr)
});

DinoKind Inostrancevia("Inostrancevia", COMMON, 1, {
    DinoRound(3900, 1200, 130, 0.0, 5.0, 125.0, 100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &Distraction2717,
        &RevengeImpact0707
    }, nullptr)
});

DinoKind Irritator("Irritator", RARE, 1, {
    DinoRound(4500, 1000, 126, 0.0, 30.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &ReadyToCrush43AE,
        &GroupTakedown066E
    }, nullptr)
});

DinoKind IrritatorGen2("Irritator Gen 2", COMMON, 1, {
    DinoRound(3300, 1000, 124, 0.0, 30.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &FerociousStrike71CC
    }, nullptr)
});

DinoKind Kaprosuchus("Kaprosuchus", RARE, 1, {
    DinoRound(3900, 1000, 125, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &FierceStrike106A,
        &GroupFerocityStrike7A2D,
        &GroupCleansingStrike8B0C
    }, nullptr)
});

DinoKind Kelenken("Kelenken", RARE, 1, {
    DinoRound(3000, 1600, 131, 0.0, 5.0, 125.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &Sidestep5439,
        &RakingClawsF16C,
        &EvasiveStrikeA8EB
    }, nullptr)
});

DinoKind Kentrosaurus("Kentrosaurus", EPIC, 1, {
    DinoRound(4500, 1000, 112, 10.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 100.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupDeceleratingStrikeBAC6,
        &ResilientImpact7BB4
    }, &DeceleratingCounterD9D3)
});

DinoKind Keratoporcus("Keratoporcus", LEGENDARY, 1, {
    DinoRound(4500, 1200, 110, 20.0, 5.0, 125.0, 0.0, 50.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupDefenseShatteringStrikeF98B,
        &MutualFury2752,
        &GroupShatteringImpact7EAE,
        &FierceRampageDC31
    }, nullptr)
});

DinoKind Koolabourgiana("Koolabourgiana", LEGENDARY, 1, {
    DinoRound(4950, 1000, 117, 0.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 50.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupTauntingShieldsStrikeDA58,
        &DistractingImpactD4D6,
        &InstantInvincibility9B21
    }, nullptr)
});

DinoKind Koolasuchus("Koolasuchus", EPIC, 1, {
    DinoRound(3900, 1000, 127, 0.0, 5.0, 125.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &DistractingImpactD4D6,
        &GroupDistractionFB00
    }, nullptr)
});

DinoKind KoolasuchusGen2("Koolasuchus Gen 2", RARE, 1, {
    DinoRound(4500, 1500, 126, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &DistractingStrikeD81E,
        &InstantDistractionF5AC
    }, nullptr)
});

DinoKind Koreanosaurus("Koreanosaurus", OMEGA, 1, 60, 10, 1, 1.99999, 0.99999, 0.99999, 76, 150, 16, 8, 45, 10,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {11, RestrictionType::Ability, 3},
    {16, RestrictionType::Counter, 1},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(1440, 400, 104, 10.0, 5.0, 125.0, 100.0, 25.0, 50.0, 66.0, 0.0, 0.0, 0.0, 0.0, 100.0, 100.0, 0.0, {
        &InstantShieldedStrike3368,
        &ResilientImpact7BB4,
        &UnstoppableForce55F5,
        &Rejuvenate381D
    }, &MediumResilientCounter_attack3EB5)
});

DinoKind Lystrosaurus("Lystrosaurus", EPIC, 3, {
    DinoRound(3600, 1150, 125, 0.0, 10.0, 125.0, 0.0, 0.0, 0.0, 33.0, 50.0, 50.0, 50.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &EvasiveRestore11D0,
        &ImpactAndRun738D
    }, nullptr)
});

DinoKind Lystrosavis("Lystrosavis", UNIQUE, 3, {
    DinoRound(3750, 1350, 131, 0.0, 20.0, 125.0, 0.0, 33.0, 50.0, 33.0, 0.0, 75.0, 50.0, 0.0, 0.0, 0.0, 0.0, {
        &DebilitatingStrike1814,
        &EvasiveRestore11D0,
        &EvasiveResilientImpactBCAB,
        &EvasiveAlertRampageF230
    }, nullptr)
});

DinoKind Lystrosuchus("Lystrosuchus", LEGENDARY, 3, {
    DinoRound(3900, 1150, 123, 10.0, 10.0, 125.0, 0.0, 0.0, 0.0, 33.0, 50.0, 50.0, 50.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &EvasiveRestore11D0,
        &ResilientRampageB23D,
        &StunningImpactAndRun3EB7
    }, nullptr)
});

DinoKind Lythronax("Lythronax", COMMON, 1, {
    DinoRound(4200, 1000, 104, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ShieldedTauntingStrike73D4,
        &GroupShield54BA
    }, &ArmorPiercingCounterAEB5)
});

DinoKind Magnapyritor("Magnapyritor", UNIQUE, 1, {
    DinoRound(4800, 1450, 128, 0.0, 20.0, 125.0, 100.0, 100.0, 50.0, 50.0, 100.0, 100.0, 75.0, 0.0, 100.0, 0.0, 0.0, {
        &FierceStrike106A,
        &MagnaImpact79A2,
        &InstantGroupDistractionImpactC757,
        &FierceRampageDC31
    }, nullptr)
});

DinoKind Magnaraptor("Magnaraptor", APEX, 1, {
    DinoRound(4200, 1900, 132, 0.0, 25.0, 125.0, 100.0, 100.0, 50.0, 50.0, 100.0, 100.0, 100.0, 0.0, 100.0, 0.0, 0.0, {
        &GroupFierceStrikeA254,
        &DominantPounceDBBD,
        &MagnaImpact79A2,
        &FlockOfOneBDDA
    }, nullptr)
});

DinoKind Maiasaura("Maiasaura", EPIC, 1, {
    DinoRound(3000, 1300, 126, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupCleansingStrike8B0C,
        &LesserGroupHeal5491,
        &InstantRampageC258
    }, nullptr)
});

DinoKind Majundaboa("Majundaboa", EPIC, 1, {
    DinoRound(3600, 1000, 110, 0.0, 5.0, 125.0, 0.0, 0.0, 100.0, 0.0, 50.0, 100.0, 75.0, 100.0, 0.0, 0.0, 0.0, {
        &ShieldedDeceleratingStrike627F,
        &CleansingImpact351E,
        &FerociousStrike71CC,
        &PreciseImpact9D87
    }, &RakingCounter_attackC77B)
});

DinoKind Majundasuchus("Majundasuchus", RARE, 1, {
    DinoRound(3750, 1100, 108, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &TauntingDefense72E3,
        &FerociousStrike71CC,
        &CleansingImpact351E
    }, &DisarmingCounterStrike8AAD)
});

DinoKind Majungasaurus("Majungasaurus", COMMON, 1, {
    DinoRound(3450, 1000, 105, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 25.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &TauntingShields1CF6
    }, &ArmorPiercingCounterAEB5)
});

DinoKind Mammolania("Mammolania", UNIQUE, 1, {
    DinoRound(5100, 1000, 115, 50.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 100.0, 100.0, 0.0, 100.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &ResilientRampageB23D,
        &DigInTaunt1BB1,
        &BellowingImpact7163
    }, &CounterFerocity85EF)
});

DinoKind Mammotherium("Mammotherium", LEGENDARY, 1, {
    DinoRound(3600, 1500, 115, 30.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &PersistentFerociousStrikeAF52,
        &ResilientImpact7BB4,
        &DigInTaunt1BB1,
        &TauntingBellow3BBD
    }, nullptr)
});

DinoKind MarsupialLion("Marsupial Lion", RARE, 1, {
    DinoRound(4050, 1000, 117, 0.0, 40.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &MinorRendingAttackEE1F,
        &RendingTakedown1CED,
        &Prowl38DE
    }, &MediumCounter_attackE4A7)
});

DinoKind Masiakasaurus("Masiakasaurus", OMEGA, 1, 30, 25, 1, 0.99999, 0.99999, 0.99999, 129, 64, 12, 5, 20, 65,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {11, RestrictionType::Ability, 3},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(820, 425, 117, 0.0, 10.0, 110.0, 100.0, 50.0, 50.0, 25.0, 100.0, 0.0, 100.0, 50.0, 0.0, 0.0, 0.0, {
        &ThievishStrikeBD4A,
        &InstantDodgeImpact4070,
        &Fade8650,
        &WeakeningDecimateAndRun76AD
    }, nullptr)
});

DinoKind Megalania("Megalania", OMEGA, 1, 30, 20, 1, 0.99999, 0.99999, 0.99999, 130, 76, 25, 10, 10, 75,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {6, RestrictionType::Ability, 3},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(1200, 380, 100, 0.0, 0.0, 125.0, 0.0, 50.0, 50.0, 100.0, 50.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DegeneratingStrikeBC83,
        &DeviousImpactAED3,
        &OverwhelmingImpact226E,
        &LockdownPressure62CB
    }, nullptr)
});

DinoKind Megaloceros("Megaloceros", RARE, 1, {
    DinoRound(3300, 1000, 127, 10.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 100.0, 0.0, 50.0, 0.0, 0.0, {
        &ShieldedDeceleratingStrike627F,
        &DeceleratingImpact5016,
        &DigIn6DFE
    }, nullptr)
});

DinoKind Megalocevia("Megalocevia", APEX, 1, {
    DinoRound(5100, 1600, 121, 10.0, 20.0, 125.0, 0.0, 50.0, 100.0, 50.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupShatteringStrikeF634,
        &RevengeInstinct98BC,
        &GroupFerociousResilientImpact29C3,
        &PreciseRevenge51B4
    }, &MinorFerociourCounter76B6)
});

DinoKind Megalogaia("Megalogaia", EPIC, 1, {
    DinoRound(3750, 1000, 122, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 75.0, 0.0, 0.0, 0.0, 75.0, 0.0, 0.0, {
        &ShieldedDeceleratingStrike627F,
        &Bellow866E,
        &DigIn6DFE,
        &DeceleratingImpact5016
    }, &DeceleratingCounterD9D3)
});

DinoKind Megalonyx("Megalonyx", RARE, 1, {
    DinoRound(3450, 1200, 103, 0.0, 10.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &Camouflage8414,
        &CautiousRampage36B3
    }, &MaximalCounter_attack5683)
});

DinoKind Megalosaurus("Megalosaurus", RARE, 1, {
    DinoRound(3900, 1000, 105, 0.0, 5.0, 125.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 25.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &TauntingShields1CF6,
        &FerociousStrike71CC
    }, &ArmorPiercingCounterAEB5)
});

DinoKind Megalosuchus("Megalosuchus", LEGENDARY, 1, {
    DinoRound(4500, 1200, 116, 0.0, 15.0, 150.0, 0.0, 0.0, 100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &GroupCleansingStrike8B0C,
        &GroupFerociousResilientImpact29C3,
        &FierceRampageDC31,
        &DigInTaunt1BB1
    }, &ArmorPiercingCounterAEB5)
});

DinoKind Megalotops("Megalotops", EPIC, 1, {
    DinoRound(3750, 1150, 108, 10.0, 10.0, 125.0, 0.0, 0.0, 0.0, 0.0, 75.0, 0.0, 33.0, 0.0, 0.0, 0.0, 0.0, {
        &DeterminedStrike3D79,
        &DistractingImpactD4D6,
        &Camouflage8414,
        &CautiousRampage36B3
    }, &ArmorPiercingCounterAEB5)
});

DinoKind Megistocurus("Megistocurus", LEGENDARY, 1, {
    DinoRound(3750, 1400, 115, 15.0, 30.0, 125.0, 0.0, 0.0, 50.0, 0.0, 75.0, 50.0, 0.0, 100.0, 75.0, 0.0, 0.0, {
        &FierceStrike106A,
        &GroupShield54BA,
        &ResilientImpact7BB4,
        &DefensiveRendingAttack54CB
    }, nullptr)
});

DinoKind Megistotherium("Megistotherium", EPIC, 1, {
    DinoRound(3600, 1350, 120, 0.0, 40.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &FierceStrike106A,
        &ArmorPiercingImpactB10F,
        &RendingAttack9BF1
    }, nullptr)
});

DinoKind Meiolania("Meiolania", RARE, 1, {
    DinoRound(3300, 1000, 105, 50.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &LesserEmergencyHealE329,
        &Devastation3723
    }, nullptr)
});

DinoKind Microraptor("Microraptor", EPIC, 3, {
    DinoRound(1650, 1100, 136, 0.0, 15.0, 125.0, 0.0, 0.0, 0.0, 33.0, 0.0, 0.0, 75.0, 100.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &PreciseDoubleStrike2357,
        &DistractingTripleStrike777F
    }, nullptr)
});

DinoKind Miragaia("Miragaia", COMMON, 1, {
    DinoRound(3000, 1000, 109, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ShieldedDeceleratingStrike627F,
        &EmergencyHeal679C
    }, &DeceleratingCounterD9D3)
});

DinoKind Monolometrodon("Monolometrodon", LEGENDARY, 1, {
    DinoRound(4200, 1400, 125, 0.0, 5.0, 125.0, 0.0, 100.0, 25.0, 75.0, 75.0, 100.0, 75.0, 0.0, 100.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &NullifyingStrike38B2,
        &DistractingImpactD4D6,
        &FierceImpactB3BE
    }, nullptr)
});

DinoKind Monolophosaurus("Monolophosaurus", EPIC, 1, {
    DinoRound(3100, 1300, 127, 0.0, 5.0, 125.0, 0.0, 25.0, 25.0, 0.0, 25.0, 0.0, 0.0, 0.0, 25.0, 0.0, 0.0, {
        &DispersedCunningStrike30D1,
        &DistractingRampageBD0D,
        &CunningImpactEE79
    }, nullptr)
});

DinoKind MonolophosaurusGen2("Monolophosaurus Gen 2", COMMON, 1, {
    DinoRound(2700, 1350, 126, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &DistractingImpactD4D6
    }, nullptr)
});

DinoKind Monolorhino("Monolorhino", UNIQUE, 1, {
    DinoRound(4500, 1250, 116, 30.0, 5.0, 125.0, 100.0, 100.0, 50.0, 50.0, 75.0, 100.0, 100.0, 0.0, 100.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &DefiniteImpactE2FE,
        &GroupShield54BA,
        &TauntingShields1CF6
    }, nullptr)
});

DinoKind Monomimus("Monomimus", LEGENDARY, 1, {
    DinoRound(3750, 1350, 131, 0.0, 5.0, 125.0, 100.0, 100.0, 100.0, 0.0, 0.0, 100.0, 75.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &DistractingRampageBD0D,
        &InstantDistractionF5AC,
        &EvasiveStanceF473
    }, nullptr)
});

DinoKind Monostegotops("Monostegotops", LEGENDARY, 1, {
    DinoRound(4250, 1250, 116, 25.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 50.0, 0.0, {
        &CunningStrike75A8,
        &DigIn6DFE,
        &GreaterStunningRampageAC0D,
        &GroupResilientImpact3AE3
    }, &NullifyingCounter3724)
});

DinoKind MorosIntrepidus("Moros Intrepidus", EPIC, 3, {
    DinoRound(3300, 1200, 115, 0.0, 20.0, 125.0, 0.0, 50.0, 0.0, 33.0, 100.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, {
        &PinningStrike3832,
        &FierceDevouringImpactB728,
        &ChallengingAlertImpact0839
    }, nullptr)
});

DinoKind MortemRex("Mortem Rex", APEX, 1, {
    DinoRound(4950, 2000, 108, 10.0, 40.0, 125.0, 0.0, 50.0, 0.0, 0.0, 100.0, 100.0, 75.0, 0.0, 100.0, 0.0, 0.0, {
        &AlertFatalStrikeE0D9,
        &AfflictingLockdownImpact2EFB,
        &FierceRampageDC31,
        &Roar3648
    }, nullptr)
});

DinoKind Moschops("Moschops", RARE, 1, {
    DinoRound(4500, 1000, 113, 25.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &RevengeDeceleratingImpact6A2C,
        &PreciseRampageA036
    }, nullptr)
});

DinoKind Nasutoceratops("Nasutoceratops", RARE, 1, {
    DinoRound(4800, 1000, 109, 20.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &LongDeceleratingStrike7953,
        &Distraction8FE1,
        &GreaterStunningStrikeBAEF
    }, nullptr)
});

DinoKind Nodopatosaurus("Nodopatosaurus", EPIC, 1, {
    DinoRound(4800, 1000, 106, 30.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 50.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupDeceleratingStrikeBAC6,
        &TauntingRampage3362,
        &TauntingShields1CF6
    }, nullptr)
});

DinoKind Nodopatotitan("Nodopatotitan", LEGENDARY, 1, {
    DinoRound(6150, 1100, 108, 40.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 75.0, 75.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &TauntingHealBellow5344,
        &GroupDeceleratingImpact9451,
        &TauntingShields1CF6
    }, &MinorPreciseCounterA27F)
});

DinoKind Nodosaurus("Nodosaurus", RARE, 1, {
    DinoRound(4350, 950, 115, 30.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &DeceleratingImpact5016,
        &GroupTauntingShieldsEB4C
    }, nullptr)
});

DinoKind Nomingia("Nomingia", UNIQUE, 1, {
    DinoRound(4500, 1450, 125, 10.0, 10.0, 150.0, 100.0, 0.0, 100.0, 0.0, 50.0, 75.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &InstantDeviousStrike33EA,
        &CriticalSidestep78B0,
        &CunningDeviousImpactC699,
        &CunningDecimateC992
    }, &CriticalCounterStrikeA142)
});

DinoKind Nundasuchus("Nundasuchus", COMMON, 1, {
    DinoRound(3000, 1500, 128, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &ArmorPiercingStrike69E0,
        &FerociousStrike71CC
    }, nullptr)
});

DinoKind Olorotitan("Olorotitan", OMEGA, 1, 45, 15, 1, 0.99999, 0.99999, 0.99999, 121, 81, 15, 20, 10, 0,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {6, RestrictionType::Ability, 3},
    {11, RestrictionType::Counter, 1},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(810, 495, 103, 5.0, 0.0, 125.0, 0.0, 0.0, 50.0, 0.0, 100.0, 75.0, 0.0, 100.0, 100.0, 50.0, 0.0, {
        &ProtectTheHerdC716,
        &FerociousAssistedRampage8974,
        &RampageInterventionE0F0,
        &HerdSentinelB67B
    }, &CounterVulnerabilityStrikeEE02)
});

DinoKind Ophiacodon("Ophiacodon", COMMON, 1, {
    DinoRound(4350, 1400, 108, 0.0, 40.0, 125.0, 0.0, 100.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &ArmorPiercingRampage4328
    }, nullptr)
});

DinoKind Ornithomimus("Ornithomimus", RARE, 1, {
    DinoRound(3000, 1600, 131, 0.0, 5.0, 125.0, 0.0, 0.0, 100.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &EvasiveStrikeA8EB,
        &RampageAndRunB223,
        &InstantDistractionF5AC
    }, nullptr)
});

DinoKind Ouranosaurus("Ouranosaurus", EPIC, 1, {
    DinoRound(3600, 1500, 104, 10.0, 5.0, 125.0, 0.0, 50.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupCleansingStrike8B0C,
        &LesserGroupHeal5491,
        &GreaterEmergencyHeal456B
    }, &MinorDeceleratingCounter076E)
});

DinoKind Ovilophomoloch("Ovilophomoloch", LEGENDARY, 1, {
    DinoRound(3150, 1250, 129, 0.0, 10.0, 125.0, 100.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DeviousStrike53F7,
        &AlertDistractingImpact85F8,
        &GroupCunningImpact436E,
        &SlyRampageAndRun367D
    }, nullptr)
});

DinoKind Ovilophosaurus("Ovilophosaurus", EPIC, 1, {
    DinoRound(2850, 1200, 127, 0.0, 10.0, 125.0, 100.0, 0.0, 100.0, 75.0, 100.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DeviousStrike53F7,
        &GroupCunningImpact436E,
        &CriticalImpactD735,
        &DistractingRampageBD0D
    }, nullptr)
});

DinoKind Oviraptor("Oviraptor", RARE, 1, {
    DinoRound(2700, 1300, 129, 0.0, 15.0, 125.0, 100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DeviousStrike53F7,
        &DualClawC2BD,
        &CunningRampage8AEB
    }, nullptr)
});

DinoKind OviraptorGen2("Oviraptor Gen 2", EPIC, 1, {
    DinoRound(2600, 1350, 131, 0.0, 15.0, 125.0, 100.0, 0.0, 50.0, 0.0, 75.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CriticalStrike8706,
        &GroupCriticalAlertF371,
        &CunningRampage8AEB
    }, &DartingCounter6039)
});

DinoKind Pachycephalosaurus("Pachycephalosaurus", EPIC, 1, {
    DinoRound(3900, 1200, 121, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ShieldingStrikeEDCA,
        &DeceleratingImpact5016,
        &RampageAndRunB223
    }, nullptr)
});

DinoKind Panthera("Panthera", EPIC, 1, {
    DinoRound(3250, 1300, 126, 5.0, 10.0, 125.0, 0.0, 0.0, 50.0, 0.0, 100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &Retreat5950,
        &BerserkClawedRevenge111B,
        &BerserkBitingRevenge5D5E
    }, nullptr)
});

DinoKind PantheraBlytheae("Panthera Blytheae", LEGENDARY, 1, {
    DinoRound(3900, 1550, 126, 0.0, 20.0, 125.0, 100.0, 0.0, 100.0, 0.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DebilitatingStrike1814,
        &EvasiveHunt089A,
        &CunningRampage8AEB,
        &PreciseDoubleStrike2357
    }, &MediumNullifyingCounter4816)
});

DinoKind Pantherator("Pantherator", UNIQUE, 1, {
    DinoRound(4300, 1600, 127, 0.0, 30.0, 125.0, 75.0, 0.0, 100.0, 0.0, 100.0, 66.0, 25.0, 0.0, 50.0, 0.0, 0.0, {
        &DeterminedStrike3D79,
        &ShreddingWound5EC6,
        &EvasiveHunt089A,
        &FloatingDualClaw4DF9
    }, &PiercingCounterNullification55E0)
});

DinoKind Paramoloch("Paramoloch", LEGENDARY, 1, {
    DinoRound(4350, 1500, 126, 0.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 50.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupCleansingStrike8B0C,
        &LesserGroupHeal5491,
        &InstantCharge0917,
        &GroupShield54BA
    }, nullptr)
});

DinoKind Parasaurolophus("Parasaurolophus", COMMON, 1, {
    DinoRound(4500, 1200, 106, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupCleansingStrike8B0C,
        &LesserGroupHeal5491
    }, nullptr)
});

DinoKind ParasaurolophusLux("Parasaurolophus Lux", LEGENDARY, 1, {
    DinoRound(4950, 1400, 106, 15.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 0.0, 75.0, 75.0, 0.0, 100.0, 0.0, 0.0, {
        &Bulwark2D7E,
        &PreciseDeceleratingRampageB02E,
        &EmergencyGroupHealC79B,
        &ResilientGroupRampage9B37
    }, &MinorHealingCounter5330)
});

DinoKind Parasauthops("Parasauthops", UNIQUE, 1, {
    DinoRound(4650, 1550, 109, 0.0, 15.0, 125.0, 0.0, 75.0, 50.0, 0.0, 0.0, 33.0, 0.0, 100.0, 0.0, 0.0, 0.0, {
        &DispersedCunningStrike30D1,
        &AlertInstantHeal6BB9,
        &GreaterGroupHeal566D,
        &ResilientRampageRevenge6F80
    }, &CounterPowerHeal4DD2)
});

DinoKind Phorurex("Phorurex", UNIQUE, 1, {
    DinoRound(3900, 1500, 128, 0.0, 10.0, 125.0, 0.0, 0.0, 0.0, 0.0, 50.0, 75.0, 50.0, 0.0, 0.0, 0.0, 0.0, {
        &DaringStrikeE486,
        &CriticalSidestep78B0,
        &CautiousCunningRampage8C7B,
        &LethalRampageAndRun204F
    }, nullptr)
});

DinoKind Phorusaura("Phorusaura", LEGENDARY, 1, {
    DinoRound(3600, 1400, 130, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 75.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &InstantRampageC258,
        &DelayedRampageAndRun7020,
        &Sidestep5439
    }, nullptr)
});

DinoKind Phorusrhacos("Phorusrhacos", COMMON, 1, {
    DinoRound(3000, 1500, 130, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &Sidestep5439,
        &RakingClawsF16C
    }, nullptr)
});

DinoKind Plateopikasaurus("Plateopikasaurus", UNIQUE, 1, {
    DinoRound(5100, 1450, 117, 25.0, 10.0, 125.0, 0.0, 0.0, 100.0, 0.0, 100.0, 100.0, 0.0, 0.0, 75.0, 50.0, 0.0, {
        &ResilientDoubleStrike8E1A,
        &LesserGroupDeceleratingRampage52DB,
        &DoubleImpactBulwark0442,
        &PreciseDispiritingRampage0073
    }, &CounterPowerHeal1300)
});

DinoKind Plateorex("Plateorex", APEX, 1, {
    DinoRound(5100, 1750, 117, 25.0, 20.0, 125.0, 0.0, 0.0, 100.0, 0.0, 100.0, 100.0, 67.0, 0.0, 100.0, 50.0, 0.0, {
        &InstantResilientStrikeB7E8,
        &Skirmish0914,
        &DoubleImpactBulwark0442,
        &PreciseDevouringRampage3852
    }, &SlowingCounterPowerHeal6A69)
});

DinoKind Plateosaurus("Plateosaurus", COMMON, 1, {
    DinoRound(4200, 1300, 117, 15.0, 15.0, 125.0, 50.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientDoubleStrike8E1A,
        &InstantArmoredDeflection6FB3
    }, &DefensiveCounterStrike801C)
});

DinoKind Postimetrodon("Postimetrodon", EPIC, 1, {
    DinoRound(4500, 1200, 124, 0.0, 5.0, 125.0, 0.0, 50.0, 50.0, 0.0, 100.0, 100.0, 100.0, 0.0, 100.0, 0.0, 0.0, {
        &FierceStrike106A,
        &GroupFerocityStrike7A2D,
        &FierceImpactB3BE,
        &HealA906
    }, nullptr)
});

DinoKind Postosuchus("Postosuchus", RARE, 1, {
    DinoRound(3000, 1200, 126, 0.0, 20.0, 125.0, 0.0, 50.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &FierceStrike106A,
        &GroupFerocityStrike7A2D,
        &AdrenalinePulse2BA5
    }, nullptr)
});

DinoKind Poukaidei("Poukaidei", LEGENDARY, 1, {
    DinoRound(4050, 1500, 131, 0.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &EvasiveStrikeA8EB,
        &FearlessFlap6CE3,
        &Distraction8FE1,
        &InstantDistractionF5AC
    }, nullptr)
});

DinoKind Poukandactylus("Poukandactylus", UNIQUE, 1, {
    DinoRound(4050, 1200, 127, 0.0, 15.0, 125.0, 0.0, 0.0, 50.0, 0.0, 50.0, 100.0, 75.0, 0.0, 50.0, 0.0, 0.0, {
        &Sideflap66AF,
        &DistractingImpactD4D6,
        &FearlessFlap6CE3,
        &GroupInstantDistractionA5D4
    }, &DefenseShatteringCounterCA13)
});

DinoKind Preondactylus("Preondactylus", RARE, 3, {
    DinoRound(2250, 1350, 133, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 33.0, 100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &Sideflap66AF,
        &EvasiveImpact7999,
        &InstantDodgeImpact4070
    }, nullptr)
});

DinoKind Procerathomimus("Procerathomimus", EPIC, 1, {
    DinoRound(3000, 1600, 127, 0.0, 5.0, 125.0, 100.0, 100.0, 100.0, 0.0, 0.0, 75.0, 75.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &DistractingRampageBD0D,
        &InstantDistractionF5AC,
        &EvasiveStanceF473
    }, &NullifyingCounter3724)
});

DinoKind Proceratosaurus("Proceratosaurus", RARE, 1, {
    DinoRound(3000, 1300, 126, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &DistractingImpactD4D6,
        &CunningImpactEE79
    }, nullptr)
});

DinoKind Pteranodon("Pteranodon", EPIC, 1, {
    DinoRound(3300, 900, 127, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &FierceImpactB3BE,
        &ImpactAndRun738D
    }, &ArmorPiercingCounterAEB5)
});

DinoKind Pteranokyrie("Pteranokyrie", APEX, 1, {
    DinoRound(5100, 1450, 128, 25.0, 10.0, 125.0, 0.0, 100.0, 75.0, 0.0, 100.0, 75.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &DefiniteStrike51A6,
        &DispersedRakingImpact1D47,
        &MercilessAlert571C,
        &AlertSquall6E68
    }, &RobbingWing33B1)
});

DinoKind Pteraquetzal("Pteraquetzal", LEGENDARY, 1, {
    DinoRound(4500, 1000, 125, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &SuperiorityStrike2549,
        &LongDefenseStrike1237,
        &NullifyingImpact65A2,
        &ImpactAndRun738D
    }, &ArmorPiercingCounterAEB5)
});

DinoKind Pterovexus("Pterovexus", UNIQUE, 1, {
    DinoRound(4450, 1450, 130, 5.0, 20.0, 125.0, 100.0, 100.0, 50.0, 50.0, 100.0, 100.0, 100.0, 0.0, 100.0, 0.0, 0.0, {
        &RazorBeakCE11,
        &Exhaust71B8,
        &AlertHarpyD23C,
        &ClawSleight8F2A
    }, &VenomousCounter56D1)
});

DinoKind Pulmonoscorpius("Pulmonoscorpius", EPIC, 3, {
    DinoRound(2400, 1000, 116, 30.0, 15.0, 125.0, 100.0, 100.0, 0.0, 33.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &EnfeeblingStinger5E49,
        &ObstructingFierceImpact9462,
        &EnfeeblingImpact9D6C
    }, &PoisonCounterFC4D)
});

DinoKind Purrolyth("Purrolyth", RARE, 1, {
    DinoRound(3600, 1000, 105, 10.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &FerociousStrike71CC,
        &HealA906,
        &ShortDefense7ED4
    }, &RendingCounter_attack24B1)
});

DinoKind Purussaurus("Purussaurus", RARE, 1, {
    DinoRound(4500, 1000, 111, 15.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &VulnerabilityStrike1E04,
        &BindingImpactA742,
        &FerociousImpactA5CC
    }, nullptr)
});

DinoKind PurussaurusGen2("Purussaurus Gen 2", COMMON, 1, {
    DinoRound(4200, 1250, 111, 10.0, 20.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &VulnerabilityStrike1E04,
        &BindingImpactA742
    }, nullptr)
});

DinoKind Purutaurus("Purutaurus", EPIC, 1, {
    DinoRound(4200, 1000, 110, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CleansingStrike541F,
        &ShortDefense7ED4,
        &FierceImpactB3BE,
        &InstantDistractionF5AC
    }, &RendingCounter_attack24B1)
});

DinoKind Pyroraptor("Pyroraptor", EPIC, 1, {
    DinoRound(3150, 1500, 129, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &HighPounceD062,
        &InstantDistractionF5AC
    }, nullptr)
});

DinoKind PyroraptorGen2("Pyroraptor Gen 2", RARE, 1, {
    DinoRound(3150, 1200, 129, 0.0, 10.0, 125.0, 25.0, 0.0, 15.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &NullifyingImpact65A2,
        &DistractingImpactD4D6
    }, &DistractingCounterA897)
});

DinoKind Pyrorixis("Pyrorixis", UNIQUE, 1, {
    DinoRound(4500, 1500, 128, 10.0, 10.0, 125.0, 100.0, 0.0, 50.0, 25.0, 75.0, 25.0, 0.0, 0.0, 75.0, 0.0, 0.0, {
        &DispersedCautiousStrikeDD1C,
        &GreaterNullification593D,
        &InstantPreciseImpact5A71,
        &BerserkDecimatingWound9D0A
    }, &FerociousCounterStunE8A6)
});

DinoKind Pyrosuchus("Pyrosuchus", LEGENDARY, 1, {
    DinoRound(3750, 1350, 126, 15.0, 5.0, 125.0, 100.0, 0.0, 25.0, 0.0, 50.0, 0.0, 0.0, 0.0, 75.0, 0.0, 0.0, {
        &InstantDistractingStrikeF18F,
        &ShieldedLockdown6EE2,
        &StunningDistractionB884,
        &FerociousRampage7FD3
    }, &NullifyingCounter3724)
});

DinoKind Pyrritator("Pyrritator", LEGENDARY, 1, {
    DinoRound(2550, 1400, 129, 0.0, 20.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &HighPounceD062,
        &DistractingImpactD4D6,
        &DefenseShatteringImpact25E3
    }, nullptr)
});

DinoKind Quetzalcoatlus("Quetzalcoatlus", RARE, 1, {
    DinoRound(5100, 1000, 117, 0.0, 5.0, 125.0, 0.0, 0.0, 100.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &TauntingShields1CF6,
        &ImpactAndRun738D
    }, nullptr)
});

DinoKind QuetzalcoatlusGen2("Quetzalcoatlus Gen 2", EPIC, 1, {
    DinoRound(3600, 1080, 121, 10.0, 10.0, 125.0, 0.0, 0.0, 0.0, 0.0, 50.0, 25.0, 33.0, 0.0, 0.0, 0.0, 0.0, {
        &FierceDevouringCleanse4BB9,
        &FerociousShieldedHeal2912,
        &ResilientRampageAndRun6933
    }, nullptr)
});

DinoKind Quetzaljara("Quetzaljara", UNIQUE, 1, {
    DinoRound(4650, 1450, 123, 10.0, 20.0, 125.0, 0.0, 33.0, 50.0, 66.0, 100.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &AlertHarpyD23C,
        &GroupAfflictingImpact189F,
        &AerialDominance7897
    }, &WoundingCounterA785)
});

DinoKind Quetzorion("Quetzorion", UNIQUE, 1, {
    DinoRound(4350, 1600, 130, 0.0, 20.0, 125.0, 0.0, 100.0, 100.0, 50.0, 0.0, 0.0, 67.0, 0.0, 0.0, 0.0, 0.0, {
        &CraftyStrike1DFE,
        &LongInvincibilityBB2D,
        &NullifyingRampage11B6,
        &DistractingSidestep6F60
    }, &NullifyingCounter3724)
});

DinoKind Rajakylosaurus("Rajakylosaurus", LEGENDARY, 1, {
    DinoRound(4350, 1000, 104, 30.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &TauntingShields1CF6,
        &GroupShield54BA,
        &InstantInvincibilityTaunt6C65
    }, &PrecisePiercingStrike5679)
});

DinoKind Rajasaurus("Rajasaurus", EPIC, 1, {
    DinoRound(4200, 1000, 104, 0.0, 30.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &TauntingShields1CF6,
        &GroupShield54BA
    }, &ArmorPiercingCounterAEB5)
});

DinoKind Rativates("Rativates", OMEGA, 1, 30, 15, 1, 0.99999, 0.99999, 0.99999, 104, 96, 17, 5, 30, 25,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {6, RestrictionType::Counter, 1},
    {11, RestrictionType::Ability, 3},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(1170, 485, 114, 0.0, 10.0, 125.0, 50.0, 50.0, 0.0, 0.0, 75.0, 100.0, 0.0, 50.0, 0.0, 0.0, 0.0, {
        &OffensiveStance5250,
        &ShatteringTripleJabF0E0,
        &JabAndWeaveF9E7,
        &FrustratingRendingTakedown4D3A
    }, &CounterDualPeckA28F)
});

DinoKind Red("Red", EPIC, 1, {
    DinoRound(3450, 1250, 123, 15.0, 5.0, 125.0, 0.0, 25.0, 33.0, 0.0, 25.0, 100.0, 0.0, 0.0, 25.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &AcceleratingShieldedDistraction80B6,
        &BerserkResilientRampageD249
    }, nullptr)
});

DinoKind Refrenantem("Refrenantem", APEX, 1, {
    DinoRound(4800, 1600, 126, 0.0, 20.0, 125.0, 100.0, 50.0, 100.0, 75.0, 0.0, 75.0, 0.0, 100.0, 25.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &AlertNullification3D09,
        &CunningRampage8AEB,
        &SuperDistractionDE40
    }, &AlertCounterDistractionBE9B)
});

DinoKind Rexy("Rexy", LEGENDARY, 1, {
    DinoRound(4950, 1850, 106, 0.0, 44.99998, 125.0, 0.0, 75.0, 0.0, 75.0, 100.0, 75.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &AlertFierceStrikeF86F,
        &DefenseShatteringRevengeFFF1,
        &DominantRoar01DF,
        &FierceDevouringRampage6CE7
    }, nullptr)
});

DinoKind Rinchenia("Rinchenia", EPIC, 1, {
    DinoRound(2700, 1450, 129, 0.0, 10.0, 125.0, 100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DeviousStrike53F7,
        &Sidestep5439,
        &RampageAndRunB223
    }, nullptr)
});

DinoKind Rinchicyon("Rinchicyon", LEGENDARY, 1, {
    DinoRound(3450, 1400, 129, 0.0, 25.0, 125.0, 100.0, 0.0, 50.0, 0.0, 75.0, 0.0, 67.0, 0.0, 0.0, 0.0, 0.0, {
        &DeviousStrike53F7,
        &InstantBuff41DC,
        &DispersedFierceImpact938B,
        &AlertSafetyRampage24DB
    }, nullptr)
});

DinoKind RodriguesSolitaire("Rodrigues Solitaire", RARE, 3, {
    DinoRound(2850, 1300, 128, 0.0, 5.0, 125.0, 0.0, 50.0, 50.0, 33.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &FlightlessStrikeCC17,
        &ProtectiveAlert2FA4,
        &CunningRampage8AEB
    }, nullptr)
});

DinoKind SahPanthera("Sah Panthera", APEX, 1, {
    DinoRound(4650, 1700, 128, 10.0, 30.0, 125.0, 50.0, 25.0, 100.0, 33.0, 100.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &DeterminedStrike3D79,
        &AfflictingTrap30DA,
        &ResilientGroupRampage9B37,
        &VengefulDoubleStrikeEF0B
    }, &MediumNullifyingCounter4816)
});

DinoKind Sarcorixis("Sarcorixis", EPIC, 1, {
    DinoRound(4500, 1100, 113, 25.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 75.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GreaterStunningStrikeBAEF,
        &ImmobilizeEA4E,
        &FerociousImpactA5CC
    }, nullptr)
});

DinoKind Sarcosuchus("Sarcosuchus", COMMON, 1, {
    DinoRound(3600, 1000, 108, 10.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &StrikeBE64,
        &LethalWound98A0
    }, nullptr)
});

DinoKind Scaphognathus("Scaphognathus", RARE, 1, {
    DinoRound(2700, 1000, 128, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &StrikeBE64,
        &MinorSwoop6A00,
        &HealA906
    }, nullptr)
});

DinoKind Scaphotator("Scaphotator", EPIC, 1, {
    DinoRound(3000, 1000, 127, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &FierceStrike106A,
        &DistractingImpactD4D6,
        &MinorSwoop6A00,
        &EmergencyHeal679C
    }, nullptr)
});

DinoKind Scelidosaurus("Scelidosaurus", LEGENDARY, 1, {
    DinoRound(4900, 1450, 113, 40.0, 10.0, 125.99997, 0.0, 0.0, 50.0, 50.0, 100.0, 75.0, 0.0, 0.0, 50.0, 100.0, 0.0, {
        &SuperiorVulnerability7C25,
        &RegeneratingBulwark1162,
        &HealingDecimationCED6,
        &ResilientGroupRampage9B37
    }, nullptr)
});

DinoKind Scolosaurus("Scolosaurus", COMMON, 1, {
    DinoRound(4050, 1000, 107, 30.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &TauntingRampage3362
    }, nullptr)
});

DinoKind ScorpiosRex("Scorpios Rex", LEGENDARY, 1, {
    DinoRound(3750, 1300, 117, 0.0, 15.0, 125.0, 0.0, 0.0, 25.0, 0.0, 100.0, 75.0, 75.0, 0.0, 25.0, 0.0, 0.0, {
        &FierceStrike106A,
        &CunningImpactEE79,
        &Camouflage03BB,
        &LethalQuillShotF007
    }, nullptr)
});

DinoKind ScorpiosRexGen2("Scorpios Rex Gen 2", EPIC, 1, {
    DinoRound(3600, 1250, 118, 0.0, 10.0, 125.0, 0.0, 0.0, 0.0, 0.0, 75.0, 50.0, 100.0, 0.0, 25.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &StrikeAndRun11DF,
        &FierceImpactB3BE,
        &QuillImpact2A70
    }, nullptr)
});

DinoKind ScorpiosRexGen3("Scorpios Rex Gen 3", UNIQUE, 1, {
    DinoRound(4050, 1350, 119, 0.0, 25.0, 125.0, 0.0, 0.0, 50.0, 0.0, 100.0, 100.0, 50.0, 0.0, 50.0, 0.0, 0.0, {
        &FierceStrike106A,
        &InstantAmbushD57D,
        &CunningRampage8AEB,
        &ToxicQuills1E91
    }, nullptr)
});

DinoKind Scutophicyon("Scutophicyon", LEGENDARY, 1, {
    DinoRound(4050, 1350, 118, 10.0, 25.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 75.0, 0.0, 0.0, {
        &InstantDefenseShatteringStrikeB62F,
        &RevengeFierceImpact9788,
        &RevengeProtection914E,
        &ResilientGroupRampage9B37
    }, nullptr)
});

DinoKind Scutosaurus("Scutosaurus", EPIC, 1, {
    DinoRound(4800, 1200, 116, 25.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &RevengeDeceleratingImpact6A2C,
        &RevengeProtection914E
    }, nullptr)
});

DinoKind Secodontosaurus("Secodontosaurus", EPIC, 1, {
    DinoRound(3900, 1500, 114, 0.0, 5.0, 125.0, 0.0, 100.0, 50.0, 50.0, 100.0, 100.0, 75.0, 0.0, 100.0, 0.0, 0.0, {
        &FierceStrike106A,
        &FierceRampageDC31,
        &ArmorPiercingImpactB10F
    }, nullptr)
});

DinoKind Segnoraptor("Segnoraptor", LEGENDARY, 1, {
    DinoRound(3300, 1250, 134, 0.0, 5.0, 125.0, 0.0, 50.0, 100.0, 0.0, 0.0, 75.0, 75.0, 50.0, 0.0, 0.0, 0.0, {
        &MinimalSpeedupStrike44A5,
        &CunningFerociousStrike6867,
        &DistractingTripleStrike777F,
        &RampageAndRunB223
    }, nullptr)
});

DinoKind Segnosaurus("Segnosaurus", OMEGA, 1, 40, 20, 1, 0.99999, 0.99999, 0.99999, 93, 61, 20, 20, 25, 75,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {6, RestrictionType::Counter, 1},
    {11, RestrictionType::Ability, 3},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(1260, 460, 103, 5.0, 5.0, 125.0, 100.0, 50.0, 50.0, 50.0, 50.0, 75.0, 0.0, 0.0, 0.0, 50.0, 0.0, {
        &LockdownDefiniteStrikeC9F1,
        &HeavyClawsFFF3,
        &DemolitionClaws9934,
        &InstantCriticalImpact7F22
    }, &AlertCleanseFBF7)
});

DinoKind Segnotherisaurus("Segnotherisaurus", UNIQUE, 1, {
    DinoRound(4100, 1350, 125, 10.0, 25.0, 125.0, 50.0, 0.0, 100.0, 50.0, 75.0, 100.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &AcceleratingFerociousStrike1E8B,
        &TeamFortificationB18F,
        &WildTripleStrikeF0C6,
        &RevengeImpactAndRun0730
    }, nullptr)
});

DinoKind Sinoceratops("Sinoceratops", EPIC, 1, {
    DinoRound(3300, 1000, 107, 25.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &DigIn6DFE,
        &InstantCharge0917
    }, nullptr)
});

DinoKind Sinokotaraptor("Sinokotaraptor", LEGENDARY, 3, {
    DinoRound(3300, 1200, 128, 0.0, 10.0, 125.0, 100.0, 0.0, 100.0, 33.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &Distraction2717,
        &Sidestep5439,
        &CunningImpactEE79,
        &PrecisePounceF675
    }, nullptr)
});

DinoKind Sinosauropteryx("Sinosauropteryx", COMMON, 3, {
    DinoRound(2700, 1000, 128, 0.0, 10.0, 125.0, 0.0, 0.0, 0.0, 33.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &Distraction2717,
        &HighPounceD062
    }, nullptr)
});

DinoKind Sinraptor("Sinraptor", OMEGA, 1, 34, 35, 1, 0.0, 1.99999, 0.99999, 134, 55, 24, 0, 35, 50,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {6, RestrictionType::Ability, 3},
    {11, RestrictionType::Counter, 1},
    {11, RestrictionType::DamageReductionResistance, 75.0},
    {11, RestrictionType::DamageOverTimeResistance, 33.0},
    {11, RestrictionType::SpeedReductionResistance, 50.0},
    {16, RestrictionType::Ability, 4}
}, {
    DinoRound(1350, 575, 114, 0.0, 5.0, 125.0, 100.0, 0.0, 0.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &FierceStrike106A,
        &DeviousImpactAED3,
        &DefiniteImpactE2FE,
        &AfflictingVengefulSwoop46D1
    }, &WoundingCounterA785)
});

DinoKind Skoolasaurus("Skoolasaurus", LEGENDARY, 1, {
    DinoRound(4800, 1100, 124, 30.0, 15.0, 125.0, 0.0, 0.0, 50.0, 0.0, 100.0, 75.0, 0.0, 0.0, 50.0, 50.0, 0.0, {
        &ResilientStrikeFEDE,
        &TipTheScales61DD,
        &GroupDistractingRampageA326,
        &GroupTauntingShieldsStrikeDA58
    }, &NullifyingCounter3724)
});

DinoKind Skoonametrodon("Skoonametrodon", APEX, 1, {
    DinoRound(5190, 1900, 112, 10.0, 20.0, 125.0, 0.0, 33.0, 50.0, 50.0, 75.0, 100.0, 0.0, 100.0, 100.0, 100.0, 0.0, {
        &AlertStrike9EBE,
        &AlertImpactDA02,
        &AlertDefenseF5F7,
        &BattleReadyE24E
    }, &AlertCounterEF7D)
});

DinoKind Skoonasaurus("Skoonasaurus", UNIQUE, 1, {
    DinoRound(5850, 1150, 108, 30.0, 20.0, 125.0, 0.0, 0.0, 50.0, 0.0, 75.0, 100.0, 67.0, 100.0, 50.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupDeceleratingRampageE77E,
        &InstantInvincibilityTaunt6C65,
        &RestrictedGroupDistraction08AC
    }, &DeceleratingCounterD9D3)
});

DinoKind Smilocephalosaurus("Smilocephalosaurus", LEGENDARY, 1, {
    DinoRound(3750, 1400, 127, 0.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &EvasiveStrikeA8EB,
        &DeliberateProwlDF39,
        &PrecisePounceF675,
        &RampageAndRunB223
    }, nullptr)
});

DinoKind Smilodon("Smilodon", EPIC, 1, {
    DinoRound(3000, 1500, 129, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &EvasiveStrikeA8EB,
        &PrecisePounceF675,
        &Prowl38DE
    }, nullptr)
});

DinoKind Smilonemys("Smilonemys", UNIQUE, 1, {
    DinoRound(4500, 1500, 127, 40.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 50.0, 100.0, 60.0, 0.0, 0.0, 0.0, 0.0, {
        &ShieldedDeceleratingStrike627F,
        &DeliberateProwlDF39,
        &PrecisePounceF675,
        &DevastateAndRun2D50
    }, nullptr)
});

DinoKind Sonorasaurus("Sonorasaurus", EPIC, 1, {
    DinoRound(5250, 1000, 105, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, {
        &GroupResilientStrike74A6,
        &BraceB9A2,
        &Devastation3723
    }, &MediumResilientCounter_attack3EB5)
});

DinoKind Spinoceratops("Spinoceratops", LEGENDARY, 1, {
    DinoRound(5100, 1150, 118, 30.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 100.0, 100.0, 100.0, 0.0, 100.0, 0.0, 0.0, {
        &HeavyStrike5748,
        &BraceB9A2,
        &LethalWound98A0,
        &InstantRend0585
    }, nullptr)
});

DinoKind Spinoconstrictor("Spinoconstrictor", UNIQUE, 1, {
    DinoRound(4500, 1300, 126, 0.0, 10.0, 125.0, 0.0, 0.0, 100.0, 0.0, 75.0, 75.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &PreciseAfflictingRampageC6D1,
        &EvasiveWoundingStrikeC8F8,
        &InstantAfflictingDistractionFDA3
    }, &WoundingCounterA785)
});

DinoKind Spinonyx("Spinonyx", LEGENDARY, 1, {
    DinoRound(4200, 1000, 124, 0.0, 5.0, 125.0, 0.0, 75.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &MinorRendingAttackEE1F,
        &LethalWound98A0,
        &PreciseRampageA036,
        &DefiniteRampageD45A
    }, nullptr)
});

DinoKind Spinosaurus("Spinosaurus", RARE, 1, {
    DinoRound(3600, 1000, 122, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &FierceStrike106A,
        &LethalWound98A0,
        &FierceImpactB3BE
    }, nullptr)
});

DinoKind SpinosaurusAegyptiacus("Spinosaurus Aegyptiacus", OMEGA, 1, 40, 25, 1, 0.99999, 0.99999, 0.99999, 134, 84, 12, 0, 45, 25,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {6, RestrictionType::Counter, 1},
    {11, RestrictionType::Ability, 3},
    {11, RestrictionType::DamageReductionResistance, 25.0},
    {11, RestrictionType::VulnerabilityResistance, 50.0},
    {11, RestrictionType::StunResistance, 100.0},
    {16, RestrictionType::SpeedReductionResistance, 100.0},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(1300, 520, 106, 0.0, 5.0, 125.0, 0.0, 50.0, 0.0, 66.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &FierceStrike106A,
        &Lacerate372D,
        &VengefulDoublePiercingStrike4149,
        &VengefulDevouringRampage8CE5
    }, &CounterFerocity85EF)
});

DinoKind SpinosaurusGen2("Spinosaurus Gen 2", EPIC, 1, {
    DinoRound(3900, 1000, 122, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CleansingStrike541F,
        &LethalWound98A0,
        &FierceImpactB3BE
    }, nullptr)
});

DinoKind Spinotahraptor("Spinotahraptor", EPIC, 1, {
    DinoRound(2850, 1400, 126, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &StrikeBE64,
        &GashingWound4BC2,
        &DistractingImpactD4D6,
        &CunningImpactEE79
    }, nullptr)
});

DinoKind Spinotasuchus("Spinotasuchus", LEGENDARY, 1, {
    DinoRound(4250, 1150, 129, 0.0, 5.0, 125.0, 0.0, 0.0, 25.0, 0.0, 50.0, 50.0, 100.0, 0.0, 25.0, 0.0, 0.0, {
        &PrecisePiercingStrike93AA,
        &LethalWound98A0,
        &CleansingSwoopB410,
        &DispersedFierceImpact938B
    }, &DistractingCounterA897)
});

DinoKind Stegoceras("Stegoceras", EPIC, 1, {
    DinoRound(3600, 1250, 115, 0.0, 15.0, 125.0, 100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &InstantCharge0917,
        &FierceCriticalImpact8120
    }, nullptr)
});

DinoKind Stegoceratops("Stegoceratops", EPIC, 1, {
    DinoRound(3600, 1000, 107, 25.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &DigIn6DFE,
        &GroupDeceleratingImpact9451,
        &GreaterStunningStrikeBAEF
    }, nullptr)
});

DinoKind Stegodeus("Stegodeus", LEGENDARY, 1, {
    DinoRound(5100, 1100, 107, 30.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupDeceleratingImpact9451,
        &ShortDefense7ED4,
        &ResilientRampageB23D
    }, nullptr)
});

DinoKind Stegosaurus("Stegosaurus", COMMON, 1, {
    DinoRound(3900, 1000, 116, 20.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupDeceleratingStrikeBAC6
    }, nullptr)
});

DinoKind StegosaurusUngulatus("Stegosaurus Ungulatus", OMEGA, 1, 60, 15, 1, 0.99999, 0.99999, 0.99999, 97, 85, 10, 30, 15, 0,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {11, RestrictionType::Ability, 3},
    {11, RestrictionType::StunResistance, 100.0},
    {11, RestrictionType::DamageOverTimeResistance, 33.0},
    {11, RestrictionType::ArmorReductionResistance, 33.0},
    {16, RestrictionType::Counter, 1},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(1180, 350, 100, 10.0, 5.0, 125.0, 0.0, 0.0, 100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ShieldedDeceleratingStrike627F,
        &PreciseGroupSlowingImpact7F84,
        &LingeringFerocityD91F,
        &DefensiveRampageFA24
    }, &PowerfulCounterHeal16F3)
});

DinoKind Stegouros("Stegouros", OMEGA, 1, 50, 10, 1, 1.99999, 1.99999, 1.99999, 94, 157, 12, 18, 22, 8,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {6, RestrictionType::Counter, 1},
    {16, RestrictionType::Ability, 3},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(1300, 430, 109, 3.99998, 5.99999, 135.0, 50.0, 50.0, 50.0, 100.0, 0.0, 100.0, 0.0, 100.0, 25.0, 50.0, 0.0, {
        &ProtectiveAdvanceCA82,
        &DispersedFierceImpact938B,
        &Embolden90A1,
        &StunningVulnerabilityRampageA9E3
    }, &DistractingCounterA897)
});

DinoKind Struthiomimus("Struthiomimus", EPIC, 1, {
    DinoRound(3300, 1300, 126, 0.0, 15.0, 125.0, 100.0, 0.0, 100.0, 0.0, 0.0, 100.0, 75.0, 0.0, 0.0, 0.0, 0.0, {
        &EvasiveStrikeA8EB,
        &GroupDistractionFB00,
        &CunningRampage8AEB
    }, nullptr)
});

DinoKind Stygidaryx("Stygidaryx", UNIQUE, 1, {
    DinoRound(4050, 1150, 128, 0.0, 5.0, 125.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &MercilessAlert571C,
        &CleansingSwoopB410,
        &GroupInstantInvincibility82CC
    }, &RakingCounter_attackC77B)
});

DinoKind Stygimoloch("Stygimoloch", EPIC, 1, {
    DinoRound(3150, 1500, 129, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ShieldingStrikeEDCA,
        &ImpactAndRun738D,
        &InstantCharge0917
    }, nullptr)
});

DinoKind StygimolochGen2("Stygimoloch Gen 2", COMMON, 1, {
    DinoRound(3000, 1300, 128, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ShieldingStrikeEDCA,
        &ImpactAndRun738D
    }, nullptr)
});

DinoKind StyracosaurusLux("Styracosaurus Lux", UNIQUE, 1, {
    DinoRound(4800, 1500, 121, 15.0, 10.0, 125.0, 0.0, 50.0, 50.0, 0.0, 75.0, 100.0, 0.0, 100.0, 100.0, 50.0, 0.0, {
        &ShieldedHeavyStrike02CB,
        &DigInTaunt1BB1,
        &InstantFierceRampage6114,
        &GoringChargeD8A9
    }, nullptr)
});

DinoKind Suchomimus("Suchomimus", COMMON, 1, {
    DinoRound(3900, 1000, 104, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &FierceStrike106A,
        &LethalWound98A0
    }, nullptr)
});

DinoKind Suchotator("Suchotator", RARE, 1, {
    DinoRound(4500, 1300, 116, 0.0, 20.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &SuperiorityStrike2549,
        &LethalWound98A0,
        &NullifyingImpact65A2,
        &InstantDistractionF5AC
    }, nullptr)
});

DinoKind Tanycolagreus("Tanycolagreus", COMMON, 1, {
    DinoRound(2850, 1560, 130, 0.0, 5.0, 125.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DefiniteStrike51A6,
        &NullifyingImpact65A2
    }, nullptr)
});

DinoKind Tapejara("Tapejara", RARE, 1, {
    DinoRound(3650, 1350, 124, 0.0, 25.0, 125.0, 0.0, 33.0, 50.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &GroupAfflictingStrike1956,
        &InstantDistractionF5AC,
        &EvasiveRampage40C8
    }, nullptr)
});

DinoKind Tarbognathus("Tarbognathus", LEGENDARY, 3, {
    DinoRound(3000, 1450, 123, 0.0, 30.0, 125.0, 0.0, 0.0, 0.0, 33.0, 50.0, 75.0, 0.0, 100.0, 50.0, 0.0, 0.0, {
        &AlertSurge82DA,
        &HopAndMockD6D1,
        &AlertShatteringImpact9D9B,
        &FierceImpactB3BE
    }, nullptr)
});

DinoKind Tarbosaurus("Tarbosaurus", COMMON, 1, {
    DinoRound(4500, 1700, 104, 0.0, 40.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &FierceStrike106A,
        &ArmorPiercingImpactB10F
    }, nullptr)
});

DinoKind Tenontorex("Tenontorex", UNIQUE, 1, {
    DinoRound(4750, 1900, 117, 15.0, 20.0, 125.0, 0.0, 50.0, 50.0, 0.0, 0.0, 67.0, 67.0, 0.0, 100.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &DistractingTeamHeal41AD,
        &GroupShatteringRampageA42F,
        &DistractingDevourImpactF535
    }, nullptr)
});

DinoKind Tenontosaurus("Tenontosaurus", RARE, 1, {
    DinoRound(4500, 1100, 114, 0.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 50.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, {
        &GroupCleansingStrike8B0C,
        &RampageInterventionE0F0,
        &GreaterEmergencyHeal456B
    }, &DeceleratingCounterD9D3)
});

DinoKind Testacornibus("Testacornibus", UNIQUE, 1, {
    DinoRound(4200, 1100, 128, 44.99998, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 100.0, 66.69998, 33.0, 0.0, 100.0, 0.0, 0.0, {
        &SuperiorVulnerability7C25,
        &DigInTaunt1BB1,
        &Devastation3723,
        &CleansingDeceleratingImpact66A0
    }, &CounterPowerHealA54F)
});

DinoKind Therizinosaurus("Therizinosaurus", RARE, 1, {
    DinoRound(3300, 1300, 130, 0.0, 5.0, 125.0, 0.0, 50.0, 50.0, 0.0, 0.0, 75.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &MinimalSpeedupStrike44A5,
        &CunningFerociousStrike6867,
        &DelayedPreciseRampage5DFE
    }, nullptr)
});

DinoKind Thoradolosaur("Thoradolosaur", UNIQUE, 1, {
    DinoRound(4500, 1750, 105, 0.0, 30.0, 125.0, 0.0, 75.0, 0.0, 0.0, 0.0, 50.0, 100.0, 0.0, 50.0, 0.0, 0.0, {
        &FierceStrike106A,
        &CleansingGroupDestroyer66E8,
        &FierceRampageDC31,
        &InstantCharge0917
    }, nullptr)
});

DinoKind Thylaconyx("Thylaconyx", LEGENDARY, 1, {
    DinoRound(4800, 1250, 122, 0.0, 25.0, 125.0, 0.0, 25.0, 0.0, 75.0, 100.0, 100.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &CrushingProwl3FF5,
        &DevouringWound32A1,
        &Skirmish0914
    }, &DefenseShatteringCounter_attackD663)
});

DinoKind Thylacotator("Thylacotator", EPIC, 1, {
    DinoRound(4500, 1000, 117, 0.0, 40.0, 125.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &SuperiorityStrike2549,
        &DeliberateProwlDF39,
        &RendingTakedown1CED,
        &MaimingWoundFC48
    }, nullptr)
});

DinoKind ThylosIntrepidus("Thylos Intrepidus", UNIQUE, 3, {
    DinoRound(4200, 1400, 125, 0.0, 40.0, 125.0, 50.0, 50.0, 0.0, 33.0, 100.0, 0.0, 100.0, 100.0, 0.0, 0.0, 0.0, {
        &MinorRendingLockdown18B8,
        &CrushingProwl3FF5,
        &WoundingDevourRampage4191,
        &DualRendingAssaultC57D
    }, nullptr)
});

DinoKind Tiger("Tiger", EPIC, 1, {
    DinoRound(3600, 1350, 119, 15.0, 5.0, 125.0, 0.0, 50.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &DeceleratingImpact5016,
        &BerserkRampagingCloak51AA
    }, &DefenseShatteringCounter_attackD663)
});

DinoKind Titanoboa("Titanoboa", EPIC, 1, {
    DinoRound(4500, 1300, 115, 0.0, 20.0, 125.0, 0.0, 0.0, 100.0, 0.0, 50.0, 67.0, 75.0, 100.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &PreciseRampageA036,
        &DeceleratingImpact5016
    }, nullptr)
});

DinoKind TitanoboaGen2("Titanoboa Gen 2", RARE, 1, {
    DinoRound(4350, 1000, 115, 0.0, 20.0, 125.0, 0.0, 0.0, 100.0, 0.0, 0.0, 100.0, 100.0, 100.0, 0.0, 0.0, 0.0, {
        &ShieldedDeceleratingStrike627F,
        &PreciseRampageA036,
        &PreciseImpact9D87
    }, nullptr)
});

DinoKind Toro("Toro", OMEGA, 1, 40, 15, 1, 0.99999, 0.99999, 0.99999, 112, 97, 9, 30, 35, 15,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {6, RestrictionType::Ability, 3},
    {16, RestrictionType::Ability, 4},
    {21, RestrictionType::Counter, 1}
}, {
    DinoRound(1320, 395, 107, 5.0, 5.0, 125.0, 0.0, 50.0, 50.0, 50.0, 50.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &DeceleratingCleanse6E7E,
        &AngryEndurance8CB4,
        &HornedDevour10A1,
        &ThrashingImpactAndRun9E6F
    }, &MinorHealingCounter5330)
});

DinoKind Tragodistis("Tragodistis", LEGENDARY, 1, {
    DinoRound(4500, 1000, 105, 40.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, {
        &DispersedSuperiorVulnerability5AC2,
        &GroupDeceleratingImpact9451,
        &GroupTauntingShieldsEB4C,
        &Shelter12ED
    }, &MediumCounter_attackE4A7)
});

DinoKind Triceratops("Triceratops", RARE, 1, {
    DinoRound(3300, 1000, 111, 20.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &DigIn6DFE,
        &GreaterStunningStrikeBAEF
    }, nullptr)
});

DinoKind TriceratopsGen2("Triceratops Gen 2", COMMON, 1, {
    DinoRound(3750, 1000, 110, 10.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &RampageB9EA
    }, nullptr)
});

DinoKind Troodoboa("Troodoboa", UNIQUE, 1, {
    DinoRound(3900, 1200, 117, 0.0, 10.0, 125.0, 0.0, 100.0, 100.0, 0.0, 75.0, 75.0, 0.0, 100.0, 0.0, 0.0, 0.0, {
        &InstantDeceleratingPrecision323A,
        &GroupCleansingFatalStrike3DBD,
        &PreciseDistractingImpact90A3,
        &GroupCunningRampageA204
    }, &RakingCounter_attackC77B)
});

DinoKind Troodon("Troodon", EPIC, 1, {
    DinoRound(3000, 1200, 130, 0.0, 15.0, 125.0, 0.0, 0.0, 100.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CraftyStrike1DFE,
        &HighPounceD062,
        &CautiousCunningRampage8C7B
    }, nullptr)
});

DinoKind Trykosaurus("Trykosaurus", UNIQUE, 1, {
    DinoRound(4350, 1600, 108, 34.99999, 20.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &FierceDevouringCleanse4BB9,
        &ResilientImpact7BB4,
        &DefenseShatteringRampageC9FF,
        &InstantInvincibilityTaunt6C65
    }, &MediumCounter_attackE4A7)
});

DinoKind Tryostronix("Tryostronix", LEGENDARY, 1, {
    DinoRound(4200, 1400, 125, 0.0, 20.0, 125.0, 0.0, 50.0, 50.0, 50.0, 100.0, 100.0, 75.0, 0.0, 50.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &ReadyToCrush43AE,
        &FierceRampageDC31,
        &Refresh8EAD
    }, nullptr)
});

DinoKind Tsintamoth("Tsintamoth", LEGENDARY, 1, {
    DinoRound(4950, 1250, 113, 10.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 0.0, 75.0, 75.0, 0.0, 100.0, 0.0, 0.0, {
        &GroupPersistenceStrike0246,
        &GroupFortifyingImpact9551,
        &GroupHeal0723,
        &HealingBellow73D3
    }, nullptr)
});

DinoKind Tsintaosaurus("Tsintaosaurus", EPIC, 1, {
    DinoRound(4350, 1250, 108, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 67.0, 67.0, 0.0, 100.0, 0.0, 0.0, {
        &GroupCleansingStrike8B0C,
        &GroupFerocityStrike7A2D,
        &GroupHeal0723
    }, nullptr)
});

DinoKind Tuojiangosaurus("Tuojiangosaurus", RARE, 1, {
    DinoRound(3600, 1000, 105, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupDeceleratingStrikeBAC6,
        &PreciseRampageA036
    }, &DeceleratingCounterD9D3)
});

DinoKind Tuoramoloch("Tuoramoloch", UNIQUE, 1, {
    DinoRound(4380, 1600, 126, 5.0, 5.0, 125.0, 0.0, 0.0, 50.0, 0.0, 100.0, 100.0, 50.0, 0.0, 0.0, 0.0, 0.0, {
        &HealingSuperiorityStrike0C0B,
        &GroupResilientImpact3AE3,
        &GroupAcceleration6211,
        &ShieldedDoubleHeal9DEE
    }, nullptr)
});

DinoKind Tupandactylus("Tupandactylus", RARE, 1, {
    DinoRound(3000, 950, 126, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 25.0, 0.0, 0.0, {
        &DefenseShatteringStrike1CA6,
        &ShortDefense7ED4,
        &ImpactAndRun738D
    }, &ArmorPiercingCounterAEB5)
});

DinoKind Tyrannolophosaur("Tyrannolophosaur", LEGENDARY, 1, {
    DinoRound(4200, 1650, 108, 0.0, 30.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &DistractingImpactD4D6,
        &FierceImpactB3BE,
        &FierceRampageDC31
    }, nullptr)
});

DinoKind Tyrannometrodon("Tyrannometrodon", UNIQUE, 1, {
    DinoRound(4950, 1900, 110, 0.0, 34.99999, 125.0, 100.0, 25.0, 15.0, 50.0, 100.0, 75.0, 50.0, 0.0, 100.0, 0.0, 0.0, {
        &FerociousCleansingStrike120F,
        &GroupDevouringImpactC9D9,
        &Tyrant_sRoarD436,
        &DecimatingHunger9FEA
    }, nullptr)
});

DinoKind TyrannosaurBuck("Tyrannosaur Buck", LEGENDARY, 1, {
    DinoRound(5100, 1700, 104, 10.0, 25.0, 125.0, 0.0, 50.0, 0.0, 75.0, 100.0, 75.0, 0.0, 0.0, 0.0, 100.0, 0.0, {
        &GroupFierceStrikeA254,
        &FierceDevouringRampage6CE7,
        &AlphaIntimidation8FBA,
        &ImmobilizeEA4E
    }, &CounterFerocity85EF)
});

DinoKind TyrannosaurDoe("Tyrannosaur Doe", LEGENDARY, 1, {
    DinoRound(4500, 1750, 121, 0.0, 20.0, 125.0, 100.0, 25.0, 75.0, 33.0, 75.0, 50.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &FierceDoubleStrike700F,
        &InstantPreciseImpact5A71,
        &GreaterNullification593D,
        &MaternalRoar86DC
    }, &DefenseShatteringCounter_attackD663)
});

DinoKind TyrannosaurusRex("Tyrannosaurus Rex", EPIC, 1, {
    DinoRound(4800, 1900, 102, 0.0, 30.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, {
        &FierceStrike106A,
        &DispersedFierceImpact938B,
        &FierceRampageDC31
    }, &CounterFerocity85EF)
});

DinoKind TyrannosaurusRexGen2("Tyrannosaurus Rex Gen 2", RARE, 1, {
    DinoRound(4350, 1800, 104, 0.0, 20.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &FierceStrike106A,
        &DefenseShatteringImpact25E3,
        &ArmorPiercingRampage4328
    }, nullptr)
});

DinoKind Utahraptor("Utahraptor", RARE, 1, {
    DinoRound(2250, 1400, 128, 0.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &StrikeBE64,
        &HighPounceD062,
        &CunningImpactEE79
    }, nullptr)
});

DinoKind Utarinex("Utarinex", UNIQUE, 1, {
    DinoRound(3600, 1650, 128, 10.0, 25.0, 125.0, 0.0, 50.0, 75.0, 0.0, 0.0, 75.0, 34.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &DistractingImpactAndRunBB70,
        &StunningRampageAndRun9FFA,
        &InstantStunningStrikeEA34
    }, nullptr)
});

DinoKind Utasinoraptor("Utasinoraptor", LEGENDARY, 1, {
    DinoRound(3000, 1400, 127, 15.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &CunningStrike75A8,
        &DistractingImpactD4D6,
        &CunningImpactEE79,
        &InstantCharge0917
    }, nullptr)
});

DinoKind Vectispinus("Vectispinus", OMEGA, 1, 35, 20, 1, 0.99999, 0.99999, 0.99999, 159, 51, 17, 20, 10, 25,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {11, RestrictionType::Ability, 3},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(975, 550, 99, 10.0, 0.0, 125.0, 0.0, 50.0, 0.0, 0.0, 0.0, 50.0, 0.0, 50.0, 0.0, 50.0, 0.0, {
        &InstantDeceleratingPrecision323A,
        &LingeringFerociousStrike7A11,
        &LingeringResilientImpact1971,
        &DevouringRevenge88AA
    }, nullptr)
});

DinoKind Velociraptor("Velociraptor", COMMON, 1, {
    DinoRound(1650, 1550, 132, 0.0, 5.0, 125.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &StrikeBE64,
        &HighPounceD062
    }, nullptr)
});

DinoKind Velosrhacos("Velosrhacos", EPIC, 1, {
    DinoRound(3000, 1400, 130, 0.0, 5.0, 125.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, {
        &CautiousStrike3CE4,
        &HighPounceD062,
        &DeliberateProwlDF39,
        &RampageB9EA
    }, nullptr)
});

DinoKind WoollyMammoth("Woolly Mammoth", EPIC, 1, {
    DinoRound(4200, 1000, 115, 10.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &PersistentFerociousStrikeAF52,
        &GroupDeceleratingImpact9451,
        &TauntingBellow3BBD
    }, nullptr)
});

DinoKind WoollyRhino("Woolly Rhino", EPIC, 1, {
    DinoRound(4500, 1500, 108, 10.0, 5.0, 125.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, {
        &ShieldedTauntingStrike73D4,
        &ResilientImpact7BB4,
        &InstantInvincibilityTaunt6C65
    }, nullptr)
});

DinoKind Wuerhosaurus("Wuerhosaurus", RARE, 1, {
    DinoRound(4500, 1000, 115, 25.0, 5.0, 125.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, {
        &ResilientStrikeFEDE,
        &GroupDeceleratingRampageE77E,
        &TauntingBellow3BBD
    }, nullptr)
});

DinoKind Yutyrannus("Yutyrannus", OMEGA, 1, 30, 30, 1, 0.99999, 1.99999, 1.99999, 136, 63, 10, 0, 47, 40,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {11, RestrictionType::Ability, 3},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(1420, 500, 110, 0.0, 5.99999, 125.0, 100.0, 50.0, 15.0, 50.0, 25.0, 0.0, 100.0, 100.0, 0.0, 0.0, 0.0, {
        &GroupFierceStrikeA254,
        &Roar3648,
        &FerociousRestoreD2AB,
        &AlertFierceRampage151A
    }, nullptr)
});

DinoKind Yuxisaurus("Yuxisaurus", OMEGA, 1, 50, 15, 1, 0.99999, 0.99999, 0.99999, 90, 86, 12, 23, 40, 50,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {6, RestrictionType::Ability, 3},
    {11, RestrictionType::Counter, 1},
    {21, RestrictionType::Ability, 4}
}, {
    DinoRound(1500, 410, 105, 10.0, 10.0, 125.0, 0.0, 0.0, 75.0, 0.0, 75.0, 0.0, 0.0, 0.0, 100.0, 50.0, 0.0, {
        &TerritorialStrikeFC54,
        &ResilientRampageB23D,
        &PaybackRampage4545,
        &SpikedProtection8FA1
    }, &LesserWoundingCounter7BC3)
});

DinoKind _93ClassicT_Rex("'93 Classic T. Rex", OMEGA, 1, 35, 25, 1, 0.0, 0.99999, 1.99999, 122, 73, 10, 0, 90, 35,
{0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112, 119, 126, 133, 140, 147, 154, 161, 168, 175, 182, 189, 196, 203, 210}, {
    {6, RestrictionType::Counter, 1},
    {11, RestrictionType::Ability, 3},
    {16, RestrictionType::Ability, 4}
}, {
    DinoRound(1350, 540, 109, 0.0, 10.0, 129.99999, 100.0, 100.0, 33.0, 100.0, 100.0, 0.0, 0.0, 100.0, 25.0, 0.0, 0.0, {
        &EmboldeningAlertBAC9,
        &InvulnerableDevourImpactAB87,
        &ImmobilizingImpact43FC,
        &AlertRampageOverthrow7EE6
    }, &RendingCounter_attack24B1)
});


using namespace std;
using namespace boss;

map<string, vector<Dino>> BossDex = {
    make_pair<string, vector<Dino>>("Alacranix", {Dino(0, 0, 30, 10, 14, 5, &AlacranixBoss), Dino(0, 5, 28, 5, 5, 18, &GallimimusMinion), Dino(0, 6, 28, 5, 13, 10, &SuchomimusMinion)}),
    make_pair<string, vector<Dino>>("Albertospinos", {Dino(0, 0, 24, 6, 10, 6, &AlbertospinosBoss), Dino(0, 5, 23, 12, 7, 4, &DoedicurusMinion), Dino(0, 6, 23, 8, 8, 7, &KoolasuchusGen2Minion)}),
    make_pair<string, vector<Dino>>("Andrewtops", {Dino(0, 0, 24, 8, 12, 4, &AndrewtopsBoss), Dino(0, 5, 23, 12, 7, 4, &ScolosaurusMinion), Dino(0, 6, 23, 9, 9, 6, &DilophosaurusMinion)}),
    make_pair<string, vector<Dino>>("Arctodus", {Dino(0, 0, 9, 0, 0, 0, &ArctodusBoss)}),
    make_pair<string, vector<Dino>>("Bajadasaurus", {Dino(0, 0, 9, 0, 0, 0, &BajadasaurusBoss)}),
    make_pair<string, vector<Dino>>("Beelzebufo", {Dino(0, 0, 30, 10, 13, 7, &BeelzebufoBoss), Dino(0, 5, 29, 8, 5, 10, &MajungasaurusMinion), Dino(0, 6, 29, 8, 2, 10, &KoolasuchusGen2Minion)}),
    make_pair<string, vector<Dino>>("Blue", {Dino(0, 0, 14, 0, 0, 0, &BlueBoss)}),
    make_pair<string, vector<Dino>>("Brachiosaurus", {Dino(0, 0, 14, 0, 0, 0, &BrachiosaurusBoss)}),
    make_pair<string, vector<Dino>>("Carnotaurus", {Dino(0, 0, 8, 0, 0, 0, &CarnotaurusBoss)}),
    make_pair<string, vector<Dino>>("Ceramagnus", {Dino(0, 0, 30, 15, 15, 0, &CeramagnusBoss), Dino(0, 5, 29, 20, 8, 1, &KoolasuchusGen2Minion), Dino(0, 6, 29, 9, 20, 0, &MiragaiaMinion)}),
    make_pair<string, vector<Dino>>("Dreadnoughtus", {Dino(0, 0, 9, 0, 0, 0, &DreadnoughtusBoss)}),
    make_pair<string, vector<Dino>>("Erlikogamma", {Dino(0, 0, 14, 0, 0, 0, &ErlikogammaBoss)}),
    make_pair<string, vector<Dino>>("Fukuimimus", {Dino(0, 0, 19, 7, 7, 5, &FukuimimusBoss), Dino(0, 5, 18, 9, 5, 3, &EntelodonMinion), Dino(0, 6, 18, 7, 5, 6, &MiragaiaMinion)}),
    make_pair<string, vector<Dino>>("Giganotosaurus", {Dino(0, 0, 30, 15, 15, 0, &GiganotosaurusBoss), Dino(0, 5, 29, 10, 10, 9, &MajungasaurusMinion), Dino(0, 6, 29, 4, 10, 15, &VelociraptorMinion)}),
    make_pair<string, vector<Dino>>("Glyptoceras", {Dino(0, 0, 19, 5, 3, 8, &GlyptocerasBoss), Dino(0, 5, 17, 7, 6, 1, &KoolasuchusGen2Minion), Dino(0, 6, 17, 8, 3, 3, &WuerhosaurusMinion)}),
    make_pair<string, vector<Dino>>("Gorgotrebax", {Dino(0, 0, 30, 10, 15, 5, &GorgotrebaxBoss), Dino(0, 5, 29, 13, 6, 10, &EntelodonMinion), Dino(0, 6, 29, 15, 9, 5, &DoedicurusMinion)}),
    make_pair<string, vector<Dino>>("Grypolyth", {Dino(0, 0, 24, 12, 12, 0, &GrypolythBoss), Dino(0, 5, 23, 8, 5, 10, &EchoMinion), Dino(0, 6, 23, 20, 3, 0, &ScolosaurusMinion)}),
    make_pair<string, vector<Dino>>("HaastMaximus", {Dino(0, 0, 30, 16, 14, 0, &HaastMaximusBoss), Dino(0, 5, 29, 16, 5, 8, &DoedicurusMinion), Dino(0, 6, 29, 18, 8, 0, &IrritatorMinion)}),
    make_pair<string, vector<Dino>>("HadrosLux", {Dino(0, 0, 30, 15, 15, 0, &HadrosLuxBoss), Dino(0, 5, 30, 15, 10, 5, &EntelodonMinion), Dino(0, 6, 30, 20, 10, 0, &GorgosaurusMinion)}),
    make_pair<string, vector<Dino>>("HydraBoa", {Dino(0, 0, 30, 10, 15, 5, &HydraBoaBoss), Dino(0, 5, 29, 10, 15, 4, &BaryonyxMinion), Dino(0, 6, 29, 15, 9, 5, &MajungasaurusMinion)}),
    make_pair<string, vector<Dino>>("Imperatosuchus", {Dino(0, 0, 30, 10, 13, 7, &ImperatosuchusBoss), Dino(0, 5, 29, 8, 5, 10, &MajungasaurusMinion), Dino(0, 6, 29, 8, 2, 10, &KoolasuchusGen2Minion)}),
    make_pair<string, vector<Dino>>("IndominusRex", {Dino(0, 0, 19, 4, 5, 10, &IndominusRexBoss), Dino(0, 5, 18, 5, 3, 10, &EchoMinion), Dino(0, 6, 18, 4, 5, 9, &CharlieMinion)}),
    make_pair<string, vector<Dino>>("Indoraptor", {Dino(0, 0, 24, 8, 8, 8, &IndoraptorBoss), Dino(0, 5, 23, 5, 10, 8, &CarnotaurusMinion), Dino(0, 6, 23, 5, 5, 13, &WuerhosaurusMinion)}),
    make_pair<string, vector<Dino>>("Mammotherium", {Dino(0, 0, 16, 8, 5, 3, &MammotheriumBoss), Dino(0, 5, 15, 5, 2, 8, &GallimimusMinion)}),
    make_pair<string, vector<Dino>>("Megalonyx", {Dino(0, 0, 9, 0, 0, 0, &MegalonyxBoss)}),
    make_pair<string, vector<Dino>>("Megalosuchus", {Dino(0, 0, 19, 4, 5, 10, &MegalosuchusBoss), Dino(0, 5, 18, 7, 10, 1, &AllosaurusMinion), Dino(0, 6, 18, 8, 10, 0, &AllosaurusMinion)}),
    make_pair<string, vector<Dino>>("Megalotops", {Dino(0, 0, 14, 0, 0, 0, &MegalotopsBoss)}),
    make_pair<string, vector<Dino>>("Meiolania", {Dino(0, 0, 8, 0, 0, 0, &MeiolaniaBoss)}),
    make_pair<string, vector<Dino>>("MiniMo", {Dino(0, 0, 30, 0, 0, 0, &MiniMortem), Dino(0, 5, 26, 0, 0, 0, &TinyT_Rex), Dino(0, 6, 26, 0, 0, 0, &TinyT_RexTwin)}),
    make_pair<string, vector<Dino>>("MortemRex", {Dino(0, 0, 30, 15, 15, 0, &MortemRexBoss), Dino(0, 5, 29, 10, 10, 9, &MajungasaurusMinion), Dino(0, 6, 29, 4, 10, 15, &VelociraptorMinion)}),
    make_pair<string, vector<Dino>>("Parasauthops", {Dino(0, 0, 24, 8, 8, 8, &ParasauthopsBoss), Dino(0, 5, 23, 9, 4, 10, &MajungasaurusMinion), Dino(0, 6, 23, 12, 3, 8, &SuchomimusMinion)}),
    make_pair<string, vector<Dino>>("Phorurex", {Dino(0, 0, 24, 7, 3, 14, &PhorurexBoss), Dino(0, 5, 23, 13, 7, 3, &TenontosaurusMinion), Dino(0, 6, 23, 13, 7, 3, &NodosaurusMinion)}),
    make_pair<string, vector<Dino>>("Postimetrodon", {Dino(0, 0, 14, 0, 0, 0, &PostimetrodonBoss)}),
    make_pair<string, vector<Dino>>("Pteranokyrie", {Dino(0, 0, 30, 15, 10, 5, &PteranokyrieBoss), Dino(0, 5, 29, 10, 15, 4, &PteranodonMinion), Dino(0, 6, 29, 15, 10, 4, &AlanqaMinion)}),
    make_pair<string, vector<Dino>>("Pyrritator", {Dino(0, 0, 19, 5, 5, 9, &PyrritatorBoss), Dino(0, 5, 18, 12, 6, 0, &ArchaeotheriumMinion), Dino(0, 6, 18, 12, 6, 0, &NodosaurusMinion)}),
    make_pair<string, vector<Dino>>("Refrenantem", {Dino(0, 0, 30, 15, 15, 0, &RefrenantemBoss), Dino(0, 5, 29, 15, 3, 6, &ArchaeotheriumMinion), Dino(0, 6, 29, 15, 4, 10, &NodosaurusMinion)}),
    make_pair<string, vector<Dino>>("Rinchicyon", {Dino(0, 0, 19, 8, 5, 6, &RinchicyonBoss), Dino(0, 5, 18, 8, 5, 6, &NodosaurusMinion), Dino(0, 6, 18, 10, 5, 3, &GallimimusMinion)}),
    make_pair<string, vector<Dino>>("ScorpiosRex", {Dino(0, 0, 19, 6, 9, 4, &ScorpiosRexBoss), Dino(0, 5, 18, 10, 5, 3, &KoolasuchusGen2Minion), Dino(0, 6, 18, 5, 10, 3, &NodosaurusMinion)}),
    make_pair<string, vector<Dino>>("Sinoceratops", {Dino(0, 0, 14, 0, 0, 0, &SinoceratopsBoss)}),
    make_pair<string, vector<Dino>>("Smilonemys", {Dino(0, 0, 22, 6, 9, 7, &SmilonemysBoss), Dino(0, 5, 21, 8, 7, 6, &MonolophosaurusGen2Minion), Dino(0, 6, 21, 9, 6, 6, &CarnotaurusMinion)}),
    make_pair<string, vector<Dino>>("SpinosaurusAegyptiacus", {Dino(0, 0, 30, 10, 10, 10, &SpinosaurusAegyptiacusBoss)}),
    make_pair<string, vector<Dino>>("Stygidaryx", {Dino(0, 0, 24, 7, 7, 10, &StygidaryxBoss), Dino(0, 5, 23, 9, 6, 8, &ArambourgianiaMinion), Dino(0, 6, 23, 8, 7, 8, &KoolasuchusGen2Minion)}),
    make_pair<string, vector<Dino>>("Therizinosaurus", {Dino(0, 0, 10, 0, 0, 0, &TherizinosaurusBoss)}),
    make_pair<string, vector<Dino>>("Troodoboa", {Dino(0, 0, 25, 10, 10, 5, &TroodoboaBoss), Dino(0, 5, 24, 4, 10, 10, &GorgosaurusMinion), Dino(0, 6, 24, 10, 4, 10, &KoolasuchusGen2Minion)}),
    make_pair<string, vector<Dino>>("TyrannosaurusRex", {Dino(0, 0, 14, 0, 0, 0, &TyrannosaurusRexBoss)}),
    make_pair<string, vector<Dino>>("WoollyMammoth", {Dino(0, 0, 14, 0, 0, 0, &WoollyMammothBoss)}),
};

map<string, const DinoKind *> DinoDex = {
    make_pair("Acrocanthops", &Acrocanthops),
    make_pair("Acrocanthosaurus", &Acrocanthosaurus),
    make_pair("Aenocyonyx", &Aenocyonyx),
    make_pair("Ailurarctos", &Ailurarctos),
    make_pair("Alacranix", &Alacranix),
    make_pair("Alankyloceratops", &Alankyloceratops),
    make_pair("Alankylosaurus", &Alankylosaurus),
    make_pair("Alanqa", &Alanqa),
    make_pair("Albertocevia", &Albertocevia),
    make_pair("Albertosaurus", &Albertosaurus),
    make_pair("Albertospinos", &Albertospinos),
    make_pair("Allodrigues", &Allodrigues),
    make_pair("Alloraptor", &Alloraptor),
    make_pair("Allosaurus", &Allosaurus),
    make_pair("AllosaurusGen2", &AllosaurusGen2),
    make_pair("Allosinosaurus", &Allosinosaurus),
    make_pair("Amargasaurus", &Amargasaurus),
    make_pair("Amargocephalus", &Amargocephalus),
    make_pair("Amphicyon", &Amphicyon),
    make_pair("Andrewsarchus", &Andrewsarchus),
    make_pair("Andrewtherium", &Andrewtherium),
    make_pair("Andrewtodon", &Andrewtodon),
    make_pair("Andrewtops", &Andrewtops),
    make_pair("Ankylocodon", &Ankylocodon),
    make_pair("Ankylodactylus", &Ankylodactylus),
    make_pair("Ankylodicurus", &Ankylodicurus),
    make_pair("Ankylomoloch", &Ankylomoloch),
    make_pair("AnkylosLux", &AnkylosLux),
    make_pair("Ankylosaurus", &Ankylosaurus),
    make_pair("AnkylosaurusGen2", &AnkylosaurusGen2),
    make_pair("Ankyntrosaurus", &Ankyntrosaurus),
    make_pair("Antarctopelta", &Antarctopelta),
    make_pair("Antarctovenator", &Antarctovenator),
    make_pair("Anurognathus", &Anurognathus),
    make_pair("Apatosaurus", &Apatosaurus),
    make_pair("Aquilamimus", &Aquilamimus),
    make_pair("Arambourgiania", &Arambourgiania),
    make_pair("Archaeopteryx", &Archaeopteryx),
    make_pair("Archaeotherium", &Archaeotherium),
    make_pair("Arctalces", &Arctalces),
    make_pair("Arctodus", &Arctodus),
    make_pair("Arctops", &Arctops),
    make_pair("Arctovasilas", &Arctovasilas),
    make_pair("Ardentismaxima", &Ardentismaxima),
    make_pair("Ardontognathus", &Ardontognathus),
    make_pair("Ardontosaurus", &Ardontosaurus),
    make_pair("Argentavis", &Argentavis),
    make_pair("Argenteryx", &Argenteryx),
    make_pair("Argentinosaurus", &Argentinosaurus),
    make_pair("Atrocimoloch", &Atrocimoloch),
    make_pair("Atrocodistis", &Atrocodistis),
    make_pair("Australotitan", &Australotitan),
    make_pair("Bajadasaurus", &Bajadasaurus),
    make_pair("Bajatonodon", &Bajatonodon),
    make_pair("Baryonyx", &Baryonyx),
    make_pair("BaryonyxGen2", &BaryonyxGen2),
    make_pair("Beelzebufo", &Beelzebufo),
    make_pair("Beta", &Beta),
    make_pair("Blue", &Blue),
    make_pair("Borealopelta", &Borealopelta),
    make_pair("Brachiosaurus", &Brachiosaurus),
    make_pair("Brontolasmus", &Brontolasmus),
    make_pair("Brontotherium", &Brontotherium),
    make_pair("Bumpy", &Bumpy),
    make_pair("Carbonemys", &Carbonemys),
    make_pair("Carbotoceratops", &Carbotoceratops),
    make_pair("Carcharodontosaurus", &Carcharodontosaurus),
    make_pair("Carnotarkus", &Carnotarkus),
    make_pair("Carnotaurus", &Carnotaurus),
    make_pair("Ceramagnus", &Ceramagnus),
    make_pair("Ceratosaurus", &Ceratosaurus),
    make_pair("CeratosaurusGen2", &CeratosaurusGen2),
    make_pair("Cervalces", &Cervalces),
    make_pair("Charlie", &Charlie),
    make_pair("CleverGirl", &CleverGirl),
    make_pair("Coelhaast", &Coelhaast),
    make_pair("Coelurosauravus", &Coelurosauravus),
    make_pair("Compsocaulus", &Compsocaulus),
    make_pair("Compsognathus", &Compsognathus),
    make_pair("CompsognathusGen2", &CompsognathusGen2),
    make_pair("Compsoraptor", &Compsoraptor),
    make_pair("Concakuisaurus", &Concakuisaurus),
    make_pair("Concatoloch", &Concatoloch),
    make_pair("Concatosaurus", &Concatosaurus),
    make_pair("Concavenator", &Concavenator),
    make_pair("Constrictoraptor", &Constrictoraptor),
    make_pair("Crichtomoloch", &Crichtomoloch),
    make_pair("Crichtonsaurus", &Crichtonsaurus),
    make_pair("Cryolophosaurus", &Cryolophosaurus),
    make_pair("Dakotanops", &Dakotanops),
    make_pair("Dakotaraptor", &Dakotaraptor),
    make_pair("Darwezopteryx", &Darwezopteryx),
    make_pair("Darwinopterus", &Darwinopterus),
    make_pair("Deinocheirus", &Deinocheirus),
    make_pair("Deinonychus", &Deinonychus),
    make_pair("Deinotherium", &Deinotherium),
    make_pair("Delta", &Delta),
    make_pair("Diabloceratops", &Diabloceratops),
    make_pair("Dilophoboa", &Dilophoboa),
    make_pair("Dilophosaurus", &Dilophosaurus),
    make_pair("DilophosaurusGen2", &DilophosaurusGen2),
    make_pair("Diloracheirus", &Diloracheirus),
    make_pair("Diloranosaurus", &Diloranosaurus),
    make_pair("Dimetrodon", &Dimetrodon),
    make_pair("DimetrodonGen2", &DimetrodonGen2),
    make_pair("Dimodactylus", &Dimodactylus),
    make_pair("Dimorphodon", &Dimorphodon),
    make_pair("Diorajasaur", &Diorajasaur),
    make_pair("Diplocaulus", &Diplocaulus),
    make_pair("DiplocaulusGen2", &DiplocaulusGen2),
    make_pair("Diplodocus", &Diplodocus),
    make_pair("Diplotator", &Diplotator),
    make_pair("Diplovenator", &Diplovenator),
    make_pair("DireWolf", &DireWolf),
    make_pair("Dodo", &Dodo),
    make_pair("Dodocevia", &Dodocevia),
    make_pair("Doedicurus", &Doedicurus),
    make_pair("DracoLux", &DracoLux),
    make_pair("Dracoceratops", &Dracoceratops),
    make_pair("Dracoceratosaurus", &Dracoceratosaurus),
    make_pair("Dracorex", &Dracorex),
    make_pair("DracorexGen2", &DracorexGen2),
    make_pair("Dracovenator", &Dracovenator),
    make_pair("Dreadactylus", &Dreadactylus),
    make_pair("Dreadnoughtus", &Dreadnoughtus),
    make_pair("Dsungaia", &Dsungaia),
    make_pair("Dsungaripterus", &Dsungaripterus),
    make_pair("Dsungascorpios", &Dsungascorpios),
    make_pair("Echo", &Echo),
    make_pair("Edaphocevia", &Edaphocevia),
    make_pair("Edaphosaurus", &Edaphosaurus),
    make_pair("Edmontoguanodon", &Edmontoguanodon),
    make_pair("Edmontosaurus", &Edmontosaurus),
    make_pair("Einiasuchus", &Einiasuchus),
    make_pair("Einiosaurus", &Einiosaurus),
    make_pair("Elasmotherium", &Elasmotherium),
    make_pair("Enteloceros", &Enteloceros),
    make_pair("Entelochops", &Entelochops),
    make_pair("Entelodon", &Entelodon),
    make_pair("Entelolania", &Entelolania),
    make_pair("Entelomoth", &Entelomoth),
    make_pair("Eremoceros", &Eremoceros),
    make_pair("Eremotherium", &Eremotherium),
    make_pair("Erlidominus", &Erlidominus),
    make_pair("Erlikogamma", &Erlikogamma),
    make_pair("Erlikosaurus", &Erlikosaurus),
    make_pair("ErlikosaurusGen2", &ErlikosaurusGen2),
    make_pair("Erlikospyx", &Erlikospyx),
    make_pair("Eucladoceros", &Eucladoceros),
    make_pair("Euoplocephalus", &Euoplocephalus),
    make_pair("Fukuimimus", &Fukuimimus),
    make_pair("Fukuiraptor", &Fukuiraptor),
    make_pair("Fukuisaurus", &Fukuisaurus),
    make_pair("Gallimimus", &Gallimimus),
    make_pair("Geminideus", &Geminideus),
    make_pair("Geminititan", &Geminititan),
    make_pair("Geosternbergia", &Geosternbergia),
    make_pair("Ghost", &Ghost),
    make_pair("Giganotosaurus", &Giganotosaurus),
    make_pair("Giganspinoceratops", &Giganspinoceratops),
    make_pair("Gigantspinosaurus", &Gigantspinosaurus),
    make_pair("Giganyx", &Giganyx),
    make_pair("Gigaspikasaur", &Gigaspikasaur),
    make_pair("Giraffatitan", &Giraffatitan),
    make_pair("Glyptoceras", &Glyptoceras),
    make_pair("Glyptodon", &Glyptodon),
    make_pair("Gorgonops", &Gorgonops),
    make_pair("Gorgosaurus", &Gorgosaurus),
    make_pair("Gorgosuchus", &Gorgosuchus),
    make_pair("Gorgotrebax", &Gorgotrebax),
    make_pair("Gryganyth", &Gryganyth),
    make_pair("Grylenken", &Grylenken),
    make_pair("Grypolyth", &Grypolyth),
    make_pair("Gryposuchus", &Gryposuchus),
    make_pair("HaastEagle", &HaastEagle),
    make_pair("HaastEagleGen2", &HaastEagleGen2),
    make_pair("HaastMaximus", &HaastMaximus),
    make_pair("HadrosLux", &HadrosLux),
    make_pair("Hatzegopteryx", &Hatzegopteryx),
    make_pair("Homalocephale", &Homalocephale),
    make_pair("HydraBoa", &HydraBoa),
    make_pair("Ichthyovenator", &Ichthyovenator),
    make_pair("Iguanodon", &Iguanodon),
    make_pair("Imperatosuchus", &Imperatosuchus),
    make_pair("Indolycan", &Indolycan),
    make_pair("IndominusRex", &IndominusRex),
    make_pair("IndominusRexGen2", &IndominusRexGen2),
    make_pair("Indonemys", &Indonemys),
    make_pair("Indoraptor", &Indoraptor),
    make_pair("IndoraptorGen2", &IndoraptorGen2),
    make_pair("Indotaurus", &Indotaurus),
    make_pair("Inostherium", &Inostherium),
    make_pair("Inostrancevia", &Inostrancevia),
    make_pair("Irritator", &Irritator),
    make_pair("IrritatorGen2", &IrritatorGen2),
    make_pair("Kaprosuchus", &Kaprosuchus),
    make_pair("Kelenken", &Kelenken),
    make_pair("Kentrosaurus", &Kentrosaurus),
    make_pair("Keratoporcus", &Keratoporcus),
    make_pair("Koolabourgiana", &Koolabourgiana),
    make_pair("Koolasuchus", &Koolasuchus),
    make_pair("KoolasuchusGen2", &KoolasuchusGen2),
    make_pair("Koreanosaurus", &Koreanosaurus),
    make_pair("Lystrosaurus", &Lystrosaurus),
    make_pair("Lystrosavis", &Lystrosavis),
    make_pair("Lystrosuchus", &Lystrosuchus),
    make_pair("Lythronax", &Lythronax),
    make_pair("Magnapyritor", &Magnapyritor),
    make_pair("Magnaraptor", &Magnaraptor),
    make_pair("Maiasaura", &Maiasaura),
    make_pair("Majundaboa", &Majundaboa),
    make_pair("Majundasuchus", &Majundasuchus),
    make_pair("Majungasaurus", &Majungasaurus),
    make_pair("Mammolania", &Mammolania),
    make_pair("Mammotherium", &Mammotherium),
    make_pair("MarsupialLion", &MarsupialLion),
    make_pair("Masiakasaurus", &Masiakasaurus),
    make_pair("Megalania", &Megalania),
    make_pair("Megaloceros", &Megaloceros),
    make_pair("Megalocevia", &Megalocevia),
    make_pair("Megalogaia", &Megalogaia),
    make_pair("Megalonyx", &Megalonyx),
    make_pair("Megalosaurus", &Megalosaurus),
    make_pair("Megalosuchus", &Megalosuchus),
    make_pair("Megalotops", &Megalotops),
    make_pair("Megistocurus", &Megistocurus),
    make_pair("Megistotherium", &Megistotherium),
    make_pair("Meiolania", &Meiolania),
    make_pair("Microraptor", &Microraptor),
    make_pair("Miragaia", &Miragaia),
    make_pair("Monolometrodon", &Monolometrodon),
    make_pair("Monolophosaurus", &Monolophosaurus),
    make_pair("MonolophosaurusGen2", &MonolophosaurusGen2),
    make_pair("Monolorhino", &Monolorhino),
    make_pair("Monomimus", &Monomimus),
    make_pair("Monostegotops", &Monostegotops),
    make_pair("MorosIntrepidus", &MorosIntrepidus),
    make_pair("MortemRex", &MortemRex),
    make_pair("Moschops", &Moschops),
    make_pair("Nasutoceratops", &Nasutoceratops),
    make_pair("Nodopatosaurus", &Nodopatosaurus),
    make_pair("Nodopatotitan", &Nodopatotitan),
    make_pair("Nodosaurus", &Nodosaurus),
    make_pair("Nomingia", &Nomingia),
    make_pair("Nundasuchus", &Nundasuchus),
    make_pair("Olorotitan", &Olorotitan),
    make_pair("Ophiacodon", &Ophiacodon),
    make_pair("Ornithomimus", &Ornithomimus),
    make_pair("Ouranosaurus", &Ouranosaurus),
    make_pair("Ovilophomoloch", &Ovilophomoloch),
    make_pair("Ovilophosaurus", &Ovilophosaurus),
    make_pair("Oviraptor", &Oviraptor),
    make_pair("OviraptorGen2", &OviraptorGen2),
    make_pair("Pachycephalosaurus", &Pachycephalosaurus),
    make_pair("Panthera", &Panthera),
    make_pair("PantheraBlytheae", &PantheraBlytheae),
    make_pair("Pantherator", &Pantherator),
    make_pair("Paramoloch", &Paramoloch),
    make_pair("Parasaurolophus", &Parasaurolophus),
    make_pair("ParasaurolophusLux", &ParasaurolophusLux),
    make_pair("Parasauthops", &Parasauthops),
    make_pair("Phorurex", &Phorurex),
    make_pair("Phorusaura", &Phorusaura),
    make_pair("Phorusrhacos", &Phorusrhacos),
    make_pair("Plateopikasaurus", &Plateopikasaurus),
    make_pair("Plateorex", &Plateorex),
    make_pair("Plateosaurus", &Plateosaurus),
    make_pair("Postimetrodon", &Postimetrodon),
    make_pair("Postosuchus", &Postosuchus),
    make_pair("Poukaidei", &Poukaidei),
    make_pair("Poukandactylus", &Poukandactylus),
    make_pair("Preondactylus", &Preondactylus),
    make_pair("Procerathomimus", &Procerathomimus),
    make_pair("Proceratosaurus", &Proceratosaurus),
    make_pair("Pteranodon", &Pteranodon),
    make_pair("Pteranokyrie", &Pteranokyrie),
    make_pair("Pteraquetzal", &Pteraquetzal),
    make_pair("Pterovexus", &Pterovexus),
    make_pair("Pulmonoscorpius", &Pulmonoscorpius),
    make_pair("Purrolyth", &Purrolyth),
    make_pair("Purussaurus", &Purussaurus),
    make_pair("PurussaurusGen2", &PurussaurusGen2),
    make_pair("Purutaurus", &Purutaurus),
    make_pair("Pyroraptor", &Pyroraptor),
    make_pair("PyroraptorGen2", &PyroraptorGen2),
    make_pair("Pyrorixis", &Pyrorixis),
    make_pair("Pyrosuchus", &Pyrosuchus),
    make_pair("Pyrritator", &Pyrritator),
    make_pair("Quetzalcoatlus", &Quetzalcoatlus),
    make_pair("QuetzalcoatlusGen2", &QuetzalcoatlusGen2),
    make_pair("Quetzaljara", &Quetzaljara),
    make_pair("Quetzorion", &Quetzorion),
    make_pair("Rajakylosaurus", &Rajakylosaurus),
    make_pair("Rajasaurus", &Rajasaurus),
    make_pair("Rativates", &Rativates),
    make_pair("Red", &Red),
    make_pair("Refrenantem", &Refrenantem),
    make_pair("Rexy", &Rexy),
    make_pair("Rinchenia", &Rinchenia),
    make_pair("Rinchicyon", &Rinchicyon),
    make_pair("RodriguesSolitaire", &RodriguesSolitaire),
    make_pair("SahPanthera", &SahPanthera),
    make_pair("Sarcorixis", &Sarcorixis),
    make_pair("Sarcosuchus", &Sarcosuchus),
    make_pair("Scaphognathus", &Scaphognathus),
    make_pair("Scaphotator", &Scaphotator),
    make_pair("Scelidosaurus", &Scelidosaurus),
    make_pair("Scolosaurus", &Scolosaurus),
    make_pair("ScorpiosRex", &ScorpiosRex),
    make_pair("ScorpiosRexGen2", &ScorpiosRexGen2),
    make_pair("ScorpiosRexGen3", &ScorpiosRexGen3),
    make_pair("Scutophicyon", &Scutophicyon),
    make_pair("Scutosaurus", &Scutosaurus),
    make_pair("Secodontosaurus", &Secodontosaurus),
    make_pair("Segnoraptor", &Segnoraptor),
    make_pair("Segnosaurus", &Segnosaurus),
    make_pair("Segnotherisaurus", &Segnotherisaurus),
    make_pair("Sinoceratops", &Sinoceratops),
    make_pair("Sinokotaraptor", &Sinokotaraptor),
    make_pair("Sinosauropteryx", &Sinosauropteryx),
    make_pair("Sinraptor", &Sinraptor),
    make_pair("Skoolasaurus", &Skoolasaurus),
    make_pair("Skoonametrodon", &Skoonametrodon),
    make_pair("Skoonasaurus", &Skoonasaurus),
    make_pair("Smilocephalosaurus", &Smilocephalosaurus),
    make_pair("Smilodon", &Smilodon),
    make_pair("Smilonemys", &Smilonemys),
    make_pair("Sonorasaurus", &Sonorasaurus),
    make_pair("Spinoceratops", &Spinoceratops),
    make_pair("Spinoconstrictor", &Spinoconstrictor),
    make_pair("Spinonyx", &Spinonyx),
    make_pair("Spinosaurus", &Spinosaurus),
    make_pair("SpinosaurusAegyptiacus", &SpinosaurusAegyptiacus),
    make_pair("SpinosaurusGen2", &SpinosaurusGen2),
    make_pair("Spinotahraptor", &Spinotahraptor),
    make_pair("Spinotasuchus", &Spinotasuchus),
    make_pair("Stegoceras", &Stegoceras),
    make_pair("Stegoceratops", &Stegoceratops),
    make_pair("Stegodeus", &Stegodeus),
    make_pair("Stegosaurus", &Stegosaurus),
    make_pair("StegosaurusUngulatus", &StegosaurusUngulatus),
    make_pair("Stegouros", &Stegouros),
    make_pair("Struthiomimus", &Struthiomimus),
    make_pair("Stygidaryx", &Stygidaryx),
    make_pair("Stygimoloch", &Stygimoloch),
    make_pair("StygimolochGen2", &StygimolochGen2),
    make_pair("StyracosaurusLux", &StyracosaurusLux),
    make_pair("Suchomimus", &Suchomimus),
    make_pair("Suchotator", &Suchotator),
    make_pair("Tanycolagreus", &Tanycolagreus),
    make_pair("Tapejara", &Tapejara),
    make_pair("Tarbognathus", &Tarbognathus),
    make_pair("Tarbosaurus", &Tarbosaurus),
    make_pair("Tenontorex", &Tenontorex),
    make_pair("Tenontosaurus", &Tenontosaurus),
    make_pair("Testacornibus", &Testacornibus),
    make_pair("Therizinosaurus", &Therizinosaurus),
    make_pair("Thoradolosaur", &Thoradolosaur),
    make_pair("Thylaconyx", &Thylaconyx),
    make_pair("Thylacotator", &Thylacotator),
    make_pair("ThylosIntrepidus", &ThylosIntrepidus),
    make_pair("Tiger", &Tiger),
    make_pair("Titanoboa", &Titanoboa),
    make_pair("TitanoboaGen2", &TitanoboaGen2),
    make_pair("Toro", &Toro),
    make_pair("Tragodistis", &Tragodistis),
    make_pair("Triceratops", &Triceratops),
    make_pair("TriceratopsGen2", &TriceratopsGen2),
    make_pair("Troodoboa", &Troodoboa),
    make_pair("Troodon", &Troodon),
    make_pair("Trykosaurus", &Trykosaurus),
    make_pair("Tryostronix", &Tryostronix),
    make_pair("Tsintamoth", &Tsintamoth),
    make_pair("Tsintaosaurus", &Tsintaosaurus),
    make_pair("Tuojiangosaurus", &Tuojiangosaurus),
    make_pair("Tuoramoloch", &Tuoramoloch),
    make_pair("Tupandactylus", &Tupandactylus),
    make_pair("Tyrannolophosaur", &Tyrannolophosaur),
    make_pair("Tyrannometrodon", &Tyrannometrodon),
    make_pair("TyrannosaurBuck", &TyrannosaurBuck),
    make_pair("TyrannosaurDoe", &TyrannosaurDoe),
    make_pair("TyrannosaurusRex", &TyrannosaurusRex),
    make_pair("TyrannosaurusRexGen2", &TyrannosaurusRexGen2),
    make_pair("Utahraptor", &Utahraptor),
    make_pair("Utarinex", &Utarinex),
    make_pair("Utasinoraptor", &Utasinoraptor),
    make_pair("Vectispinus", &Vectispinus),
    make_pair("Velociraptor", &Velociraptor),
    make_pair("Velosrhacos", &Velosrhacos),
    make_pair("WoollyMammoth", &WoollyMammoth),
    make_pair("WoollyRhino", &WoollyRhino),
    make_pair("Wuerhosaurus", &Wuerhosaurus),
    make_pair("Yutyrannus", &Yutyrannus),
    make_pair("Yuxisaurus", &Yuxisaurus),
    make_pair("_93ClassicT_Rex", &_93ClassicT_Rex),
};
