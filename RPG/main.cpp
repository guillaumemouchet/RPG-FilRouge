#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <fstream>

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

using namespace std;
using namespace HE_ARC::RPG;

int nSalle = 0;

//c'est ce qui commence les combats
void Room(Hero *_hero, Monster *_monster);

//fais la boucle pour choisir les stats
void WhileStat(int tab[], int size);
//faire le choix des stats
int Stat(int i, int tot, int size);

//Valeur clobal pour avoir les actions en erreur de base (souvent compris entre 0 et x)
int action = -1;

int main()
{
    //string const nomFichier("C:\\DEV\\cpp_filrouge_iscc_mouchetg\\log.txt");
    //ofstream cout(nomFichier.c_str());

    //Création des Monstres pour les combats (les monstres sont soigné en fin de combat)
    Goblin *ptrG1 = new Goblin(3, 3, 3, 60);
    Undead *ptrU1 = new Undead(4, 4, 4, 80);
    Azazel *ptrA = new Azazel(6, 6, 6, 150);

    //Valeur par défaut des objects pour les personnages
    Sword *ptrS = new Sword(5);
    Potion *ptrP = new Potion(5);
    Shield *ptrSh = new Shield(5);

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
    if (action == 0)
    {
        int statSize = 4;
        int tab[statSize];
        WhileStat(tab, statSize);

        Warrior *hero = new Warrior(tab[0], tab[1], tab[2], (tab[3] * 10.0), "Chandra", ptrSh);
        //Stockage d'objet par défaut
        hero->backpack.pack(new Sword(3));
        hero->backpack.pack(new Potion(3));

        hero->show();
        //Combat de goblin
        Room(hero, ptrG1);
        //Combat de mort-vivant
        Room(hero, ptrU1);
        //Combat de Boss contre Azazel
        Room(hero, ptrA);
    }
    else if (action == 1)
    {
        int statSize = 5;
        int tab[statSize];
        WhileStat(tab, statSize);
        Wizard *hero = new Wizard(tab[0], tab[1], tab[2], (tab[3] * 10.0), "Jace", ptrS, (tab[4] * 10));
        //Stockage d'objet par défaut
        hero->backpack.pack(new Shield(3));
        hero->backpack.pack(new Potion(3));
        //Combat de goblin
        Room(hero, ptrG1);
        //Combat de mort-vivant
        Room(hero, ptrU1);
        //Combat de Boss contre Azazel
        Room(hero, ptrA);
    }
    else if (action == 2)
    {
        int statSize = 5;
        int tab[statSize];
        WhileStat(tab, statSize);
        Necromancer *hero = new Necromancer(tab[0], tab[1], tab[2], (tab[3] * 10.0), "Liliana", ptrS, (tab[4] * 10));
        //Stockage d'objet par défaut
        hero->backpack.pack(new Shield(3));
        hero->backpack.pack(new Potion(3));
        //Combat de goblin
        Room(hero, ptrG1);
        //Combat de mort-vivant
        Room(hero, ptrU1);
        //Combat de Boss contre Azazel
        Room(hero, ptrA);
    }
}
void Room(Hero *_hero, Monster *_monster)
{
    string tab[] = {"première", "deuxième", "troisième", "quatrième"};
    cout << "Vous entrez dans la " << tab[nSalle] << " salle du donjon" << endl;
    if (typeid(*_monster) == typeid(Goblin))
    {
        cout << "Vous tombez sur un goblin, préparez-vous au combat" << endl;
    }
    else if (typeid(*_monster) == typeid(Undead))
    {
        cout << "Vous tombez sur un mort-vivant, préparez-vous au combat" << endl;
    }
    else if (typeid(*_monster) == typeid(Azazel))
    {
        cout << "Vous tombez sur Azazel, préparez vous pour votre ultime combat" << endl;
    }
    //création du système de combat
    Battle bataille;
    //Combat
    bataille.Fight(_hero, _monster);
    nSalle++;
    //Une fois le combat fini le héro se repose
    bataille.Restsite(_hero);
}
void WhileStat(int tab[], int size)
{
    int total = 0;
    int erreur = 0;
    do
    {
        if (erreur == -1)
        {
            cout << endl
                 << "ERREUR DE SAISIE, Recommencer de distribuer vos compétences" << endl
                 << endl;
        }

        total = 0;
        for (int i = 0; i < size; i++)
        {
            tab[i] = Stat(i, total, size);
            total += tab[i];
        }
        erreur = -1; // comme ça si on répère le while on sait si c'était une erreur ou non;
    } while (total != 30);
}

int Stat(int i, int tot, int size)
{
    int status = 0;
    string tab[] = {"Force", "Agilité", "Intelligence", "HP", "Mana"};
    int stat = 0;
    do
    {
        cout << "=======================================" << endl;
        cout << "Vous possèdez " << size << " compétences";
        for (int k = 0; k < size; k++)
        {
            cout << ", " << tab[k];
        }

        cout << ":" << endl
             << "Vous avez dépensé un total de (" << tot << "/"
             << "30) points" << endl;
        cout << "Choissisez le nombre de point pour: " << tab[i] << endl;
        cout << "=======================================" << endl;
        fflush(stdin);
        status = scanf(" %d", &stat);
        cout << endl;
    } while (status != 1);
    return stat;
}