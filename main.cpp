#include <iostream>
#include <string>

//TOUJOURS inclure les headers !!
#include "hero.h"
#include "sword.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Necromancer.h"
using namespace std;
using namespace HE_ARC::RPG;


int main()
{
    Sword Sword1(2);
    Sword Sword2(3);
    Sword Sword3(24);
    Warrior hero1(5,5,5,50.0,"Chandra", Sword1);
    Wizard hero2(2,4,10,70.5, "Jace", Sword2, 15);
    Necromancer hero3(10,10,10,15.5,"Liliana", Sword3, 15);
    /*Necromancer hero4;
    Wizard hero5;
    Warrior hero6;*/
    hero3.show();
    hero1.interact(hero2);
    hero2.castSpell();
    hero3.interact(hero1);
    hero1.show();
    hero2.show();
    hero3.riseUndeads();

    cout << "Agility: " << hero1.getAgility() << endl;

    
    cout << "Damage : " << Sword1.getDamage() << endl;

    return 0;
}