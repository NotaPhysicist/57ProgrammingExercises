#include "Calculator.h"

Calculator::Calculator()
{
    slicesPerPizza = 8;  // set default value to 8 for a regular size pizza 
}


int Calculator::getSlicesPerPizza() const
{
    return slicesPerPizza;
}


void Calculator::setSlicesPerPizza(int n_Slices)
{
    slicesPerPizza = n_Slices;
}


int Calculator::calc_SlicesPerPerson(int n_People, int n_Pizzas)
{
    return (slicesPerPizza * n_Pizzas) / n_People;
}


int Calculator::calc_SlicesRemaining(int n_People, int n_Pizzas)
{
    return (slicesPerPizza * n_Pizzas) % n_People;
}


int Calculator::calc_PizzasRequired(int n_SlicesWanted, int n_People)
{
    int slices_Required = n_SlicesWanted * n_People;
    int pizzas_Required{};
    
    if ((slices_Required % slicesPerPizza) == 0) 
    {
        // A whole number of pizzas required, no leftovers
        pizzas_Required = slices_Required / slicesPerPizza;
    } 
    else 
    {
        // Round up the division using the standard idiom
        pizzas_Required = (slices_Required + slicesPerPizza - 1) / slicesPerPizza;
    }
    return pizzas_Required;
}
