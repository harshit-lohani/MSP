#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<string.h>

char lowercase(char, int);
char uppercase(char, int);

int main(int argc, string argv[])
{
    //checks number of arguments
    if(argc!=2)
    {
        printf("./caeser key");
        return 1;
    }

    //checks if integer
    for(int i=0; i<strlen(argv[1]);i++)
    {
        if(argv[1][i]>'9'||argv[1][i]<'0')
        {
            printf("./caeser key");
            return 1;
        }
    }

    //convert to integer
    int key = atoi(argv[1]);

    //printf("Key: %d", key);

    string str = get_string("plaintext: ");

    string newstr = str;

    int i=0;
    for(; i<=strlen(str); i++)
    {
        char ch = str[i];

        if(ch>='a'&&ch<='z')
        {
            newstr[i] = lowercase(ch, key);
        }
        else if(ch>='A'&&ch<='Z')
        {
            newstr[i] = uppercase(ch, key);
        }
        else
        {
            newstr[i] = ch;
        }
    }
    newstr[i]='\0';

    //print
    printf("ciphertext: %s\n", newstr);
    return 0;
}

char lowercase(char ch, int key)
{
     char newch = 97 + (ch-97+key) % 26;
     return newch;
}

char uppercase(char ch, int key)
{
     char newch = 65 + (ch-65+key) % 26;
     return newch;
}
