#include<cs50.h>
#include<stdio.h>

void draw(int n);
int main (void)
{
    // int height = get_int("Height: ");

    // draw(height);

    int n = 50;
    int *p = &n;
    printf("%p\n", p);
    printf("%i\n", *p);

    string s = "HI!";
    char *c = &s[0];
    printf("%p\n", s);
    printf("%p\n", c);


}


void draw(int n)
{
    if(n<=0)
    {
        return;
    }

    draw(n-1);
    for(int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}