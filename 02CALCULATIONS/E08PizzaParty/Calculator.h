#pragma once

#include <print>

class Calculator
{
public:
    // Constructors
    Calculator();

    // Getters
    int getSlicesPerPizza() const;

    // Setters
    void setSlicesPerPizza(int n_Slices = 8);
    
    // Functions
    int calc_SlicesPerPerson(int n_People, int n_Pizzas);
    int calc_SlicesRemaining(int n_People, int n_Pizzas);
    // int calc_PizzasRequired(int n_SlicesWanted);

private:
    int slicesPerPizza;       // default: 8, based on an average pizza, can be set 
};