//
// Created by kvk1920 on 18.04.18.
//

#ifndef TASK2_FRANCE_H
#define TASK2_FRANCE_H

#include "UnitFactory.h"
#include "unique_pointer.h"

namespace France {

using namespace BasicUnitFactory;

__UnitClassDefinition(Pickeman, Lancer)
__UnitClassDefinition(Knight, Rider)

class FrenchUnitFactory : public UnitFactory {
  public:
    std::unique_ptr<Lancer> makeLancer() const;
    std::unique_ptr<Rider> makeRider() const;
};

};


#endif //TASK2_FRANCE_H
