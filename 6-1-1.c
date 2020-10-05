#include<stdio.h>
int main()
{
	char ch[2][5]={"6937","7254"},*p[2];
	int i,j,s=0;
	for(i=0;i<2;i++) 
  	  p[i]=ch[i];
	for(i=0;i<2;i++)
	  for(j=0;p[i][j]>'\0';j+=2)
		s=10*s+p[i][j]-'0';
	printf("%d\n",s);
	return 0;
}