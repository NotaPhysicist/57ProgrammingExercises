/**
 * RETIREMENT CALULATOR
 * -=-=-=-=-=-=-=-=-=-=-
 * 
 * EXAMPLE OUTPUT
 *      What is your current age? 25 
 *      At what age would you like to retire? 65 
 *      You have 40 years left until you can retire.
 *      It's 2015, so you can retire in 2055.
 *  
 * CONSTRAINTS/CHALLENGES
 *      1. Convert input to numerical data before processing
 *      2. Get the current date from the computer and perform calculations 
 *         on the date. 
 *      3. Handle the case of a negative number, indicating that the user 
 *         can already retire. 
 *      4. Consolidate the pattern of keeping input, processing, output 
 *         separate, toward reusable components. 
 */

#include <iostream>
#include <format>

#include "../../00Common/Console.h"

int main()
{
    // INPUT
    Console console;
    console.printline("\nRETIREMENT CALCULATOR\n");
    console.printline("=====================\n");

    // Get the user's current age.

    std::string input = console.getUserString("What's up? ");
    console.printline(input);
    int value = console.getUserInteger("Enter an integer: ");
    console.printline(std::format("{}", value));
    
    // int age = getInteger(0, 200, "What is your cureent age: ");
    
    // Get the user's proposed retirement age.
    
    // PROCESSING
    // Calculate the years remaining until retirement.
    // Calculate the year of proposed retirement.

    // OUTPUT
    // Display years remainning until reitirement
    // Display the year of proposed retirement

    return 0;
}


/*
void printline(std::string line) { std::cout << line; }

std::string getUserInput(const std::string prompt)
{
    return prompt;
}


bool isInteger(int min, int max)
{
    return true;
}


int getCurrentAge(int min, int max, std::string prompt)
{
    return 1;
}


auto getCurrentDate()
{
    return "date";
}


int yearsUntilRetirement(int currentYear)
{
    return 0;
}


int yearOfRetirement(int currentYear)
{
    return 0;
}

*/
