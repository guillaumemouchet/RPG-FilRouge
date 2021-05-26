#include <iostream>
#include <string>

//TOUJOURS inclure les headers !!
#include "..\include\Hero.h"
#include "..\..\Stuff\include\IObject.h"
#include "..\..\Stuff\include\Potion.h"
#include "..\..\Stuff\include\Shield.h"
#include "..\..\Stuff\include\Sword.h"

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

    //SURCHARGE D'OPÉRATEUR AMIE <<
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
        int i = rand() %3;
        IObject *tab[] = {new Sword(valeur), new Shield(valeur), new Potion(valeur)};
        cout << "Vous trouvez un "; tab[i]->show();
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
}
