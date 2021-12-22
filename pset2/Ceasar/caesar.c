#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


string caesar(string text, int key);


int main(int argc, char *argv[])
{

    if(argc == 2){
        string text;
        int a = atoi(argv[1]);

        if( a >= 1 ){
            //Prompt for text
            text = get_string("plaintext: ");

            //Translate text into cyphertext
            caesar(text, a);

            return 0;
        }
    }else{
            printf("Usage: ./ceasar key\n");
            return 1;
    }
}

string caesar(string text, int key)
{
    //Iterate through the string
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //Check if uppercase then encrypts text
        if(isupper(text[i]))
        {
            text[i]= (text[i]+key-65)%26+65;
        }
        //Check if lowercase then encrypts text
        else if(islower(text[i]))
        {
            text[i]= (text[i]+key-97)%26+97;
        }
    }

    //Print new text
    printf("ciphertext: %s\n", text);


    return text;
}
