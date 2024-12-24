#include "Keeper.h"
#include "Hero.h"
#include "Villain.h"
#include "Monster.h"
using namespace std;
Keeper::Keeper() : characters(nullptr), counter(0) {}

Keeper::~Keeper() {
    clear();
}

void Keeper::clear() {
    for (int i = 0; i < counter; ++i) {
        delete characters[i];
    }
    delete[] characters;
    counter = 0;
     characters = nullptr;
}

void Keeper::add(Character* character) {
    Character** temp = new Character*[counter + 1];
    for (int i = 0; i < counter; ++i) {
        temp[i] = characters[i];
    }
    temp[counter] = character;
    delete[] characters;
    characters = temp;
    ++counter;
}

void Keeper::remove(int index) {
    if (index < 0 || index >= counter) {
        cerr << "Invalid index.\n";
        return;
    }
    delete characters[index];
    for (int i = index; i < counter - 1; ++i) {
        characters[i] = characters[i + 1];
    }
    --counter;
}

void Keeper::show() const {
    for (int i = 0; i < counter; ++i) {
        characters[i]->show();
        cout << "-----------------------\n";
    }
}

void Keeper::save(const string& filename) {
    ofstream file(filename, ios::trunc);
    if (!file) {
        cerr << "Error opening a file for writing.\n";
        return;
    }

    for (int i = 0; i < counter; ++i) {
        if (dynamic_cast<Hero*>(characters[i])) {
            file << "[hero]\n";
        }else if (dynamic_cast<Villain*>(characters[i])) {
            file << "[villain]\n";
        }else if (dynamic_cast<Monster*>(characters[i])) {
            file << "[monster]\n";
        }
        characters[i]->save(file);
    }
    file.close();
    cout << "Saved.\n";
}

void Keeper::load(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening the file for reading.\n";
        return;
    }

    clear();
    string line;
    while (getline(file, line)) {
        Character* character = nullptr;
        if (line == "[hero]"){
            character = new Hero();
        }else if (line == "[villain]") {
            character = new Villain();
        } else if (line == "[monster]") {
            character = new Monster();
        }
        if (character) {
            character->load(file);
            add(character);
        }
    }
    file.close();
    cout << "The data is downloaded from a file.\n";

}

void Keeper::rename(int index){
    if (index < 0 || index >= counter) {
        cerr << "Invalid index.\n";
        return;
    }
    characters[index]->menu();
    characters[index]->show();
    cout << "-----------------------\n";
}