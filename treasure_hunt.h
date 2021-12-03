#ifndef TREASURE_HUNT_H
#define TREASURE_HUNT_H

#include "treasure.h"

// poprawna reprezentacja szablonu treasure
template<typename T>
concept TresureType = requires (T a) {
    {Treasure(a)} -> std::same_as<T>;
};

// poprawna reprezentacja szablonu uczestnika
template<typename T>
concept isAdventurer = requires (T a) {
    typename T::strength_t
    {a.isArmed} -> std::same_as<bool>;
    {a.pay()} -> TreasureValid;
    a.loot(std::declval<Treasure<decltype(a.pay()), true || false>>());
};

template<typename T>
concept EncounterSide = isTreasure<T> || isAdventurer<T>;

/* template<EncounterSide sideA, EncounterSide sideB>
class Encounter{
    run(encounter);
} */

#endif //TREASURE_HUNT_H
