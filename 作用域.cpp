#include<stdio.h>
#include"x.h"
//鍏ㄥ眬鍙橀噺
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
	extern int A;//申明这是外部变量，程序会在函数外部查找 
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
