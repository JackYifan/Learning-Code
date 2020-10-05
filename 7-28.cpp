#include<stdio.h>
int main()
{
    int a[1010];
    int n;
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=1;
    }
    int cnt=0;
    int sum=0;
    for(i=0;;i++)
    {
        // while(a[i]==0)
        // {
        //    i++;
        //    if(i==n) i=0;
        // }
        if(i==n) i=0;
        if(a[i]==1)
        {
            cnt++;
            if(cnt%3==0) 
            {
                a[i]=0;
                sum++;
            }
        }
        
        if(sum==n-1) break;
    }
    for(int j=0;j<n;j++)
    {
        if(a[j]==1)
        {
            printf("%d ",j+1);
        }
    }
    return 0;
}