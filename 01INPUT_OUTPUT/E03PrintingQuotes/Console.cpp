#include "Console.h"

Console::Console(std::string s) { str = s; }


std::string Console::getString() const { return str; }


void Console::setString(std::string s) { str = s; }


void Console::newline() { std::cout << "\n"; }


void Console::newline(int n)
{
    if (n > 0 && n < 100) {
        for (int i = 0; i < n; i++) {
            std::cout << "\n";
        }
    }
}


void Console::endline() { std::cout << std::endl; }


void Console::printline(const std::string line) const
{
    std::cout << line;
}


std::string Console::getUserInput()
{
    std::string input;
    bool done {false};
    while (!done) {
        std::getline(std::cin, input);
        if (!input.empty()) {
            str = input;  
            done = true;
        } else {
            printline("Input cannot be empty. Try again.\n");
            printline("> ");
        }
    }
    
    return input;
}


std::string Console::getUserInput(std::string prompt)
{
    std::string input;
    bool done {false};
    while (!done) {
        printline(prompt);
        std::getline(std::cin, input);
        if (!input.empty()) {
            str = input; 
            done = true;
        } else {
            printline("Input cannot be empty. Try again.\n");
            printline(prompt);
        }
    }
    
    return input;
}
