#ifndef MEMBER_H
#define MEMBER_H

#define reduce_strength_constant 2
#include <type_traits>
#include "treasure.h"

template <typename ValueType, bool IsArmed>
class Adventurer{
    static_assert(std::is_integral<ValueType>::value, "ValueType must be an integral type");
private:
    ValueType collectedTreasure = 0;
public:
    bool isArmed = IsArmed;

    ValueType pay(){
        ValueType treasureFound = collectedTreasure;
        collectedTreasure = 0;
        return treasureFound;
    }
};

template <typename ValueType>
class Adventurer<ValueType, false>{
private:
    ValueType collectedTreasure = 0;
public:
    Adventurer()= default;

    void loot(auto &&treasure){
        if(!treasure.isTrapped)
         collectedTreasure = treasure.getLoot();
    }
};

template <typename ValueType>
class Adventurer<ValueType, true>{
private:
    ValueType collectedTreasure = 0;
public:
    size_t strength_t;

    Adventurer(size_t strength): strength_t(strength){
    }

    void loot(auto &&treasure){
        if(treasure.isTrapped && getStrength() > 0){
            strength_t /= reduce_strength_constant;
            collectedTreasure += treasure.getLoot();
        }
        else
            collectedTreasure += treasure.getLoot();
    }

    ValueType getStrength(){
        return strength_t;
    }
};

template <typename ValueType>
using Explorer = Adventurer<ValueType, false>;

template <typename ValueType, size_t completedExpeditions>
class Veteran{
    static_assert(completedExpeditions < 25, "Too many expeditions done");
private:
    ValueType collectedTreasure;

public:

    Veteran()= default;

    bool isArmed = true;

    size_t strength;

    void loot(auto &&treasure){
        collectedTreasure += treasure.getLoot();
    }

    ValueType pay(){
        ValueType treasureFound = collectedTreasure;
        collectedTreasure = 0;
        return treasureFound;
    }

    size_t getStrength(){
        // n-ta liczba fibonacciego
    }

};
#endif //MEMBER_H
