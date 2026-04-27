#include "area.h"

// STAGE TWO: Choose feet or inches for input
void run(FeetToMeterConvert& converter, Console& console)
{
    constexpr std::string_view prompt_FeetOrMeters {
        "What unit are you measuring in: [f]eet or [m]eters? " };
    constexpr std::string_view prompt_LenghtFeet{ 
        "What is the length of the room in feet? " };
    constexpr std::string_view prompt_WidthFeet{ 
        "What is the width of the room in feet? " };
    constexpr std::string_view prompt_LenghtMeters{ 
        "What is the length of the room in meters? " };
    constexpr std::string_view prompt_WidthMeters{ 
        "What is the width of the room in meters? " };

    double length_ft{};
    double length_m{};
    double width_ft{};
    double width_m{};
    
    // Get the choice or units fromt the user
    char choice = inUnitChoice(prompt_FeetOrMeters, console);
    switch (choice)
    {
        case 'f':  // feet
            // Get dimensions from the user
            length_ft = inDimension(prompt_LenghtFeet, console);
            width_ft = inDimension(prompt_WidthFeet, console);
            length_m = converter.ftToM(length_ft);
            width_m = converter.ftToM(width_ft);
            std::println("\nYou entered dimensions of {} feet by {} feet.", 
                length_ft, width_ft);
            std::println("These are equivalent to {:.2f} by {:.2f} meters.", 
                length_m, width_m);
            break;
        case 'm':  // meters
            length_m = inDimension(prompt_LenghtMeters, console);
            width_m = inDimension(prompt_WidthMeters, console);
            length_ft = converter.mToFt(length_m);
            width_ft = converter.mToFt(width_m);
            std::println("\nYou entered dimensions of {:.2f} meters by {:.2f} meters.", 
                length_m, width_m);
            std::println("These are equivalent to {:.2f} feet by {:.2f} feet.", 
                length_ft, width_ft);
            break;
        default:   // unknown error
            std::println("Unknown error: program terminated.");
            return;
    }
            
    // Calculations
    double area_ft = length_ft * width_ft;
    double area_m = length_m + width_m;
    
    // Display the result
    
    // Display area results
    std::println("The area is:");
    std::println("    {:.2f} square feet", area_ft);
    std::println("    {:.2f} square meters\n", area_m);

    // Display tests while developing. 
    // std::println("\nTESTS:");
    // std::println("{} x {} = {}", length_ft, width_ft, area_ft);
    // std::println("{} x {} = {}", length_m, width_m, area_m);
    // std::println("choice: {}\n", choice);
}


int inUnitChoice(std::string_view prompt, Console& console)
{
    constexpr char choice_Ft = 'f';
    constexpr char choice_M  = 'm';
    
    char choice{};
    bool done{ false };
    while (!done)
    {
        choice = console.in_Char(prompt);
        choice = tolower(choice);
        switch (choice)
        {
            case choice_Ft: 
            case choice_M:
                done = true;
                break;
            default:
                std::println(
                    "{} is not a valid choice. "
                    "Please choose between [f]eeet or [m]eters.",
                    choice
                );
                break;
        }
    }
    return choice;
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
    std::string title{ " AREA OF A RECTANGLE ROOM "};
    std::string underline(title.size(), '=');
    std::println("\n{}\n{}\n{}\n", underline, title, underline);    
}
