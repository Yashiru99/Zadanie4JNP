#ifndef TREASURE_H
#define TREASURE_H

#include <type_traits>
#include <concepts>


template<typename ValueType>
concept TreasureValid = std::integral<ValueType>;

template<TreasureValid ValueType, bool IsTrapped>
class Treasure{
private:
    ValueType value;
public:

    Treasure(ValueType v) : value(v){
    }

    ValueType evaluate(){
        return value;
    }

    ValueType getLoot(){
        ValueType loot = value;
        value = 0;
        return loot;
    }

    bool isTrapped = IsTrapped;

};

template <typename ValueType>
using SafeTreasure = Treasure<ValueType, false>;

template <typename ValueType>
using TrappedTreasure = Treasure<ValueType, true>;


#endif //TREASURE_H
