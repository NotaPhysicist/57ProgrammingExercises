/*
    Get an input string from the user.
        "What is the input string: Homer"
    If the user enters nothing, inform the user that they are retarded 
    and suggest they try again. 
    Count the number of chars in the string.
    Output the result to the user, with the string in the output
        e.g., "Homer has 5 charcters."

    This exercise asks for simple, procedural code, nothing fancy. 

    Further challenge: 
        - GUI
        - Update character counter each time a key is pressed
 */

#include <iostream>
#include <string>

void newline() { std::cout << "\n"; }  // used to show explicit formatting
void endline() { std::cout << std::endl; }  // to delete the buffer
void printline(std::string s) { std::cout << s; } // why not 

std::string getUserInput();

int main()
{
    // Get the string from the user
    newline();
    printline("COUNT THE LENGTH OF A STRING\n");
    printline("----------------------------\n");
    newline();
    printline("What is the input string: ");
    std::string input = getUserInput();
    
    std::string length = std::to_string(input.length());
    printline("\"" + input + "\"" + " has " + length + " characters.\n");
    newline();
    
    return 0;
}

std::string getUserInput()
{
    std::string input;
    while (true)
    {
        std::getline(std::cin, input);
        
        // Check for an empty string
        if (!input.empty()) {
            return input;
        }
        printline("Input cannot be empty. Try again\n");
    }
}

