#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Character {
public:
    Character() : fullName("-") {}
    Character(const string& name) : fullName(name) {}
    virtual ~Character() {}

    virtual void save(ofstream& file) = 0;
    virtual void load(ifstream& file) = 0;
    virtual void menu() = 0;
    virtual void show() const {
        cout << "Full Name: " << fullName << endl;
    }

    void setName(const string& name) {
        fullName = name;
    }

    string getName() const {
        return fullName;
    }
protected:
    string fullName;
};
#endif

