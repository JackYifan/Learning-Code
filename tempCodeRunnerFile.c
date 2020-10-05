#include<stdio.h>
int main()
{
    int i=0;
    do if(i<2) i++; else i+=2;while(i<10);
    printf("%d",i);
}