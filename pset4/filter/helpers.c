#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    printf("height: %i\nwidth: %i\nimage %i\n" , height, width, image[0][0].rgbtRed);

    for (int h = 0; h < height-1; h++)
    {
        for (int w = 0; w < width-1; w++)
        {
            float gray = (image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue);
            gray = gray/3;
            int avgGray = roundf(gray);

            image[h][w].rgbtRed = avgGray;
            image[h][w].rgbtGreen = avgGray;
            image[h][w].rgbtBlue = avgGray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    printf("height: %i\nwidth: %i\nimage %i\n" , height, width, image[0][300].rgbtRed);

    for (int h = 0; h < height-1; h++)
    {
        for (int w = 0; w < width-1; w++)
        {
            float rawSepiaRed = ((.393*image[h][w].rgbtRed)
                                + (.769*image[h][w].rgbtGreen)
                                + (.189*image[h][w].rgbtBlue));

            float rawSepiaGreen = ((.349*image[h][w].rgbtRed)
                                + (.686*image[h][w].rgbtGreen)
                                + (.168*image[h][w].rgbtBlue));

            float rawSepiaBlue = ((.272*image[h][w].rgbtRed)
                                + (.534*image[h][w].rgbtGreen)
                                + (.131*image[h][w].rgbtBlue));

            int sepianRed = roundf(rawSepiaRed);
            int sepianGreen = roundf(rawSepiaGreen);
            int sepianBlue = roundf(rawSepiaBlue);

            if(sepianRed >= 256){
                sepianRed = 255;
            }

            if(sepianGreen >= 256){
                sepianGreen = 255;
            }

            if(sepianBlue >= 256){
                sepianBlue = 255;
            }

            image[h][w].rgbtRed = sepianRed;
            image[h][w].rgbtGreen = sepianGreen;
            image[h][w].rgbtBlue = sepianBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int hi = height-0;
    printf("height: %i\nwidth: %i\nimage %i\n" , height-0, width, image[height][width].rgbtRed);

    for (int h = 0; h < height-1; h++)
    {
        for (int w = 0; w < width-1; w++)
        {

            int tempRed = image[height-h][width-w].rgbtRed;
            int tempGreen = image[height-h][width-w].rgbtGreen;
            int tempBlue = image[height-h][width-w].rgbtBlue;

            image[height-h][width-w].rgbtRed = image[h][w].rgbtRed;
            image[height-h][width-w].rgbtGreen = image[h][w].rgbtGreen;
            image[height-h][width-w].rgbtBlue = image[h][w].rgbtBlue;

            image[h][w].rgbtRed = tempRed;
            image[h][w].rgbtGreen = tempGreen;
            image[h][w].rgbtBlue = tempBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}