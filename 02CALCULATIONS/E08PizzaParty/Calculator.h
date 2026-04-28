#pragma once

#include <print>

class Calculator
{
public:
    // Constructors
    Calculator();

    // Getters
    int getSlicesPerPerson();
    int getSlicesRemaing();

    // Setters
    void setSlicesPerPizza(int n_Slices = 8);
    // Functions
    void calculateSlicesPerPerson(int n_People, int n_Pizzas);

private:
    int totalSlices;
    int slicesPerPerson;
    int slicesRemaining;
    int slicesPerPizza;
};