//
// Created by l30014168 on 2021/9/22.
//

#include <stdbool.h>
#include "util.h"

bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    if (jug1Capacity < targetCapacity - jug2Capacity) {
        return false;
    }
    return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
}