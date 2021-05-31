#include <iostream>
#include <string>

//TOUJOURS inclure les headers !!
#include "..\include\Hero.h"
#include "..\include\Warrior.h"
#include "..\include\Wizard.h"
#include "..\include\Necromancer.h"
#include "..\..\Stuff\include\Potion.h"
#include "..\..\Stuff\include\Sword.h"
#include "..\..\Stuff\include\Shield.h"
#include "..\..\Stuff\include\IObject.h"

using namespace std;

namespace HE_ARC::RPG
{
    //CONSTUCTEURS
    //par paramètres
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
        cout << endl
             << "=========================" << endl
             << "Hero's name : " << this->name << endl
             << "=========================" << endl
             << "Strength : " << this->strength << endl
             << "Health : " << this->hp << endl
             << "Agility : " << this->agility << endl
             << "Intelligence : " << this->intelligence << endl
             << "Object(" << this->pObject->getName() << ") : " << this->pObject->getFeature() << endl
             << "=========================" << endl
             << endl;
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
        }
        else
        {
            this->currentHp += _heal;
        }
    }
    void Hero::looseHp(int _damage, int _stat)
    {
        double damage = 0;
        if (this->dodge())
        {
            cout << "Vous avez esquivé l'attaque" << endl;
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
            cout << "Vous perdez " << damage << " HP" << endl;
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
        int valeur = rand() % 10 + 5;
        int i = rand() % 3;
        IObject *tab[] = {new Sword(valeur), new Shield(valeur), new Potion(valeur)};
        cout << "Vous trouvez un ";
        tab[i]->show();
        int action = -1;
        int status = 0;
        do
        {
            cout << "Voulez vous le mettre dans votre sac?" << endl;
            cout << "[0] Oui" << endl
                 << "[1] Non" << endl;
            fflush(stdin);
            status = scanf("%d", &action);
        } while (not(0 <= action && action <= 1 && status == 1));
        switch (action)
        {
        case 0:
            cout << "Vous mettez l'object en haut de votre sac" << endl;
            this->backpack.pack(tab[i]);
            break;
        case 1:
            cout << "L'object n'est pas utile vous le laissez par terre" << endl;
        default:
            break;
        }
    }

    //fonction qui permet au héro de choisir qu'elle action faire
    void Hero::HeroAction(Monster *_monster)
    {
        int action = -1;
        int status = 0;
        do
        {
            cout << "[0] Attack" << endl;
            cout << "[1] Backpack " << endl;
            cout << "[2] Concede" << endl;
            fflush(stdin);
            status = scanf("%d", &action);
        } while (not(0 <= action && action <= 2 && status == 1));
        switch (action)
        {
        case 0:
            this->HeroAttack(_monster);
            break;
        case 1:
            cout << "Ouverture du sac" << endl;
            this->UseBackpack(_monster);
            break;
        case 2:
            cout << "Vous avez abondonné la partie" << endl;
            this->Concede(); // on met ses points de vie à 0
            break;
        default:
            cout << "Erreur" << endl;
            this->HeroAttack(_monster); // on fait un retour à la fonction en cas d'erreur qu'il puisse rejouer son tour
            break;
        }
    }

    //Après avoir choisir "Attaque" dans HeroAction, on choisi des attaques spécifique à la calsse
    void Hero::HeroAttack(Monster *_monster)
    {
        if (typeid(*this) == typeid(Warrior))
        {
            int action = -1;
            int status = 0;
            do
            {
                cout << "[0] Rampage" << endl;
                cout << "[1] Shieldbash" << endl;
                cout << "[2] Taunt" << endl;
                fflush(stdin);
                status = scanf("%d", &action);
            } while (not(0 <= action && action <= 2 && status == 1));
            Warrior *_warrior = dynamic_cast<Warrior *>(this);
            switch (action)
            {
            case 0:
                _warrior->Rampage(_monster);
                break;
            case 1:
                _warrior->ShieldBash(_monster);
                break;
            case 2:
                _warrior->Taunt(_monster);
                break;
            default:
                this->HeroAttack(_monster);
                break;
            }
        }
        if (typeid(*this) == typeid(Wizard))
        {
            int action = -1;
            int status = 0;
            do
            {
                cout << "[0] Fireball (5)" << endl;
                cout << "[1] Blizzard (7)" << endl;
                cout << "[2] Leech (10)" << endl;
                fflush(stdin);
                status = scanf("%d", &action);
            } while (not(0 <= action && action <= 2 && status == 1));
            Wizard *_wizard = dynamic_cast<Wizard *>(this);
            switch (action)
            {
            case 0:
                _wizard->Fireball(_monster);
                break;
            case 1:
                _wizard->Blizzard(_monster);
                break;
            case 2:
                _wizard->Leech(_monster);
                break;
            default:
                this->HeroAttack(_monster);
                break;
            }
        }
        if (typeid(*this) == typeid(Necromancer))
        {
            int action = -1;
            int status = 0;
            do
            {
                cout << "[0] Leech (10)" << endl;
                cout << "[1] RiseUndead (5)" << endl;
                cout << "[2] Cataclysme (8)" << endl;
                fflush(stdin);
                status = scanf("%d", &action);
            } while (not(0 <= action && action <= 4 && status == 1));
            Necromancer *_necromancer = dynamic_cast<Necromancer *>(this);
            switch (action)
            {
            case 0:
                _necromancer->Leech(_monster);
                break;
            case 1:
                _necromancer->RiseUndead(_monster);
                break;
            case 2:
                _necromancer->Cataclysme(_monster);
                break;
            default:
                this->HeroAttack(_monster);
                break;
            }
        }
    }
    //On regarde ce qui a dans le sac puis on avise si on l'utilise ou non
    void Hero::UseBackpack(Monster *_monster)
    {

        if (this->backpack.isNotEmpty() == true)
        {
            cout << "Vous ouvrez votre sac" << endl;
            IObject *mItem = this->backpack.unPack();
            cout << "Il y a tout en haut ";
            mItem->show();

            if (typeid(*mItem) == typeid(Potion))
            {
                int action = -1;
                int status = 0;
                do
                {
                    cout << "Voulez vous boire la potion?" << endl;
                    cout << "[0] Oui" << endl
                         << "[1] Non" << endl
                         << "[2] Jeter" << endl;
                    fflush(stdin);
                    status = scanf("%d", &action);
                } while (not(0 <= action && action <= 2 && status == 1));
                switch (action)
                {
                case 0:
                    //on utilise l'objet
                    this->heal(mItem->getFeature() * 10.0);
                    break;
                case 1:
                    // vu qu'on ne l'utilise pas on le remet au dessus
                    this->backpack.pack(mItem);
                    this->HeroAction(_monster);
                    break;
                case 2:
                    // on jete l'objet du coup rien n'est fait on passe à la suite
                    cout << "Vous jetez votre objet: ";
                    mItem->show();
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
                    cout << "[0] Oui" << endl
                         << "[1] Non" << endl
                         << "[2] Jeter" << endl;
                    fflush(stdin);
                    status = scanf("%d", &action);
                } while (not(0 <= action && action <= 2 && status == 1));

                switch (action)
                {
                case 0:
                {
                    //on va d'abord enlever l'équipement actif
                    IObject *mItem1 = this->unequip();
                    //on va lui équiper le nouvel objet
                    this->equip(mItem);
                    //on remet l'autre objet en haut du sac
                    this->backpack.pack(mItem1);
                    break;
                }
                case 1:
                    // on la range et on refait le tour
                    this->backpack.pack(mItem);
                    this->HeroAction(_monster);
                    break;
                case 2:
                    // on jete l'objet du coup rien n'est fait on passe à la suite
                    cout << "Vous jetez votre objet: ";
                    mItem->show();
                default:
                    break;
                }
            }
        }
        else
        {
            cout << "votre sac est vide" << endl;
            this->HeroAction(_monster);
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
