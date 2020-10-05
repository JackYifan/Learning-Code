#include<cstdio>

double a[1010] = { 0 };
int main()
{
	for (int i = 1; i <= 2; i++)
	{

		int n;
		scanf("%d", &n);
		for (int j = 1; j <= n; j++)
		{
			int exp;
			scanf("%d", &exp);
			double coe;
			scanf("%lf", &coe);
			a[exp]+=coe;
		}
	}
	//处理数据
	int cnt = 0;
	for (int i=0;i<=1001;i++)
	{
		if (a[i]) cnt++;
	}
	printf("%d", cnt);
	for (int j = 1001; j >=0; j--)
	{
		if (a[j]) printf(" %d %.1f", j, a[j]);
	}
	return 0;

}
