#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    // Make sure every character in argv[1] is a digit
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);
    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    // For each character in the plaintext:
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // Rotate the character if it's a letter
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");
}

bool only_digits(string s)
{
    // Note that every command line argument is a string
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        // Use isdigit function in ctype.h to check whether a char is a digit
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    char ans = c;
    if (islower(c))
    {
        ans = 'a' + (c - 'a' + n) % 26;
    }
    else if (isupper(c))
    {
        ans = 'A' + (c - 'A' + n) % 26;
    }
    return ans;
}
