#include "..\include\Azazel.h"
#include "..\include\Monster.h"
#include "..\include\Hero.h"
#include "..\include\Necromancer.h"
#include "..\include\Wizard.h"
#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    /**
    *@brief Constructeur par paramètre
    *@param _strength la force qui défini les dégats de ses attaques physiques
    *@param _agility l'agilité qui permet d'esquiver les attaques
    *@param _intelligence l'intelligence qui défini les dégats de ses attaques phsychique et magique
    *@param _hp ses points de vie totaux
    */
    Azazel::Azazel(int _strength, int _agility, int _intelligence, double _hp) : Undead(_strength, _agility, _intelligence, _hp)
    {
        this->currentHp = _hp;
    }

    /**
    *@brief Le monstre lance un gigantesque laser sur le joueur, c'est une attaque magique
    *@param _hero le joueur qui combat le monstre
    */
    void Azazel::brimStorm(Hero *_hero)
    {
        int const cDamage = 8;
        cout << "Votre adversaire lance une gigantesque Laser de sa bouche" << endl;
        _hero->looseHp(this->getIntelligence(), cDamage);
    }
    /**
    *@brief Le monstre frappe 2 fois avec un fouet le joueur, c'est une attaque physique
    *@param _hero le joueur qui combat le monstre
    */
    void Azazel::doubleSlash(Hero *_hero)
    {
        int const cDamage = 4;
        cout << "Votre adversaire vous frappe avec un fouet" << endl;
        _hero->looseHp(this->getStrength(), cDamage);
        cout << "Attention! le coup revient" << endl;
        _hero->looseHp(this->getStrength(), cDamage);
    }
    /**
    *@brief Le monstre invoque un cataclysme sur le joueur, c'est une attaque physique
    il y a des dégats aléatoire en rapport à l'objet qu'il se prend
    *@param _hero le joueur qui combat le monstre
    */
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
    /**
    *@brief permet de définir les attaques du monstre, elles marchent sur un pattern défini, sauf pour Azazel ou c'est aléatoire
    *@param _hero pointeur sur le hero qu'il attaque
    */
    void Azazel::MonsterAttack(Hero *_hero)
    {
        
            Azazel *_azazel = dynamic_cast<Azazel *>(this);
            srand(time(nullptr));
            int random = rand() % 3;
            switch (random)
            {
            case 0:
                _azazel->manaDrain(_hero);

                break;
            case 1:
                _azazel->brimStorm(_hero);

                break;
            case 2:
                _azazel->doubleSlash(_hero);
                break;
            case 3:
                _azazel->apocalypse(_hero);
            default:
                //si jamais le random fait une mauvaise valeur (ce qui ne devrait pas mais double protection)
                cout << "Mauvaise Valeur, reessai" << endl;
                this->MonsterAttack(_hero);
                break;
            }
        cout << "========================================" << endl;
        Sleep(3000);
    }
}