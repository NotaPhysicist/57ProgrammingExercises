/*
    Mad Lib. A simple game where you create a story template  with blanks
    for words.

    PLAN:
    
    1. Create a story template (one sentence), with blanks for a noun, verb, 
       adjective and adverb. 
    2. Get from the user:
        A noun:
        A verb:
        An adjective
        An adverb
    3. Put these words into the story.
    4. Display the story.

    RELEVENT CONSTRAINTS:
    
    1. Use a single output statement (constuct a single string to display)
    2. Use string substitution or templating if supported. 

    RELEVENT CHALLENGES:
    
    1. Make it more complex. Branch into alternate storylines. Add More story. 
       But this is too tedius. 
    2. This project is about templating and strings. 
*/

#include <iostream>
#include <format>

std::string getUserInput(std::string prompt);

void printline(std::string line) { std::cout << line; }
void newline() { std::cout << "\n"; }  // explicit formatting


int main()
{
    struct Blank
    {
        std::string noun;
        std::string verb;
        std::string adjective;
        std::string adverb;
    } blank; 
    
    // Create the story template
    // Orginal: ""Why do you walk your dog quickly?""
    // std::string storyTemplate;
    // storyTemplate = std::format("Why do you {} your {} {} {}?\n",
    //     blank.verb,        
    //     blank.noun,        
    //     blank.adjective,   
    //     blank.adverb      
    // );

    newline();
    printline("MAD LIB\n");
    printline("Enter some random words and get back a hilarious story.\n");
    newline();
       
    // Get the words from the user
    blank.noun = getUserInput("Enter a noun: ");
    blank.verb = getUserInput("Enter a verb: ");
    blank.adjective = getUserInput("Enter an adjective: ");
    blank.adverb = getUserInput("Enter an adverb: ");
    newline();
    
    // Put these words into the story and display the result.
    printline(std::format("Why do you {} your {} {} {}?\n",
        blank.verb, blank.noun, blank.adjective, blank.adverb));
    newline();
}

std::string getUserInput(std::string prompt)
{
    std::string input = "";
    bool done {false};  // flag to indicate a successful input
    // Guard against empty input
    while (!done)
    {
        printline(prompt);
        std::getline(std::cin, input);
        if (!input.empty()) {
            done = true;
        } 
        else
        {
            printline("Input cannot be empty. Please try again.\n");
            printline(prompt);
        }
    }
    return input;
}

