//
// Created by kvk1920 on 18.04.18.
//

#include "France.h"

namespace France {

__UnitDataDeclaration(Knight, 21, 12, 160, 3)
__UnitDataDeclaration(Pickeman, 5, 20, 100, 1)

__UnitClassDeclaration(Knight, Rider)
__UnitClassDeclaration(Pickeman, Lancer)

__FactoryMethodRealisation(FrenchUnitFactory, Rider, Knight)
__FactoryMethodRealisation(FrenchUnitFactory, Lancer, Pickeman)

}