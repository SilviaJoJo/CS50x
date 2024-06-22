#include <cs50.h>
#include <stdio.h>

int sumHelper(int n)
{
    if (n < 10)
    {
        return n;
    }
    return n / 10 + n % 10;
}

bool checkSum(long card)
{
    int sum = 0;
    int index = 0;
    long toTraverse = card;
    while (toTraverse > 0)
    {
        int remainder = toTraverse % 10;
        if (index % 2 == 0)
        {
            sum += remainder;
        }
        else
        {
            sum += sumHelper(2 * remainder);
        }
        index += 1;
        toTraverse /= 10;
    }
    return (sum % 10 == 0);
}

bool checkValidAE(long card)
{
    if ((card < 38e13 && card >= 37e13) || (card < 35e13 && card >= 34e13))
    {
        return true;
    }
    return false;
}

bool checkValidM(long card)
{
    if (card < 56e14 && card >= 51e14)
    {
        return true;
    }
    return false;
}

bool checkValidV(long card)
{
    if ((card < 5e15 && card >= 4e15) || (card < 5e12 && card >= 4e12))
    {
        return true;
    }
    return false;
}

int main(void)
{
    // be sure to use long to store the input
    // otherwise int will cut it and results in incorrectness
    long card;
    card = get_long("Number: ");
    if (!checkSum(card))
    {
        // in invalid cases, return 0 to exit the program
        // otheriwse cannot pass the testcases
        printf("INVALID\n");
        return 0;
    }
    if (checkValidAE(card))
    {
        printf("AMEX\n");
    }
    else if (checkValidM(card))
    {
        printf("MASTERCARD\n");
    }
    else if (checkValidV(card))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}
