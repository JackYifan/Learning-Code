#include<stdio.h>
#include<string.h>
int main()
{
    char a[500010];
    int i,j,k;
    gets(a);
    //printf("%s",a);
    int cnt=0;
    //hello
    for(i=strlen(a)-1;i>=0;i--)
    {
        int flag=0;
        if(a[i]==' ')
        {
            for(int k=i+1;k<i+1+cnt;k++)
            {
                printf("%c",a[k]);
            }
            for(int j=0;j<=i;j++)
            {
                if(a[j]!=' ')
                {
                    flag=1;
                    break;
                }
            }
            if(cnt!=0&&flag==1) printf(" ");
            cnt=0;
        }
        else cnt++;
    }
    if(a[0]!=' ')
    {
        for(int i=0;i<cnt;i++)
        {
            printf("%c",a[i]);
        }
    }
    
    return 0;
}
