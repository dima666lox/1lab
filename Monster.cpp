#include "Monster.h"
using namespace std;
void Monster::save(ofstream& file) {
    file << getName() << "\n";
    file << getAppearance() << "\n";

}

void Monster::load(ifstream& file) {
    getline(file, fullName);
    getline(file, appearance);
    setAppearance(appearance);
}

void Monster::menu() {
    int choice;
    do {
        cout << "1. Show\n";
        cout << "2. Change name\n";
        cout << "3. Change appearance\n";
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
            cout << "Enter appearance: ";
            cin.ignore();
            getline(cin, appearance);
            setAppearance(appearance);
            break;
        }
        }
    } while (choice != 0);
}

void Monster::show() const {
    cout << "Monster\n";
    cout << "Name: " << getName() << "\n";
    cout << "Appearance: " << getAppearance() << "\n";
}