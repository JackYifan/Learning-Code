#include<stdio.h>
const int n=5;
void bubble(int a[])
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void select (int a[])
{
    for(int i=0;i<n-1;i++)
    {
        int index=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[index])
            {
                index=j;
            }
        }
        int temp=a[index];
        a[index]=a[i];
        a[i]=temp;
    }
}
void insert(int *a)
{
    int i,j;
    for(int i=1;i<n;i++)
    {
        int temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(temp<a[j]) 
            {
                a[j+1]=a[j];
            }
            else break;
        }
        a[j+1]=temp;
    }
}
int main ()
{
    int a[5]={5,4,3,2,1};
   // bubble(a);
    // select(a);
    insert(a);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    
}