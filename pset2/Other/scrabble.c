#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1,
            3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word);


int main(void){
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if(score1>score2)
    {
        printf("Player 1 wins!");
    }
    else if(score1<score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!\n");
    }

}

int compute_score(string word)
{
    int sum=0;
    int numb;

    // TODO: Compute and return score for string
    for (int  i = 0, n = strlen(word); i < n; i++)
    {
        //printf("%c | ", word[i]);

        if(isupper(word[i]))
        {
            numb = word[i] - 65;
            numb = POINTS[numb];
        }
        else if(islower(word[i]))
        {
            numb = word[i] - 97;
            numb = POINTS[numb];
        }
        else
        {
            numb = 0;

        }

        sum+=numb;
    }
    //printf("\n");
    return sum;
}