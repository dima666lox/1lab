#include "Hero.h"
using namespace std;
void Hero::save(ofstream& file) {
    file << getName() << "\n";
    file << getWeapon() << "\n";
    file << getSkill1() << "\n";
    file << getSkill2() << "\n";
}

void Hero::load(ifstream& file) {
    getline(file, fullName);
    getline(file, weapon);
    setWeapon(weapon);
    getline(file, skill1);
    setSkill1(skill1);
    getline(file, skill2);
    setSkill2(skill2);
}

void Hero::menu() {
    int choice;
    do {
        cout << "1. Show\n";
        cout << "2. Change name\n";
        cout << "3. Change weapon\n";
        cout << "4. Change skill1\n";
        cout << "5. Change skill2\n";
        cout << "0. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            show();
            break;
        case 2: {
            string newName;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, newName);
            setName(newName);
            break;
        }
        case 3: {
            cout << "Enter weapon: ";
            cin.ignore();
            getline(cin, weapon);
            setWeapon(weapon);
            break;
        }
        case 4: {
            cout << "Enter skill1: ";
            cin.ignore();
            getline(cin, skill1);
            setSkill1(skill1);
            break;
        }
        case 5: {
            cout << "Enter skill2: ";
            cin.ignore();
            getline(cin, skill2);
            setSkill2(skill2);
            break;
        }
        }
    } while (choice != 0);
}

void Hero::show() const {
    cout << "Hero\n";
    cout << "Name: " << getName() << "\n";
    cout << "Weapon: " << getWeapon() << "\n";
    cout << "Skill1: " << getSkill1() << "\n";
    cout << "Skill2: " << getSkill2() << "\n";
}