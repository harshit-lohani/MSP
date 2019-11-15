#include <stdio.h>
#include <stdlib.h>
#define BLOCK_SIZE 512

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    //checks for only 2 aguments
    if (argc != 2)
    {
        printf("Usage : ./recover image");
        return 1;
    }

    //checks if file is openable
    FILE *file = fopen(argv[1], "r") ;

    if (file == NULL)
    {
        printf("can't open file\n") ;
        return 1 ;
    }

    BYTE buffer[512] ;

    char outfilename[8] ;

    FILE *outptr = NULL ;
    int count = 0 ;

    while (1)
    {

        int bytesRead = fread(buffer, sizeof(BYTE), BLOCK_SIZE, file) ;

        //signifies end of the file
        if (feof(file))
        {
            break ;
        }

        int containsHeaderFile = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 ;

        //signifies end of an image
        if (containsHeaderFile && outptr != NULL)
        {
            fclose(outptr) ;
            count++ ;
        }

        //if found a JPG, new file needs to be opened
        if (containsHeaderFile)
        {
            sprintf(outfilename, "%03d.jpg", count) ;
            outptr = fopen(outfilename, "w") ;

        }

        //write on that file if file is open
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), bytesRead, outptr) ;
        }
    }

    //closes any open file
    fclose(outptr) ;
    fclose(file) ;

    return 0 ;
}
