#include<stdio.h>
int main()
{
	int a[5]={1,2};
	for(int i=0;i<5;i++)
	{
		printf("%d",a[i]);
	}
	int x=12345;
	int xx=12345;
	int temp=x;
	int n=1;
	while(temp>9)
	{
		n*=10;
		temp/=10;
	}
	int y=0;
	while(temp!=0)
	{
		y=y*10+x/temp;
		x=x%temp;
		temp/=10;
	}
	printf("%d",y);
	int b[10];
	int i=0;
	int aa[3][2]={{1},{3}};
	
	 
 } 
