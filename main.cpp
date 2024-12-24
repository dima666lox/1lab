#include <iostream>
#include "Keeper.h"
#include "Hero.h"
#include "Villain.h"
#include "Monster.h"
using namespace std;
int main() 
{
    Keeper keeper;
    int choice;
    do {
        cout << "1. Add hero\n";
        cout << "2. Add villain\n";
        cout << "3. Add monster\n";
        cout << "4. Show all characters\n";
        cout << "5. Delete character\n";
        cout << "6. Save to file\n";
        cout << "7. Download from file\n";
        cout << "8. Edit an entry\n";
        cout << "0. Exit\n";
        cin >> choice;

        switch (choice)
        {
                case 1: {
                   string name, weapon, skill1, skill2;
                    cout << "Enter name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter weapon: ";
                    getline(cin, weapon);
                    cout << "Enter skill1: ";
                    getline(cin, skill1);
                    cout << "Enter skill2: ";
                    getline(cin, skill2);
                    keeper.add(new Hero(name, weapon, skill1, skill2));
                    break;  
                }
                case 2: {
                    string name, weapon, crime, skill;
                    cout << "Enter name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter weapon: ";
                    getline(cin, weapon);
                    cout << "Enter crime: ";
                    getline(cin, crime);
                    cout << "Enter skill: ";
                    getline(cin, skill);
                    keeper.add(new Villain(name, weapon, crime, skill));
                    break;
                }
                case 3: {
                    string name, appearance;
                    cout << "Enter name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter appearance: ";
                    getline(cin, appearance);
                    keeper.add(new Monster(name, appearance));
                    break;
                }
                case 4:
                    keeper.show();
                break;
                case 5: {
                    int index;
                    cout << "Enter index of the character to delete: ";
                    cin >> index;
                    keeper.remove(index - 1);
                    break;
                }
                case 6: {
                    string filename;
                    cout << "Enter file's name to save: ";
                    cin >> filename;
                    keeper.save(filename);
                    break;
                }
                case 7: {
                    string filename;
                    cout << "Enter file's name to download: ";
                    cin >> filename;
                    keeper.load(filename);
                    break;
                }
                case 8: {
                    int index;
                    cout << "Enter index of the character to edit: ";
                    cin >> index;
                    keeper.rename(index - 1);
                    break;
                }
            }
        }
    while (choice != 0);

return 0;
}