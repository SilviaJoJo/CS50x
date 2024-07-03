// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string original);

int main(int argc, string argv[])
{
    // Check the number of command line arguments
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
    string replaced = replace(argv[1]);
    printf("%s\n", replaced);
}

string replace(string original)
{
    // We haven't learnt memory allocation
    // And we cannot return the address of a no-memory variable
    // So I have to make modifications on the original string
    int length = strlen(original);
    for (int i = 0; i < length; i++)
    {
        char curr = original[i];
        if (curr == 'a')
        {
            original[i] = '6';
        }
        else if (curr == 'e')
        {
            original[i] = '3';
        }
        else if (curr == 'i')
        {
            original[i] = '1';
        }
        else if (curr == 'o')
        {
            original[i] = '0';
        }
        else
        {
            original[i] = curr;
        }
    }
    return original;
}
