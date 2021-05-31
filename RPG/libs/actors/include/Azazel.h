
#ifndef AZAZEL_H
#define AZAZEL_H

#include "Hero.h"
#include "Monster.h"
#include "Undead.h"
#include <iostream>

using namespace std;

namespace HE_ARC::RPG
{
    class Azazel : public Undead
    {
    protected:
    public:
        // constructeurs
        //par défaut
        Azazel() = default;
        //par paramètre
        Azazel(int _strength, int _agility, int _intelligence, double _hp);
        ~Azazel() = default;
        //liste des sorts du monstre
        void brimStorm(Hero *_hero);
        void doubleSlash(Hero *_hero);
        void apocalypse(Hero *_hero);
    };

}
#endif