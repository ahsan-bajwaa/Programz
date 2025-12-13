#include <iostream>
using namespace std;

class Logger
{
private:
    static int message_count;

public:
    static void logger(const string &message)
    {
        cout << "Log: " << message << endl;
        message_count++;
    }

    static void show_count()
    {
        cout << "Total messages logged: " << message_count << endl;
    }
};

int Logger::message_count = 0;

int main()
{
    Logger::logger("Starting system...");
    Logger::logger("System running...");
    Logger::logger("System shutting down...");

    Logger::show_count();
    return 0;

    /*
    Reason:
    -> Static functions can only access static data.
    -> They don’t belong to any one object, so they can’t 
        see non-static members directly.
        */
}
