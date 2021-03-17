#ifndef Hero_h
#define Hero_h
#include <string>
using namespace std;

namespace HE_ARC::RPG
{
    class Hero
    {   
        public:
            void show();
            void interact(const Hero &);
            int getAgility();
            Hero();
            Hero(int _strength, int _agility, int _intelligence, double _hp, string _name);
            Hero(const Hero& hero);
        private:
            friend class Sword;
            int strength;
            int agility;
            int intelligence;
            double hp;
            string name;
            Sword Sword;
             
    };
}
#endif //Hero_h