#include <iostream>
#include "Battle.h"
/*
    Pour l'instant le combat suivera un paterne prédéfini d'attack au tour par tour, et qui se fait
    jusqu'à la mort d'un personnage, il y a un transtypage pour savoir à quelle calsse nous appartenons
*/
using namespace std;
namespace HE_ARC::RPG
{
    //c'est pour faire un pattern pour les attaques du monstre
    int Battle::mCounter = 0;

    void Battle::Fight(Hero *_hero, Monster *_monster)
    {
        cout << "=======================================" << endl;
        cout << "=======================================" << endl;
        cout << "Le combat commence" << endl;
        cout << "=======================================" << endl;
        cout << "=======================================" << endl;
        cout << endl;
        while ((isHAlive(_hero) && isMAlive(_monster))) // vérifie si quelqu'un est mort
        {
            cout << "========================================" << endl;
            MonsterAttack(_monster, _hero);
            show(_hero, _monster);
            if (not isHAlive(_hero)) //Pour éviter que le héro attaque en étant mort
            {
                break;
            }
            HeroAction(_hero, _monster);
            show(_hero, _monster);
        }
        cout << "Fin du combat" << endl;
        if (isHAlive(_hero) == true)
        {
            cout << "BRAVO!!!" << endl
                 << endl;
            _monster->resetcHp();                    //on le ramène à la vie si jamais on doit le réutiliser
            if (typeid(*_monster) != typeid(Azazel)) //si c'est le boss final pas besoin de loot
            {
                _hero->loot(); // le héro trouve un object random
            }
            else
            {
                cout << "Victoire, Vous avez battu le boss final" << endl;
            }
        }
        else
        {
            cout << "le monstre a gagné ='(" << endl
                 << "Game Over"
                 << endl;
            exit(-1); // il est mort donc fin de la partie
        }
    }

    //fonction qui permet au héro de choisir qu'elle action faire
    void Battle::HeroAction(Hero *_hero, Monster *_monster)
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
            HeroAttack(_hero, _monster);
            break;
        case 1:
            cout << "Ouverture du sac" << endl;
            UseBackpack(_hero, _monster);
            break;
        case 2:
            cout << "Vous avez abondonné la partie" << endl;
            _hero->looseHp(_hero->getHp(), 4); //on le tue fois 4 pour être large
            break;
        default:
            cout << "Erreur" << endl;
            HeroAction(_hero, _monster); // on fait un retour à la fonction en cas d'erreur qu'il puisse rejouer son tour
            break;
        }
    }

    //Pour voir si les personnages sont en vie
    bool Battle::isHAlive(Hero *_hero) const
    {
        return (_hero->getcHp() > 0);
    }
    bool Battle::isMAlive(Monster *_monster) const
    {
        return (_monster->getcHp() > 0);
    }

    //Les attaques des monstres fonctionnent sur un pattern simple
    void Battle::MonsterAttack(Monster *_monster, Hero *_hero)
    {
        if (typeid(*_monster) == typeid(Goblin))
        {
            Goblin *_goblin = dynamic_cast<Goblin *>(_monster);
            switch (Battle::mCounter)
            {
            case 0:
                _goblin->steal(_hero);
                Battle::mCounter++;
                break;
            case 1:
                _goblin->rallye(_hero);
                Battle::mCounter++;
                break;
            case 2:
                _goblin->slingShot(_hero);
                Battle::mCounter = 0;
            default:
                break;
            }
        }
        if (typeid(*_monster) == typeid(Undead))
        {
            Undead *_undead = dynamic_cast<Undead *>(_monster);
            switch (Battle::mCounter)
            {
            case 0:
                _undead->PoisonGrip(_hero);
                Battle::mCounter++;
                break;
            case 1:
                _undead->manaDrain(_hero);
                Battle::mCounter++;
                break;
            case 2:
                _undead->RiseUndead(_hero);
                Battle::mCounter = 0;
                break;
            default:
                break;
            }
        }
        //vu que c'est le boss les attaques sont sur random pour ne pas avoir de pattern
        if (typeid(*_monster) == typeid(Azazel))
        {
            Azazel *_azazel = dynamic_cast<Azazel *>(_monster);
            srand(time(nullptr));
            int random = rand()% 3;
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
                MonsterAttack(_monster, _hero);
                break;
            }
        }
    }

    //Après avoir choisir "Attaque" dans HeroAction, on choisi des attaques spécifique à la calsse
    void Battle::HeroAttack(Hero *_hero, Monster *_monster)
    {
        if (typeid(*_hero) == typeid(Warrior))
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
            Warrior *_warrior = dynamic_cast<Warrior *>(_hero);
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
                HeroAttack(_hero, _monster);
                break;
            }
        }
        if (typeid(*_hero) == typeid(Wizard))
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
            Wizard *_wizard = dynamic_cast<Wizard *>(_hero);
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
                HeroAttack(_hero, _monster);
                break;
            }
        }
        if (typeid(*_hero) == typeid(Necromancer))
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
            Necromancer *_necromancer = dynamic_cast<Necromancer *>(_hero);
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
                HeroAttack(_hero, _monster);
                break;
            }
        }
    }

    void Battle::show(Hero *_hero, Monster *_monster) const
    {
        cout << "========================================" << endl;
        cout << "Hero current HP: " << _hero->getcHp() << endl;
        if (typeid(*_hero) == typeid(Wizard) || typeid(*_hero) == typeid(Necromancer))
        {
            Wizard *_wizard = dynamic_cast<Wizard *>(_hero);
            cout << "Hero current MP: " << _wizard->getcMana() << endl;
        }
        cout << "Monster current HP: " << _monster->getcHp() << endl;
        cout << "========================================" << endl;
    }

    //On regarde ce qui a dans le sac puis on avise si on l'utilise ou non
    void Battle::UseBackpack(Hero *_hero, Monster *_monster)
    {

        if (_hero->backpack.isNotEmpty() == true)
        {
            cout << "Vous ouvrez votre sac" << endl;
            IObject *mItem = _hero->backpack.unPack();
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
                    _hero->heal(mItem->getFeature() * 10.0);
                    break;
                case 1:
                    // vu qu'on ne l'utilise pas on le remet au dessus
                    _hero->backpack.pack(mItem);
                    HeroAction(_hero, _monster);
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
                    IObject *mItem1 = _hero->unequip();
                    //on va lui équiper le nouvel objet
                    _hero->equip(mItem);
                    //on remet l'autre objet en haut du sac
                    _hero->backpack.pack(mItem1);
                    break;
                }
                case 1:
                    // on la range et on refait le tour
                    _hero->backpack.pack(mItem);
                    HeroAction(_hero, _monster);
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
            HeroAction(_hero, _monster);
        }
    }

    void Battle::Restsite(Hero *_hero)
    {
        cout << "Vous vous reposez et regagnez de HP" << endl;
        _hero->heal((_hero->getHp() * 30 / 100));
        if (typeid(*_hero) == typeid(Wizard))
        {
            Wizard *_wizard = dynamic_cast<Wizard *>(_hero);
            _wizard->mHeal(_wizard->getMana() * 30 / 100);
        }
        else if (typeid(*_hero) == typeid(Necromancer))
        {
            Necromancer *_necromancer = dynamic_cast<Necromancer *>(_hero);
            _necromancer->mHeal(_necromancer->getMana() * 30 / 100);
        }

        _hero->show();

        //Rangement du sac
        cout << "Ouverture du sac pour le trier" << endl;

        //on détermine la taille du sac
        int size = _hero->backpack.getSize();
        IObject *Sac[size];
        //on met a nullptr pour définir quand on range au meme endroit ou non
        for (int i = 0; i < size; i++)
        {
            Sac[i] = nullptr;
        }

        int status = 0;
        int action = 0;
        //on fait ranger le sac tant qu'il n'est pas vide
        while (_hero->backpack.isNotEmpty() == true)
        {
            IObject *Item = _hero->backpack.unPack();

            cout << "Choissiez l'emplacement dans votre sac, 0 étant le fond de votre sac" << endl;
            cout << "Votre sac à une taille de " << size << endl;
            //on sort de ce qui il y en haut du sac et on demande ou il veut le stocker
            do
            {
                cout << "Rentrez des valeurs entre 0 et " << size - 1 << endl;
                cout << "Ou voulez vous ranger l'objet -> " << Item->getName() << "(" << Item->getFeature() << ")" << endl;
                fflush(stdin);
                status = scanf("%d", &action);
                //on fait un premier controle pour savoir si la saisie est juste et est dans la taille du tab
            } while (not(0 <= action && action <= size - 1 && status == 1));

            //si lemplacement dans le sac vaut nullptr alors on y a rien mit donc on peut y stocker item
            if (Sac[action] == nullptr)
            {
                Sac[action] = Item;
                //sinon ça veut dire que la place est déjà prise donc on le rerange pour le resortir dans la suite de la boucle
            }
            else
            {
                cout << "Erreur, place déjà prise, veuillez prendre une autre valeur que " << action << endl;
                //on rerange pour faire denouveau la boucle
                _hero->backpack.pack(Item);
            }
        }
        for (int i = 0; i < size; i++)
        {
            _hero->backpack.pack(Sac[i]);
        }
    }
}