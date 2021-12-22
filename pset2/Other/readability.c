#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int readability(string text);

int main(void){
    // Get input words from both players
    string t = get_string("Text: ");

    //Call the method readability and assign the alue to the variable
    float grade = readability(t);

    if(grade < 1){
        //Display "Before Grade 1"
        printf("Before Grade 1\n");
    }
    else if(grade>16)
    {
        //Display "Grade 16+"
        printf("Grade 16+\n");
    }
    else
    {
        //Display the grade
        printf("Grade %.0f\n", grade);
    }




}

int readability(string text){
    float letters =0, words =0, sentences=0, gradeAvg=0, letterAvg=0, sentenceAvg=0;



    //Itterate through the text, word by word
    for (int  i = 0, n = strlen(text); i < n; i++)
    {
        //Check for first words and letter
        if(i==0){
            words++;
            letters++;
        }
        //Check for letters
        else if(text[i] >= 'A' && text[i] <= 'z'){
            letters++;
        }
        //Check for end of word
        else if(text[i] == ' ')
        {
            words++;
        }
        //Check for end of sentence
        else if((text[i] == '.') ||(text[i] == '?') || (text[i] == '!')){
            sentences++;        }

    }

    //Calculate the grade level of text using Coleman-Liau index.
    letterAvg = (letters/words)*100;
    sentenceAvg = (sentences/words)*100;
    gradeAvg = (0.0588 * letterAvg) - (0.296 * sentenceAvg) - 15.8;
    gradeAvg = round(gradeAvg);

    return gradeAvg;
}