#include <cs50.h>
#include <stdio.h>

// Greedy Algorithm
int main(void)
{
    // Prompt users to give a valid total (> 0)
    int total;
    do
    {
        total = get_int("Change owed: ");
    }
    while (total <= 0);

    // Iteratively approache the correct coins
    int coins = 0;
    do
    {
        if (total >= 25)
        {
            total -= 25;
        }
        else if (total >= 10)
        {
            total -= 10;
        }
        else if (total >= 5)
        {
            total -= 5;
        }
        else
        {
            total -= 1;
        }
        coins++;
    }
    while (total > 0);

    // Print the number of coins
    printf("%i\n", coins);
}
