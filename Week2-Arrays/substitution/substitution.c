#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool containDuplicates(string s);
bool containNonLetter(string s);
void cipher(string s, string key);

int main(int argc, string argv[])
{
    // error checking
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    if (strlen(key) != 26 || containDuplicates(key) || containNonLetter(key))
    {
        printf("Invalid key!\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    cipher(plaintext, key);
    printf("\n");
    return 0;
}

bool containDuplicates(string s)
{
    int map[26] = {0};
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            int index = tolower(s[i]) - 'a';
            if (map[index] == 0)
            {
                map[index] += 1;
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

bool containNonLetter(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isalpha(s[i]))
        {
            return true;
        }
    }
    return false;
}

void cipher(string s, string key)
{
    char mapping[26] = {'\0'};
    for (int i = 0; i < strlen(key); i++)
    {
        mapping[i] = tolower(key[i]);
    }
    for (int i = 0; i < strlen(s); i++)
    {
        const char c = s[i];
        if (islower(c))
        {
            printf("%c", mapping[c - 'a']);
        }
        else if (isupper(c))
        {
            printf("%c", toupper(mapping[c - 'A']));
        }
        else
        {
            printf("%c", c);
        }

    }
}

