#include "Logger.h"

namespace HE_ARC::RPG
{
    bool Logger::isOk = false;
    int Logger::nbBattles = 0;

    string Logger::pathBin = "";
    string Logger::pathRoot = "";
    string Logger::pathBattles = "";
    string Logger::pathMovements = "";

    string Logger::battleLogName = "";

    /**
     * @brief Constructor of logger
     */
    Logger::Logger()
    {
        // Get the .exe path
        char buffer[MAX_PATH] = "";
        GetModuleFileNameA(NULL, buffer, MAX_PATH);

        string exePath(buffer);
        size_t iBin = exePath.find_last_of("/\\");

        // Get back of one folder - bin folder
        string binPath = exePath.substr(0, iBin);
        Logger::pathBin = binPath + "/";

        // Get the date and time
        time_t now = time(0);
        tm *lTime = localtime(&now);

        if (!exists(Logger::pathBin + DIR_LOG))
        {
            mkdir((Logger::pathBin + DIR_LOG).c_str());
        }
            

        char folderLogName[16];
        sprintf(folderLogName, "%04d%02d%02d_%02d%02d%02d", 1900 + lTime->tm_year, 1 + lTime->tm_mon, lTime->tm_mday, lTime->tm_hour, lTime->tm_min, lTime->tm_sec);

        //string folderLogName = "00001122_334455";

        Logger::pathRoot = Logger::pathBin + DIR_LOG + "/" + folderLogName + "/";
        Logger::pathBattles = Logger::pathRoot + "Battles/";
        //Logger::pathMovements = Logger::pathRoot + "Movements/";

        mkdir(Logger::pathRoot.c_str());

        Logger::isOk = true;

        Logger::writeGame("Initialization completed");
    }

    /**
     * @brief Checks if logger is initialized
     * @returns True if it is
     */
    bool Logger::isInitialized()
    {
        return Logger::isOk;
    }

    /**
     * @brief Write on battle log
     * @param _log The log
     * @param _fileName The file name
     */
    void Logger::writeBattle(string _log, string _fileName)
    {
        if (_fileName != "")
        {
            Logger::battleLogName = _fileName;
            Logger::nbBattles++;
        }

        _fileName = Logger::battleLogName;

        char index[5];
        sprintf(index, "%03d_", Logger::nbBattles);

        Logger::writeLog(Logger::pathBattles, index + _fileName, _log);
    }

    /**
     * @brief Write on game log
     * @param _log The log
     */
    void Logger::writeGame(string _log)
    {
        Logger::writeLog(Logger::pathRoot, "Game.log", _log);
    }


    // =================================================
    // Private Methods
    // =================================================

    /**
     * @brief Creates a new log file
     * @param _path The path
     * @param _fileName The name
     */
    void Logger::createFile(string _path, string _fileName)
    {
        if (!Logger::isOk)
            return;

        if (!Logger::exists(_path))
        {
            if (mkdir(_path.c_str()) != 0)
            {
                cout << "[ERROR : Logger::createFile] Unable to create folder" << endl
                     << "path = " << _path << endl;
                exit(-1);
            }
        }

        if (!Logger::exists(_path + _fileName))
        {
            ofstream file(_path + _fileName);
            file.close();
        }
    }

    /**
     * @brief Tells if a file or folder exists
     * @param _fullPath The path
     * @returns True if it exists
     */
    bool Logger::exists(string _fullPath)
    {
        struct stat buffer;
        return (stat(_fullPath.c_str(), &buffer) == 0);
    }

    /**
     * @brief Write a log in a file
     * @param _fullPath The full path
     * @param _nameFile The file name
     * @param _log The log to write
     */
    void Logger::writeLog(string _fullPath, string _nameFile, string _log)
    {
        if (!Logger::isOk)
            return;

        Logger::createFile(_fullPath, _nameFile);

        time_t now = time(0);
        tm *lTime = localtime(&now);

        char timeLog[9];
        sprintf(timeLog, "%02d:%02d:%02d", lTime->tm_hour, lTime->tm_min, lTime->tm_sec);

        ofstream oFile;
        oFile.open(_fullPath + _nameFile, ios::app);

        oFile << "[" << timeLog << "] " << _log << endl;
        cout << _log << endl;
        oFile.close();
    }
}