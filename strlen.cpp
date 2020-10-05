#include<stdio.h>
#include<string.h>
int main()
{
    char a[]="hello\\\t\101\n";
    char b[5]={'a','b'};
    printf("%d\n",strlen(b));
    printf("%s",b);
    int len=strlen(a);
    printf("%d",len);
    printf("%d",sizeof(a));
    

}