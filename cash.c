#include<stdio.h>
#include<cs50.h>
#include<math.h>
int main()
{
    int cents;
    do
    {
        float cash = get_float("Enter Cash");
        cents = round(cash*100);
    }while(cents<0);
    int c25, c10, c5, c1;
    c25=cents/25;
    cents=cents%25;
    c10=cents/10;
    cents=cents%10;
    c5=cents/5;
    cents=cents%5;
    c1=cents;
    
    int total = c1+c5+c10+c25;
    printf("%d", total);
}
