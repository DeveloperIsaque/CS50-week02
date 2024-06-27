#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float average_number(int letter, float word);


int main (void)
{
    // prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int word = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    float l = average_number(letters, word);
    float s = average_number(sentences, word);
    float indice = 0.0588 * l - 0.296 * s - 15.8;
    int result = round(indice);

    // Print the grade level
    if(indice > 1)
    {
        if(indice >= 16)
        {
            printf("Grade 16+");
        }
        else
        {
            printf("Grade %i\n", result);
        }
    }
    else
    {
        printf("Before Grade 1\n");
    }

}

int count_letters(string text)
{
    int count = 0;
    for(int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 1;
    for(int i = 0, length = strlen(text); i < length; i++)
    {
        if(isblank(text[i]))
        {
                count++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for(int i = 0, length = strlen(text); i < length; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

float average_number (int x, float y)
{
    float z = (x / y) * 100;

    return z;
}