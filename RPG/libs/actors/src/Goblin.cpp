#include "..\include\Goblin.h"
#include "..\include\Monster.h"
#include <iostream>
using namespace std;

namespace HE_ARC::RPG
{
    /*constructeur par paramètre*/
    Goblin::Goblin(int _strength, int _agility, int _intelligence, double _hp) : Monster(_strength, _agility, _intelligence, _hp)
    {
        this->currentHp=_hp;
    }
    /*constructeur par défaut*/

    //liste des sorts du monstre

    //invoque un autre Goblin pour le rejoindre dans le combat
    void Goblin::Rallye(Hero *_hero)
    {
        int cDamage = 8;
        double damage = 0;
        cout << "Des Goblins aux alentours sont venus vous faire des dégats" << endl;
        damage = (this->getStrength()*cDamage)/2;
        _hero->currentHp -=damage; 
        cout << "vous perdez " << damage << " HP" << endl;
    }

    //si le sac a dos n'est pas vide vole l'objet au dessus
    void Goblin::Steal(Hero *_hero)
    {
        int cDamage = 4;
        double damage = 0;
        cout << "le Gobelin vous vole l'objet en haut de votre sac et vous donne une giffle" << endl;
        damage = (this->getStrength()*cDamage)/2;
        _hero->currentHp -=damage;
        cout << "vous perdez " << damage << " HP" << endl;
    }


}