/**
 * AREA OF A RECTANGLE ROOM
 * -=-=-=-=-=-=-=-=-=-=-=-=-
 * Project-7 from: Hogan. 2015. (57) Exercises for Programmers.
 * 
 * EXAMPLE OUTPUT
 * 
 *     What is the length of the room in feet? 15 
 *     What is the width of the room in feet? 20 
 *     You entered dimensions of 15 feet by 20 feet. 
 *     The area is 
 *     300 square feet 
 *     27.871 square meters
 * 
 * CONSTRAINTS
 * 
 *     1. Keep calculations separate from output
 *     2. Use a constant to hold the conversion factor
 * 
 * CHALLENGES
 * 
 *     1. Enforce valid input for numeric values.
 *     2. Choose feet or meters for inputs
 *     3. GUI that automatically updates values when they change. 
 * 
 *  Give formula for conversion
 * 
 *      m^2 = f^2 x 0.09290304
 * 
 * NOTES
 * 
 *     • Probably better if I convert the input values into the corrent units,
 *       rather than convert the result.  
 *     
 * CONVERSION FACTORS
 * 
 *                   Meters = ft x 0.3048
 *          Meters / 0.3048 = ft
 * 
 * LEARNING GOALS
 * 
 *     1. Floating point precision. 
 *     2. More architecture. More separation of concerns. 
 *     3. Curious about using:
 *         a. C++23 println()
 *         b. constexp
 *         c. std::string_view
 *         c. STL std::stack, std::queue, templates. 
 *         d. OOP design patterns
 *         e. MVC architecture
 */

#include <iostream>

#include "FeetToMeterConvert.h"

int main()
{
    FeetToMeterConvert ftmc;
    ftmc.test_runtTests();

    return EXIT_SUCCESS;
}
