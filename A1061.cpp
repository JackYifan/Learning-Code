#include<stdio.h>
#include<string.h>
int isA_G(char c)
{
    if(c>='A'&&c<='G') return 1;
    else return 0;
}
int isA_N(char c)
{
    if(c>='A'&&c<='N') return 1;
    else return 0;
}
int isnumber(char c)
{
    if(c>='0'&&c<='9') return 1;
    else return 0;
}
int isletter(char c)
{
    if(c>='A'&&c<='Z'||(c>='a'&&c<='z')) return 1;
    else return 0;
}
void printday(char c)
{
    int n=c-'A'+1;
    switch(n)
    {
        case 1:printf("MON");break;
        case 2:printf("TUE");break;
        case 3:printf("WED");break;
        case 4:printf("THU");break;
        case 5:printf("FRI");break;
        case 6:printf("SAT");break;
        case 7:printf("SUN");break;
    }
    printf(" ");
}
void printhour(char c)
{
    if(c>='0'&&c<='9')
    {
        printf("%02d",c-'0');
    }
    else
    {
        printf("%02d",c-'A'+10);
    }
}
void printminute(int n)
{
    printf("%02d",n);
}
int main()
{
    char a1[100];
    char a2[100];
    char a3[100];
    char a4[100];
    gets(a1);
    gets(a2);
    gets(a3);
    gets(a4);
    int len1=strlen(a1);
    int len2=strlen(a2);
    int len3=strlen(a3);
    int len4=strlen(a4);
    int len11=len1<=len2?len1:len2;
    int len22=len3<=len4?len3:len4;
    char n1;
    char n2;
    int n3;
    int tot=0;
    for(int i=0;i<len11;i++)
    { 
        if(a2[i]==a1[i]&&isA_G(a1[i])&&tot==0)
        {
            n1=a1[i];
            tot++;
            continue;
        }

        if(a2[i]==a1[i]&&(isA_N(a1[i])||isnumber(a1[i]))&&tot==1)
        {
            n2=a1[i];
            break;
        }
    }
    for(int i=0;i<len22;i++)
    { 
        if(a3[i]==a4[i]&&isletter(a3[i]))
        {
            n3=i;
            break;
        } 
    }
    //输出
    printday(n1);
    printhour(n2);
    printf(":");
    printminute(n3);
    return 0;
}