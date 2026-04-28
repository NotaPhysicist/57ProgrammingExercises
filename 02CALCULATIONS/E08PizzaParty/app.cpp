#include "app.h"

void run(Console& console, Calculator& calculator)
{
    // Display program header
    std::string header{ getProgramTitle() };
    std::println("{}\n", header);
    
    // Get calulation parameters from the user
    int n_People { 
        getValidQuantity(console, 
            "How many people? ", 
            "We need at least one person to have a party. Please try again."
        ) 
    };
    int n_Pizzas {
        getValidQuantity(console,
            "How many pizzas do you have? ",
            "We need at list one pizza to have a pizza party. Please try again"
        )
    };
    
    // Calulate the results
    calculator.calculateSlicesPerPerson(n_People, n_Pizzas);
    int slicesPerPerson = calculator.getSlicesPerPerson();
    int slicesRemaining = calculator.getSlicesRemaing();    
    
    // Display the results
    std::println("\n{} people with {} pizzas.", n_People, n_Pizzas);
    std::println("Each persion gets {} pieces of pizza.", slicesPerPerson);
    std::println("There are {} leftover pieces.\n", slicesRemaining);
}


int getValidQuantity(Console& console, std::string_view prompt, std::string_view errMsg)
{
    bool done{ false };
    int amount{};
    while(!done)
    {
        amount = console.in_Integer(prompt);
        if (1 < amount) {
            done = true;
        } 
        else {
            std::println(stderr, "Error: {}", errMsg);
        }
    }
    return amount;
}


bool utility_isPositive(int n)
{
    return ((0 < n) ? true : false);
}


/**
 * As I write this, I'm not entirely sure this is will evaluate at compile
 * time. I have not got the relevant chapter in learncpp.com, yet. 
 */
std::string getProgramTitle()
{
    /*
     * I know this is expensive to sling strings around like this. 
     *   • I'm only doing it once at program start, and   
     *   • I don't yet know how to properly use string constants and avoid 
     *     expensive copying.
     *   • I am attempting to move away from unnecessary side affects and 
     *     toward, outside of ADTs, modular functions with return values.   
     */    
    std::string title{ "  PIZZA PARTY  " };
    std::string subTitle{
        "Project 8 from: Hogan. 2015. (57) Exercises for Programmers"};
    std::string underline(title.size(), '=');
    return std::format("\n{}\n{}\n{}\n{}", underline, title, underline, subTitle);
}