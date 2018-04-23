//
// Created by kvk1920 on 19.04.18.
//

#include "Squad.h"
#include <cmath>

namespace SquadUtility {

/*
 * AbstractSquad
 */

//AbstractSquad::~AbstractSquad() {}
//AbstractSquad


/*
 * Squad
 */

Squad::Squad(std::unique_ptr<Unit>&& unit, int nsize) :
        unit(std::move_cast<Unit>(std::move(unit))),
        cnt(nsize)
{}

std::string Squad::name() const { return (unit)->name(); }

int Squad::attack(float modify) const {
    return unit->attack(modify);
}

int Squad::defence(float modify) const {
    return unit->defence(modify);
}

int Squad::speed(float modify) const {
    return unit->speed(modify);
}

inline bool mergeSquads(Squad* first, Squad* second) {
    if (!UnitUtility::isSameUnitClass(first->unit.get(), second->unit.get()))
        return false;
    first->cnt += second->cnt;
    second->cnt = 0;
    return true;
}

bool Squad::GetDamage(int damage) {
    return unit->GetDamage(damage) >= cnt;
}

int Squad::size() const {
    return cnt;
}
//Squad

/*
 * SquadDecorator
 */

SquadDecorator::SquadDecorator(float A, float S, float D) :
        attack_buff(A),
        defence_buff(D),
        speed_buff(S),
        object(nullptr)
{}

std::string SquadDecorator::name() const {
    return object->name();
}

int SquadDecorator::attack(float modify) const {
    return object->attack(modify + attack_buff);
}

int SquadDecorator::defence(float modify) const {
    return object->defence(modify + defence_buff);
}

int SquadDecorator::speed(float modify) const {
    return object->speed(modify + speed_buff);
}

SquadDecorator::SquadDecorator(const SquadDecorator* p) :
        attack_buff(p->attack_buff),
        speed_buff(p->speed_buff),
        defence_buff(p->defence_buff),
        object(nullptr)
{}

void SquadDecorator::setObject(AbstractSquad* p) {
    object = p;
}

SquadDecorator* SquadDecorator::decorate(AbstractSquad* p) const {
    SquadDecorator* decorated_object = new SquadDecorator(this);
    decorated_object->setObject(p);
    return decorated_object;
}

int SquadDecorator::size() const {
    if (!object)
        throw std::logic_error("Empty SquadDecorator used as Squad");
    return object->size();
}

bool SquadDecorator::GetDamage(int damage) {
    return object->GetDamage(damage);
}

SquadDecorator::~SquadDecorator() {
    if (object and not object->is_not_decorator())
        delete object;
}
//SquadDecorator

}