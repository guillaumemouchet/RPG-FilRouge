#include <iostream>
#include <string>
#include <list>
#include <algorithm>

//TOUJOURS inclure les headers !!
#include "hero.h"
#include "sword.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Necromancer.h"
using namespace std;
using namespace HE_ARC::RPG;

/*
les ptrW avec un W majuscule sont pour les Warriors
les ptrw avec un w miniscule sont pour les wizards
les ptrN avec un N majuscule sont pour les Necromancer
*/

int main()
{
    
    list<Hero*> myParty;
    Sword Sword1(2);
    Sword Sword2(3);
    Sword Sword3(24);
    //Warrior hero1(5,5,5,50.0,"Chandra", Sword1);
    Warrior *ptrW1 = new Warrior(5,5,5,50.0,"Chandra", Sword1);

    //Wizard hero2(2,4,10,70.5, "Jace", Sword2, 25);
    Wizard *ptrw1 = new Wizard(2,4,10,70.5, "Jace", Sword2, 25);

    //Necromancer hero3(10,10,10,15.5,"Liliana", Sword3, 15);
    Necromancer *ptrN1 = new Necromancer(10,10,10,15.5,"Liliana", Sword3, 15);

    myParty.push_back(ptrW1);
    myParty.push_back(ptrw1);
    myParty.push_back(ptrN1);
    for_each(myParty.begin(), myParty.end(),[](Hero *n)
    {
        n->show();
    });
   
    
    ptrW1->show();
    ptrW1->interact(*ptrw1);
    ptrw1->castSpell();
    ptrN1->interact(*ptrw1);
    ptrW1->show();
    ptrw1->show();
    ptrN1->riseUndeads();

    cout << "Agility: " << ptrW1->getAgility() << endl;

    
    cout << "Damage : " << Sword1.getDamage() << endl;

    while(!myParty.empty())
    {
        delete myParty.front();
        myParty.pop_front();

    }
    return 0;
}