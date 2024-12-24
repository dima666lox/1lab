#ifndef VILLAIN_H
#define VILLAIN_H

#include "Character.h"
#include <string>
class Villain: public Character
{
private:
    string weapon;
    string crime;
    string skill;
protected:
    string fullWeapon;
    string fullCrime;
    string fullSkill;
public:
    Villain() : weapon(""), crime(""), skill("") {}
    Villain(const string& name, const string& w, const string& c, const string& s)
        : Character(name), fullWeapon(w), fullCrime(c), fullSkill(s){}

    void save(ofstream& file) override;
    void load(ifstream& file) override;
    void menu() override;
    void show() const override;

    void setWeapon(const string& weapon) {
        fullWeapon = weapon;
    }
    string getWeapon() const {
        return fullWeapon;
    }

    void setCrime(const string& crime) {
        fullCrime = crime;
    }
    string getCrime() const {
        return fullCrime;
    }
    void setSkill(const string& skill) {
        fullSkill = skill;
    }
    string getSkill() const {
        return fullSkill;
    }
};
#endif
