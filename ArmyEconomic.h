//
// Created by kvk1920 on 21.04.18.
//

#ifndef TASK2_ARMYECONOMIC_H
#define TASK2_ARMYECONOMIC_H

#include "Squad.h"
#include <vector>
#include <string>

namespace Economic {

using namespace SquadUtility;

class ArmyEconomic {
    friend class EconomicProxy;
  private:
    int money;
    int income;

    std::vector<SquadDecorator> decorator_list;
    std::vector<std::string> name_list;
    std::vector<int> cost_list;
  public:
    ArmyEconomic(int start_money, int start_income);

    int getMoney() const;
    int getIncome() const;
    void increaseMoney();
    void increaseIncome(int add);

    std::vector<std::string> getDecoratorLists() const;
    std::vector<int> getPrices() const;

    SquadDecorator* buyDecorator(int id);
};

}

#endif //TASK2_ARMYECONOMIC_H
