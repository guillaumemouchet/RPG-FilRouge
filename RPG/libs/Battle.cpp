#include <iostream>
#include <windows.h>
#include "Battle.h"

using namespace std;
namespace HE_ARC::RPG
{
    /**
    *@brief le joueur combat un monstre, le monstre aura soit un pattern défini ou aura des attaques aléatoire
    *@param _hero le pointeur du joueur
    *@param _monster le pointeur du monstre qu'il combat
    */
    void Battle::fight(Hero *_hero, Monster *_monster)
    {
        Logger::writeBattle("=======================================");
        Logger::writeBattle("Le combat commence");
        Logger::writeBattle("=======================================");
        Sleep(lTime);
        cout << endl;
        while ((_hero->isHAlive() && _monster->isMAlive())) // vérifie si quelqu'un est mort
        {
            cout << "========================================" << endl;
            _monster->monsterAttack(_hero);

            show(_hero, _monster);

            if (not _hero->isHAlive()) //Pour éviter que le héro attaque en étant mort
            {
                break;
            }
            _hero->heroAction(_monster);
            show(_hero, _monster);
        }
        Logger::writeBattle("Fin du combat");
        Sleep(sTime);
        if (_hero->isHAlive() == true)
        {
            Logger::writeBattle("BRAVO!!!");
            _monster->resetcHp();                    //on le ramène à la vie si jamais on doit le réutiliser
            if (typeid(*_monster) != typeid(Azazel)) //si c'est le boss final pas besoin de loot
            {
                _hero->loot(); // le héro trouve un object random
            }
            else
            {
                Logger::writeBattle("Victoire, Vous avez battu le boss final");
            }
        }
        else
        {
            Logger::writeBattle("le monstre a gagné ='(");
            Logger::writeBattle("Game Over");
            exit(-1); // il est mort donc fin de la partie, et du programme
        }
    }
    /**
    *@brief Affichage des points de vie du monster et du joueur (et du mana si il en )
    *@param _hero le pointeur du joueur
    *@param _monster le pointeur du monstre qu'il combat
    */
    void Battle::show(Hero *_hero, Monster *_monster) const
    {

        Logger::writeBattle("========================================");
        Logger::writeBattle("Hero current HP: " + to_string(_hero->getcHp()));
        if (typeid(*_hero) == typeid(Wizard) || typeid(*_hero) == typeid(Necromancer))
        {
            Wizard *_wizard = dynamic_cast<Wizard *>(_hero);
            Logger::writeBattle("Hero current MP: " + to_string(_wizard->getcMana()));
        }
        Logger::writeBattle("Monster current HP: " + to_string(_monster->getcHp()));
        Logger::writeBattle("========================================");
        Sleep(lTime);
    }

    /**
    *@brief le joueur regagne une partie de ses points de vie et de son mana, il doit aussi trier son sac
    *@param _hero le pointeur du joueur
    *@param _monster le pointeur du monstre qu'il combat
    */
    void Battle::restsite(Hero *_hero)
    {

        Logger::writeGame("Vous vous reposez et regagnez de HP et du Mana");
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
        Sleep(lTime);
        _hero->show();

        //Rangement du sac

        cout << "Ouverture du sac pour le trier" << endl;
        Sleep(lTime);
        //on détermine la taille du sac
        int size = _hero->backpack.getSize();
        IObject *Sac[size];
        //on met a nullptr pour définir quand on range au meme endroit ou non
        for (int i = 0; i < size; i++)
        {
            Sac[i] = nullptr;
        }

        int status = 0;
        int action = -1;
        //on fait ranger le sac tant qu'il n'est pas vide
        while (_hero->backpack.isNotEmpty() == true)
        {
            IObject *Item = _hero->backpack.unPack();

            cout << "Choissiez l'emplacement dans votre sac, 0 étant le fond de votre sac" << endl;
            cout << "Votre sac à une taille de " << size << endl;
            Sleep(lTime);
            //on sort de ce qui il y en haut du sac et on demande ou il veut le stocker
            do
            {

                cout << "Rentrez des valeurs entre 0 et " << size - 1 << endl;
                cout << "Ou voulez vous ranger l'objet -> " << Item->getName() << "(" << Item->getFeature() << ")" << endl;
                fflush(stdin);
                status = scanf("%d", &action);
                //on fait un premier controle pour savoir si la saisie est juste et est dans la taille du tab
            } while (not(0 <= action && action <= size - 1 && status == 1));

            //si l'emplacement dans le sac vaut nullptr alors on y a rien mit donc on peut y stocker item
            if (Sac[action] == nullptr)
            {
                Sac[action] = Item;
                //sinon ça veut dire que la place est déjà prise donc on le rerange pour le resortir dans la suite de la boucle
            }
            else
            {

                cout << "Erreur, place déjà prise, veuillez prendre une autre valeur que " << action << endl;
                Sleep(lTime);
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