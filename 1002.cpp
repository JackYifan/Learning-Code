#include<stdio.h>
#include<string.h>
void print(int n)
{
    switch(n)
    {
        case 0:printf("ling");break;
        case 1:printf("yi");break;
        case 2:printf("er");break;
        case 3:printf("san");break;
        case 4:printf("si");break;
        case 5:printf("wu");break;
        case 6:printf("liu");break;
        case 7:printf("qi");break;
        case 8:printf("ba");break;
        case 9:printf("jiu");break;
    }
}
int main()
{
    int sum=0;
    char a[110];
    gets(a);
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
        sum+=a[i]-'0';
    }
    int num[100];
    int j=0;
    while(sum!=0)
    {
        num[j++]=sum%10;
        sum/=10;
    }
    for(j=j-1;j>=0;j--)
    {
        print(num[j]);
        if(j!=0) printf(" ");
    }
    
}