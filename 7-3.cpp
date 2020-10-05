#include<stdio.h>
int main()
{
	int n,cnt=0,i;
	scanf("%d",&n);
	getchar();
	int b[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char M[]="10X98765432";
	for(i=1;i<=n;i++)
	{
		char a[20];
		gets(a);
		int flag=1;
		//检验前17位全为数字 
		for(int j=0;j<17;j++)
		{
			if(a[j]>'9'||a[j]<'0')
			{
				flag=0;break;
			}
		} 
		
		//计算m 
		int sum,k,z;
		char m;
		sum=0;
		for(k=0;k<17;k++)
		{
			sum+=(a[k]-'0')*b[k];
		}
		z=sum%11;
		
		//检验最后一位 
		if(a[17]!=M[z]) flag=0;
		if(flag==0) printf("%s\n",a);
		else cnt++; 
	}
	if(cnt==n) printf("All passed");
	return 0;
}