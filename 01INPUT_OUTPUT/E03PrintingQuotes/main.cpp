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

    Separate IO concerns into a view class. Something to develop
    and use as you work though these early console applications. 

    Remember: you have to write a program once to know how you should have 
    written it the first time. 
*/

#include "Console.h"
#include <fstream>
#include <string>
#include <vector>

struct quotation
{
    std::string quote;
    std::string author;
};

std::string formatQuote(const quotation q);
std::string formatQuote(std::string quote, std::string author);

int main()
{
    Console console;
    
    // Diplay program title
    console.newline();
    console.printline("PRINTING QUOTES\n");
    console.printline("---------------\n");
    

    /***************************************************
     STAGE ONE
     ***************************************************/
    console.newline();
    console.printline("STAGE ONE\n");
    
    // Get a quote and author from the user.
    // Store the repsonse
    quotation qu;
    console.newline();
    qu.quote = console.getUserInput("What is the quote: ");
    qu.author = console.getUserInput("Who said it? ");
    
    // Display the quotation and author
    console.printline(formatQuote(qu));
    

    /***************************************************
     STAGE TWO. Challenge
     ***************************************************/
    console.newline();
    console.printline("STAGE TWO\n");
    
    /*
    *  The quotes are in a text file the format:
    *      <quote>
    *      <author>
    *      <quote>
    *      <author>
    *      ...
    * 
    * A JSON-like format would be better but, baby steps, baby steps. 
    */
   
    // Ask the user for a filename (because, why not?)
    console.newline();
    std::string inData = console.getUserInput("Enter a filename: ");
   
    // Open the data file. 
    std::ifstream file;
    file.open(inData);
    if (!file.is_open()) 
    {    
        console.printerror("Error opening file: " + inData);
        return 1;
    }

   /*
    * To KIS, read the quotes and authors into two parallel vector arrays,
    * for now. Creating an ADT to store quote objects is inviting,  
    * but it is two complex right now for my tiny, still learning, brain. 
    */

    // Import the data.
    std::vector<std::string> quote; 
    std::vector<std::string> author; 
    std::string line;
    bool even = false;  // flag to alternate which array to push to 

    while (std::getline(file, line))
    {
        if (even) 
        {
            author.push_back(line);
            even = false;
        }
        else
        {
            quote.push_back(line);
            even = true;
        }
    }

    // Display the quotes.
    for (unsigned long i = 0; i < quote.size(); i++) {
        console.printline(formatQuote(quote[i], author[i]));
    }
    console.newline();
    
    return 0;
}


std::string formatQuote(const quotation q)
{
    return (q.author +  " said, \"" + q.quote + ".\"\n");
}


std::string formatQuote(std::string quote, std::string author)
{
    return (author +  " said, \"" + quote + ".\"\n");
}



