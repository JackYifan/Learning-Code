#include<stdio.h>
int main()
{
    const int n=10;
    int a[10]={9,8,7,6,5,4,3,2,1,0};
    int temp;
    int i,j;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(temp<a[j]) 
            {
                a[j+1]=a[j];
                if(j==0) break;
            }
            //else break;
        }
        a[j]=temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
