#ifndef MONSTER_h
#define MONSTER_h

#include <string>
#include "..\..\Logger.h"
//TOUJOURS inclure les headers !!

using namespace std;

namespace HE_ARC::RPG
{
    class Hero;
    class Monster
    {
    public:
        //CONSTUCTEURS

        //par défaut
        Monster() = default;
        //par paramètres
        Monster(int _strength, int _agility, int _intelligence, double _hp);

        //DESTRUCTEUR
        virtual ~Monster();

        //GETTER
        //comme il n'y a qu'un return à faire, on peut se permettre de les laisser dans le .h(pp)
        int getStrength() const { return this->strength; }
        int getAgility() const { return this->agility; }
        int getIntelligence() const { return this->intelligence; }
        double getHp() const { return this->hp; }
        double getcHp() const { return this->currentHp; }
        bool isMAlive() const { return (this->getcHp() > 0); };
        //SETTER
        void resetcHp() { this->currentHp = hp; }
        //FONCTIONS
        void looseHp(int _damage, int _stat);
        bool dodge();
        //les attaques du monstre
        void virtual monsterAttack(Hero *_hero) = 0;

        //Pour le pattern des monstres
        static int mCounter;

    protected:
        //ATTRIBUTS
        int strength = 0;
        int agility = 0;
        int intelligence = 0;
        double hp = 0;
        double currentHp;
    };
}
#endif //Monster_h