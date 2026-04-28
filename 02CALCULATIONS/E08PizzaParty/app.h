#pragma once

#include <print>
#include <format>

#include "Calculator.h"
#include "Console.h"

/**
 * Run the application.
 */
void run(Console& console, Calculator& calculator);

// GET SOMETHING DONE FUNCTIONS
std::string getProgramTitle(); 
int getAmountOfPeople(Console& console, std::string_view prompt);                  

// UTILITY FUNCTIONS
bool utility_isPositive(int n);
