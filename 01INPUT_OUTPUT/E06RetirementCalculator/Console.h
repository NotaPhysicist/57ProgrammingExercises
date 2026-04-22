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
    Console();

    // GETTERS
    std::string getString() const { return str; };

    // SETTERS
    void setString(std::string s) { str = s; };

    // FUNCTIONS
    void newlines(int n, int max = 100);
    void endline();
    void println(const std::string line) const;
    void printline(const std::string line = "") const;
    void printerror(const std::string line) const;
    
    std::string getUserString(std::string prompt = "> ");
    int getUserInteger(std::string prompt = "> ");

private:
    // std::string getInput();

    // Varaible for temporary storage for the console object
    std::string str; 
};