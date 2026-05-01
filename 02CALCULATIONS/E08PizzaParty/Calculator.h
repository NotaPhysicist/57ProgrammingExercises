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
    /**
     * Default value set to 8 in the constructor. 
     */
    void setSlicesPerPizza(int n_Slices);
    
    // Functions
    int calc_SlicesPerPerson(int n_People, int n_Pizzas);
    int calc_SlicesRemaining(int n_People, int n_Pizzas);
    int calc_PizzasRequired(int n_SlicesWanted, int n_People);

private:
    int slicesPerPizza;       // default: 8, based on an average pizza, can be set 
};