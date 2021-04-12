#include <iostream>
#include <string>

//TOUJOURS inclure les headers !!
#include "hero.h"
#include "sword.h"

using namespace std;
using namespace HE_ARC::RPG;


int main()
{
    Sword Sword1(2);
    Sword Sword2(3);
    Hero hero1(5,5,5,50.0,"Guillaume", Sword1);
    Hero hero2(12,4,6,70.5,"Benjamin", Sword2);
    Hero hero3;
    
    hero3.show();
    hero1.interact(hero2);

    hero3.interact(hero1);
    hero1.show();
    hero2.show();

    cout << "Agility: " << hero1.getAgility() << endl;

    Sword Sword3(24);
    cout << "Damage : " << Sword1.getDamage() << endl;

    return 0;
}