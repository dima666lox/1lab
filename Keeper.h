#ifndef KEEPER_H
#define KEEPER_H

#include "Character.h"
#include <fstream>

class Keeper {
private:
    Character** characters;
    int counter;

public:
    Keeper();
    ~Keeper();

    void add(Character* character);
    void remove(int index);
    void show() const;
    void save(const string& filename);
    void load(const string& filename);
    void rename(int index);
    void clear();
};


#endif
