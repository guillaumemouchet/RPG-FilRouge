#include "..\include\Azazel.h"
#include "..\include\Monster.h"
#include "..\include\Hero.h"
#include "..\include\Necromancer.h"
#include "..\include\Wizard.h"
#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    /*constructeur par paramètre*/
    Azazel::Azazel(int _strength, int _agility, int _intelligence, double _hp) : Undead(_strength, _agility, _intelligence, _hp)
    {
        this->currentHp = _hp;
    }

    //liste des sorts du monstre

    void Azazel::brimStorm(Hero *_hero)
    {
        int const cDamage = 8;
        cout << "Votre adversaire lance une gigantesque Laser de sa bouche" << endl;
        _hero->looseHp(this->getIntelligence(), cDamage);
    }
    void Azazel::doubleSlash(Hero *_hero)
    {
        int const cDamage = 4;
        cout << "Votre adversaire vous frappe avec un fouet" << endl;
        _hero->looseHp(this->getStrength(), cDamage);
        cout << "Attention! le coup revient" << endl;
        _hero->looseHp(this->getStrength(), cDamage);
    }
    void Azazel::apocalypse(Hero *_hero)
    {
        int const cDamage = 5;
        string furniture[] = {"Une chaise", "Une tuile", "Un parpaing", "Une fenêtre", "Un mur", "Une cheminée", "Un toit"};
        srand(time(nullptr));
        int random = rand() % 6;

        cout << "Votre adversaire crée une apocalypse autour de vous" << endl;
        cout << furniture[random] << " vous tombe violamment dessus pendant ce déluge" << endl;
        _hero->looseHp(this->getStrength() + random, cDamage);
    }
}