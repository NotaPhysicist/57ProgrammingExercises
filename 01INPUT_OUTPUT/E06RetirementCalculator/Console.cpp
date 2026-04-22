#include "Console.h"

Console::Console()
{ 
    str = ""; 
}


void Console::newlines(int n, int max)
{
    if (0 < n && n < max) {
        for (int i = 0; i < n; i++) {
            printline("\n");    
        }
    }
}


void Console::endline() { std::cout << std::endl; }


void Console::println(const std::string line) const { std::cout << line; };


void Console::printline(const std::string line) const
{ 
    std::cout << line << "\n"; 
};


void Console::printerror(const std::string line) const
{
    std::cerr << line << "\n";
}


std::string Console::getUserString(std::string prompt)
{
    std::string input;
    bool done {false};
    while (!done)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!input.empty()) 
        {
            str = input; 
            done = true;
        } 
        else 
        {
            printline("Input cannot be empty. Try again.");
            std::cout << prompt;
        }
    }
    return input;
}


int Console::getUserInteger(std::string prompt)
{
    std::string input{};
    bool done {false};
    int value{};
    while (!done)
    {
        input = getUserString(prompt);
        // Safe int to string conversion
        try 
        {
            value = std::stoi(input);
            done = true;
        } catch (const std::invalid_argument&) {
            printerror("Invalid input: not an integer. Please try again.");
        } catch (const std::out_of_range&) {
            printerror("Invalid input: the number is out of range. Please try again.");
        }
    }
    return value;
}



