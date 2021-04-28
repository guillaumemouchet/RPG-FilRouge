#include "..\include\Necromancer.h"
#include "..\include\Hero.h"
#include "..\include\Monster.h"
#include "..\..\Stuff\include\IObject.h"
#include "..\..\Stuff\include\Potion.h"
#include "..\..\Stuff\include\Shield.h"
#include "..\..\Stuff\include\Sword.h"
#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    /*constructeur par paramètre*/
    Necromancer::Necromancer(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject, int _mana) : Wizard(_strength,_agility, _intelligence, _hp, _name, _pObject, _mana)
    {
        this->cMana = _mana;
        this->currentHp=_hp;
    }
    /*constructeur par défaut*/
    Necromancer::Necromancer() : Wizard(0,0,0,0,"NoName", new Potion(), 0)
    {
        cout << "CONSTRUCTEUR par defaut" << endl;
    }
    //Liste des sorts du Héro

    //Réveille des monstres pour l'aider dans le combat
    void Necromancer::RiseUndead(Monster *_monster)
    {
        int cDamage = 4;
        double damage=0;
        if (this->cMana >= 5)
        {
            cout << this->getName() << " invoque des morts pour attaquer votre ennemi" << endl;
            damage = (this->getIntelligence()*cDamage)/10; 
            _monster->currentHp -=damage;
            this->cMana -=5;
            cout << "votre adversaire perd "<< damage << "HP"<< endl;
        }else
        {
            cout << "Tu n'as pas assez de mana" << endl;
            cout << "Tu frappe l'adversaire avec ton arme" << endl;
            damage = (this->getStrength())/3;
            _monster->currentHp -=damage;
            cout << "votre adversaire perd "<< damage << "HP"<< endl;
        }
    }

    //Invoque une cataclysme qui blesse tout les ennemis, mais lui fait perdre un quart de sa vie
    void Necromancer::Cataclysme(Monster *_monster)
    { 
        int cDamage = 4;
        double damage=0;
        if (this->cMana >= 8)
        {
            cout << this->getName() << " un cataclyme sur votre ennemi" << endl;
            damage = (this->getIntelligence()*cDamage)/10; 
            _monster->currentHp -=damage;
            this->currentHp -=damage/2;
            this->cMana -=8;
            cout << "votre adversaire perd "<< damage << "HP"<< endl;
            cout << "vous perdez "<< damage/2 << "HP"<< endl;
        }else
        {
            cout << "Tu n'as pas assez de mana" << endl;
            cout << "Tu frappe l'adversaire avec ton arme" << endl;
            damage = (this->getStrength())/3;
            _monster->currentHp -=damage;
            cout << "votre adversaire perd "<< damage << "HP"<< endl;

        }
    
    }
}