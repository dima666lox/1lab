#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include <string>
class Hero: public Character
{
private:
    string weapon;
    string skill1;
    string skill2;
protected:
    string fullWeapon;
    string fullSkill1;
    string fullSkill2;
public:
    Hero() : weapon(""), skill1(""), skill2("") {}
    Hero(const string& name, const string& w, const string& s1, const string& s2)
        : Character(name), fullSkill1(s1), fullSkill2(s2) {}

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

    void setSkill1(const string& skill1) {
        fullSkill1 = skill1;
    }
    string getSkill1() const {
        return fullSkill1;
    }

    void setSkill2(const string& skill2) {
        fullSkill2 = skill2;
    }
    string getSkill2() const {
        return fullSkill2;
    }
};
#endif
