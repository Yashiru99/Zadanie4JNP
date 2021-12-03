#ifndef TREASURE_HUNT_H
#define TREASURE_HUNT_H

#include <utility>
#include "treasure.h"
#include "member.h"

// poprawna reprezentacja szablonu treasure
template<typename T>
concept TreasureType = requires (T a) {
    {Treasure(a)} -> std::same_as<T>;
};

// poprawna reprezentacja szablonu uczestnika
template<typename T>
concept AdventurerType = requires (T a) {
    typename T::strength_t;

    std::convertible_to<decltype(T::isArmed), bool>;
    {[] () constexpr { return T::isArmed; }()};

    {a.pay()} -> TreasureValid;

    a.loot(std::declval<Treasure<decltype(a.pay()), true || false>>());
};

template<typename T>
concept EncounterSide = TreasureType<T> || AdventurerType<T>;

template<EncounterSide sideA, EncounterSide sideB>
using Encounter = std::pair<sideA&, sideB&>;

template<TreasureType T, AdventurerType A>
inline constexpr void run(Encounter<T, A> encounter) {
    auto [sideA, sideB] = encounter;

    sideB.loot(std::move(sideA));
}

#endif //TREASURE_HUNT_H
