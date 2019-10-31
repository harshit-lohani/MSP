#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size;
    do
    {
        size = get_int("Height: ");
    }
    while (size <= 0 || size > 8); //to check the input
    for (int i = 1; i <= size; i++) //rows
    {
        for (int j = 1; j <= size ; j++) 
        {
            if (i + j <= size)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");   
    }
}
