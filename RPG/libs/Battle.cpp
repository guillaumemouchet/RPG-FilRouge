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
            cout << "BRAVO!!! vous avez gagné votre premier combat" << endl
                 << endl;
            _monster->currentHp = _monster->getHp(); //on le ramène à la vie pour éviter de crée trop de monstre
        }
        else
        {
            cout << "le monstre à gagné" << endl
                 << endl;
            _monster->currentHp = _monster->getHp();
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
            cout << "[1] Concede" << endl;
            cout << "[2] Backpack" << endl;
            fflush(stdin);
            status = scanf("%d", &action);
        } while (not(0 <= action && action <= 2 && status == 1));
        switch (action)
        {
        case 0:
            HeroAttack(_hero, _monster);
            break;
        case 1:
            cout << "You abondon the run" << endl;
            _hero->currentHp = 0;
            break;
        case 2:
            cout << "Open Backpack" << endl;
            break;
        default:
            cout << "erreur" << endl;
            HeroAction(_hero, _monster); // on fait un retour à la fonction en cas d'erreur qu'il puisse rejouer son tour
            break;
        }
    }

    //Pour voir si les personnages sont en vie
    bool Battle::isHAlive(Hero *_hero)
    {
        return (_hero->getcHp() > 0);
    }
    bool Battle::isMAlive(Monster *_monster)
    {
        return (_monster->getcHp() > 0);
    }

    //the attack of the monster work on a pattern
    void Battle::MonsterAttack(Monster *_monster, Hero *_hero)
    {
        if (typeid(*_monster) == typeid(Goblin))
        {
            Goblin *_goblin = dynamic_cast<Goblin *>(_monster);
            switch (Battle::mCounter)
            {
            case 0:
                _goblin->Steal(_hero);
                Battle::mCounter++;
                break;
            case 1:
                _goblin->Rallye(_hero);
                Battle::mCounter = 0;
                break;
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
                _undead->ManaDrain(_hero);
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
    }

    //after chosing attack in HeroAction depending on your classe you have different action
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
                cout << "[0] Fireball" << endl;
                cout << "[1] Blizzard" << endl;
                cout << "[2] Leech" << endl;
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
                cout << "[0] Fireball" << endl;
                cout << "[1] Blizzard" << endl;
                cout << "[2] Leech" << endl;
                cout << "[3] RiseUndead" << endl;
                cout << "[4] Cataclysme" << endl;
                fflush(stdin);
                status = scanf("%d", &action);
            } while (not(0 <= action && action <= 4 && status == 1));
            Necromancer *_necromancer = dynamic_cast<Necromancer *>(_hero);
            switch (action)
            {
            case 0:
                _necromancer->Fireball(_monster);
                break;
            case 1:
                _necromancer->Blizzard(_monster);
                break;
            case 2:
                _necromancer->Leech(_monster);
                break;
            case 3:
                _necromancer->RiseUndead(_monster);
                break;
            case 4:
                _necromancer->Cataclysme(_monster);
                break;
            default:
                HeroAttack(_hero, _monster);
                break;
            }
        }
    }

    void Battle::show(Hero *_hero, Monster *_monster)
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
}