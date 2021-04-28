#include <iostream>
#include <string>
#include <list>
#include <algorithm>

//TOUJOURS inclure les headers !!
//inclusion des objets utilisables
#include "libs\Stuff\include\IObject.h"
#include "libs\Stuff\include\Sword.h"
#include "libs\Stuff\include\Shield.h"
#include "libs\Stuff\include\Potion.h"

//inclusions des personnages
#include "libs\actors\include\Hero.h"
#include "libs\actors\include\Warrior.h"
#include "libs\actors\include\Wizard.h"
#include "libs\actors\include\Necromancer.h"
#include "libs\actors\include\Monster.h"
#include "libs\actors\include\Goblin.h"
#include "libs\actors\include\Undead.h"

//inclusions du sytème de combat
#include "libs/Battle.h"
using namespace std;
using namespace HE_ARC::RPG;

int w =0;
//c'est ce qui commence les combats
void Room(Hero *_hero, Monster *_monster)
{
    
    string tab[] = {"première", "deuxième", "troisième"};
    cout << "Vous entrez dans la "<<tab[w]<< " salle du donjon" << endl;
    if (typeid(*_monster)== typeid(Goblin))
    {
        cout << "Vous tomber sur un goblin, préparez vous au combat" << endl;
    }else if (typeid(*_monster)== typeid(Undead))
    {
        cout << "Vous tomber sur un mort-vivant, préparez vous au combat" << endl;
    }
    //création du premier combat
    Battle bataille;
    bataille.Fight(_hero, _monster);
    w++;
}
//faire le choix des stats
int Stat(int i, int tot)
{
    int status = 0;
    string tab[] = {"strength", "agility", "intelligence", "HP", "Mana"};
    int stat = 0;
    do
    {
        cout << "=======================================" << endl;
        cout << "You have 5 Stats, strength, agility, intelligence, HP, Mana (not for the Warrior)" << endl;
        cout << "You have a total of (" << tot <<"/" << "30) points" << endl;
        cout << "Choose the number of point for " << tab[i] << endl;
        cout << "=======================================" << endl;
        fflush(stdin);
        status = scanf(" %d", &stat);
        cout << endl;
    } while (status != 1);
    return stat;
}
int main()
{
    int action = -1;

    //Création des Monstres pour les combats (les monstres sont soigné en fin de combat)
    Goblin *ptrG1 = new Goblin(3, 3, 3, 30);
    Undead *ptrU1 = new Undead(5, 5, 5, 50);

    //Valeur par défaut des objects pour les personnages
    Sword *ptrS = new Sword(2);
    Potion *ptrP = new Potion(2);
    Shield *ptrSh = new Shield(2);

    //sélection de la classe
    int status = 0;
    do
    {
        cout << "=======================================" << endl;
        cout << "Veuillez selectionner votre classe, cela déterminera vos attaques" << endl;
        cout << "[0] Warrior" << endl;
        cout << "[1] Wizard" << endl;
        cout << "[2] Necromancer" << endl;
        cout << "=======================================" << endl;
        fflush(stdin);
        status = scanf("%d", &action);
        cout << endl;
    } while (not(0 <= action && action <= 2 && status == 1));
    cout << "=======================================" << endl;
    cout << "BRAVO, Vous avez crée votre premier héro!" << endl;
    cout << "=======================================" << endl;
    //Création du personnage en fonction de sa classe
    //l'utilisation du if peut paraitre bizarre mais avec le switch ça ne fonctionne pas
    //car il détermine que hero aura déjà été déclaré comme Warrior et ne vouda pas faire le changement
    if (action == 0)
    {
        int tab[4];
        int total = 0;
        do
        {
            total = 0;
            for (int i = 0; i < 4; i++)
            {
                tab[i] = Stat(i, total);
                total += tab[i];
            }
        } while (total != 30);

        Warrior *hero = new Warrior(tab[0], tab[1], tab[2], (tab[3] * 10.0), "Chandra", ptrSh);
        Room(hero, ptrG1);
        Room(hero, ptrU1);
    }
    else if (action == 1)
    {
        int tab[5];
        int total = 0;
        do
        {
            total = 0;

            for (int i = 0; i < 5; i++)
            {
                tab[i] = Stat(i, total);
                total += tab[i];
            }
        } while (total != 30);
        Wizard *hero = new Wizard(tab[0], tab[1], tab[2], (tab[3] * 10.0), "Jace", ptrS, (tab[4] * 10));
        Room(hero, ptrG1);
        Room(hero, ptrU1);
    }
    else if (action == 2)
    {
        int tab[5];
        int total = 0;
        do
        {
            total = 0;

            for (int i = 0; i < 5; i++)
            {
                tab[i] = Stat(i, total);
                total += tab[i];
            }
        } while (total != 30);
        Necromancer *hero = new Necromancer(tab[0], tab[1], tab[2], (tab[3] * 10.0), "Liliana", ptrP, (tab[4] * 10));
        Room(hero, ptrG1);
        Room(hero, ptrU1);
    }

    
    /*//Creation of the Backpack and filling it for the Warrior
    ptrW1->backpack.pack(new Potion(3));
    ptrW1->backpack.pack(new Potion(6));
    ptrW1->backpack.pack(new Sword(15));
    ptrW1->backpack.pack(new Sword(23));
    ptrW1->backpack.pack(new Sword(12));
    ptrW1->backpack.pack(new Shield(30));
    ptrW1->backpack.pack(new Shield(27));

    //unpacking the bag
    for (int k = 0; k < ptrW1->backpack.getSize(); k++)
    {
        IObject *mItem = ptrW1->backpack.unPack();
        cout << "you removed : " << mItem->getName() << "\t" << mItem->getFeature() << " from your backpack." << endl;
        delete mItem;
        mItem = nullptr;
    }*/

}