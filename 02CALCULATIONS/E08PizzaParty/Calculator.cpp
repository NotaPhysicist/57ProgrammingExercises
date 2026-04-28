#include "Calculator.h"

Calculator::Calculator()
{
    totalSlices = 0;
    slicesPerPerson = 0;
    slicesRemaining = 0;
    slicesPerPizza = 8;  // set default value to 8: regular size pizza 
}


int Calculator::getSlicesPerPerson() 
{
    return slicesPerPerson;
}


int Calculator::getSlicesRemaing()
{
    return slicesRemaining;
}


void Calculator::setSlicesPerPizza(int n_Slices)
{
    slicesPerPizza = n_Slices;
}


void Calculator::calculateSlicesPerPerson(int n_People, int n_Pizzas)
{
    totalSlices = slicesPerPizza * n_Pizzas; 
    slicesPerPerson = totalSlices / n_People;
    slicesRemaining = totalSlices % n_People;
}

