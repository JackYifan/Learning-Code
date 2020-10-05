#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int n, m;
int a[maxn];
int sum[maxn] = { 0 };
//二分查找大于等于x的位置
int flag;
int biSearch(int left, int right, int x)
{
	flag = 0;
	while (left < right) 
	{
		int mid = (left + right) / 2;
		if (sum[mid] == x)
		{
			flag = 1;
			return mid;
		}
		if (sum[mid] < x) left = mid + 1;
		else right = mid;
	}
	return right;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	int nears = maxn;
	for (int i = 1; i <= n; i++) 
	{
		int pos=biSearch(i , n, sum[i - 1] + m);
		if (sum[pos] - sum[i - 1] == m) {
			printf("%d-%d\n", i, pos);
			nears = m;
		}
		else
		{
			int s = sum[pos] - sum[i - 1];
			if (s > m&&s - m < nears - m)
			{
				nears = s;
			}
		}
	}
	if (nears != m)
	{
		for (int i = 1; i <= n; i++) 
		{
			int pos = biSearch(i, n, sum[i - 1] + nears);
			if(sum[pos]-sum[i-1]==nears) printf("%d-%d\n", i, pos);
		}
	}
}