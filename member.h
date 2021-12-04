#ifndef MEMBER_H
#define MEMBER_H

#include <type_traits>
#include <cstdint>
#include "treasure.h"

static const int reduce_strength_constant = 2;

template<TreasureValid ValueType, bool IsArmed>
class Adventurer {
public:
    using strength_t = uint32_t;

private:
    ValueType collectedTreasure = 0;

    strength_t strength = 0;

public:
    constexpr Adventurer() requires (!IsArmed) = default;

    constexpr Adventurer(std::size_t strength) requires IsArmed: strength(strength) {}

    constexpr strength_t getStrength() const requires IsArmed {
        return strength;
    }

    static constexpr bool isArmed = IsArmed;

    constexpr void loot(Treasure<ValueType, false> &&treasure) {
        if (!treasure.isTrapped)
            collectedTreasure += treasure.getLoot();
    }

    constexpr void loot(Treasure<ValueType, true> &&treasure) {
        if (isArmed && strength > 0) {
            strength /= reduce_strength_constant;
            collectedTreasure += treasure.getLoot();
        }
    }

    constexpr ValueType pay() {
        ValueType treasureFound = collectedTreasure;
        collectedTreasure = 0;
        return treasureFound;
    }
};

template<typename ValueType>
using Explorer = Adventurer<ValueType, false>;

template<TreasureValid ValueType, std::size_t completedExpeditions> requires (completedExpeditions < 25)
class Veteran {
public:
    using strength_t = uint32_t;

private:
    ValueType collectedTreasure = 0;

    static constexpr strength_t nthFib(std::size_t n) {
        strength_t fib1 = 0;
        strength_t fib2 = 1;
        strength_t sum;

        for (std::size_t i = 1; i <= n; i++) {
            sum = fib1 + fib2;
            fib1 = fib2;
            fib2 = sum;
        }

        return fib1;
    }

    strength_t strength = nthFib(completedExpeditions);
public:

    constexpr Veteran() = default;

    static constexpr bool isArmed = true;

    constexpr void loot(Treasure<ValueType, false> &&treasure) {
        collectedTreasure += treasure.getLoot();
    }

    constexpr void loot(Treasure<ValueType, true> &&treasure) {
        if (strength > 0)
            collectedTreasure += treasure.getLoot();
    }

    constexpr ValueType pay() {
        ValueType treasureFound = collectedTreasure;
        collectedTreasure = 0;
        return treasureFound;
    }

    constexpr strength_t getStrength() const {
        return strength;
    }
};

#endif //MEMBER_H
