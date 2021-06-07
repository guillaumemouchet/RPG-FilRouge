#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <fstream>
#include <windows.h>

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
#include "libs\actors\include\Azazel.h"

//inclusions du sytème de combat
#include "libs\Battle.h"
#include "libs\Logger.h"
#include "libs\Enum.h"

using namespace std;
using namespace HE_ARC::RPG;

void room(Hero *_hero, Monster *_monster);

void whileStat(int tab[], int size);

int chooseStat(int i, int tot, int size);

//Valeur global pour le numéro de la salle
int nSalle = 0;

int main()
{
    Logger mylog;
    //Création des Monstres pour les combats (les monstres sont soigné en fin de combat)
    Goblin *ptrG1 = new Goblin(3, 3, 3, 60);
    Undead *ptrU1 = new Undead(4, 4, 4, 80);
    Azazel *ptrA = new Azazel(6, 6, 6, 150);

    //Valeur par défaut des objects pour les personnages
    int oDefault = 3;
    Sword *ptrS = new Sword(oDefault);
    Potion *ptrP = new Potion(oDefault);
    Shield *ptrSh = new Shield(oDefault);

    //sélection de la classe
    int status = 0;
    int action = -1;
    do
    {
        cout << "======================================= " << endl;
        cout << "Veuillez selectionner votre classe, cela déterminera vos attaques" << endl;
        cout << "["<<warrior<<"] Warrior" << endl;
        cout << "["<<wizard<<"] Wizard" << endl;
        cout << "["<<necromancer<<"] Necromancer " << endl;
        cout << "======================================= " << endl;

        fflush(stdin);
        status = scanf("%d", &action);
        cout << endl;

    } while (not(0 <= action && action <= 2 && status == 1));

    cout << "======================================= " << endl;
    cout << "BRAVO, Vous avez crée votre premier héro! " << endl;
    cout << "======================================= " << endl;

    //Création du personnage en fonction de sa classe
    if (action == warrior)
    {
        Logger::writeGame("Vous avez choisi un Warrior");

        int StatSize = 4;
        int tab[StatSize];
        whileStat(tab, StatSize);

        Warrior *hero = new Warrior(tab[0], tab[1], tab[2], (tab[3] * 10.0), "Chandra", ptrSh);

        //Stockage d'objet par défaut
        hero->backpack.pack(new Sword(oDefault));
        hero->backpack.pack(new Potion(oDefault));
        //on affiche le héro
        hero->show();
        //Combat de goblin
        room(hero, ptrG1);
        //Combat de mort-vivant
        room(hero, ptrU1);
        //Combat de Boss contre Azazel
        room(hero, ptrA);
    }
    else if (action == wizard)
    {
        Logger::writeGame("Vous avez choisi un Wizard");
        int StatSize = 5;
        int tab[StatSize];
        whileStat(tab, StatSize);
        Wizard *hero = new Wizard(tab[0], tab[1], tab[2], (tab[3] * 10.0), "Jace", ptrS, (tab[4] * 10));

        //Stockage d'objet par défaut
        hero->backpack.pack(new Shield(oDefault));
        hero->backpack.pack(new Potion(oDefault));

        //on affiche le héro
        hero->show();
        //Combat de goblin
        room(hero, ptrG1);
        //Combat de mort-vivant
        room(hero, ptrU1);
        //Combat de Boss contre Azazel
        room(hero, ptrA);
    }
    else if (action == necromancer)
    {
        Logger::writeGame("Vous avez choisi un Necromancer");
        int StatSize = 5;
        int tab[StatSize];
        whileStat(tab, StatSize);
        Necromancer *hero = new Necromancer(tab[0], tab[1], tab[2], (tab[3] * 10.0), "Liliana", ptrS, (tab[4] * 10));

        //Stockage d'objet par défaut
        hero->backpack.pack(new Shield(oDefault));
        hero->backpack.pack(new Potion(oDefault));

        //on affiche le héro
        hero->show();

        //Combat de goblin
        room(hero, ptrG1);

        //Combat de mort-vivant
        room(hero, ptrU1);

        //Combat de Boss contre Azazel
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

    //création du système de combat
    Battle bataille;
    //Combat
    bataille.fight(_hero, _monster);
    nSalle++;
    //Une fois le combat fini le héro se repose
    bataille.restsite(_hero);
}
/**
*@brief fait une boucle pour le choix des compétences
*@param tab[] les différentes compétences rangée dans un tableau
*@param size le nombre de compétence du héro (4 warrior, 5 wizard et necromancer)
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
        erreur = -1; // comme ça si on répère le while on sait si c'était une erreur ou non;
    } while (total != 30);
}
/**
*@brief Le joueur fait sa séléction de compétences
*@param i la compétence "active"
*@param tot la valeur total des points distribué
*@param size le nombre de compétence du héro (4 warrior, 5 wizard et necromancer)
*@returns un entier représentant la valeur choisie
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

        cout <<":" << endl<<"Vous avez dépensé un total de (" << tot << "/"
             << "30) points de compétances " << endl;
        cout << "Choissisez le nombre de point pour: " << tab[i] << "" << endl;
        cout << "======================================= " << endl;
        fflush(stdin);
        status = scanf(" %d", &stat);
        cout << endl;

    } while (not(stat > 1 && status == 1));
    return stat;
}
