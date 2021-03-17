#ifndef Sword_h
#define Sword_h
using namespace std;

namespace HE_ARC::RPG
{
    class Sword
    {   
        public:
            Sword(int damage);
            int getDamage() const;
        private:
            friend class Hero;
            int damage;
    };
}
#endif //Sword_h