/*
 * Program asks for a name, and repeats it back to the user
 * inside message. 
 *  
 * Just the basic program. No challenges. 
 */

 #include <iostream>

 int main()
 {
    // Get the a name for the user.
    std::cout << "\nWhat is your name? ";
    std::string name{};
    std::getline(std::cin, name);
    
    // Build the message
    std::string message { "Hello, " + name + ", nice to meet you!" };
    
    // Output the message
    std::cout << message << "\n\n";

    return 0;
 }