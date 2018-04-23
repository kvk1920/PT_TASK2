//
// Created by kvk1920 on 17.04.18.
//

#include "BasicUnitTypes.h"

namespace BasicUnitTypes {

__UnitDataDeclaration(Saber, 10, 10, 100, 2)
__UnitDataDeclaration(Archer, 15, 5, 70, 3)
__UnitDataDeclaration(Lancer, 7, 15, 90, 1)
__UnitDataDeclaration(Rider, 20, 10, 150, 4)

__UnitClassDeclaration(Saber, Unit)
__UnitClassDeclaration(Archer, Unit)
__UnitClassDeclaration(Lancer, Unit)
__UnitClassDeclaration(Rider, Unit)

}
