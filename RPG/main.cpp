#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <fstream>
#include <windows.h>

//ALWAYS include .h (or .hpp) files
//including all the objects
#include "libs\Stuff\include\IObject.h"
#include "libs\Stuff\include\Sword.h"
#include "libs\Stuff\include\Shield.h"
#include "libs\Stuff\include\Potion.h"

//including all of the Characters
#include "libs\actors\include\Hero.h"
#include "libs\actors\include\Warrior.h"
#include "libs\actors\include\Wizard.h"
#include "libs\actors\include\Necromancer.h"
#include "libs\actors\include\Monster.h"
#include "libs\actors\include\Goblin.h"
#include "libs\actors\include\Undead.h"
#include "libs\actors\include\Azazel.h"

//including all of the battle system
#include "libs\Battle.h"

//including the rest
#include "libs\Logger.h"
#include "libs\Enum.h"

using namespace std;
using namespace HE_ARC::RPG;

void room(Hero *_hero, Monster *_monster);

void whileStat(int tab[], int size);

int chooseStat(int i, int tot, int size);

//global variable for the actual number room
int nSalle = 0;

int main()
{
    Logger mylog;
    //Creating monster for the figths (they are heal after the fight)
    Goblin *ptrG1 = new Goblin(3, 3, 3, 60);
    Undead *ptrU1 = new Undead(4, 4, 4, 80);
    Azazel *ptrA = new Azazel(5, 5, 5, 150);

    //Default value for the items
    int oDefault = 3;

    //The user is selecting the class
    int status = 0;
    int action = -1;
    do
    {
        cout << "======================================= " << endl;
        cout << "Veuillez selectionner votre classe, cela déterminera vos attaques" << endl;
        cout << "[" << warrior << "] Warrior" << endl;
        cout << "[" << wizard << "] Wizard" << endl;
        cout << "[" << necromancer << "] Necromancer " << endl;
        cout << "======================================= " << endl;

        fflush(stdin);
        status = scanf("%d", &action);
        cout << endl;

    } while (not(0 <= action && action <= 2 && status == 1));

    cout << "======================================= " << endl;
    cout << "BRAVO, Vous avez crée votre premier héro! " << endl;
    cout << "======================================= " << endl;

    //Creating the character depending what he choose
    if (action == warrior)
    {
        Logger::writeGame("Vous avez choisi un Warrior");

        int StatSize = 4; // Warrior has only for stats because he has no mana
        int tab[StatSize];
        whileStat(tab, StatSize);

        Warrior *hero = new Warrior(tab[0], tab[1], tab[2], (tab[3] * 10.0), "Chandra", new Shield(oDefault));

        //Putting the default items in the bag with potion on top
        hero->backpack.pack(new Sword(oDefault));
        hero->backpack.pack(new Potion(oDefault));
        //Show the hero
        hero->show();
        //fight against Goblin
        room(hero, ptrG1);
        //fight against Undead
        room(hero, ptrU1);
        //fight against Azazel
        room(hero, ptrA);
    }
    else if (action == wizard)
    {
        Logger::writeGame("Vous avez choisi un Wizard");
        int StatSize = 5;
        int tab[StatSize];
        whileStat(tab, StatSize);
        Wizard *hero = new Wizard(tab[0], tab[1], tab[2], (tab[3] * 10.0), "Jace", new Sword(oDefault), (tab[4] * 10.0));

        //Putting the default items in the bag with potion on top
        hero->backpack.pack(new Shield(oDefault));
        hero->backpack.pack(new Potion(oDefault));

        //Show the hero
        hero->show();
        //fight against Goblin
        room(hero, ptrG1);
        //fight against Undead
        room(hero, ptrU1);
        //fight against Azazel
        room(hero, ptrA);
    }
    else if (action == necromancer)
    {
        Logger::writeGame("Vous avez choisi un Necromancer");
        int StatSize = 5;
        int tab[StatSize];
        whileStat(tab, StatSize);
        Necromancer *hero = new Necromancer(tab[0], tab[1], tab[2], (tab[3] * 10.0), "Liliana", new Sword(oDefault), (tab[4] * 10.0));

        //Putting the default items in the bag with potion on top
        hero->backpack.pack(new Shield(oDefault));
        hero->backpack.pack(new Potion(oDefault));
        
        //Show the hero
        hero->show();
        //fight against Goblin
        room(hero, ptrG1);
        //fight against Undead
        room(hero, ptrU1);
        //fight against Azazel
        room(hero, ptrA);
    }
}
/**
*@brief le joueur entre dans la salle et commence un combat contre une créature
*@param _hero le pointeur du joueur
*@param _monster le pointeur du monstre qu'il combat
*/
void room(Hero *_hero, Monster *_monster)
{
    string tab[] = {"première", "deuxième", "troisième", "quatrième", "cinquième"};

    Logger::writeBattle("Vous entrez dans la " + tab[nSalle] + " salle du donjon ");

    if (typeid(*_monster) == typeid(Goblin))
    {
        Logger::writeBattle("Vous tombez sur un goblin, préparez-vous au combat ");
    }
    else if (typeid(*_monster) == typeid(Undead))
    {
        Logger::writeBattle("Vous tombez sur un mort-vivant, préparez-vous au combat ");
    }
    else if (typeid(*_monster) == typeid(Azazel))
    {
        Logger::writeBattle("Vous tombez sur Azazel, préparez vous pour votre ultime combat ");
    }
    Sleep(3000);

    //Creation of the fight system
    Battle bataille;
    //start a fight
    bataille.fight(_hero, _monster);
    nSalle++;
    //Once the fight ended the hero rest and heal
    bataille.restsite(_hero);
}
/**
*@brief do a while for the user to choose each stat he wants
*@param tab[] All the stats are in an array
*@param size The total number of stat of the hero(4 warrior, 5 wizard et necromancer)
*/
void whileStat(int tab[], int size)
{
    int total = 0;
    int erreur = 0;
    do
    {
        if (erreur == -1)
        {
            cout << endl
                 << " ERREUR DE SAISIE, Recommencer de distribuer vos compétences " << endl;
        }

        total = 0;
        for (int i = 0; i < size; i++)
        {
            tab[i] = chooseStat(i, total, size);
            total += tab[i];
        }
        erreur = -1; // To know if we repeat the while that their is a mistake
    } while (total != 30);
}
/**
*@brief The player choose his stats
*@param i the actuel stat he is choosing for
*@param tot the total stat point choosed from the start
*@param size The total number of stat of the hero(4 warrior, 5 wizard et necromancer)
*@returns An int with the choosen value for tue actual stat
*/
int chooseStat(int i, int tot, int size)
{
    int status = 0;
    string tab[] = {"Force", "Agilité", "Intelligence", "HP", "Mana"};
    int stat = 0;
    do
    {

        cout << "======================================= " << endl;
        cout << "Vous possèdez " << size << " compétences";
        for (int k = 0; k < size; k++)
        {
            cout << ", " + tab[k];
        }

        cout << ":" << endl
             << "Vous avez dépensé un total de (" << tot << "/"
             << "30) points de compétances " << endl;
        cout << "Choissisez le nombre de point pour: " << tab[i] << "" << endl;
        cout << "======================================= " << endl;
        fflush(stdin);
        status = scanf(" %d", &stat);
        cout << endl;

    } while (not(stat > 1 && status == 1));
    return stat;
}
