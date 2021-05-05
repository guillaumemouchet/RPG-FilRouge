#ifndef MONSTER_h
#define MONSTER_h

#include <string>

//TOUJOURS inclure les headers !!

using namespace std;

namespace HE_ARC::RPG
{
    class Monster
    {
        public:
            //CONSTUCTEURS
            double currentHp;
            //par défaut
            Monster()=default;
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

            //FONCTIONS
            void virtual show();
            void looseHp(int _damage, int _stat);
            
        protected:
            //ATTRIBUTS
            int strength=0;
            int agility=0;
            int intelligence=0;
            double hp=0;
            
            //SURCHARGE D'OPÉRATEUR AMIE <<
            friend ostream& operator<<(ostream &s,const Monster &h);
    };
}
#endif //Monster_h