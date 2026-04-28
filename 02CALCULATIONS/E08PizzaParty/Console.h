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
        char getInput_Char();
        
        // Setters
        // Console In Functions
        std::string   in(std::string_view prompt = "> ");
        int   in_Integer(std::string_view prompt = "> ");
        char     in_Char(std::string_view prompt = "> ");
        
        // Console Out Functions
        void print(std::string_view s);

    private:
        std::string  input;
        int          input_Integer;
        double       input_Double; 
        char         ch;
};