/*
    STATE ONE:
    Create a program that:

    1. Prompts for a quote and an author
    2. Display the quotation and author
        
        Example outupt:

        What is the quote? These aren't the droids you're looking for. 
        Who said it? Obi-Wan Kenobi 
        Obi-Wan Kenobi says, "These aren't the droids you're looking for."

    Relevent constraints:

    1. Use a single output statement.
    2. Use string-escaping sequences for quotes. 

    Theses were already achieved in the previous program. Ignore. 

    STAGE TWO:
    "Modify this program so that instead of prompting for quotes from the user, 
    you create a structure that holds quotes and their associated attributions 
    and then display all of the quotes using the format in the example. An 
    array of maps would be a good choice."

    Interpetation and Modification:

    1. Read a series of quotes from a file.
    2. Store these quotes a suitable data structure. 
    3. Read the quotes back to the user in the format specified about
    4. End of program. 

    Notes:

    Stage Two to add to Stage One.

    1. Prompt the user for a quote and author. 
    2. Store the response in data structure.
    3. Display the quotation and author.
    4. Read the file of more quotes and author
       An alternative would be to ask the user for more quotes. But this
       would be tedious. 
    5. Store the quotes in the date structure
    6. Read all the quotes back to the user.
    7. End of program. 

    Other Notes:

    Separate console and IO concerns into a view class. Something to develop
    and use as you work though these early console applications. 

    Remember: you have to write a program once to know how you should have 
    written it the first time. 
*/

#include "Console.h"

int main()
{
    Console console;
    std::string line;

    console.newline();
    //console.printline("Enter a string: ");
    //console.getUserInput();
    line = console.getUserInput("Enter a string: ");
    console.printline("You entered: " + line + "\n");
    console.newline();
    
    return 0;
}