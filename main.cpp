#include <iostream>
#include "Hero.cpp"
#include "Sword.cpp"
#include <string>
using namespace std;
using namespace HE_ARC::RPG;

int main()
{
    Hero Hero1(5,5,5,50.0,"Guillaume");
    Hero Hero2(12,4,6,70.5,"Benjamin");
    Hero Hero3;
    Hero3.show();
    Hero1.interact(Hero2);
    cout << "Agility: " << Hero1.getAgility() << endl;  
    Sword Sword1(24);
    cout << "Damage : " << Sword1.getDamage() << endl;
    Hero2.interact(Hero1);
    Hero1.show();
    Hero2.show();

    return 0;
}