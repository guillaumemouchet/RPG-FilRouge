#include <iostream>
#include <string>
#include <windows.h>

//TOUJOURS inclure les headers !!
#include "..\include\Hero.h"
#include "..\include\Warrior.h"
#include "..\include\Wizard.h"
#include "..\include\Necromancer.h"
#include "..\..\Stuff\include\Potion.h"
#include "..\..\Stuff\include\Sword.h"
#include "..\..\Stuff\include\Shield.h"
#include "..\..\Stuff\include\IObject.h"
#include "..\..\Enum.h"

using namespace std;

namespace HE_ARC::RPG
{
    //CONSTUCTEURS
    
    Hero::Hero(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pObject) : pObject(_pObject)
    {
        // cout << "CONSTRUCTEUR par parametres: " << _name << endl;
        this->strength = _strength;
        this->agility = _agility;
        this->hp = _hp;
        this->intelligence = _intelligence;
        this->name = _name;
        this->currentHp = _hp;
    }

    //DESTRUCTEUR  
    Hero::~Hero()
    {
        // cout << "DESTRUCTEUR: " << this->name << endl;
        //On détruit l'objet courrant
        delete this->pObject;
        this->pObject = nullptr;
        //on détruit les éléments du sac
        for (int k = 0; k < this->backpack.getSize(); k++)
        {
            IObject *mItem = this->backpack.unPack();
            //cout << "you removed : " << mItem->getName() << "\t" << mItem->getFeature() << " from your backpack." << endl;
            delete mItem;
            mItem = nullptr;
        }
    }

    //FONCTIONS
    
    void Hero::show()
    {
        /*cout << endl
             << "=========================" << endl
             << "Nom : " << this->name << endl
             << "=========================" << endl
             << "Force : " << this->strength << endl
             << "Hp : " << this->hp << endl
             << "Agilité : " << this->agility << endl
             << "Intelligence : " << this->intelligence << endl
             << "Objet : "; this->pObject->show();
             cout << "=========================" << endl
             << endl;*/
        Logger::writeGame("=========================");
        Logger::writeGame("Hero's name : " + this->name);
        Logger::writeGame("=========================");
        Logger::writeGame("Strength : " + to_string(this->strength));
        Logger::writeGame("Health : " + to_string(this->hp));
        Logger::writeGame("Agility : " + to_string(this->agility));
        Logger::writeGame("Intelligence : " + to_string(this->intelligence));
        Logger::writeGame("Object : ");
        this->pObject->show();
        Logger::writeGame("=========================\n");
        Sleep(lTime);
    }

    void Hero::equip(IObject *_pObject)
    {
        this->pObject = _pObject;
    }

    IObject *Hero::unequip()
    {
        IObject *mItem = this->pObject;
        this->pObject = nullptr;
        return mItem;
    }

    void Hero::heal(double _heal)
    {
        if (_heal >= (this->getHp() - this->getcHp()))
        {
            this->currentHp = this->getHp();
            Logger::writeBattle("Vous regagnez tous vos Hp.");
        }
        else
        {

            this->currentHp += _heal;
            Logger::writeBattle("Vous vous soignez de " + to_string(_heal) + "Hp.");
        }
    }

    void Hero::looseHp(int _damage, int _stat)
    {

        double damage = 0;
        if (this->dodge())
        {
            Logger::writeBattle("Vous avez esquivé l'attaque");
        }
        else
        {
            if (typeid(this->pObject) == typeid(Shield))
            {
                damage = (_stat * _damage) / 2.0 - this->pObject->getFeature();
            }
            else
            {
                damage = (_stat * _damage) / 2.0;
            }
            this->currentHp -= damage;

            Logger::writeBattle("Vous perdez " + to_string(damage) + " Hp");
        }
    }

    bool Hero::dodge()
    {
        srand(time(nullptr));
        //return (((rand() % 15 + 1) + this->getAgility()) >= 15);
        return (rand() % 100 + 1 <= this->getAgility());
    }

    void Hero::loot()
    {

        srand(time(nullptr));
        int valeur = rand() % 6 + 5;
        IObject *tab[] = {new Sword(valeur), new Shield(valeur), new Potion(valeur)};
        int i = rand() % 3;
        cout << "Vous trouvez l'objet: ";
        tab[i]->show();
        Sleep(lTime);
        int action = -1;
        int status = 0;
        do
        {

            cout << "Voulez vous le mettre dans votre sac?" << endl;
            cout << "[" << oui << "] Oui" << endl
                 << "[" << non << "] Non" << endl;
            fflush(stdin);
            status = scanf("%d", &action);
        } while (not(0 <= action && action <= 1 && status == 1));
        switch (action)
        {
        case 0:

            Logger::writeGame("Vous mettez l'object en haut de votre sac");
            this->backpack.pack(tab[i]);
            Sleep(lTime);
            break;
        case 1:

            Logger::writeGame("L'object n'est pas utile vous le laissez par terre");
            delete tab[i];
            tab[i] = nullptr;
            Sleep(lTime);
        default:
            break;
        }
    }


    void Hero::heroAction(Monster *_monster)
    {
        int action = -1;
        int status = 0;
        do
        {

            cout << "[" << hAction::attack << "] Attack" << endl;
            cout << "[" << hAction::backpack << "] Backpack " << endl;
            cout << "[" << hAction::concede << "] Concede" << endl;
            fflush(stdin);
            status = scanf("%d", &action);
        } while (not(0 <= action && action <= 2 && status == 1));
        switch (action)
        {
        case hAction::attack:
            Logger::writeBattle("Vous choissisez de combattre");
            this->heroAttack(_monster);
            break;
        case hAction::backpack:
            Logger::writeBattle("Vous ouvrez votre sac");
            this->useBackpack(_monster);
            break;
        case hAction::concede:
            Logger::writeBattle("Vous avez abondonné la partie");
            this->concede(); // on met ses points de vie à 0
            break;
        default:
            cout << "Erreur" << endl;
            this->heroAttack(_monster); // on fait un retour à la fonction en cas d'erreur qu'il puisse rejouer son tour
            break;
        }
    }


    void Hero::useBackpack(Monster *_monster)
    {

        if (this->backpack.isNotEmpty() == true)
        {

            IObject *mItem = this->backpack.unPack();
            cout << "Il y a tout en haut ";
            mItem->show();
            Sleep(lTime);

            if (typeid(*mItem) == typeid(Potion))
            {
                int action = -1;
                int status = 0;
                do
                {

                    cout << "Voulez vous boire la potion?" << endl;
                    cout << "["<< oui << "] Oui" << endl
                         << "["<< non << "] Non" << endl
                         << "["<< jeter << "] Jeter" << endl;
                    fflush(stdin);
                    status = scanf("%d", &action);
                } while (not(0 <= action && action <= 2 && status == 1));

                switch (action)
                {
                case oui:
                    //on utilise l'objet
                    this->heal(mItem->getFeature() * 10.0);
                    break;
                case non:
                    // vu qu'on ne l'utilise pas on le remet au dessus
                    this->backpack.pack(mItem);
                    this->heroAction(_monster);
                    break;
                case jeter:
                    // on jete l'objet du coup rien n'est fait on passe à la suite
                    cout << "Vous jetez votre objet: ";
                    mItem->show();
                    delete mItem;
                    mItem = nullptr;
                default:
                    break;
                }
            }
            else
            {
                int action = -1;
                int status = 0;
                do
                {

                    cout << "Voulez vous équipez l'objet?" << endl;
                    cout << "["<< oui << "] Oui" << endl
                         << "["<< non << "] Non" << endl
                         << "["<< jeter << "] Jeter" << endl;
                    fflush(stdin);
                    status = scanf("%d", &action);
                } while (not(0 <= action && action <= 2 && status == 1));

                switch (action)
                {
                case oui:
                {
                    //on va d'abord enlever l'équipement actif
                    IObject *mItem1 = this->unequip();
                    //on va lui équiper le nouvel objet
                    this->equip(mItem);
                    //on remet l'autre objet en haut du sac
                    this->backpack.pack(mItem1);
                    break;
                }
                case non:
                    // on la range et on refait le tour
                    this->backpack.pack(mItem);
                    this->heroAction(_monster);
                    break;
                case jeter:
                    // on jete l'objet du coup rien n'est fait on passe à la suite

                    cout << "Vous jetez votre objet: ";
                    mItem->show();
                    delete mItem;
                    mItem = nullptr;
                default:
                    break;
                }
            }
        }
        else
        {
            cout << "votre sac est vide" << endl;
            this->heroAction(_monster);
        }
    }
    //----------------FONCTION ET CONSTRUCTEUR QUI NE SONT PLUS UTILE--------------------------------------
    //par recopie
    /*
    Hero::Hero(const Hero& hero)
    {
        cout << "CONSTRUCTEUR par recopie: " << hero.name << endl;
        this->strength = hero.strength;
        this->agility = hero.agility;
        this->hp = hero.hp;
        this->intelligence = hero.intelligence;
        this->name = hero.name;
        this->pObject = new IObject(*hero.pObject);
    }
    */

    /* void Hero::interact(const Hero& hero )
    {
        cout << this->name << " says hi to " << hero.name << endl;
    } */

    //SURCHARGE D'OPÉRATEUR =
    /*
    Hero& Hero::operator=(const Hero &hero)
    {
        this->strength = hero.strength;
        this->agility = hero.agility;
        this->hp = hero.hp;
        this->intelligence = hero.intelligence;
        this->name = hero.name;
        this->pObject = new IObject(hero.pObject);
        return *this;
    }
    */
    /*//SURCHARGE D'OPÉRATEUR AMIE <<
    ostream &operator<<(ostream &s, const Hero &h)
    {
        return s << "=========================" << endl
                 << "Hero's name : " << h.name << endl
                 << "=========================" << endl
                 << "Strength : " << h.strength << endl
                 << "Health : " << h.hp << endl
                 << "Agility : " << h.agility << endl
                 << "Intelligence : " << h.intelligence << endl
                 << "Object(" << h.pObject->getName() << ") : " << h.pObject->getFeature() << endl
                 << "=========================" << endl
                 << endl;
    }*/
}
