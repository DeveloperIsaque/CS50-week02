#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string encrypting (int length, string text, string argv);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int length = strlen(argv[1]);

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    if (length != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    string text = get_string("plaintext:  ");

    length = strlen(text);

    string cripto = encrypting (length, text, argv[1]);

    printf("ciphertext: %s\n", cripto);

    return 0;
}

string encrypting (int length, string text, string argv)
{
    for(int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            char base = islower(text[i]) ? 'a' : 'A';
            int number = text[i] - base;
            if (!islower(text[i]))
            {
                argv[number] = toupper(argv[number]);
            }
            else
            {
                argv[number] = tolower(argv[number]);
            }
            text[i] = argv[number];
        }
    }
    return text;
}
