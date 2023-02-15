#include "Closet_Monster.h"
#include "Under_Bed_Monster.h"
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main() {
    /*
     * Create a vector of Darkness Monster unique pointers and push a variety of ten Closet Monsters and Under Bed Monsters to it.
     * Tell the user that there are monster eyes staring at them from the darkness!
     * TODO: Repeatedly give the user the option to poke the eyes or run away.
     *     - If they choose to poke the eyes, loop through the vector and call the poke_eye and scare method on each monster. Output the scare method return values to the console.
     *         - Note: the calls to poke_eye are NOT polymorphism.
     *         - Note: the calls to scare are polymorphism.
     *     - If they choose to run away, the program ends.
     */
    vector<unique_ptr<Darkness_Monster>> monsters = vector<unique_ptr<Darkness_Monster>>();
    const int NUM_MONSTERS = 10;
    srand(time(NULL));

    for (int i = 0; i < NUM_MONSTERS; ++i) {
        if (rand() % 2) {
            monsters.push_back(make_unique<Closet_Monster>());
        } else {
            monsters.push_back(make_unique<Under_Bed_Monster>());
        }
    }

    cout << "There are monster eyes staring at you from the darkness" << endl;
    cout << "You have two options: " << endl;
    cout << "1. Poke the monsters' eyes" << endl;
    cout << "2. Run away" << endl;

    int choice;
    cout << "What will you do: ";
    cin >> choice;
    while (choice != 1 && choice != 2) {
        cout << "Invalid choice, please choose either 1 or 2: ";
        cin >> choice;
    }

    while (choice == 1) {
        for (int i = 0; i < size(monsters); ++i) {
            monsters[i]->poke_eye();
            cout << monsters[i]->scare() << endl;
        }

        cout << endl << "You have two options: " << endl;
        cout << "1. Poke the monsters' eyes" << endl;
        cout << "2. Run away" << endl;

        cout << "What will you do: ";
        cin >> choice;
        while (choice != 1 && choice != 2) {
            cout << "Invalid choice, please choose either 1 or 2: ";
            cin >> choice;
        }
    }
    return 0;
}

