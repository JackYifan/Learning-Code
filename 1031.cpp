#include<cstdio>
#include<cstring>
int main()
{
    char a[100];
    scanf("%s",a);
    int len=strlen(a);
    int n1,n2;
    int cnt=0;
    int tail=len-1;
    len=len+2;
    if(len%3==0) n1=n2=len/3;
    else if(len%3==1)
    {
        n1=len/3;
        n2=len-2*n1;
    }
    else if(len%3==2)
    {
        n1=len/3;
        n2=len-2*n1;
    }
    // for(int i=len;i>=3;i--)
    // {
    //     n1=i;
    //     n2=len+2
    // }
    
    
    
    for(int i=0;i<n1-1;i++)
    {
        printf("%c",a[cnt++]);
        for(int j=0;j<n2-2;j++)
        {
            printf(" ");
        }
        printf("%c\n",a[tail--]);
    }
    for(int i=0;i<n2;i++)
    {
        printf("%c",a[cnt++]);
    }
        
    
}