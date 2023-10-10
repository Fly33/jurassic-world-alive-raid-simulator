#include "ability.h"
#include "dino.h"
#include <memory.h>
#include "actions.h"
#include <cassert>
#include "utils.h"
#include "pack.h"

using namespace actions;
using namespace std;

void Ability::Prepare(Dino &self, int *cooldown, int *priority) const
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

void Ability::Do(Dino &self, Dino team[], int team_size) const
{
    Dino *last = nullptr;
    for (const auto &action: actions) {
        switch(action->target) {
        case TARGET_ALL_OPPONENTS:
            for (int i = 0; i < team_size; ++i) {
                if (team[i].team == self.team)
                    continue;
                if (!team[i].Alive())
                    continue;
                action->Do(self, team[i]);
            }
            break;
        case TARGET_TEAM:
            for (int i = 0; i < team_size; ++i) {
                if (team[i].team != self.team)
                    continue;
                if (!team[i].Alive())
                    continue;
                action->Do(self, team[i]);
            }
            break;
        case TARGET_SELF:
            action->Do(self, self);
            break;
        case TARGET_ATTACKER:
            if (!self.attacker->Alive())
                continue;
            action->Do(self, *self.attacker);
            break;
        case TARGET_LAST:
            assert(last != nullptr);
            if (!last->Alive())
                continue;
            action->Do(self, *last);
            break;
        default:
            int count = 0;
            for (int i = 0; i < team_size; ++i) {
                if (!team[i].Alive())
                    continue;
                if (!CheckTarget[action->target](self, team[i]))
                    continue;
                if (action->target != TARGET_RANDOM && team[i].team != self.team && team[i].Taunt() && Rand(100) < self.ResistanceFactor(&DinoRound::taunt_resistance) * 100) {
                    last = &team[i];
                    break;
                }
                if (last == nullptr) {
                    last = &team[i];
                    count = 1;
                } else if (TargetCmp[action->target](*last, team[i]))
                    continue;
                else if (TargetCmp[action->target](team[i], *last)) {
                    last = &team[i];
                    count = 1;
                } else if (Rand(++count) == 0)
                    last = &team[i];
            }
            action->Do(self, *last);
            break;
        }
    }
}

void RevengeAbility::Prepare(Dino &self, int *cooldown, int *priority) const
{
    self.revenge_ready = self.revenge;
    if (self.revenge_ready)
        revenge_ability.Prepare(self, cooldown, priority);
    else
        Ability::Prepare(self, cooldown, priority);

}

void RevengeAbility::Do(Dino &self, Dino team[], int size) const
{
    if (self.revenge_ready)
        revenge_ability.Do(self, team, size);
    else
        Ability::Do(self, team, size);
}

void ThreatenedAbility::Prepare(Dino &self, int *cooldown, int *priority) const
{
    self.threatened = threat_checker(self);
    if (self.threatened)
        threatened_ability.Prepare(self, cooldown, priority);
    else
        Ability::Prepare(self, cooldown, priority);
}

void ThreatenedAbility::Do(Dino &self, Dino team[], int size) const
{
    if (self.threatened)
        threatened_ability.Do(self, team, size);
    else
        Ability::Do(self, team, size);
}

void CounterAbility::Do(Dino &self, Dino team[], int size) const
{
    Ability::Do(self, team, size);
}

void ThreatenedCounterAbility::Do(Dino &self, Dino team[], int size) const
{
    if (threat_checker(self))
        threatened_ability.Do(self, team, size);
    else
        Ability::Do(self, team, size);
}
