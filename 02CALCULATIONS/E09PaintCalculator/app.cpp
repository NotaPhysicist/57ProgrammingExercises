#include "app.h"

void run([[maybe_unused]] Console& console)
{
    // Display the program title and introduction
    std::println("{}", makeTitle());
    
    // object templete
    ShapeCollection collection;

    collection.add<Rectangle>(3500, 4800);
    collection.add<Circle>(3200);


    // Run the program until the user quits. 
    bool done{ false };
    while (!done)
    {
        std::string response = console.in("Is the shape a [c]ircle or a [r]ectangle?");
        char choice = std::tolower(response[0]);
        switch (choice)
        {
            case 'r': // rectangle
                std::println("You entered {} for rectangle", choice);
                break;
                case 'c': // circle
                std::println("You entered {} for circle", choice);
                break;
                case 'd': // done
                std::println("You entered {} for done", choice);
                done = true;
                break;
                case 'e': // exit
                std::println("You entered {} for exit", choice);
                break;
                default:  // invalid response
                std::println("You entered {} for whatthefuck", choice);
                break;
        }
        
        


        /*
        "Lenth: "
        "Width:"
        
        "Diameter:"
        
        "Area of {} entered: ";
        "Total area, so far: {}";
        "Litres of paint required, so far: {}";
        */
        
        // Diplay the menu
        // Get user choice. 
        // Depending on the choice, get measurements from the user
        // Calculate the area
        // Display the result
        // Ask the user for a new measurement, or exit the program. 
    }
}


bool signal(std::string_view s, char flag) 
{
    return (std::tolower(s[0]) == flag) ? true : false;
}

bool signal_Exit(std::string_view s) { return signal(s, 'e'); }
bool signal_Done(std::string_view s) { return signal(s, 'd'); }
bool signal_Circle(std::string_view s) { return signal(s, 'c'); }
bool signal_Rectangle(std::string_view s) { return signal(s, 'r'); }


std::string makeTitle()
{    
    const std::string title  { "PAINT CALCULATOR" };
    const std::string subtitle{ "Project-9 from: Hogan. 2015. (57) Exercises for Programmers"};
    // const int length{ static_cast<int>(subtitle.length()) / 2 }; 
    const std::string space((subtitle.size() / 4), ' ');
    
    const std::string introduction{
        "Estimate the amout of paint required to paint a ceiling. If\n"
        "the area is more than a single rectangle or circle shape,\n"
        "then break the area into multiple shapes and enter them one\n"
        "at a time.\n\n"
        "All measurements are in millimaters (mm).\n"
        "Type 'done' to calculate the total area, or\n"
        "type 'exit' to quit the program."
    };
    return std::format("\n{}=== {} ===\n\n{}\n\n{}", space, title, subtitle, introduction);
}



