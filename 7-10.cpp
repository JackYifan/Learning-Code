#include<stdio.h>
void max(int a[],int n)
{
    int max=a[1];
    for(int i=1;i<=n;i++)
    {
        if(a[i]>max) max=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==max)
        {
            printf("%d %d\n",i,a[i]);
        }
    }
}
int main ()
{
    int n;
    int index;
    int a[1010]={0};
    scanf("%d",&n);
    while(scanf("%d",&index)!=EOF)
    {
        a[index]++;
    }
    max(a,n);
    
}