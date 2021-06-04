#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float rgbGray;

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            rgbGray = round((image[j][i].rgbtBlue + image[j][i].rgbtGreen + image[j][i].rgbtRed) / 3.000);

            image[j][i].rgbtBlue = rgbGray;
            image[j][i].rgbtGreen = rgbGray;
            image[j][i].rgbtRed = rgbGray;
        }
    }
    return;
}


int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepBlue;
    int sepGreen;
    int sepRed;

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            sepBlue = limit(round(0.272 * image[j][i].rgbtRed + 0.534 * image[j][i].rgbtGreen + 0.131 * image[j][i].rgbtBlue));
            sepGreen = limit(round(0.349 * image[j][i].rgbtRed + 0.686 * image[j][i].rgbtGreen + 0.168 * image[j][i].rgbtBlue));
            sepRed = limit(round(0.393 * image[j][i].rgbtRed + 0.769 * image[j][i].rgbtGreen + 0.189 * image[j][i].rgbtBlue));

            image[j][i].rgbtBlue = sepBlue;
            image[j][i].rgbtGreen = sepGreen;
            image[j][i].rgbtRed = sepRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];

    for(int j = 0; j < height; j++)
    {
        for(int i = 0; i < width; i++)
        {
            temp[0] = image[j][i].rgbtBlue;
            temp[1] = image[j][i].rgbtGreen;
            temp[2] = image[j][i].rgbtRed;

            image[j][i].rgbtBlue = image[j][width - j - 1].rgbtBlue;
            image[j][i].rgbtGreen = image[j][width - j - 1].rgbtGreen;
            image[j][i].rgbtRed = image[j][width - j - 1].rgbtRed;

            image[j][width - j - 1].rgbtBlue = temp[0];
            image[j][width - j - 1].rgbtGreen = temp[1];
            image[j][width - j - 1].rgbtRed = temp [2];

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumBlue;
    int sumGreen;
    int sumRed;
    float counter;

    RGBTRIPLE temp[height][width];

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            counter = 0.00;

            for(int k = -1; k < 2; k++)
            {
                if(j + k < 0 || j + k > height - 1)
                {
                    continue;
                }
                for(int h = -1; h < 2; h++)
                {
                    if(i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    sumBlue += image[j + k][i + h].rgbtBlue;
                    sumGreen += image[j + k][i + h].rgbtGreen;
                    sumRed += image[j + k][i + h].rgbtRed;
                    counter++;
                }
            }

            temp[j][i].rgbtBlue = round(sumBlue / counter);
            temp[j][i].rgbtGreen = round(sumGreen / counter);
            temp[j][i].rgbtRed = round(sumRed / counter);
        }
    }

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }

}
