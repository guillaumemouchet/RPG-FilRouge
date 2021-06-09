#include "..\include\Azazel.h"
#include "..\include\Monster.h"
#include "..\include\Hero.h"
#include "..\include\Necromancer.h"
#include "..\include\Wizard.h"
#include "..\..\Enum.h"
#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    
    Azazel::Azazel(int _strength, int _agility, int _intelligence, double _hp) : Undead(_strength, _agility, _intelligence, _hp)
    {
        this->currentHp = _hp;
    }

    
    void Azazel::brimStorm(Hero *_hero)
    {
        cout << "Votre adversaire lance une gigantesque Laser" << endl;
        _hero->looseHp(this->getIntelligence(), aAzazel::cBrimstorm);
    }
    
    void Azazel::doubleSlash(Hero *_hero)
    {
        cout << "Votre adversaire vous frappe avec un fouet" << endl;
        _hero->looseHp(this->getStrength(), aAzazel::cDoubleslash);
        cout << "Attention! le coup revient" << endl;
        _hero->looseHp(this->getStrength(), aAzazel::cDoubleslash);
    }
    
    void Azazel::apocalypse(Hero *_hero)
    {
        string furniture[] = {"Une chaise", "Une tuile", "Un parpaing", "Une fenêtre", "Un mur", "Une cheminée", "Un toit"};
        srand(time(nullptr));
        int random = rand() % 7;

        cout << "Votre adversaire crée une apocalypse autour de vous" << endl;
        cout << furniture[random] << " vous tombe violamment dessus pendant ce déluge" << endl;
        _hero->looseHp(this->getStrength() + random, aAzazel::cApocalypse);
    }
    
    void Azazel::monsterAttack(Hero *_hero)
    {

        srand(time(nullptr));
        int random = rand() % 3;
        switch (random)
        {
        case aUndead::manadrain:
            this->manaDrain(_hero);

            break;
        case aAzazel::brimstorm:
            this->brimStorm(_hero);

            break;
        case aAzazel::doubleslash:
            this->doubleSlash(_hero);
            break;
        case aAzazel::apocalypse:
            this->apocalypse(_hero);
        default:
            //si jamais le random fait une mauvaise valeur (ce qui ne devrait pas mais double protection)
            cout << "Mauvaise Valeur, reessai" << endl;
            this->monsterAttack(_hero);
            break;
        }
        cout << "========================================" << endl;
        Sleep(lTime);
    }
}