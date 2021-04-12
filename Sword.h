#ifndef sword_h
#define sword_h

using namespace std;

namespace HE_ARC::RPG
{
    class Sword
    {
        public:
            //CONSTRUCTEURS
            //par défaut
            Sword() : damage(0) { }
            //par paramètres
            Sword(int _damage) : damage(_damage) { }
            //par recopie
            Sword(Sword &s): damage(s.damage) { }

            //GETTER
            int getDamage() const { return this->damage; };
        private:
            //ATTRIBUTS
            int damage;
            //CLASSE AMIE
            friend class Hero;
    };
}
#endif //Sword_h