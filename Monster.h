#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"
#include <string>
class Monster: public Character
{
private:
    string appearance;
protected:
    string fullAppearance;
public:
    Monster() : appearance(""){}
    Monster(const string& name, const string& a)
        : Character(name), fullAppearance(a) {}

    void save(ofstream& file) override;
    void load(ifstream& file) override;
    void menu() override;
    void show() const override;

    void setAppearance(const string& appearance) {
        fullAppearance = appearance;
    }
    string getAppearance() const {
        return fullAppearance;
    }
};
#endif
