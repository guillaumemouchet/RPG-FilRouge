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
            //il faut faire un moyen de drop du loot
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
            cout << "Vous avez abondonner la partie" << endl;
            _hero->currentHp = 0;
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
                cout << "[0] Fireball (5)" << endl;
                cout << "[1] Blizzard (7)" << endl;
                cout << "[2] Leech (10)" << endl;
                cout << "[3] RiseUndead (5)" << endl;
                cout << "[4] Cataclysme (8)" << endl;
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

    //on regarde ce qui a dans le sac puis on avise si on l'utilise ou non
    void Battle::UseBackpack(Hero *_hero, Monster *_monster)
    {

        if (_hero->backpack.isNotEmpty() == true)
        {
            cout << "Vous ouvrez votre sac" << endl;
            IObject *mItem = _hero->backpack.unPack();
            cout << "il y a tout en haut " << mItem->getName() << "(" << mItem->getFeature() << ")" << endl;

            if (typeid(*mItem) == typeid(Potion))
            {
                int action = -1;
                int status = 0;
                do
                {
                    cout << "Voulez vous boire la potion?" << endl;
                    cout << "[0] Oui" << endl
                         << "[1] Non" << endl;
                    fflush(stdin);
                    status = scanf("%d", &action);
                } while (not(0 <= action && action <= 1 && status == 1));
                switch (action)
                {
                case 0:
                    _hero->Heal(mItem->getFeature() * 10.0);
                    break;
                case 1:
                    // vu qu'on ne l'utilise pas on le remet au dessus
                    _hero->backpack.pack(mItem);
                    HeroAction(_hero, _monster);
                    break;
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
                         << "[1] Non" << endl;
                    fflush(stdin);
                    status = scanf("%d", &action);
                } while (not(0 <= action && action <= 1 && status == 1));

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
                    HeroAction(_hero, _monster);
                    break;
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
        cout << "Vous vous reposer et regagnez de HP" << endl;
        _hero->Heal((_hero->getHp() * 30 / 100));
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
        //il faudra faire un truc pour réaranger le sac mais ca risque d'etre chaud
    }
}