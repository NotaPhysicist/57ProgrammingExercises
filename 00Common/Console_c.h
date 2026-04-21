#pragma once

#include <iostream>
#include <string>

/**
 * A class that constructs a console object to handle the IO for
 * a simple console program. 
 */
class Console
{
public:
    // CONSTRUCTORS
    /**
     * Construct a console object. 
     * Set all private members to a default value.
     */
    Console();

    // GETTERS
    /**
     * Get the string of this console.
     * @return the string
     */
    std::string getString() const { return str; };

    // SETTERS
    /**
     * Set the string on this console.
     * @param s the string to set
     */
    void setString(std::string s) { str = s; };

    // FUNCTIONS
    /**
     * Display a blank line. 
     * Intended to clearly document added newlines for purely presentational 
     * purposes. 
     */
    void newline() { printline("\n"); };
    
    /**
     * Display n blank lines.
     * @param int the number of blank lines to display
     * Intended to clearly document added newlines for purely presentational 
     * purposes. 
     */
    void newline(int n, int max = 100);
    
    /**
     * Display the std::endl character.
     * Intended as a convenient replacement to standalone calls 
     * to std::cout << endl.
     */
    void endline() { std::cout << std::endl; };

    /**
     * Display a line of text.
     * @param string line of text to display
     */
    void printline(const std::string line) const { std::cout << line; };
    
    void printerror(const std::string line) const;
    std::string getUserInput();
    std::string getUserInput(std::string prompt);

private:
    // Varaible for temporary storage for the console object
    std::string str; 
};