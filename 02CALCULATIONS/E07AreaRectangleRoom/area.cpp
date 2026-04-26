#include "area.h"

void run(FeetToMeterConvert& converter, Console& console)
{
    // STAGE ONE: Feet to inches. 
    constexpr std::string_view promptLfeet{ 
        "What is the length of the room in feet? " };
    constexpr std::string_view promptWfeet{ 
        "What is the width of the room in feet? " };

    // Get dimensions from the user
    double length_ft = inDimension(promptLfeet, console);
    double width_ft = inDimension(promptWfeet, console);
    
    // Calculations
    double length_m = converter.ftToM(length_ft);
    double width_m = converter.ftToM(width_ft);
    double area_ft = length_ft * width_ft;
    double area_m = length_m + width_m;
    
    // Display the result
    std::println("You entered dimensions of {} feet by {} feet.", 
        length_ft, width_ft);
    std::println("These are equivalent to {:.2f} by {:.2f} meters.", 
        length_m, width_m);
    std::println("The area is:");
    std::println("    {} square feet", area_ft);
    std::println("    {:.2f} square meters\n", area_m);

    // std::println("\nTESTS:");
    // std::println("{} x {} = {}", length_ft, width_ft, area_ft);
    // std::println("{} x {} = {}\n", length_m, width_m, area_m);
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
    std::println("\n{}\n{}\n{}\n", underline, title, underline);    
}
