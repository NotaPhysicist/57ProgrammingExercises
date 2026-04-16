/*
 * Program asks for a name, and repeats it back to the user
 * inside message. 
 *  
 * This exercise asks for simple, procedural code, nothing fancy. 
 * 
 * Further challenge: Display different greetngs for different people. 
 * In you're not a complete beginner, no need to go that far. Move on
 * to more interesting challenges. 
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