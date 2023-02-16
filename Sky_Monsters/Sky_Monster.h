//
// Created by seans on 2/13/2023.
//

#ifndef MONSTERS_SKY_MONSTER_H
#define MONSTERS_SKY_MONSTER_H

#include <string>

class Sky_Monster {
public:
    /**
     * Requires: nothing
     * Modifies: number_of_wings
     * Effects: sets number_of_wings to random even int in range 2-100
     */
    Sky_Monster();

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: does nothing
     */
    virtual ~Sky_Monster() = default;

    /**
     * Requires: nothing
     * Modifies: number_of_wings
     * Effects: calls set_number_of_wings with now
     */
    explicit Sky_Monster(int now);

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns number_of_wings
     */
    virtual int get_number_of_wings() const;

    /**
     * Requires: new number of wings
     * Modifies: number_of_wings
     * Effects: sets number_of_wings to now if now is an even number in range 2-100.
     *          Otherwise sets number_of_wings to 100.
     */
    void set_number_of_wings(int now);

    /*
    * Requires: nothing
    * Modifies: number_of_wings
    * Effects: increases number_of_wings by 2, limiting number_of_wings by MAX_NUMBER_WINGS
    */
    virtual bool growth_spurt();

    // pure virtual method to return a scary string
    virtual std::string scare() = 0;

    static const int MAX_NUMBER_WINGS = 100;
protected:
    int number_of_wings;
};

#endif //MONSTERS_SKY_MONSTER_H
