#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>

int countletters(string);

int main()
{
    int letters=0, words=1, sentences=0;
    string str = get_string("Text: ");
    //printf("%s", str);
    for(int i=0;i<strlen(str);i++)
    {
        char ch = str[i];
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        letters++;
        if(ch==' ')
        words++;
        if(ch=='.'||ch=='!'||ch=='?')
        sentences++;
    }
    //printf("Words= %d Letters= %d Sentences=%d\n", words, letters, sentences);
    float L = (float)letters/words * 100;
    float S = (float)sentences/words * 100;
    int index = (int)round(0.0588*L-0.296*S-15.8);
    //printf("%f %f\n",L,S);
    if(index>16)
    printf("Grade 16+\n");
    else if(index<1)
    printf("Before Grade 1\n");
    else
    printf("Grade %d\n", index);
    }
