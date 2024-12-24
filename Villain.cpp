#include "Villain.h"
using namespace std;
void Villain::save(ofstream& file) {
    file << getName() << "\n";
    file << getWeapon() << "\n";
    file << getCrime() << "\n";
    file << getSkill() << "\n";
}

void Villain::load(ifstream& file) {
    getline(file, fullName);
    getline(file, weapon);
    setWeapon(weapon);
    getline(file, crime);
    setCrime(crime);
    getline(file, skill);
    setSkill(skill);
}

void Villain::menu() {
    int choice;
    do {
        cout << "1. Show\n";
        cout << "2. Change name\n";
        cout << "3. Change weapon\n";
        cout << "4. Change crime\n";
        cout << "5. Change skill\n";
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
            cout << "Enter crime: ";
            cin.ignore();
            getline(cin, crime);
            setCrime(crime);
            break;
        }
        case 5: {
            cout << "Enter skill: ";
            cin.ignore();
            getline(cin, skill);
            setSkill(skill);
            break;
        }
        }
    } while (choice != 0);
}

void Villain::show() const {
    cout << "Villain\n";
    cout << "Name: " << getName() << "\n";
    cout << "Weapon: " << getWeapon() << "\n";
    cout << "Crime: " << getCrime() << "\n";
    cout << "Skill: " << getSkill() << "\n";
}