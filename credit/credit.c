#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    long credit_card = get_long("Credit Card Number:");
    char credit_number[20];

    sprintf(credit_number, "%ld", credit_card);

    int total;
    int digit;


    //Will test to see if credit card is valid through Luhn's algorithmn

    while (credit_card > 0)
    {
        total = total + (credit_card % 10);
        credit_card /= 10;
        digit = (credit_card % 10) * 2;
        total = total + (digit % 10);
        total = total + (digit / 10);
        credit_card /= 10;

    }

    total %= 10;

    //will print INVALID if credit card is fraud or not acceptable
    if (total != 0)
    {
        printf("INVALID\n");
    }
    else
    {

        //american express check
        if (strlen(credit_number) == 15 && (credit_number[0] == '3' && (credit_number[1] == '4' || credit_number[1] == '7')))
        {
            printf("AMEX\n");

        }
        //check mastercard
        else if (strlen(credit_number) == 16 && (credit_number[0] == '5' && (credit_number[1] == '1' || credit_number[1] == '2'
                 || credit_number[1] == '3' || credit_number[1] == '4' || credit_number[1] == '5')))
        {
            printf("MASTERCARD\n");

        }
        //visa check
        else if ((strlen(credit_number) == 13 || strlen(credit_number) == 16) && (credit_number[0] == '4'))
        {
            printf("VISA\n");
            //invalid statement print
        }
        else
        {
            printf("INVALID\n");
        }
    }


}