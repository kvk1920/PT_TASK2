//
// Created by kvk1920 on 17.04.18.
//

#ifndef TASK2_UNIT_H
#define TASK2_UNIT_H

#include <string>

namespace UnitUtility {

struct UnitData {
    const std::string name;
    const int attack;
    const int defence;
    const int max_health;
    const int speed;
    UnitData(std::string name, int attack, int defence, int max_health, int speed);
    virtual ~UnitData() = default;
};

class Unit {
  protected:
    int HP;
    const UnitData* data;
    explicit Unit(const UnitData* p) noexcept;
  public:
    std::string name() const;
    int attack(float modify = 1) const;
    int defence(float modify = 1) const;
    int max_health() const;
    int health() const;
    int speed(float modify = 1) const;

    Unit() = delete;
    virtual ~Unit();
    int GetDamage(int damage);
};

inline bool isSameUnitClass(Unit* a, Unit* b) noexcept {
    return a->name() == b->name();
}

}

#endif //TASK2_UNIT_H
