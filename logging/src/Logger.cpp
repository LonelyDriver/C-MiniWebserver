#include "Logger.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>

// standard loglevel
logger::Loglevel logger::Logger::currentLoglvl = logger::Loglevel::INFO;
// log in file
bool logger::Logger::fileLogging = false;
// file path
std::string logger::Logger::filePath = "logging.log";

void logger::Logger::Info(const std::string& msg)
{
    if(logable(logger::Loglevel::INFO) == true){
        if(FileLogEnabled()){
            try{
                std::ofstream ostream;
                ostream.open(filePath, std::ios::out | std::ios::app);
                ostream << formatLog(msg, logger::Loglevel::INFO) << std::endl;
                ostream.close();
            } catch(std::exception& e){
                std::cout << e.what() << std::endl;
            }
        }
        std::cout << formatLog(msg, logger::Loglevel::INFO) << std::endl;
    }
}

void logger::Logger::Warn(const std::string& msg)
{
    if(logable(logger::Loglevel::WARN) == true){
        if(FileLogEnabled()){
            try{
                std::ofstream ostream;
                ostream.open(filePath, std::ios::out | std::ios::app);
                ostream << formatLog(msg, logger::Loglevel::WARN) << std::endl;
                ostream.close();
            } catch(std::exception& e){
                std::cout << e.what() << std::endl;
            }
        }
        std::cout << formatLog(msg, logger::Loglevel::WARN) << std::endl;
    }
}

void logger::Logger::Error(const std::string& msg)
{
    if(logable(logger::Loglevel::ERROR) == true){
        if(FileLogEnabled()){
            try{
                std::ofstream ostream;
                ostream.open(filePath, std::ios::out | std::ios::app);
                ostream << formatLog(msg, logger::Loglevel::ERROR) << std::endl;
                ostream.close();
            } catch(std::exception& e){
                std::cout << e.what() << std::endl;
            }
        }
        std::cout << formatLog(msg, logger::Loglevel::ERROR) << std::endl;
    }
}

std::string logger::Logger::leveltoString(const Loglevel loglevel){
    if(loglevel == Loglevel::ERROR){
        return "[ERROR] ";
    }
    else if(loglevel == Loglevel::WARN){
        return "[WARN] ";
    }
    else if(loglevel == Loglevel::INFO){
        return "[INFO] ";
    }
    else{
        throw(std::invalid_argument("Invalid loglevel"));
    }

}
void logger::Logger::SetLoglevel(const Loglevel loglevel){
    currentLoglvl = loglevel;
}

/**
 *  Ist logging zulässig?
 */ 
bool logger::Logger::logable(Loglevel loglevel){
    return loglevel >= currentLoglvl;
}

void logger::Logger::LogToFile(){
    fileLogging = !fileLogging;
}

bool logger::Logger::FileLogEnabled(){
    return fileLogging;
}

std::string logger::Logger::formatLog(const std::string& msg, Loglevel loglevel){
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    std::stringstream s;
    s << std::put_time(std::localtime(&now), "%Y-%m-%d %X") << " ";
    s << leveltoString(loglevel);
    s << msg;
    return s.str();
}
