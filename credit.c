#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//This little program takes a long number from a credit card and performs a checksum to validate the card number according to the Luhn's Algorithm.
//Then it prints the type of card it is VISA, MASTERCARD or AMEX.

bool check_sum(long number); //Returns true if card is legit
long card_number;//Stores card number
int digits(long number); //Find number of digits in card_number

int main(void)
{
    card_number = (get_long("Number: "));
    int n = digits(card_number);
    int last_two = card_number / pow(10, n - 2); //gets last two digits for the card number
    if (card_number <= 0 || n < 13)
    {
        printf("INVALID\n");
    }
    else if (check_sum(card_number) == false)
    {
        printf("INVALID\n");
    }
    else if (n == 13 || (n == 16 && last_two / 10 == 4))
    {
        printf("VISA\n");
    }
    else if (n == 15 && (last_two == 34 || last_two == 37))
    {
        printf("AMEX\n");
    }
    else if (n == 16 && last_two > 50 && last_two < 56)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }

}
//Perform Checksum to validate card number if valid returns true
bool check_sum(long number)
{
    int total_sum = 0;
    while (number != 0)
    {
        int two_digits = number % 100;
        int d1 = two_digits % 10;
        total_sum += d1;
        int d2 = (two_digits / 10) * 2;
        d2 = (d2 / 10) + (d2 % 10);
        total_sum += d2;
        number = number / 100;
    }
    {
        if ((total_sum % 10) == 0)
        {
            return true;
        }
        return false;
    }
}
//Finds the number of digits in the Card Number
int digits(long number)
{
    int count = 0;
    while (number > 0)
    {
        number /= 10;
        count++;
    }
    return count;
}

