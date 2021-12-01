#ifndef TREASURE_H
#define TREASURE_H

#include <type_traits>

template<typename ValueType, bool IsTrapped>
class Treasure{
    static_assert(std::is_integral<ValueType>::value, "ValueType must be an integral type");

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
