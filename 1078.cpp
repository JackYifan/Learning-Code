#include<stdio.h>
void funC(char a[])
{
    int num=1;
    char c=a[0];
    for(int i=1;a[i-1]!='\0';i++)
    {
        while(a[i]==c)
        {
            i++;
            num++;
        }
        if(num>1)
        {
            printf("%d%c",num,c);
        }
        else printf("%c",c);
        
        c=a[i];
        num=1;
    }
}
void funD(char a[])
{
    char c;
    int num;
    int digit=1;
    // scanf("%d",&num);
    // scanf("%c",&c);
    // for(int i=0;i<num;i++)
    // {
    //     printf("%c",c);
    // }
    for(int i=0;a[i]!='\0';i++)
    {
        num=0;
        while(a[i]>='0'&&a[i]<='9')
        {
            num=num*10+a[i]-'0';
            i++;
        }
        if(num==0)
        {
            printf("%c",a[i]);
            continue;
        }
        for(int j=0;j<num;j++)
        {
            printf("%c",a[i]);
        }
    }
}
int main()
{
    char a[1010];
    char alt;
    scanf("%c",&alt);
    getchar();
    gets(a);
    switch(alt)
    {
        case 'C':funC(a);break;
        case 'D':funD(a);break;
    }
}