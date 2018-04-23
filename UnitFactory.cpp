//
// Created by kvk1920 on 17.04.18.
//

#include "UnitFactory.h"

namespace BasicUnitFactory {

UnitFactory::~UnitFactory() {}

__FactoryMethodRealisation(UnitFactory, Archer, Archer)
__FactoryMethodRealisation(UnitFactory, Lancer, Lancer)
__FactoryMethodRealisation(UnitFactory, Saber, Saber)
__FactoryMethodRealisation(UnitFactory, Rider, Rider)

}