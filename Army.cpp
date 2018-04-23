//
// Created by kvk1920 on 23.04.18.
//

#include "Army.h"

namespace Army {

BattleResult::BattleResult(winner_type winner, std::vector<Squad> losses1, std::vector<Squad> losses2) :
        winner(winner) {
    losses[0] = std::move(losses1);
    losses[1] = std::move(losses2);
}

Army::EconomicProxy::EconomicProxy(Army* p) : army(p) {}

std::vector<std::string> Army::EconomicProxy::getDecoratorNames() const {
    return army->economic->getDecoratorLists();
}

std::vector<int> Army::EconomicProxy::getDecoratorPrices() const {
    return army->economic->getPrices();
}

int Army::EconomicProxy::getIncome() const {
    return army->economic->getIncome();
}

int Army::EconomicProxy::getmoney() const {
    return army->economic->getMoney();
}

bool Army::EconomicProxy::BuyDecorator(int id) {
    SquadDecorator* new_mod = army->economic->buyDecorator(id);
    if (new_mod) {
        army->modificators.push_back(new_mod);
        return true;
    } else {
        return false;
    }
}

Army::HireProxy::HireProxy(Army* p) : army(p) {}

void Army::HireProxy::hireArcher(int k) {
    army->squads.emplace_back(new Squad(army->factory->makeArcher(), k));
}

void Army::HireProxy::hireSaber(int k) {
    army->squads.emplace_back(new Squad(army->factory->makeSaber(), k));
}
void Army::HireProxy::hireLancer(int k) {
    army->squads.emplace_back(new Squad(army->factory->makeLancer(), k));
}
void Army::HireProxy::hireRider(int k) {
    army->squads.emplace_back(new Squad(army->factory->makeRider(), k));
}

Army::Army(std::string name, UnitFactory* factory, ArmyEconomic* economic) :
        name(move(name)), factory(factory), economic(economic) {}

Army::~Army() {
    for (auto& p : squads)
        delete p;
    for (auto& p : modificators)
        delete p;
    delete economic;
    delete factory;
}

int Army::speed() const {
    int speed = 1e9;
    for (Squad* squad : squads)
    {
        AbstractSquad* p = squad;
        for (SquadDecorator* t : modificators)
            p = t->decorate(p);
        speed = std::min(p->speed(), speed);
        delete p;
    }
    return speed;
}

std::vector<std::string> Army::getUnitTypes() const {
    std::vector<std::string> units;
    for (Squad* squad : squads)
        units.push_back(squad->name());
    return units;
}

std::vector<int> Army::getSquadSizes() const {
    std::vector<int> sizes;
    for (Squad* squad : squads)
        sizes.push_back(squad->size());
    return sizes;
}

Army::EconomicProxy Army::getEconomicMenu() {
    return EconomicProxy(this);
}

Army::HireProxy Army::getHireMenu() {
    return HireProxy(this);
}

BattleResult Army::Attack(Army* other) {

}

}
