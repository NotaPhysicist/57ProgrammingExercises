#include "app.h"

void run(Console& console, Calculator& calculator)
{
    // Display program header
    std::string header{ getProgramTitle() };
    std::println("{}\n", header);
    
    // Get calulation parameters from the user
    int n_People { 
        getValidQuantity (
            console, 
            "How many people? ", 
            "We need at least one person to have a party. Please try again."
        ) 
    };
    int n_Pizzas {
        getValidQuantity (
            console,
            "How many pizzas do you have? ",
            "We need at list one pizza to have a pizza party. Please try again"
        )
    };
    int n_PiecesWanted {
        getValidQuantity (
            console,
            "How many pieces does each person want? ",
            "You need at least one piece of pizza to have a pizza party. Please try again"
        )
    };
    
    // Calulate the results
    int slices_Each = calculator.calc_SlicesPerPerson(n_People, n_Pizzas);
    int slices_Remaining = calculator.calc_SlicesRemaining(n_People, n_Pizzas);
    
    // Display the results
    std::println("\n{} {} with {} pizza{}.", 
        /* "8 people with 2 pizzas." */ 
        n_People,                                 
        pluralize_Person(n_People),
        n_Pizzas,                                 
        pluralize_Pizza(n_Pizzas)
    );
    std::println("{} person gets {} piece{} of pizza.", 
        /* "Each person gets 2 pieces of pizza" */
        pluralize_OneEach(n_People),
        slices_Each,                          
        pluralize_Piece(slices_Each)
    );
    std::println("There {} {} leftover piece{}.\n", 
        /* "There are 0 leftover pieces" */
        pluralize_toBe(slices_Remaining),
        slices_Remaining,                          // slices of pizza per person
        pluralize_Piece(slices_Remaining)
    );   

    // Do we have enough pizzas to meet our needs? 
    int pizzas_Required  = calculator.calc_PizzasRequired(n_PiecesWanted, n_People);

    if (n_Pizzas < pizzas_Required)
    {
        /* "If you want 10 pieces per person, you will need 4 pizzas in total." */
        std::println("If you want {} piece{} per person, you will need {} pizza{} in total.\n",
            n_PiecesWanted,
            pluralize_Piece(n_PiecesWanted),
            pizzas_Required,
            pluralize_Pizza(pizzas_Required)            
        );
    }
    else
    {
        /* "There are enough pizzas available to meet your target of 4 pieces per person" */
        std::println(
            "There are enough pizzas available to meet your target of {} piece{} per person.\n",
            n_PiecesWanted,
            pluralize_Piece(n_PiecesWanted)
        );
    }
}


std::string pluralize_Person(int n)  { return ((n == 1) ? "person" : "people"); }
std::string pluralize_Pizza(int n)   { return ((n == 1) ? "" : "s"); }
std::string pluralize_OneEach(int n) { return ((n == 1) ? "One" : "Each"); }
std::string pluralize_Piece(int n)   { return ((n == 1) ? "" : "s"); }
std::string pluralize_toBe(int n)    { return ((n == 1) ? "is" : "are"); }


int getValidQuantity(Console& console, std::string_view prompt, std::string_view errMsg)
{
    bool done{ false };
    int amount{};
    while(!done)
    {
        amount = console.in_Integer(prompt);
        if (0 < amount) {
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
        "Project-8 from: Hogan. 2015. (57) Exercises for Programmers"};
    std::string underline(title.size(), '=');
    return std::format("\n{}\n{}\n{}\n{}", underline, title, underline, subTitle);
}