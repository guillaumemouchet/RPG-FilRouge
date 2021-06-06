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

using namespace std;

namespace HE_ARC::RPG
{
    //CONSTUCTEURS
    /**
    *@brief constructeur par paramètres
    *@param _strength la force qui défini les dégats de ses attaques physiques
    *@param _agility l'agilité qui permet d'esquiver les attaques
    *@param _intelligence l'intelligence qui défini les dégats de ses attaques phsychique et magique
    *@param _hp ses points de vie totaux
    *@param _name son nom prédéfini selon la classe
    *@param _PObject un pointeur sur un objet équipé
    */
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
    /**
    *@brief destructeur, on y détruit les éléments courant et ceux dans le sac
    */
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
    /**
    *@brief Affiche le héro et toutes ses compétences
    */
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
        Sleep(3000);
    }
    /**
    *@brief pour équiper un objet dans la main du joueur, depuis son sac
    *@param _PObject un pointeur sur un objet 
    */
    void Hero::equip(IObject *_pObject)
    {
        this->pObject = _pObject;
    }
    /**
    *@brief Pour désequiper l'objet dans la main du joueur
    *@returns pointeur sur l'objet anciennement équipé
    */
    IObject *Hero::unequip()
    {
        IObject *mItem = this->pObject;
        this->pObject = nullptr;
        return mItem;
    }
    /**
    *@brief Pour rendre des points de vie au héro
    *@param _heal les points de vie qu'il va être rendu
    */
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
    /**
    *@brief Le calcul et la perte de point de vie du héro
    *@param _stat la valeur de la compétence utilisée
    *@param _damage la constante de dégat du sort
    */
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
            
            Logger::writeBattle("Vous perdez " +  to_string(damage) + " Hp");
        }
    }
    /**
    *@brief Pour que le héro puisse éviter les attaques du monstre, cela dépend de son agilité
    *@returns Vrai si l'attaque a été esquivée sinon faux
    */
    bool Hero::dodge()
    {
        srand(time(nullptr));
        //return (((rand() % 15 + 1) + this->getAgility()) >= 15);
        return (rand() % 100 + 1 <= this->getAgility());
    }
    /**
    *@brief La fonction qui de manière aléatoire donne un objet au héro, il peut soit le mettre dans son sac ou le jeter
    */
    void Hero::loot()
    {

        srand(time(nullptr));
        int valeur = rand() % 10 + 5;
        int i = rand() % 3;
        IObject *tab[] = {new Sword(valeur), new Shield(valeur), new Potion(valeur)};
        cout << "Vous trouvez l'objet: ";
        tab[i]->show();
        Sleep(3000);
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

            Logger::writeGame("Vous mettez l'object en haut de votre sac");
            this->backpack.pack(tab[i]);
            Sleep(3000);
            break;
        case 1:

            Logger::writeGame("L'object n'est pas utile vous le laissez par terre");
            delete tab[i];
            tab[i] = nullptr;
            Sleep(3000);
        default:
            break;
        }
    }

    /**
    *@brief Permet au joueur de choisir qu'elle action faire dans son combat
    *@param _monster le pointeur sur le monstre qui est combattu
    */
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
            Logger::writeBattle("Vous choissisez de combattre");
            this->HeroAttack(_monster);
            break;
        case 1:
            Logger::writeBattle("Vous ouvrez votre sac");
            this->UseBackpack(_monster);
            break;
        case 2:
            Logger::writeBattle("Vous avez abondonné la partie");
            this->Concede(); // on met ses points de vie à 0
            break;
        default:
            cout << "Erreur" << endl;
            this->HeroAttack(_monster); // on fait un retour à la fonction en cas d'erreur qu'il puisse rejouer son tour
            break;
        }
    }

    /**
    *@brief Permet au joueur d'ouvrir son sac et de voir ce qu'il y a dedans, il peut soit l'utiliser, ou non, ou la jeter
    *@param _monster le pointeur sur le monstre qui est combattu
    */
    void Hero::UseBackpack(Monster *_monster)
    {

        if (this->backpack.isNotEmpty() == true)
        {

            IObject *mItem = this->backpack.unPack();
            cout << "Il y a tout en haut ";
            mItem->show();
            Sleep(3000);

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
