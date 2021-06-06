#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <windows.h>

#include <sys/stat.h>
#include <iomanip>

using namespace std;

namespace HE_ARC::RPG
{
    class Logger
    {
    private:
        static bool isOk;
        static int nbBattles;

        const string DIR_LOG = "logs";
        static string pathBin;

        static string pathRoot;
        static string pathBattles;
        static string pathMovements;

        static string battleLogName;

        static bool exists(string _fullPath);
        static void writeLog(string _fullPath, string _nameFile, string _log);
        static void createFile(string _path, string _fileName);
        

    public:
        Logger();
        
        static bool isInitialized();
        static void writeBattle(string _log, string _fileName = "");
        static void writeGame(string);
    };
}

#endif
/*#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>
using namespace std;
namespace HE_ARC::RPG
{
    class Log
    {
    private:
        string File = "C:\\DEV\\cpp_filrouge_iscc_mouchetg\\RPG\\log.txt";

    public:
        Log() = default;
        void print(string str)
        {
             
            ofstream oFile;
            oFile.open(File, ios::app);
            if (oFile)
            {
                time_t now = time(0);
        tm *lTime = localtime(&now);

        char timeLog[9];
        sprintf(timeLog, "%02d:%02d:%02d", lTime->tm_hour, lTime->tm_min, lTime->tm_sec);
                
                cout << str;
                oFile <<"[" <<timeLog << "]" << endl <<str;
                
            }
            else
            {
                cout << "erreur" << endl;
            }
            oFile.close();
            
        }
        int read(int action, int status)
        {
            string const nomFichier(File);
            ofstream flux(nomFichier.c_str());
            if (flux)
            {
                fflush(stdin);
                int status = scanf("%d", &action);
                flux << action;
                print("\n");
            }
            else
            {
                cout << "erreur" << endl;
            }
            flux.close();
            return status;
        }
    };
}
#endif*/