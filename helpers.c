#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            //taking the pixel values
            int red = image[i][j].rgbtRed ;
            int green = image[i][j].rgbtGreen ;
            int blue = image[i][j].rgbtBlue ;

            //calculating new pixel values
            int average = round((red + green + blue) / 3.0f) ;

            //converting the image pixels
            image[i][j].rgbtRed = average ;
            image[i][j].rgbtGreen = average ;
            image[i][j].rgbtBlue = average ;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            //to obtain all the pixels
            int originalRed = image[i][j].rgbtRed ;
            int originalGreen = image[i][j].rgbtGreen ;
            int originalBlue = image[i][j].rgbtBlue ;

            //converting the pixels and rounding them off
            int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue) ;
            int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue) ;
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue) ;

            //chaning the pixel values
            image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed ;
            image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width / 2 ; j++)
        {
          int tempRed = image[i][j].rgbtRed ;
          int tempGreen = image[i][j].rgbtGreen ;
          int tempBlue = image[i][j].rgbtBlue ;

          image[i][j].rgbtRed = image[i][width-1-j].rgbtRed ;
          image[i][j].rgbtGreen = image[i][width-1-j].rgbtGreen ;
          image[i][j].rgbtBlue = image[i][width-1-j].rgbtBlue ;

          image[i][width-1-j].rgbtRed = tempRed ;
          image[i][width-1-j].rgbtGreen = tempGreen ;
          image[i][width-1-j].rgbtBlue = tempBlue ;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //for the top row
    for (int j = 1, i = 0 ; j < width - 1 ; j ++)
    {
        int averageRed = round((float)(image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed)/6);
        int averageGreen = round((float)(image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen)/6);
        int averageBlue = round((float)(image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue)/6);

        image[i][j].rgbtRed = averageRed ;
        image[i][j].rgbtGreen = averageGreen ;
        image[i][j].rgbtBlue = averageBlue ;
    }

    //for the bottom row
    for (int j = 1, i = height - 1 ; j < width-1 ; j++)
    {
        int averageRed = round((float)(image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed)/6);
        int averageGreen = round((float)(image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen)/6);
        int averageBlue = round((float)(image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue)/6);

        image[i][j].rgbtRed = averageRed ;
        image[i][j].rgbtGreen = averageGreen ;
        image[i][j].rgbtBlue = averageBlue ;
    }


    //for first column
    for (int i = 1, j = 0 ; i < height-1 ; i++)
    {
        int averageRed = round((float)(image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed)/6.0);
        int averageGreen = round((float)(image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen)/6.0);
        int averageBlue = round((float)(image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue)/6.0);

        image[i][j].rgbtRed = averageRed ;
        image[i][j].rgbtGreen = averageGreen ;
        image[i][j].rgbtBlue = averageBlue ;
    }

    //for last column
    for (int i = 1, j = width-1 ; i < height-1 ; i++)
    {
        int averageRed = round((float)(image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed)/6);
        int averageGreen = round((float)(image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen)/6);
        int averageBlue = round((float)(image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue)/6);

        image[i][j].rgbtRed = averageRed ;
        image[i][j].rgbtGreen = averageGreen ;
        image[i][j].rgbtBlue = averageBlue ;
    }


    //first pixel
    {
        int i = 0, j = 0;
        int averageRed = round((float)(image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed)/4);
        int averageGreen = round((float)(image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen)/4);
        int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue)/4);

        image[i][j].rgbtRed = averageRed ;
        image[i][j].rgbtGreen = averageGreen ;
        image[i][j].rgbtBlue = averageBlue ;
    }

    //first row last column
    {
        int i = 0, j = width-1;
        int averageRed = round((float)(image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed)/4);
        int averageGreen = round((float)(image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen)/4);
        int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue)/4);

        image[i][j].rgbtRed = averageRed ;
        image[i][j].rgbtGreen = averageGreen ;
        image[i][j].rgbtBlue = averageBlue ;
    }

    //last row first pixel
    {
        int i = height - 1, j = 0;
        int averageRed = round((float)(image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed)/4);
        int averageGreen = round((float)(image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen)/4);
        int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue)/4);

        image[i][j].rgbtRed = averageRed ;
        image[i][j].rgbtGreen = averageGreen ;
        image[i][j].rgbtBlue = averageBlue ;
    }

    //last pixel
    {
        int i = height - 1, j = width-1;
        int averageRed = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed)/4);
        int averageGreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen)/4);
        int averageBlue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue)/4);

        image[i][j].rgbtRed = averageRed ;
        image[i][j].rgbtGreen = averageGreen ;
        image[i][j].rgbtBlue = averageBlue ;
    }


    for (int i = 1 ; i < height - 1 ; i++)
    {
        for (int j = 1 ; j < width - 1 ; j++)
        {
            int averageRed = round((float)(image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed)/9);
            int averageGreen = round((float)(image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen)/9);
            int averageBlue = round((float)(image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue)/9);

            image[i][j].rgbtRed = averageRed ;
            image[i][j].rgbtGreen = averageGreen ;
            image[i][j].rgbtBlue = averageBlue ;
        }
    }
    return;
}
