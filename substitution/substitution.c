#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//prototype
int isValid(string code[]);


int main(int argc, string argv[])
{
//checks to see if correct number of arguments && calls isValid
    if ((argc == 1 || argc > 2) || (argc == 2 && isValid(argv) == 0))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //checks if input is correct length
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
        //encryption process
    {
        string text = get_string("plaintext: ");


        for (int i = 0, n = strlen(text); i < n; i++)
        {
            for (int j = 0; j < 27; j++)
            {
                if (text[i] == 65 + j || text[i] == 97 + j)
                {
                    //doesn't change case of originial input
                    if (isupper(text[i]))
                    {
                        text[i] = toupper(argv[1][j]);
                    }
                    else
                    {
                        text[i] = tolower(argv[1][j]);
                    }
                    break;
                }
            }
        }
        //prints out ciphertext
        printf("ciphertext: %s", text);
        printf("\n");
        return 0;
    }

}
//checks if input is valid
int isValid(string code[])
{
    //checks to see if there are any numbers or duplicates
    for (int i = 0, n = strlen(code[1]); i < n; i++)
    {
        if (isalpha(code[1][i]) == 0 || code[1][i] == code[1][i + 1])
        {
            return 0;
        }

    }

    return 1;
}






