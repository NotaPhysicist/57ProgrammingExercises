#include "area.h"

void run(FeetToMeterConvert& converter, Console& console)
{
    // STAGE ONE: Feet to inches. 
    constexpr std::string_view promptLfeet{ 
        "What is the length of the room in feet? " };
    constexpr std::string_view promptWfeet{ 
        "What is the width of the romm in feet " };

    double length_ft = inDimension(promptLfeet, console);
    double width_ft = inDimension(promptWfeet, console);
    

    
    // console.in_Integer("What is the length of the room? ");
    std::println("{} x {} = {}\n", length_ft, width_ft, length_ft * width_ft);
    converter.ftToM(23);
}


int inDimension(std::string_view prompt, Console& console)
{
    // Get a positive integer from the user
    while (!isPositiveInteger(console.in_Integer(prompt)))
    {
        std::println("This applicaiton does not understand negative space. "
            "Please try again.");
    }
    return console.getInput_Integer();
}


bool isPositiveInteger(int n)
{
    return 0 < n;
}


void displayHeader()
{
    std::string title{ "AREA OF A RECTANGLE ROOM"};
    std::string underline(title.size(), '=');
    std::println("\n{}\n{}\n", title, underline);    
}
