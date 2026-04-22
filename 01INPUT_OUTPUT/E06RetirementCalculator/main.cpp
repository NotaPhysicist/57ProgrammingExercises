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
 * Permutations: 
 *   (retirement age == current age)
 * 
 *      What is your current age? 65
 *      At what age would you like to retire? 65 
 *      Congratulations. You have reached your retirement age. 
 *      It's 2026, so you can retire this year. 
 * 
 *   (retirement age < current age)
 * 
 *      What is your current age? 65
 *      At what age would you like to retire? 60 
 *      Looks like have already reached your retirement age.
 *      It's 2026, so you could have retired in 2021. 
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
#include <string>
#include <format>
#include <chrono>

#include "Console.h"

void controller(Console& console);
void displayHeader(Console& console);
int getUsersCurrentAge(Console& console);
int getUsersRetirementAge(Console& console);
int getCurrentYear();
std::string answer_YearsRemaining(int yearsRemaining);
void tests(Console&, int, int, int, int);
std::string answer_RetirementYear(int currentYear, int retireYear);


int main()
{
    Console console;
    controller(console);
    return 0;
}


void controller(Console& console)
{
    displayHeader(console);
    
    // Get the ages from the user
    int age = getUsersCurrentAge(console);
    int retireAge = getUsersRetirementAge(console);
    
    // Process the input
    int currentYear = getCurrentYear();
    int yearsRemaining = (retireAge - age);
    int retireYear = currentYear + yearsRemaining;
    std::string answer1 = answer_YearsRemaining(yearsRemaining);
    std::string answer2 = answer_RetirementYear(currentYear, retireYear); 
    
    // Display the  answers
    console.printline(answer1);    
    console.printline(answer2);   
    console.printline(); 
    
    // tests(console, age, retireAge, currentYear, yearsRemaining);    
}


void tests(Console& console, int age, int retireAge, int currentYear, 
    int yearsRemaining)    
{
    console.printline();
    console.printline("TESTS:"); 
    console.printline("-----------------------"); 
    console.printline(std::format("    current age: {}", age)); 
    console.printline(std::format(" retirement age: {}", retireAge)); 
    console.printline(std::format("   current year: {}", currentYear)); 
    console.printline(std::format("years remaining: {}", yearsRemaining));
    console.printline(); 
}


std::string answer_RetirementYear(int currentYear, int retireYear)
{
    if (currentYear < retireYear) 
    {
        return std::format(
            "It's {}, so you can retire in {}.", currentYear, retireYear
        );
    }
    else if (currentYear == retireYear)
    {
        return std::format("It's {}, so you can retire this year.", currentYear);
    }
    else
    {
        return std::format(
            "It's {}, so you could have retired in {}.", currentYear, retireYear);
    }
}


std::string answer_YearsRemaining(int yearsRemaining)
{
    if (0 < yearsRemaining) 
    {
         return std::format(
            "You have {} years left until you can retire", yearsRemaining
        );
    } 
    else if (0 == yearsRemaining) 
    {
        return "Congratuations. You have reached your retirement age.";
    } 
    else 
    {
        return "Looks like you have already reached your retirement age.";
    }
}


int getCurrentYear() 
{
    auto today = std::chrono::floor<std::chrono::days>(
        std::chrono::system_clock::now()
    );
    std::chrono::year_month_day ymd {today};
    return int(ymd.year());
}


int getUsersRetirementAge(Console& console)
{
    int retirementAge{};
    bool done {false};
    const int ARBITRARY_MAX_RETIRE_AGE {200};
    std::string prompt {"At what age would you like to retire? "};
    while (!done)
    {
        retirementAge = console.getUserInteger(prompt);
        if (0 < retirementAge && retirementAge <= ARBITRARY_MAX_RETIRE_AGE ) {
            done = true;
        } 
        else 
        {
            std::string errMsg = 
                "Please give a retirement age that is possible for " 
                "a human being.";
            console.printerror(errMsg);
        }
    }
    return retirementAge;
}


int getUsersCurrentAge(Console& console)
{
    int age{};
    bool done {false};
    const int ARBITRARY_MAX_AGE_LIMIT {200};
    console.printline(); // blank line for formatting
    while (!done)
    {
        age = console.getUserInteger("What is your current age? ");
        if (0 < age && age <= ARBITRARY_MAX_AGE_LIMIT) {
            done = true;
        } 
        else 
        {
            std::string errMsg = 
                "Please give an age that is currently possible for "
                "a human being.";
            console.printerror(errMsg);
        }
    }
    return age;
}


void displayHeader(Console& console)
{
    std::string programTitle {"RETIREMENT YEAR CALCULATOR"};
    console.printline(std::format("\n{}", programTitle));
    for (int i = 0; i < static_cast<int>(programTitle.length()); i++) {
        console.println("=");
    }
}
