//
// Created by seans on 2/13/2023.
//

#include "Sky_Monster.h"

Sky_Monster::Sky_Monster() {
    for (int i = 0; i < 1000; i++) {
        number_of_wings = rand() % ((MAX_NUMBER_WINGS / 2)) + 1;
        number_of_wings *= 2;
    }
}

Sky_Monster::Sky_Monster(int now) {
    set_number_of_wings(now);
}

int Sky_Monster::get_number_of_wings() const {
    return number_of_wings;
}

void Sky_Monster::set_number_of_wings(int now) {
    if (now < 2 || now > MAX_NUMBER_WINGS || (now % 2 != 0)) {
        now = MAX_NUMBER_WINGS;
    }
    number_of_wings = now;
}

bool Sky_Monster::growth_spurt() {

    return false;
}