#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <math.h>


void cash(float change);


int main(void)
{
    float change=0;

    //Get positive float from user
    do
    {
        // Prompt for change
         change=get_float("Change owed: $");

    } while(change < 0.0);

    int c = round(change * 100);

    cash(c);

}

void cash(float change){
    int coins=0;

    while(change > 0.0)
    {
        if(change >= 25){
            change -= 25;
            printf("%.2f\n", change);
            coins++;
        }

        else if(change >= 10)
        {
            change -= 10;
            printf("%.2f\n", change);
            coins++;
        }

       else if(change >= 05)
        {
            change -= 05;
            printf("%.2f\n", change);
            coins++;
        }

        else
        {
            change -= 01;
            printf("%.2f\n", change);
            coins++;
        }
    }

    printf("Coins: %i\nChange: %3f\n", coins, change);
}