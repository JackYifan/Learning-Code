#include<cstdio>
#include<cstdlib>
int main()
{
	int n = 10;
	char a[100];
	itoa(n, a, 6);
	printf("%s", a);
	return 0;
}
