#ifndef TREASURE_HUNT_H
#define TREASURE_HUNT_H

#include <utility>
#include <iostream>
#include "treasure.h"
#include "member.h"

/* Concpet for correct representation of Treasure type */
template<typename T>
concept TreasureType = requires(T a) {
    { Treasure(a) } -> std::same_as<T>;
};

/* Concept for correct represantation of Adventurer type */
template<typename T>
concept MemberType = requires(T a) {
    typename T::strength_t;

    std::convertible_to<decltype(T::isArmed), bool>;
    { []() constexpr { return T::isArmed; }() };

    { a.pay() } -> TreasureValid;

    a.loot(std::declval<Treasure<decltype(a.pay()), true || false>>());
};

template<typename T>
concept EncounterSide = TreasureType<T> || MemberType<T>;

template<EncounterSide sideA, EncounterSide sideB>
using Encounter = std::pair<sideA &, sideB &>;

/* Looting treasurer by adventurer */
template<TreasureType T, MemberType M>
inline constexpr void run(Encounter<T, M> encounter) {
    auto[TreasureA, MemberB] = encounter;

    MemberB.loot(std::move(TreasureA));
}

template<MemberType M, TreasureType T>
inline constexpr void run(Encounter<M, T> encounter) {
    auto[MemberA, TreasureB] = encounter;

    MemberA.loot(std::move(TreasureB));
}

/* Encounter of two armed adventurers */
template<MemberType MA, MemberType MB>
inline constexpr void run(Encounter<MA, MB> encounter) requires (MA::isArmed) && (MB::isArmed) {
    auto [MemberA, MemberB] = encounter;

    if (MemberA.getStrength() > MemberB.getStrength()) {
        MemberA.loot(SafeTreasure(MemberB.pay()));
    } else if (MemberA.getStrength() < MemberB.getStrength()) {
        MemberB.loot(SafeTreasure(MemberA.pay()));
    }
}

/* Encounter of two adventurers from which only one is armed */
template<MemberType MA, MemberType MB>
inline constexpr void run(Encounter<MA, MB> encounter) requires (MA::isArmed) && (!MB::isArmed) {
    auto [MemberA, MemberB] = encounter;

    MemberA.loot(SafeTreasure(MemberB.pay()));
}

template<MemberType MA, MemberType MB>
inline constexpr void run(Encounter<MA, MB> encounter) requires (!MA::isArmed) && (MB::isArmed) {
    auto [MemberA, MemberB] = encounter;

    MemberB.loot(SafeTreasure(MemberA.pay()));
}

/* Encounter of two unarmed adventurers */
template<MemberType MA, MemberType MB>
inline constexpr void run(Encounter<MA, MB> encounter) requires (!MA::isArmed) && (!MB::isArmed) {}

/* Running a sequence of encounters */
template<typename... Args>
constexpr void expedition(Args... args) {
    (run(args), ...);
}


#endif //TREASURE_HUNT_H
