#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int letter_count(string text);
int word_count(string text);
int sentences_count(string text);

int main(void)s
{
    string text = get_string("Text: ");
    float letter_score = letter_count(text);
    float word_score = word_count(text);
    float sentences_score = sentences_count(text);
    //Calculate index variablews
    float L = (letter_score / word_score * 100);
    float S = (sentences_score / word_score * 100);
    //Calculate index float, round it and save it as an int
    float indexed = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(indexed);
    //Print results based on index result
    if (index > 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
}

int letter_count(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int word_count(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i]) == 32)
        {
            words++;
        }
    }
    return words;
}

int sentences_count(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i]) == 46 || (text[i]) == 33 || (text[i]) == 63)
        {
            sentences++;
        }
    }
    return sentences;
}