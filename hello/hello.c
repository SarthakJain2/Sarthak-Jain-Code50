# include <stdio.h>
# include <cs50.h>

int main(void)
{
    //Requests user to input name
    string name = get_string("What is your name\n");
    //Prints hello, + name
    printf("hello, %s\n", name);
}