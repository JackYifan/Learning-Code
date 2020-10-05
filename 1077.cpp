#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char a[100][100];
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    int minlen=1000;
    int index=0;
    for(int i=0;i<n;i++)
    {
        gets(a[i]);
        if(strlen(a[i])<minlen)
        {
            minlen=strlen(a[i]);
            index=i;
        }
        reverse(a[i],a[i]+strlen(a[i]));
    }
    int i;
    int flag=1;
    for(i=0;i<minlen;i++)
    {
        char c=a[0][i];
        for(int j=1;j<n;j++)
        {
            if(a[j][i]!=c)
            {
                flag=0;
                break;
            }
        }
        if(flag==0) break;
    }
    if(i==0)
    {
        printf("nai\n");
    }
    for(i=i-1;i>=0;i--)
    {
        printf("%c",a[0][i]);
    }
    // for(int i=0;i<n;i++)
    // {
    //     printf("%s\n",a[i]);
    // }
    

    
    // int len0=strlen(a[0]);
    // int len1=strlen(a[1]);
    // int sublen;
    // int pos;
    // int i,j;
    // for(i=len0-1,j=len1-1;i>=0,j>=0;i--,j--)
    // {
    //     if(a[0][i]!=a[1][j])
    //     {
    //         sublen=len0-i;
    //         break;
    //     }
        
    // }
    // pos=i+1;
    // int flag=1;
    // for(int i=2;i<n;i++)
    // {
    //     int len=strlen(a[i]);
    //     for(int k=len0-1, j=len-1;j>=len-sublen;j--,k--)
    //     {
    //         if(a[i][j]!=a[0][k])
    //         {
    //             flag=0;
    //             break;
    //         }
    //     }
    // }
    // if(flag==0 ) printf("nai\n");
    // else printf("%s",a[0]+pos);
    

    
}