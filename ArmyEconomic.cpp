//
// Created by kvk1920 on 21.04.18.
//

#include "ArmyEconomic.h"

namespace Economic {

#define __AddDecorator(name, A, S, D, cost) \
cost_list.push_back(cost); \
name_list.emplace_back(#name); \
decorator_list.emplace_back(A, S, D)

ArmyEconomic::ArmyEconomic(int start_money, int start_income) :
        money(start_money),
        income(start_income) {
    __AddDecorator(SteelWeapon, 0.2, 0, 0, 100);
    __AddDecorator(SteelArmor, 0, 0, 0.2, 70);
    __AddDecorator(ComfortBoots, 0, 0.1, 0, 80);
}

std::vector<std::string> ArmyEconomic::getDecoratorLists() const {
    return name_list;
}

int ArmyEconomic::getMoney() const {
    return money;
}

int ArmyEconomic::getIncome() const {
    return income;
}

void ArmyEconomic::increaseMoney() {
    money += income;
}

void ArmyEconomic::increaseIncome(int add) {
    income += add;
}

SquadDecorator* ArmyEconomic::buyDecorator(int id) {
    if (id >= decorator_list.size())
        throw std::runtime_error("Invalid decorator id.");
    if (money < cost_list[id])
        return nullptr;
    money -= cost_list[id];
    return &(decorator_list[id]);
}

std::vector<int> ArmyEconomic::getPrices() const {
    return cost_list;
}

}