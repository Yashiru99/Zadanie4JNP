#include <iostream>
#include "treasure.h"
#include "member.h"

// testuje sobie tu różne rzeczy
int main() {
    Treasure<int, false> t1(5);
    Treasure<int, false> t2(6);
    SafeTreasure<int> t3(7);
    TrappedTreasure<int> t4(10);
    Explorer<int> a;

}
