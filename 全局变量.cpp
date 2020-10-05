#include<stdio.h>
int n=0;
void f()
{
	n++;
	printf("%d",n);
}
void g()
{
	n++;
	printf("%d",n);
}
int main()
{
	f();
	g();
	return 0;
}
 
