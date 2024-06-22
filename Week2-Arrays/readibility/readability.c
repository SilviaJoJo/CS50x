#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int countLetters(string s);
int countWords(string s);
int countSentences(string s);

int main(void)
{
    // read the input
    string text = get_string("Text: ");
    int letters = countLetters(text);
    int words = countWords(text);
    int sentences = countSentences(text);

    // when computing grade, be sure to add "float" to make it accurate
    int grade = (int) round(0.0588 * (letters / (float) words * 100) -
                            0.296 * (sentences / (float) words * 100) - 15.8);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int countLetters(string s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            count += 1;
        }
    }
    return count;
}

int countWords(string s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            count += 1;
        }
    }
    return count + 1;
}

int countSentences(string s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            count += 1;
        }
    }
    return count;
}
