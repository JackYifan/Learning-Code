#include<stdio.h>
#include"x.h"
//全局变量
int x;
int f(void)
{
	extern int A ;
	static int c=4;
	c+=A;
	return c;
 } 
int main()
{
	extern int A;//���������ⲿ������������ں����ⲿ���� 
	extern int X;
    int y;
    static int z;
    printf("%d ",X);
    printf("%d %d %d %d\n",x,y,z,A);
    for(int i=0;i<3;i++)
    {
    	printf("%d ",f());
	}

    
}
int A=100;
