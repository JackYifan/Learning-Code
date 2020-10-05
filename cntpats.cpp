#include<stdio.h>
#include<string.h>
int main()
{
	int ans = 0;
	char a[1000011];
	gets(a);
	int p[100]={0};//打表 
	int t[100];
	int len=strlen(a);
	for(int i=1;i<len;i++)
	{
		if(a[i-1]=='P') p[i]=p[i-1]+1;
		else p[i]=p[i-1];
	}
	
	//
	t[len-1]=0;
	for(int j=len-2;j>=0;j--)
	{
		if(a[j+1]=='T') t[j]=t[j+1]+1;
		else t[j]=t[j+1];
        if(a[j]=='A') 
		{
			ans=(ans+t[j]*p[j])%1000000007;
		}
	}
	printf("%d",ans);
	
	return 0;
}