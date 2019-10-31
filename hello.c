#include <stdio.h>
#include<cs50.h>
int main(void)
{
    string name = get_string("What is your name?"); //gets name
    printf("hello, %s\n", name); //prints name
}
