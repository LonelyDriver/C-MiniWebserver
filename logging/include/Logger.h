#pragma once
#include <string>

namespace logger{

    enum class Loglevel{ERROR=100, WARN=70, INFO=30, ALL=0};

    class Logger{
    public:
        Logger() = delete;

        static void Error(const std::string& msg);
        static void Warn(const std::string& msg);
        static void Info(const std::string& msg);

        static void SetLoglevel(const Loglevel loglevel);
        static void LogToFile();
        static void LogFile(std::string& filePath);
        static bool FileLogEnabled();
    protected:
        static Loglevel currentLoglvl;
        static bool fileLogging;
        static std::string filePath;

        static std::string formatLog(const std::string& msg, Loglevel loglevel);

        static std::string leveltoString(const Loglevel loglevel);

        static bool logable(Loglevel loglevel);

    };

} // namespace logger

