//
// Created by kvk1920 on 23.04.18.
//

#ifndef TASK2_ARMY_H
#define TASK2_ARMY_H

#include "ArmyEconomic.h"
#include "UnitFactory.h"
#include <string>
#include <vector>

namespace Army {

using namespace SquadUtility;
using namespace Economic;
using namespace BasicUnitFactory;

enum class winner_type : bool { first, second };

struct BattleResult {
    winner_type winner;
    std::vector<Squad> losses[2];
    BattleResult(winner_type winner, std::vector<Squad> losses1,
        std::vector<Squad> losses2);
};

class Army {
  private:
    std::vector<Squad*> squads;
    std::vector<SquadDecorator*> modificators;
    ArmyEconomic* economic;
    std::string name;
    UnitFactory* factory;
  public:
    class EconomicProxy {
        friend class Army;
      private:
        Army* army;

        explicit EconomicProxy(Army* p);
      public:
        std::vector<std::string> getDecoratorNames() const;
        std::vector<int> getDecoratorPrices() const;
        int getIncome() const;
        int getmoney() const;
        bool BuyDecorator(int id);
    };

    class HireProxy {
        friend class Army;
      private:
        Army* army;

        explicit HireProxy(Army* p);
      public:
        void hireSaber(int k);
        void hireLancer(int k);
        void hireArcher(int k);
        void hireRider(int k);
    };

    Army(std::string name, UnitFactory* factory, ArmyEconomic* economic);
    ~Army();
    int speed() const;
    std::vector<std::string> getUnitTypes() const;
    std::vector<int> getSquadSizes() const;
    EconomicProxy getEconomicMenu();
    HireProxy getHireMenu();

    BattleResult Attack(Army* other);
};

}

#endif //TASK2_ARMY_H
