/**
 * PIZZA PARTY
 * Project 8 from Hogan. 2015. (57) Exercises for Programmers
 * 
 * EXAMPLE OUTPUT
 * 
 *     How many people? 8 
 *     How many pizzas do you have? 2
 *     
 *     8 people with 2 pizzas
 *     Each person gets 2 pieces of pizza. 
 *     There are 0 leftover pieces.
 * 
 * REQUIREMENTS
 * 
 *     • Evenly divide x pizzas among y people. 
 *     • Ensure tha the number of pieces come out even. 
 *     • If there are leftovers, display the number of leftover pieces. 
 * 
 * CHALLENGES
 * 
 *     • Ensure (insist that) the user enters valid input.
 *     • Handle pluralization properley
 *         • Each person gets 2 pieces of pizza.
 *         • Each person gets 1 piece of pizza. 
 * 
 * VARIANT
 * 
 *     How many people? 8 
 *     How many pieces does each person want? 3
 * 
 *     Assuming each pieces has x piecies, you will need to purchase y pizzas.
 *     You will have x leftover pieces.
 */

#include "app.h"

int main()
{
    Console console;
    Calculator calculator;

    run(console, calculator);

    return EXIT_SUCCESS;
}



