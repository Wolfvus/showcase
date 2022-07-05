#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//This program takes a 26 char key and ciphers a string of plaintext

bool valid_key(string k);//Checks validity of key

int main(int argc, string argv[])
{
    //Chekcs validity of command line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    int key_lenght = strlen(argv[1]);
    //Checks if there are no duplicated charactes with a nested loop
    int sum = 0;
    for (int i = 0; i < key_lenght; i++)
    {
        for (int j = i + 1; j < key_lenght; j++)
        {
            if (key[i] == key[j])
            {
                sum ++;
            }
        }
    }
    //Check key valitidy
    if (valid_key(key) == false || sum != 0)
    {
        printf("Key must contain 26 characters and each letter once.\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    int plain_lenght = strlen(plaintext);
    printf("ciphertext:");
    //prints the ciphered text
    for (int i = 0; i < plain_lenght; i++)
    {
        if (isupper(plaintext[i]))
        {
            int index = plaintext[i] - 65;
            printf("%c", toupper(key[index]));
        }
        else if (islower(plaintext[i]))
        {
            int index = plaintext[i] - 97;
            printf("%c", tolower(key[index]));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

//Chekcis if all values in key are alphabetical and the lenght equals 26
bool valid_key(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]) && strlen(key) == 26)
        {

        }
        else
        {
            return false;
        }
    }
    return true;
}

