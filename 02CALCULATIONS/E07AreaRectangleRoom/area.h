#pragma once

#include <print>
#include <string>
#include <string_view>

#include "FeetToMeterConvert.h"
#include "Console.h"

void displayHeader();
void run(FeetToMeterConvert& converter, Console& console);
int inDimension(std::string_view prompt, Console& console);
bool isPositiveInteger(int n);

