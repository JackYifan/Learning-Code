#include<stdio.h>
int main()
{
    int a[10];
    int i=0;
    while((scanf("%d",&a[i]))!=EOF)
    {
    	printf("%d\n",a[i]);
        i++;
        
    }
   
//    for(int i=0;i<1;i++)
//    {
//        printf("%d",a[i]);
//    }
    return 0;
}
