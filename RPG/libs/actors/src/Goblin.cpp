#include "..\include\Goblin.h"
#include "..\include\Monster.h"
#include "..\..\Enum.h"
#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    //CONSTRUCTEUR
    /**
    *@brief Constructeur par paramètre
    *@param _strength la force qui défini les dégats de ses attaques physiques
    *@param _agility l'agilité qui permet d'esquiver les attaques
    *@param _intelligence l'intelligence qui défini les dégats de ses attaques phsychique et magique
    *@param _hp ses points de vie totaux
    */
    Goblin::Goblin(int _strength, int _agility, int _intelligence, double _hp) : Monster(_strength, _agility, _intelligence, _hp)
    {
        this->currentHp = _hp;
    }

    //liste des sorts du monstre

    /**
    *@brief le monstre demande de l'aide des monstres aux alentours pour blesser le joueur, c'est une attaque physique
    *@param _hero le joueur qui combat le monstre
    */
    void Goblin::rallye(Hero *_hero)
    {
 
        cout << "Des Goblins aux alentours sont venus vous faire des dégats" << endl;
        _hero->looseHp(aGoblin::cRallye, this->getStrength());
    }

    /**
    *@brief le monstre essaie de voler le sac du joueur et de le blesser, il a une chance sur 8 de réussir son vol, c'est une attaque physique
    *@param _hero le joueur qui combat le monstre
    */
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
    /**
    *@brief le monstre tire avec une fronde sur le joueur, c'est une attaque magique
    *@param _hero le joueur qui combat le monstre
    */
    void Goblin::slingShot(Hero *_hero)
    {
     

        cout << "Le Gobelin vous tire dessus avec une fronde" << endl;
        _hero->looseHp(aGoblin::cSlingshot, this->getIntelligence());
    }
    /**
    *@brief permet de définir les attaques du monstre, elles marchent sur un pattern défini
    *@param _hero pointeur sur le hero qu'il attaque
    */
    void Goblin::MonsterAttack(Hero *_hero)
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