#include <stdio.h> /* needed for so many functions */
#include <cs50.h> /* package specific to cs50 course IDE */
#include <math.h> /* needed for rounding */

int main(void) /*beginning of the program */
{
    int q = 0; /* variable representing the number of quarters */
    int d = 0; /* variable representing the number of dimes */
    int n = 0; /* variable representing the number of nickels */
    int p = 0; /* variable representing the number of pennies */
    float i = 0; /* variable representing the user's input */
    int change1 = 0; /* variable representing the amount initial amount of cents for user's input */
    int change2 = 0; /* variable representing the remaining change after quarters removed */
    printf("This program provides instructions on how to give change using the minimum number of coins.\n");
    do
    {
        i = get_float("Enter the amount of change you need: \n$"); /*ask user for change */
    }
    while (i <= 0); /* check that it is a non-negative, non-zero float */
    change1 = round(i * 100); /* round to cents */
    if (change1 >= 25) /* check if we can use quarters */
    {
        do
        {
            change1 = change1 - 25; /* subtract the number of quarters */
            q++;
        }
        while (change1 > 24);
        change2 = change2 + change1; /* define the remaining change */
    }
    else
    {
        /* if no quarters, keep change at input */
        change2 = change2 + change1;
    }
    if (change2 > 0) /* check if there's remainder, or not enough to use quarters*/
    {
        /* if there is... */
        if (change2 >= 10) /*...and it's greater than 10 cents */
        {
            do
            {
                change2 = change2 - 10; /*use as many dimes as possible */
                d++;
            }
            while (change2 > 9);
        }
        if (change2 >= 5 && change2 < 10) /* check for remainders */
        {
            /* if there is... */
            do
            {
                change2 = change2 - 5; /* use as many nickels as possible */
                n++;
            }
            while (change2 > 4);
        }
        if (change2 > 0 && change2 < 5) /* check if there's still a remainder */
        {
            /* if there is... */
            do
            {
                change2 = change2 - 1; /* use as many pennies as needed */
                p++;
            }
            while (change2 > 0);
        }
    }
    printf("The correct change is: %d quarters, %d dimes, %d nickels, and %d pennies!\n", q, d, n, p);
}