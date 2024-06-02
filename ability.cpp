#include "ability.h"
#include "dino.h"
#include <memory.h>
#include "actions.h"
#include <cassert>
#include "utils.h"
#include "pack.h"

using namespace actions;
using namespace std;

void Ability::Prepare(Dino &dino, int *cooldown, int *priority) const
{
    if (priority != nullptr)
        *priority = this->priority;
    if (cooldown != nullptr)
        *cooldown = this->cooldown;
}

function<bool(const Dino &,const Dino &)> TargetCmp[] = {
    [](const Dino &dino1, const Dino &dino2) -> bool { return false; },
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.index < dino2.index; },
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.total_health < dino2.total_health; },
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.total_health > dino2.total_health; },
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.Damage() < dino2.Damage(); },
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.Damage() > dino2.Damage(); },
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.Speed() < dino2.Speed(); },
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.Speed() > dino2.Speed(); },
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.n_positive_effects > dino2.n_positive_effects; },
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.health < dino2.health; }, // health or total_health?
};

function<bool(const Dino &, const Dino &)> CheckTarget[] = {
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.team != dino2.team; }, // random
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.team != dino2.team; }, // none
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.team != dino2.team; }, // lowest hp
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.team != dino2.team; }, // highest hp
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.team != dino2.team; }, // lowest damage
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.team != dino2.team; }, // highest damage
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.team != dino2.team; }, // lowest speed
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.team != dino2.team; }, // highest speed
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.team != dino2.team; }, // most positive effects
    [](const Dino &dino1, const Dino &dino2) -> bool { return dino1.team == dino2.team; }, // lowest hp teammate
};

void Ability::Do(Dino &dino, Dino team[], int team_size) const
{
    Dino *last = nullptr;
    for (const auto &action: actions) {
        switch(action->target) {
        case TARGET_EVERYONE:
            for (int i = 0; i < team_size; ++i) {
                if (!team[i].Alive())
                    continue;
                action->Do(dino, team[i]);
            }
            break;
        case TARGET_ALL_OPPONENTS:
            for (int i = 0; i < team_size; ++i) {
                if (team[i].team == dino.team)
                    continue;
                if (!team[i].Alive())
                    continue;
                action->Do(dino, team[i]);
            }
            break;
        case TARGET_TEAM:
            for (int i = 0; i < team_size; ++i) {
                if (team[i].team != dino.team)
                    continue;
                if (!team[i].Alive())
                    continue;
                action->Do(dino, team[i]);
            }
            break;
        case TARGET_SELF:
            action->Do(dino, dino);
            break;
        case TARGET_ATTACKER:
            if (!dino.attacker->Alive())
                continue;
            action->Do(dino, *dino.attacker);
            break;
        case TARGET_LAST:
            assert(last != nullptr);
            if (!last->Alive())
                continue;
            action->Do(dino, *last);
            break;
        default:
            int count = 0;
            for (int i = 0; i < team_size; ++i) {
                if (!team[i].Alive())
                    continue;
                if (!CheckTarget[action->target](dino, team[i]))
                    continue;
                if (action->target == TARGET_RANDOM) {
                    if (Rand(++count) == 0)
                        last = &team[i];
                    continue;
                }
                if (team[i].team != dino.team && team[i].Taunt() && Rand(100) < dino.ResistanceFactor(&Dino::taunt_resistance) * 100) {
                    last = &team[i];
                    break;
                }
                if (last == nullptr)
                    last = &team[i];
                else if (TargetCmp[action->target](*last, team[i]))
                    continue;
                else if (TargetCmp[action->target](team[i], *last))
                    last = &team[i];
                else if (ActionOrderCmp(team[i], *last))
                    continue;
                else
                    last = &team[i];
            }
            action->Do(dino, *last);
            break;
        }
    }
}

void RevengeAbility::Prepare(Dino &dino, int *cooldown, int *priority) const
{
    if (dino.revenge_ready)
        revenge_ability.Prepare(dino, cooldown, priority);
    else
        Ability::Prepare(dino, cooldown, priority);

}

void RevengeAbility::Do(Dino &dino, Dino team[], int size) const
{
    if (dino.revenge_ready)
        revenge_ability.Do(dino, team, size);
    else
        Ability::Do(dino, team, size);
}

static inline bool Threatened(const Dino &dino, int threat_factor, ThreatComparison threat_comparison)
{
    int num = 0, den = 0;
    switch (threat_factor) {
    case 25:
        num = 1;
        den = 4;
        break;
    case 33:
        num = 1;
        den = 3;
        break;
    case 50:
        num = 1;
        den = 2;
        break;
    case 66:
        num = 2;
        den = 3;
        break;
    default:
        return false;
    }
    if (threat_comparison == ThreatComparison::Lower)
        return dino.initial_total_health * den <= dino.max_total_health * num;
    else // if (threat_comparison == ThreatComparison::Higher)
        return dino.initial_total_health * den > dino.max_total_health * num;
}

void ThreatenedAbility::Prepare(Dino &dino, int *cooldown, int *priority) const
{
    if (Threatened(dino, threat_factor, threat_comparison))
        threatened_ability.Prepare(dino, cooldown, priority);
    else
        Ability::Prepare(dino, cooldown, priority);
}

void ThreatenedAbility::Do(Dino &dino, Dino team[], int size) const
{
    if (Threatened(dino, threat_factor, threat_comparison))
        threatened_ability.Do(dino, team, size);
    else
        Ability::Do(dino, team, size);
}

void CounterAbility::Do(Dino &dino, Dino team[], int size) const
{
    Ability::Do(dino, team, size);
}

void ThreatenedCounterAbility::Do(Dino &dino, Dino team[], int size) const
{
    if (Threatened(dino, threat_factor, threat_comparison))
        threatened_ability.Do(dino, team, size);
    else
        Ability::Do(dino, team, size);
}
