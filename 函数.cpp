#include<stdio.h>
#include<string.h>
void f(int a[])
{
	for(int i=0;i<4;i++)
	{
		a[i]+=2;
	}
 } 
int main ()
{
	int a[]={0,1,2,3};
	for(int i=0;i<4;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	f(a);
	for(int i=0;i<4;i++)
	{
		printf("%d ",a[i]);
	}
	
}
