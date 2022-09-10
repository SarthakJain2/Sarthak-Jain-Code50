#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
//prototypes
int count_letters(string text);

int count_words(string text);

int count_sentences(string text);

int main(void)
{
    //requests for text from user
    string text = get_string("Text: ");

    //receives letter count
    int letter_count = count_letters(text);

    //receives word count
    int word_count = count_words(text);

    //receives sentence count
    int sentence_count = count_sentences(text);

    //letters/words *100
    double L = ((double)letter_count / word_count) * 100;

    //sentences/words * 100
    double S = ((double)sentence_count / word_count) * 100;
    
    //Coleman-Liau index
    double index = round((0.0588 * L - 0.296 * S - 15.8));




    //will print out grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        for (int i = 0; i <= index; i++)
        {
            if (index == i)
            {
                printf("Grade %i\n", i);
            }
        }
    }



}

int count_letters(string text)
{
    int number_letters = 0;

    //calculates # of letters
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            number_letters++;
        }
    }

    return number_letters;

}

int count_words(string text)
{
    //set equal to 1 to consider first word
    int number_words = 1;

    //calculates # of words
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
        {
            number_words++;
        }
    }


    return number_words;

}


int count_sentences(string text)
{

    int number_sentences = 0;

    // calculates # of sentences
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            number_sentences++;
        }
    }

    return number_sentences;

}

