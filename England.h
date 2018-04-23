//
// Created by kvk1920 on 17.04.18.
//

#ifndef TASK2_ENGLAND_H
#define TASK2_ENGLAND_H

#include "UnitFactory.h"
#include "unique_pointer.h"

namespace England {

using namespace BasicUnitFactory;

__UnitClassDefinition(LongBowman, Archer)
__UnitClassDefinition(NormanKnight, Rider)

class EnglishUnitFactory : public UnitFactory {
  public:
    std::unique_ptr<Rider> makeRider() const;
    std::unique_ptr<Archer> makeArcher() const;
};

}

#endif //TASK2_ENGLAND_H
