#pragma once

#include <iostream>
#include <string>

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
        // Functions - Console In
        std::string   in(std::string_view prompt = "> ");
        int   in_Integer(std::string_view prompt = "> ");
        char     in_Char(std::string_view prompt = "> ");

        // Functions - Console Out
        void print_Error( std::string_view msg) const;
        
        /**
         * If unsure whether value will implicitly convert to a string, then 
         * convert value to string before passing.  
         */
        void PRINT_TEST( std::string_view value) const;
        
    private:
        /**
         * These values are for internal use. All the functions that produce a value,
         * return that value to the caller. Think of these members as internal short-term 
         * memory. They don't have setters. They have getters, why not, in case they are 
         * needed, but should be used with care as they will potentially update on 
         * each subsequent use of the class. 
         */
        std::string  input;
        int          input_Integer;
        double       input_Double; 
        char         ch;
};