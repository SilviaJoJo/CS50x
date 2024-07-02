#include <cs50.h>
#include <stdio.h>

// helper functions need to be declared before the main function
// otherwise they cannot be recognized
void printBricks(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

void printEmpty(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

int main(void)
{
    int height;
    do
    {
        height = get_int("How tall you want this pyramid to be? (in # bricks) ");
    }
    while (height < 1);

    for (int i = 1; i <= height; i++)
    {
        printEmpty(height - i);
        printBricks(i);
        printf("\n");
    }
}
