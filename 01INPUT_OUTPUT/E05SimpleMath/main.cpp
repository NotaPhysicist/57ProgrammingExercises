/*  -----------
    Simple Math
    -----------
    1. Prompt for two numbers.
    2. Print the sum, difference, product and quotient of the numbers.

    RELEVENT CONSTRAINTS
    1. Accept values as strings. Convert to numbers to do the math. 
    2. Separate the concerns of I/O from conversions and other processing.

    CHALLENGES
    1. Ensure inputs are entered as numeric values. 
    2. Guard against negative numbers
    3. Break the program in fuctions (already doing this)
    4. Implement as a GUI that automatically updates  the values when any 
       value changes (future interation). 
    
    STAGE ONE
    1. As above. 
    2. Accept integers only.
    
    STAGE TWO
    Accept integers or floats.  
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <format>

void printline(std::string line) { std::cout << line; }

double getInput_Double(const std::string prompt);
bool isDouble(std::string s, std::string& message);

int main()
{
    printline("\nSIMPLE MATH\nYou will be amazed.\n");

    /**
     * Process input as a double. This handles ints well, and C++ will display
     * integer-like input when possible even when the underlaying values are
     * floating point numbers. It is a compromise to avoid further
     * complexity, as there will be issues with extememly large numbers. 
     */

    // Get two number from the user
    printline("\nEnter two interger operands:\n");
    double op1 {getInput_Double("Operand 1: ")};
    double op2 {getInput_Double("Operand 2: ")};
    
    // Display some simple arithmetic
    std::string mTemplate {"{} + {} = {}\n\n"};

    printline(std::format("{} + {} = {}\n", op1, op2, op1 + op2));
    printline(std::format("{} * {} = {}\n", op1, op2, op1 * op2));
    printline(std::format("{} - {} = {}\n", op1, op2, op1 - op2));
    printline(std::format("{} / {} = {}\n\n", op1, op2, op1 / op2));

    // Produce integer-looking output when possible ?? 

    return 0;
}


double getInput_Double(const std::string prompt)
{
    std::string input{};
    double n{};
    bool done {false};  
    std::string errorMsg{};
    while (!done)
    {
        printline(prompt);
        std::getline(std::cin, input);
        // Guard against an empty line
        if (input.empty()) 
        {
            printline("Input cannot be empty. Please try again.\n");
            continue;  // bypass check integer conversion
        }
        if (isDouble(input, errorMsg)) {
            n = std::stod(input);
            done = true;
        } else {
            printline(std::format("{}. Please try again.\n", errorMsg));
        }
    }
    return n;
}


bool isDouble(std::string s, std::string& message)
{
    try {
        std::stod(s);
    } catch (const std::invalid_argument&) {
        message = "Invalid input: not a number"; 
        return false;
    } catch (const std::out_of_range&) {
        message = "Invalid input: number is out of range";
        return false;
    }
    return true;
}



