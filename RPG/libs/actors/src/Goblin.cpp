#include "..\include\Goblin.h"
#include "..\include\Monster.h"
#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    //CONSTRUCTEUR
    //par paramètre
    Goblin::Goblin(int _strength, int _agility, int _intelligence, double _hp) : Monster(_strength, _agility, _intelligence, _hp)
    {
        this->currentHp = _hp;
    }

    //liste des sorts du monstre

    //invoque un autre Goblin pour le rejoindre dans le combat
    void Goblin::Rallye(Hero *_hero)
    {
        int cDamage = 8; // constante de dégat de l'attaque
        double damage = 0;
        cout << "Des Goblins aux alentours sont venus vous faire des dégats" << endl;
        damage = (this->getStrength() * cDamage) / 2;
        _hero->currentHp -= damage;
        cout << "vous perdez " << damage << " HP" << endl;
    }

    //si le sac a dos n'est pas vide vole l'objet au dessus
    void Goblin::Steal(Hero *_hero)
    {
        int cDamage = 4; // constante de dégat de l'attaque
        double damage = 0;
        if (_hero->backpack.isNotEmpty() == false /*|| ou alors que la chance sur 8 ne fonctionne pas*/)
        {
            cout << "Le Gobelin vous donne une giffle" << endl;
            damage = (this->getStrength() * cDamage) / 2;
            _hero->currentHp -= damage;
            cout << "vous perdez " << damage << " HP" << endl;
        }else
        {
            cout << "Le Gobelin vous donne une giffle et vole votre objet" << endl;
            _hero->backpack.unPack();
            damage = (this->getStrength() * cDamage) / 2;
            _hero->currentHp -= damage;
            cout << "vous perdez " << damage << " HP" << endl;
        }
    }

}