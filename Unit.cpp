//
// Created by kvk1920 on 17.04.18.
//

#include "Unit.h"
#include <cmath>

namespace UnitUtility {

UnitData::UnitData(std::string name, int attack, int defence, int max_health, int speed) :
    name(std::move(name)),
    attack(attack),
    defence(defence),
    max_health(max_health),
    speed(speed)
{}

Unit::Unit(const UnitData* p) noexcept :
        HP(p->max_health),
        data(p) {}

std::string Unit::name() const {
    return data->name;
}

int Unit::attack(float modify) const {
    return static_cast<int>(std::round(data->attack * modify));
}

int Unit::defence(float modify) const {
    return static_cast<int>(std::round(data->defence * modify));
}

int Unit::health() const {
    return HP;
}

int Unit::max_health() const {
    return data->max_health;
}

int Unit::speed(float modify) const {
    return static_cast<int>(std::max(1.0f, std::round(data->speed * modify)));
}

Unit::~Unit() {}

int Unit::GetDamage(int damage) {
    if (damage < HP) {
        HP -= damage;
        return 0;
    }
    int killed(1);
    damage -= HP;
    HP = max_health() - damage % max_health();
    killed += (damage + max_health()) / max_health();
    return killed;
}

inline bool isSameUnit(Unit* a, Unit* b) noexcept {
    if (!a || !b)
        return false;
    return a->name() == b->name();
}

}
