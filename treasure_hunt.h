#ifndef TREASURE_HUNT_H
#define TREASURE_HUNT_H

#include "treasure.h"

// poprawna reprezentacja szablonu treasure
template<typename T>
struct isTreasureStruct : std::false_type{};

template<typename T, bool val>
struct isTreasureStruct<Treasure<T, val>> : std::true_type{};

template<typename T>
concept isTreasure = isTreasureStruct<T>().operator bool();

// poprawna reprezentacja szablonu uczestnika
template<typename T>
concept isAdventurer = requires (T v){
    {v.strength_t};
    {v.isArmed} -> std::convertible_to<bool>;
    {v.pay()} -> TreasureValid;
    // zostało jeszcze v.loot(treasure)
};

template<typename T>
concept EncounterSide = isTreasure<T> || isAdventurer<T>;

/* template<EncounterSide sideA, EncounterSide sideB>
class Encounter{
    run(encounter);
} */

#endif //TREASURE_HUNT_H
