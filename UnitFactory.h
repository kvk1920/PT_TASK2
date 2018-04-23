//
// Created by kvk1920 on 17.04.18.
//

#ifndef TASK2_UNITFACTORY_H
#define TASK2_UNITFACTORY_H

#include "BasicUnitTypes.h"
#include "unique_pointer.h"

namespace BasicUnitFactory {

//using std::unique_ptr;
using namespace BasicUnitTypes;

class UnitFactory {
  public:
    virtual ~UnitFactory();
    virtual std::unique_ptr<Saber> makeSaber() const;
    virtual std::unique_ptr<Archer> makeArcher() const;
    virtual std::unique_ptr<Rider> makeRider() const;
    virtual std::unique_ptr<Lancer> makeLancer() const;
};

#define __FactoryMethodRealisation(Factory, UnitClass, ConcreteUnit) \
std::unique_ptr<UnitClass> Factory::make##UnitClass() const { \
    return std::move_cast<UnitClass>(std::make_unique<ConcreteUnit>()); \
}

}

#endif //TASK2_UNITFACTORY_H
