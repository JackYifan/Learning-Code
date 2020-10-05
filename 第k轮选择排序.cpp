#include<stdio.h>
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[100];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<k+1;i++)
    {
        int index=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[index]) index=j;
        }
        int temp=a[i];
        a[i]=a[index];
        a[index]=temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
        if(i<n-1) printf(" ");
    }
}