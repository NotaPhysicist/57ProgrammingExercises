#include "Console.h"

Console::Console()
{
    input = "";
    input_Integer = 0;
    input_Double = 0.0;
}


std::string Console::getInput()   { return input; }
int Console::getInput_Integer()   { return input_Integer; }
double Console::getInput_Double() { return input_Double; }
char Console::getInput_Char()     { return ch; }


std::string Console::in(std::string_view prompt)
{
    bool done {false};
    while (!done)
    {
        input = "";
        std::print("{}", prompt);
        std::getline(std::cin, input);
        if (!input.empty()) {
            done = true;
        } else {
            std::println("Input cannot by empty. Try again.");
        }
    }
    return input;
}
    

int Console::in_Integer(std::string_view prompt)
{
    bool done{ false };
    while (!done)
    {
        in(prompt);
        // Attempt to convert to an integer
        try
        {
            input_Integer = std::stoi(input);
            done = true;
        }
        catch (const std::invalid_argument&)
        {
            std::println(stderr, "Error: {}", "Not an integer. "
                "Please try again.");
        }
        catch (const std::out_of_range&)
        {
            std::println(stderr, "Error: {}", "The number is out of range. "
                "Please try again.");
        }
        catch (const std::exception& e)
        {
            std::println(stderr, "Unexpected error (well done!): {}", e.what());
        }
    }
    return input_Integer;
}


char Console::in_Char(std::string_view prompt)
{
    /* Allow the use to enter a string of any length, 
     * but all we're after is the first char
     */
    in(prompt);
    ch = input[0];
    return ch;
}


void Console::print(std::string_view s)
{
    std::println("{}", s);
}
