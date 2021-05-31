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
    

    void Battle::Fight(Hero *_hero, Monster *_monster)
    {
        cout << "=======================================" << endl;
        cout << "=======================================" << endl;
        cout << "Le combat commence" << endl;
        cout << "=======================================" << endl;
        cout << "=======================================" << endl;
        cout << endl;
        while ((_hero->isHAlive() && _monster->isMAlive())) // vérifie si quelqu'un est mort
        {
            cout << "========================================" << endl;
            _monster->MonsterAttack(_hero);
            show(_hero, _monster);
            if (not _hero->isHAlive()) //Pour éviter que le héro attaque en étant mort
            {
                break;
            }
            _hero->HeroAction(_monster);
            show(_hero, _monster);
        }
        cout << "Fin du combat" << endl;
        if (_hero->isHAlive() == true)
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