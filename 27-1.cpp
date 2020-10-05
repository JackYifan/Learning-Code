#include<stdio.h>
int main()
{
   
   int a[8];
   int b[3];
   for(int i=0;i<8;i++)
   {
       scanf("%d",&a[i]);
   }
    int i,j;
   for(i=0,j=0;i<3;i++,j++)
   {
       b[i]=a[j];
   }
   
   for(i=3;i<8;i++)
   {
       a[i-3]=a[i];
   }
   for(i=5,j=0;i<=7;i++,j++)
   {
       a[i]=b[j];
   }
    for(int i=0;i<8;i++)
    {
        printf("%3d",a[i]);
    }
}