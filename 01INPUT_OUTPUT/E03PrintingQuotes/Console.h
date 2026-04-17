#pragma once

#include <iostream>
#include <string>

class Console
{
public:
    // Constructor
    Console(std::string s = "");

    // Getters
    std::string getString() const;

    // Setters
    void setString(std::string s);

    // Functions
    void newline();
    void newline(int n);
    void endline();
    void printline(const std::string line) const;
    void printerror(const std::string line) const;
    std::string getUserInput();
    std::string getUserInput(std::string prompt);

private:
    std::string str;  // input from the console
};