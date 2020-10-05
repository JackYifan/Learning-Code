#include<stdio.h>
#include<string.h> 
int main()
{
    int i=0;
    do if(i<2) i++; else i+=2;while(i<10);
    printf("%d",i);
    printf("%d",-++i);
    char a[]=" ";
    strcpy(a,"hello");
    printf("%s",a);
    printf("#");
}
