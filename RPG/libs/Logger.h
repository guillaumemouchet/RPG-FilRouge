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

        static string battleLogName;

        /**
        * @brief Tells if a file or folder exists
        * @param _fullPath The path
        * @returns True if it exists
        */
        static bool exists(string _fullPath);
        /**
        * @brief Write a log in a file
        * @param _fullPath The full path
        * @param _nameFile The file name
        * @param _log The log to write
        */
        static void writeLog(string _fullPath, string _nameFile, string _log);
        /**
        * @brief Creates a new log file
        * @param _path The path
        * @param _fileName The name
        */
        static void createFile(string _path, string _fileName);
        

    public:
        /**
        * @brief Constructor of logger
        */
        Logger();
        /**
        * @brief Checks if logger is initialized
        * @returns True if it is
        */
        static bool isInitialized();
        /**
        * @brief Write on battle log
        * @param _log The log
        * @param _fileName The file name
        */
        static void writeBattle(string _log, string _fileName = "");
        /**
        * @brief Write on game log
        * @param _log The log
        */
        static void writeGame(string);
    };
}

#endif
