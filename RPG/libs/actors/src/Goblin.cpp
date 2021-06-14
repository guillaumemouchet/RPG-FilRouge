#include "..\include\Goblin.h"
#include "..\include\Monster.h"
#include "..\..\Enum.h"
#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    //CONSTRUCTEUR
    Goblin::Goblin(int _strength, int _agility, int _intelligence, double _hp) : Monster(_strength, _agility, _intelligence, _hp)
    {
        this->currentHp = _hp;
    }

    //liste des sorts du monstre

    
    void Goblin::rallye(Hero *_hero)
    {
 
        cout << "Des Goblins aux alentours sont venus vous faire des dégats" << endl;
        _hero->looseHp(aGoblin::cRallye, this->getStrength());
    }

    
    void Goblin::steal(Hero *_hero)
    {
        
        if (_hero->backpack.isNotEmpty() == false)
        {
            cout << "Le Gobelin vous donne une giffle" << endl;
            _hero->looseHp(aGoblin::cSteal, this->getStrength());
        }
        else /*|| ou alors que la chance sur 8 ne fonctionne pas*/
        {
            cout << "Le Gobelin vous donne une giffle et essaie de voler votre sac" << endl;
            srand(time(nullptr));
            if ((rand() % 8 + 1) == 8)
            {
                IObject *Item = _hero->backpack.unPack();
                cout << "Il vous a volé "; Item->show();
            }
            else
            {
                cout << "ouf, il a échoué." << endl;
            }

            _hero->looseHp(aGoblin::cSteal, this->getStrength());
        }
    }
    
    void Goblin::slingShot(Hero *_hero)
    {
     

        cout << "Le Gobelin vous tire dessus avec une fronde" << endl;
        _hero->looseHp(aGoblin::cSlingshot, this->getIntelligence());
    }
    
    void Goblin::monsterAttack(Hero *_hero)
    {
        switch (Monster::mCounter)
        {
        case aGoblin::steal:
            this->steal(_hero);
            Monster::mCounter++;
            break;
        case aGoblin::rallye:
            this->rallye(_hero);
            Monster::mCounter++;
            break;
        case aGoblin::slingshot:
            this->slingShot(_hero);
            Monster::mCounter = 0;
        default:
            break;
        }
        cout << "========================================" << endl;
        Sleep(lTime);
    }
}