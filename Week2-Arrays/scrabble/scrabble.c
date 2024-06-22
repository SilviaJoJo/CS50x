#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int getCharValue(char c);
int getStrValue(string s);

int main(void)
{
    // get input words and do computation
    string str1 = get_string("What's your word(uppercase)? ");
    int sum1 = getStrValue(str1);
    string str2 = get_string("What's your word(uppercase)? ");
    int sum2 = getStrValue(str2);

    // generate output based on comparison
    if (sum1 > sum2)
    {
        printf("Player 1 wins!\n");
    }
    else if (sum1 < sum2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int getCharValue(char c)
{
    int values[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int index = c - 'A';
    if (0 <= index & index < 26)
    {
        return values[index];
    }
    return 0;
}

int getStrValue(string s)
{
    int sum = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        char c = toupper(s[i]);
        sum += getCharValue(c);
    }
    return sum;
}
