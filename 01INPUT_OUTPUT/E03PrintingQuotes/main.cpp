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

void getQuoteAndAuthor(Console& console);

int main()
{
    Console console;
    
    // Diplay program title
    console.newline();
    console.printline("PRINTING QUOTES\n");
    console.printline("---------------\n");
    console.newline();

    /***************************************************
     STAGE ONE
     ***************************************************/
    
    // Get a quote and author from the user.
    getQuoteAndAuthor(console);
    
    // Store the repsonse 
    // Display the quotation and author
    
    /***************************************************
     STAGE TWO. Challenge
     ***************************************************/
    
    
    return 0;
}

/**
 * Get a single quote and author from the user.
 */
void getQuoteAndAuthor(Console& console)
{
    std::string quote;
    std::string author;

    quote = console.getUserInput("What is the quote: ");
    author = console.getUserInput("Who said it? ");
    console.newline();
}