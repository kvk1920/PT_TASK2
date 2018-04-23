//
// Created by kvk1920 on 17.04.18.
//

#ifndef TASK2_BASICUNITTYPES_H
#define TASK2_BASICUNITTYPES_H

#include "Unit.h"

namespace BasicUnitTypes {

using UnitUtility::Unit;
using UnitUtility::UnitData;

#define __UnitClassDefinition(Name, BaseClass) \
class Name : public BaseClass { \
  protected: \
    explicit Name(const UnitData* p); \
  public: \
    Name(); \
};

#define __UnitClassDeclaration(Name, BaseClass) \
Name::Name() : BaseClass(&Name##Data) {} \
Name::Name(const UnitData* p) : BaseClass(p) {}

#define __UnitDataDeclaration(Name, Attack, Defence, MaxHealth, Speed) \
static const UnitData Name##Data(#Name, Attack, Defence, MaxHealth, Speed);

__UnitClassDefinition(Saber, Unit)
__UnitClassDefinition(Archer, Unit)
__UnitClassDefinition(Lancer, Unit)
__UnitClassDefinition(Rider, Unit)

}


#endif //TASK2_BASICUNITTYPES_H
