#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int a[maxn];
int dp[maxn];//以i结尾的最大值
int s[maxn] = { 0 };//用于存放起始元素的位置
int main()
{
	int n;
	scanf("%d", &n);
	int flag = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > 0) flag = 0;
	}
	if (flag == 1) printf("0 %d %d", a[0], a[n - 1]);
	else
	{

		dp[0] = a[0];
		for (int i = 1; i < n; i++)
		{
			if (a[i] < dp[i - 1] + a[i])
			{
				dp[i] = a[i] + dp[i - 1];
				s[i] = s[i - 1];
			}
			else
			{
				dp[i] = a[i];
				s[i] = i;
			}
		}
		int max = 0, index = 0;
		int min = maxn;
		for (int i = 0; i < n; i++)
		{
			if (dp[i] > max)
			{
				max = dp[i];
				index = i;
				min = s[i];
			}
			else if (dp[i] == max && s[i] < min)
			{
				index = i;
				min = s[i];
			}
		}
		printf("%d %d %d", dp[index], a[s[index]], a[index]);
	}
	return 0;
}