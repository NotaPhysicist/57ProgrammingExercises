#pragma once

#include <iostream>
#include <string>
#include <print>

class Console 
{
    public:
        // Constructores
        Console();

        // Getters
        std::string getInput();
        int getInput_Integer();
        double getInput_Double();
        
        // Setters
        // Functions
        std::string in(std::string_view prompt = "> ");
        int in_Integer(std::string_view prompt = "> ");
        // double in_Double(std::string_view prompt = "> ");

    private:
        std::string  input;
        int          input_Integer;
        double       input_Double; 
};