//
// Created by kvk1920 on 17.04.18.
//

#include "England.h"

namespace England {

__UnitDataDeclaration(NormanKnight, 21, 7, 140, 4)
__UnitDataDeclaration(LongBowman, 17, 5, 70, 3)

__UnitClassDeclaration(NormanKnight, Rider)
__UnitClassDeclaration(LongBowman, Archer)

__FactoryMethodRealisation(EnglishUnitFactory, Rider, NormanKnight)
__FactoryMethodRealisation(EnglishUnitFactory, Archer, LongBowman)

}