#include "Closet_Monster.h"
#include "Under_Bed_Monster.h"
#include <ctime>
#include <iostream>
using namespace std;

bool test_Darkness_Monster();
bool test_Closet_Monster();
bool test_Under_Bed_Monster();

int main() {
    srand(time(NULL));
    if (test_Darkness_Monster()) {
        cout << "Passed all Darkness Monster test cases" << endl;
    }
    if (test_Closet_Monster()) {
        cout << "Passed all Closet Monster test cases" << endl;
    }
    if (test_Under_Bed_Monster()) {
        cout << "Passed all Under Bed Monster test cases" << endl;
    }
    return 0;
}

bool test_Darkness_Monster() {
    bool passed = true;
    // Darkness Monster is abstract so we can only access it through the child classes
    Closet_Monster cm;
    if (cm.get_number_of_eyes() < 2 || cm.get_number_of_eyes() > Darkness_Monster::MAX_NUMBER_EYES) {
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }
    Closet_Monster cm2(1);
    if (cm2.get_number_of_eyes() != Darkness_Monster::MAX_NUMBER_EYES) {
        passed = false;
        cout << "FAILED 1 test case" << endl;
    }
    cm2.set_number_of_eyes(50);
    if (cm2.get_number_of_eyes() != 50) {
        passed = false;
        cout << "FAILED 50 test case" << endl;
    }
    cm2.set_number_of_eyes(101);
    if (cm2.get_number_of_eyes() != Darkness_Monster::MAX_NUMBER_EYES) {
        passed = false;
        cout << "FAILED 101 test case" << endl;
    }
    cm2.set_number_of_eyes(50);
    cm2.set_number_of_eyes(-7);
    if (cm2.get_number_of_eyes() != Darkness_Monster::MAX_NUMBER_EYES) {
        passed = false;
        cout << "FAILED negative test case" << endl;
    }
    // Test poke_eye method
    Closet_Monster cm3(2);
    cm3.poke_eye();
    cm3.poke_eye();
    cm3.poke_eye();
    if (cm3.get_number_of_eyes() < 5 && cm3.get_number_of_eyes() > Darkness_Monster::MAX_NUMBER_EYES){
        cout << "FAILED 0 eye poke test case" << endl;
        passed = false;
    }
    Closet_Monster cm4(5);
    cm4.poke_eye();
    if (cm4.get_number_of_eyes() != 4){
        cout << "FAILED 5 eye poke test case" << endl;
        passed = false;
    }
    return passed;
}

bool test_Closet_Monster() {
    bool passed = true;
    Closet_Monster cm(4);
    if (cm.is_open()) {
        passed = false;
        cout << "FAILED non-default constructor test case" << endl;
    }
    cm.open_door();
    if (!cm.is_open()) {
        passed = false;
        cout << "FAILED open door test case" << endl;
    }
    Closet_Monster cm2;
    if (cm2.is_open()) {
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }
    // test scare method
    Closet_Monster cm3;
    if (cm3.scare() != "*Knocks on door*") {
        cout << "FAILED closed door scare" << endl;
        passed = false;
    }
    cm3.open_door();
    if (cm3.scare() != "*Slams door*" && cm3.is_open() == false) {
        cout << "FAILED open door scare" << endl;
        passed = false;
    }
    return passed;
}

bool test_Under_Bed_Monster() {
    bool passed = true;
    Under_Bed_Monster ubm(78);
    if (ubm.get_number_of_eyes() != 78) {
        passed = false;
        cout << "FAILED non-default constructor test case" << endl;
    }
    Under_Bed_Monster ubm2;
    if (ubm2.get_number_of_eyes() < 2 || ubm2.get_number_of_eyes() > Darkness_Monster::MAX_NUMBER_EYES) {
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }
    //  test scare method
    Under_Bed_Monster ubm3;
    for (int i = 0; i <= ubm3.MAX_NUMBER_EYES; ++i) {
        string message = ubm3.scare();
        if (message != "*Grabs you*" && message != "*" + to_string(ubm3.get_number_of_eyes()) + " eyes watching you*") {
            cout << "FAILED scare test case" << endl;
            passed = false;
        }
    }

    return passed;
}