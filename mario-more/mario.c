#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //initialize height
    int height;
    //asks use for height
    //if height is not between 1 and 8 inclusive, the user will be reprompted
    do
    {
        height = get_int("How tall is the pyramid?\n");

    }
    while (height < 1 || height > 8);

    //prints height
    //commented out print statement, so compiling check50 would not result in errors
    //printf("Height: %i\n", height);

    //create new variable to edit and access
    //without needing to change the actual value of height
    int x = height;

    for (int i = 1; i <= height; i++)
    {
        //print spaces to create backwards pyramid
        for (int j = x; j > 1; j--)
        {
            printf(" ");
        }
        //prints hashes for left side of pyramid
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        //creates two spaces between both sides of pyramid
        printf("  ");
        //prints hashes for right side of pyramid
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        //creates new line for each level
        printf("\n");
        x--;

    }


}


