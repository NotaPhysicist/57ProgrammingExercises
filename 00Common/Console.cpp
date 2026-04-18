#include "Console.h"

/**
 * Constructor.
 * 
 * @param string (optional) the string to store in this instance. Defaults to 
 *               an empty string
 */
Console::Console(std::string s) { str = s; }

/**
 * Get the string stored in this instance. 
 * 
 * @return the string stored
 * 
 * Haven't found a use for this member yet, just kind of threw it in, kitchen 
 * sink style. 
 */
std::string Console::getString() const { return str; }

/**
 * Set the string stored in the console instance
 * 
 * @return the string stored in this instance
 * 
 * Haven't found a use for this member yet, just kind of threw it in, kitchen 
 * sink style. 
 */
void Console::setString(std::string s) { str = s; }

/**
 * Display a blank line. 
 * 
 * Generally used for additional blank lines for presentational purposes. Not 
 * intended to replace normal end of line newlines. 
 */
void Console::newline() { std::cout << "\n"; }

/**
 * Display n blank lines.
 * 
 * @param int the number of blank lines to display
 * 
 * Generally used for additional blank lines for presentational purposes. Not 
 * intended to replace normal end of line newlines.
 */
void Console::newline(int n)
{
    if (n > 0 && n < 100) {
        for (int i = 0; i < n; i++) {
            std::cout << "\n";
        }
    }
}

/**
 * Display the std::endl character.
 * 
 * Intended to replace standalone calls to std::cout << endl.
 */
void Console::endline() { std::cout << std::endl; }

/**
 * Display a line of text.
 * 
 * @param string line of text to display
 */
void Console::printline(const std::string line) const
{
    std::cout << line;
}

/**
 * Display an error message.
 * 
 * @param string message to display
 */
void Console::printerror(const std::string line) const
{
    std::cerr << line;
}

/**
 * Get a string from the user.
 * 
 * @return the string entered by the user
 */
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

/**
 * Prompt the user for input. Get a string from the user.
 * 
 * @param string to display to the user
 * @return the string entered by the user
 */
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
