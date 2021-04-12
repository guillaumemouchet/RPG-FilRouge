#ifndef hero_h
#define hero_h

#include <string>

//TOUJOURS inclure les headers !!
#include "sword.h"

using namespace std;

namespace HE_ARC::RPG
{
    class Hero
    {
        public:
            //CONSTUCTEURS
            //par défaut
            Hero();
            //par paramètres
            Hero(int _strength, int _agility, int _intelligence, double _hp, string _name, Sword _sword);
            //par recopie
            Hero(const Hero& hero);

            //DESTRUCTEUR
            ~Hero();

            //GETTER
            //comme il n'y a qu'un return à faire, on peut se permettre de les laisser dans le .h(pp)
            int getStrength() const { return this->strength; }
            int getAgility() const { return this->agility; }
            int getIntelligence() const { return this->intelligence; }
            double getHp() const { return this->hp; }
            string getName() const { return this->name; }

            //FONCTIONS
            void virtual show();
            void virtual interact(const Hero &) = 0;

            //SURCHARGE D'OPÉRATEUR =
            Hero& operator=(const Hero &hero);

        protected:
            //ATTRIBUTS
            int strength;
            int agility;
            int intelligence;
            double hp;
            string name;
            Sword *sword;

            //SURCHARGE D'OPÉRATEUR AMIE <<
            friend ostream& operator<<(ostream &s,const Hero &h);
    };
}
#endif //Hero_h