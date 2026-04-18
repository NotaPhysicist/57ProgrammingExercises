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

struct Blank
{
    std::string noun;
    std::string verb;
    std::string adjective;
    std::string adverb;
};

int main()
{
    std::string storyTemplate;
    Blank blank;
    
    // Create the story template
    // Orginal: ""Why do you walk your dog quickly?""
    storyTemplate = std::format("Why do you {1} your {0} {2} {3}?",
        blank.noun,        // 0
        blank.verb,        // 1
        blank.adjective,   // 2
        blank.adverb       // 3
    );
       
    // Get the words from the user
    // Put these words into the story and display the result.
}