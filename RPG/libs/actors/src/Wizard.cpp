#include "..\include\Wizard.h"
#include "..\include\Hero.h"
#include "..\include\Monster.h"
#include "..\..\Stuff\include\IObject.h"
#include "..\..\Stuff\include\Potion.h"
#include "..\..\Stuff\include\Shield.h"
#include "..\..\Stuff\include\Sword.h"
#include "..\..\..\libs\Battle.h"
#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    /*constructeur par paramètre*/
    Wizard::Wizard(int _strength, int _agility, int _intelligence, double _hp, string _name,IObject *_pObject, int _mana) : Hero(_strength,_agility, _intelligence, _hp, _name, _pObject)
    {
        mana = _mana;
        cMana = _mana;
        this->currentHp=_hp;
    }
    /*constructeur par défaut*/
    Wizard::Wizard() 
    {
        cout << "CONSTRUCTEUR par defaut" << endl;
        this->strength = 0;
        this->agility = 0;
        this->hp = 0.0;
        this->intelligence = 0;
        this->name = "NoName";
        this->pObject = new Potion();
        this->mana = 0;
    }

    //Fonction
    void Wizard::interact(const Hero & hero)
    {
        cout << this->name << " do a magic trick for " << hero.getName() << endl;
    } 

    void Wizard::show()
    {
        cout << endl << "=========================" << endl
        << "Hero's name : " << this->name <<endl
        << "=========================" << endl
        << "Strength : " << this->strength << endl
        << "Health : " << this->hp << endl
        << "Agility : " << this->agility << endl
        << "Intelligence : " << this->intelligence << endl
        << "Object(" <<this->pObject->getName() <<") : " << this->pObject->getFeature() << endl
        << "Mana : " << this->mana << endl
        << "=========================" << endl << endl;
    }

    //Liste des sorts du Héro

    //Lance une puissante boule de feu sur un unique ennemi
    void Wizard::Fireball(Monster *_monster) 
    {
        //constante de dégat du sort
        int cDamage = 5;
        double damage = 0;
        if (this->cMana >= 5)
        {
            
            cout << this->getName() << " lance une violente boule de feu" << endl;
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

    //Lance un Bizzard qui fait de faible dégats sur tout les ennemis
    void Wizard::Blizzard(Monster *_monster)
    {
        int cDamage = 7;
        double damage = 0;
        if (this->cMana>=7)
        {
        cout << this->getName() << " lance un magnifique Blizzard" << endl;
        damage = (this->getIntelligence()*cDamage)/10;
        _monster->currentHp -=damage;
        this->cMana -=7;
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

    //Vole de la vie au monstre et reconvertis un pourcentage en vie
    void Wizard::Leech(Monster *_monster)
    {
        int cDamage = 8;
        double damage=0;
        if (this->cMana>=10)
        {
        cout << this->getName() << "Inflige des dégats à l'adversaire et se soigne" << endl;
        damage = (this->getIntelligence()*cDamage)/10;
        _monster->currentHp -=damage;
        this->cMana -=10;
        this->currentHp += damage/2;
        cout << "votre adversaire perd "<< damage << "HP"<< endl;
        cout << "vous gagnez "<<damage << "HP "<< endl;
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