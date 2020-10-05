#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    int n=1;
    int temp=x;
    while(temp>9)
    {
        temp/=10;
        n*=10;
    }
    while(x!=0)
    {
        int num=x/n;
        switch (n)
        {
        case 100:
            for(int i=0;i<num;i++)
            {
                printf("B");
            }
            break;
        case 10:
            for(int i=0;i<num;i++)
            {
                printf("S");
            }
            break;
        case 1:
            for(int i=1;i<=num;i++)
            {
                printf("%d",i);
            }
            break;
        }
    x=x%n;
    n/=10;
    }
}