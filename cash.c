#include <stdio.h>
#include <cs50.h>
#include <math.h>
/* Program that uses Greedy Algorithm to asks the user how much change is owed and then prints the minimum number of coins with which that change can be made. */
int main(void)
{
    /* Initializing 2 variables; One to get the user input in the form of Float value and the other to count the coins */
    float cash;
    int counter = 0;
    /* A standard do while loop to keep prompting the user to enter the value until it's positive and until it's a numeric value */
    do
    {
        cash = get_float("Change owed: ");
    }
    while (cash < 0);
    int balance = round(cash * 100); /* Rounding the Float value off to the nearest integer value and storing it in an int variable */
    /* A do while loop to keep reducing the variable holding the cents by checking if its closer to 25 or 10 or 1 and incrementing a counter with every check
    it matches with */
    do
    {
        if (balance >= 25)
        {
            balance -= 25;
            counter++;
        }
        else if (balance >= 10 && balance < 25)
        {
            balance -= 10;
            counter++;
        }
        else if (balance >= 5 && balance < 10)
        {
            balance -= 5;
            counter++;
        }
        else if (balance > 0 && balance < 5)
        {
            balance -= 1;
            counter++;
        } 
    }
    while (balance != 0); /* The loop exits only if the final value has been reduced to zero */
    printf("%i\n", counter);
}
