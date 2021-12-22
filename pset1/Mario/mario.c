#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

void mario();

int main(void)
{
    //Get positive integer from user
    int h=0;

    do
    {
        h = get_int("Height: ");

    }
    while (h<1 || h>9);

    //Print the Pyramid
    if (h==0)
    {
        exit(1);
    }

    mario(h);

}

void mario(int size)
{
    int spaces;
    int blocks;

    for(int i = 1; i<=size;i++){
        for(spaces = (size-i); spaces>0;spaces--){
            printf(" ");
        }
        for (blocks = 1; blocks <= i; blocks++){
            printf("#");
        }
        printf("\n");
    }
}