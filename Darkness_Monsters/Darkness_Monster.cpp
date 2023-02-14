#include "Darkness_Monster.h"


Darkness_Monster::Darkness_Monster() {
    number_of_eyes = rand() % (MAX_NUMBER_EYES - 1) + 2;
}

Darkness_Monster::Darkness_Monster(int noe) {
    set_number_of_eyes(noe);
}

int Darkness_Monster::get_number_of_eyes() const {
    return number_of_eyes;
}

void Darkness_Monster::set_number_of_eyes(int noe) {
    if (noe < 2 || noe > MAX_NUMBER_EYES) {
        noe = MAX_NUMBER_EYES;
    }
    number_of_eyes = noe;
}

// Implement poke_eye method here
bool Darkness_Monster::poke_eye() {
    if (number_of_eyes >= 1) {
        --number_of_eyes;
        return true;
    }
    else {
        int min = 5;
        int range = (MAX_NUMBER_EYES - min) + 1;
        number_of_eyes = (rand() % range) + min;
        return false;
    }
}
