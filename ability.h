#ifndef __ABILITY__H__
#define __ABILITY__H__

#include <list>
#include <string>
#include <memory>
#include <functional>
#include "actions.h"
#include "pack.h"

struct Dino;

struct Ability
{
    std::string name;
    int delay;
    int cooldown;
    int priority;
    std::list<std::unique_ptr<actions::Action>> actions;

    Ability(const std::string &_name, int _delay, int _cooldown, int _priority, std::initializer_list<std::list<std::unique_ptr<actions::Action>>> _action_lists)
        : name(_name)
        , delay(_delay)
        , cooldown(_cooldown)
        , priority(_priority)
        , actions()
    {
        for (auto list_it = _action_lists.begin(); list_it != _action_lists.end(); ++list_it) {
            for (auto action_it = const_cast<std::list<std::unique_ptr<actions::Action>>*>(&*list_it)->begin(); action_it != const_cast<std::list<std::unique_ptr<actions::Action>>*>(&*list_it)->end(); ++action_it) {
                actions.push_back(std::move(*action_it));
            }
        }
    }
    virtual ~Ability() {}
    virtual void Prepare(Dino &self, int *cooldown, int *priority) const;
    virtual void Do(Dino &self, Dino team[], int size) const;
};

struct RevengeAbility : public Ability
{
    Ability revenge_ability;
    RevengeAbility(const std::string &_name, int _delay, int _cooldown, int _priority, std::initializer_list<std::list<std::unique_ptr<actions::Action>>> _action_lists, int _revenge_delay, int _revenge_cooldown, int _revenge_priority, std::initializer_list<std::list<std::unique_ptr<actions::Action>>> _revenge_action_lists)
        : Ability(_name, _delay, _cooldown, _priority, std::move(_action_lists))
        , revenge_ability(_name, _revenge_delay, _revenge_cooldown, _revenge_priority, std::move(_revenge_action_lists))
    {}
    virtual void Prepare(Dino &self, int *cooldown, int *priority) const override;
    virtual void Do(Dino &self, Dino team[], int size) const override;
};

struct ThreatenedAbility : public Ability
{
    std::function<bool(Dino&)> threat_checker;
    Ability threatened_ability;
    ThreatenedAbility(const std::string &_name, int _delay, int _cooldown, int _priority, std::initializer_list<std::list<std::unique_ptr<actions::Action>>> _action_lists, std::function<bool(Dino&)> _threat_checker, int _threatened_delay, int _threatened_cooldown, int _threatened_priority, std::initializer_list<std::list<std::unique_ptr<actions::Action>>> _threatened_action_lists)
        : Ability(_name, _delay, _cooldown, _priority, std::move(_action_lists))
        , threat_checker(_threat_checker)
        , threatened_ability(_name, _threatened_delay, _threatened_cooldown, _threatened_priority, std::move(_threatened_action_lists))
    {}
    virtual void Prepare(Dino &self, int *cooldown, int *priority) const override;
    virtual void Do(Dino &self, Dino team[], int size) const override;
};

struct CounterAbility : public Ability
{
    CounterAbility(const std::string &_name, std::initializer_list<std::list<std::unique_ptr<actions::Action>>> _action_lists)
        : Ability(_name, 0, 0, 0, std::move(_action_lists))
    {}
    virtual void Prepare(Dino &self, int *cooldown, int *priority) const override
    {}
    virtual void Do(Dino &self, Dino team[], int size) const override;
};

struct ThreatenedCounterAbility : public CounterAbility
{
    std::function<bool(Dino&)> threat_checker;
    CounterAbility threatened_ability;
    ThreatenedCounterAbility(const std::string &_name, std::initializer_list<std::list<std::unique_ptr<actions::Action>>> _action_lists, std::function<bool(Dino&)> _threat_checker, std::initializer_list<std::list<std::unique_ptr<actions::Action>>> _threatened_action_lists)
        : CounterAbility(_name, std::move(_action_lists))
        , threat_checker(_threat_checker)
        , threatened_ability(_name, std::move(_threatened_action_lists))
    {}
    virtual void Prepare(Dino &self, int *cooldown, int *priority) const override
    {}
    virtual void Do(Dino &self, Dino team[], int size) const override;
};

#include "unpack.h"

#endif //__ABILITY__H__
