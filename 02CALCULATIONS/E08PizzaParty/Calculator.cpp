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


// void Calculator::calc_PizzasRequired(int n_SlicesWanted)
// {
//     int slicesRequired = n_SlicesWanted * slicesPerPizza;
//     if ((slicesRequired % slicesPerPizza) == 0) {
//         // A whole number of pizzas required, no leftovers
//         pizzasRequired = slicesRequired / slicesPerPizza;
//     } else {
//         // Round up the division
//         pizzasRequired = (slicesRequired + slicesPerPizza - 1) / slicesPerPizza;
//     }
// }
