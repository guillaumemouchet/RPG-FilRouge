#include "..\include\Necromancer.h"
#include "..\include\Hero.h"
#include "..\include\Monster.h"
#include "..\..\Stuff\include\IObject.h"
#include "..\..\Stuff\include\Potion.h"
#include "..\..\Stuff\include\Shield.h"
#include "..\..\Stuff\include\Sword.h"
#include "..\..\Enum.h"
#include <iostream>
#include <windows.h>
using namespace std;

namespace HE_ARC::RPG
{
    /**
    *@brief Constructeur par paramètre
    *@param _strength la force qui défini les dégats de ses attaques physiques
    *@param _agility l'agilité qui permet d'esquiver les attaques
    *@param _intelligence l'intelligence qui défini les dégats de ses attaques phsychique et magique
    *@param _hp ses points de vie totaux
    *@param _name son nom prédéfini selon la classe
    *@param _PObject un pointeur sur un objet équipé
    *@param _mana le mana qui doit être dépensé pour attaquer
    */
    Necromancer::Necromancer(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject, int _mana) : Wizard(_strength, _agility, _intelligence, _hp, _name, _pObject, _mana)
    {
        this->cMana = _mana;
        this->currentHp = _hp;
    }

    //Liste des sorts du Héro
    /**
    *@brief Le joueur invoque des morts pour blesser son ennemi
    *@param _monster pointeur sur le monstre que le joueur attaque
    */
    void Necromancer::riseUndead(Monster *_monster)
    {

        if (this->cMana >= aUndead::mRiseundead)
        {
            cout << this->getName() << " invoque des morts pour attaquer votre ennemi" << endl;
            this->looseMana(aUndead::mRiseundead);
            _monster->looseHp(aUndead::cRiseundead, this->getStrength());
        }
        else
        {
            attack(_monster);
        }
    }

    /**
    *@brief Le joueur invoque un cataclysme pour blesser l'ennemi, mais se prend des dégats en contre-coup
    *@param _monster pointeur sur le monstre que le joueur attaque
    */
    void Necromancer::cataclysme(Monster *_monster)
    {

        if (this->cMana >= aNecromancer::mCataclysme)
        {
            cout << this->getName() << " lance un cataclyme sur votre ennemi" << endl;
            _monster->looseHp(aNecromancer::cCataclysme, this->getIntelligence());
            this->looseHp(aNecromancer::cCataclysme, this->getIntelligence() / 2.0);
            this->looseMana(aNecromancer::mCataclysme);
        }
        else
        {
            attack(_monster);
        }
    }
    /**
    *@brief Permet au joueur de choisir quelle attaque utiliser en combat, cela dépend de sa classe
    *@param _monster le pointeur sur le monstre qui est combattu
    */
    void Necromancer::heroAttack(Monster *_monster)
    {
        int action = -1;
        int status = 0;
        do
        {

            cout << "[" << aNecromancer::cataclysme << "] Cataclysme (" << aNecromancer::mCataclysme << ")" << endl;
            cout << "[" << aUndead::riseundead << "] RiseUndead (" << aUndead::mRiseundead << ")" << endl;
            cout << "[" << aWizard::leech << "] Leech (" << aWizard::mLeech << ")" << endl;
            fflush(stdin);
            status = scanf("%d", &action);
        } while (not(0 <= action && action <= 4 && status == 1));

        cout << "========================================" << endl;

        switch (action)
        {
        case aWizard::leech:
            this->leech(_monster);
            break;
        case aUndead::riseundead:
            this->riseUndead(_monster);
            break;
        case aNecromancer::cataclysme:
            this->cataclysme(_monster);
            break;
        default:
            this->heroAttack(_monster);
            break;

            cout << "========================================" << endl;
            Sleep(lTime);
        }
    }
}
