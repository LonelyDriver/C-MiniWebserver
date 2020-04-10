#include "Logger.h"
using logger::Logger;
int main() {
    Logger::Info("Loggingngng");
    Logger::Info("Logging is working" + std::to_string(1337));
    Logger::Warn("Warning");
    Logger::Error("EROOOOOOR");

    Logger::LogToFile();
    Logger::Info("Write to file");
    Logger::SetLoglevel(logger::Loglevel::WARN);
    Logger::Info("Infoooo");

    return 0;
}