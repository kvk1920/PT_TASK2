//
// Created by kvk1920 on 19.04.18.
//

#ifndef TASK2_SQUAD_H
#define TASK2_SQUAD_H

#include "Unit.h"
#include "unique_pointer.h"
#include <algorithm>

namespace SquadUtility {

using UnitUtility::Unit;

class AbstractSquad {
  public:
    virtual bool is_not_decorator() const = 0;
  public:
    virtual ~AbstractSquad() = default;
    virtual std::string name() const = 0;
    virtual int attack(float modify = 1) const = 0;
    virtual int speed(float modify = 1) const = 0;
    virtual int defence(float modify = 1) const = 0;
    virtual int size() const = 0;
    virtual bool GetDamage(int damage) = 0;
};

class Squad : public AbstractSquad {
    friend inline bool mergeSquads(Squad*, Squad*);
  public:
    bool is_not_decorator() const { return true; }
  private:
    std::unique_ptr<Unit> unit;
    int cnt;
  public:
    bool GetDamage(int damage) final;
    Squad(std::unique_ptr<Unit>&& unit, int nsize);

    std::string name() const final;
    int attack(float modify = 1) const final;
    int defence(float modify = 1) const final;
    int speed(float modify = 1) const final;

    int size() const final;
};

class SquadDecorator : public AbstractSquad {
    SquadDecorator& operator=(const SquadDecorator&) = delete;
  public:
    bool is_not_decorator() const { return false; }
  private:
    const float attack_buff;
    const float speed_buff;
    const float defence_buff;
    AbstractSquad* object;
    void setObject(AbstractSquad* p);
    explicit SquadDecorator(const SquadDecorator* p);
  public:
    SquadDecorator(float A, float S, float D);
    ~SquadDecorator();

    std::string name() const final;
    int attack(float modify = 1) const final;
    int defence(float modify = 1) const final;
    int speed(float modify = 1) const final;

    int size() const final;

    SquadDecorator* decorate(AbstractSquad* p) const;

    bool GetDamage(int damage) final;
};

inline bool mergeSquads(Squad* first, Squad* second);
}

#endif //TASK2_SQUAD_H
