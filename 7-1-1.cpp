#include<stdio.h>
int main()
{
    int n;
    int i,j,k;
    scanf("%d",&n);
    int a[20];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int x;
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(x<a[i]) break; 
    }
    for(j=n-1;j>=i;j--)
    {
        a[j+1]=a[j];
    }
    a[i]=x;
    for(int i=0;i<n+1;i++)
    {
        printf("%d ",a[i]);
    }

}