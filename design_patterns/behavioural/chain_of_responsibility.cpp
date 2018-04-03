#include <iostream>
#include <string>

using namespace std;

class Logger {
public:
    enum Level {DEBUG = 3, INFO = 2, ERROR = 1};
private:
    Level level;
    Logger * nextLogger;

public:
    Logger(Level level) : level(level) {}

    void setNextLogger(Logger * logger) {
        nextLogger = logger;
    }

    void logMessage(int lvl, const string & msg) const {
        if(level >= lvl) {
            this->write(msg);
        }
        if(nextLogger != nullptr) {
            nextLogger->logMessage(lvl, msg);
        }
    }

    virtual void write(const string & msg) const = 0;
};

class ConsoleLogger : public Logger {
public:
    ConsoleLogger(Level level) : Logger(level) {}

    void write(const string & msg) const {
        cout << "Wrote to console: " << msg << endl;
    }
};

class FileLogger : public Logger {
public:
    FileLogger(Level level) : Logger(level) {}

    void write(const string & msg) const {
        cout << "Wrote to file: " << msg << endl;
    }
};

int main(){
    auto logger1 = new ConsoleLogger(Logger::Level(2));
    auto logger2 = new FileLogger(Logger::Level(1));
    logger1->setNextLogger(logger2);

    logger1->logMessage(3, "A debug message");
    logger1->logMessage(2, "An info message");
    logger1->logMessage(1, "An error message");
}