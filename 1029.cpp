#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
const int inf = 1000000000;
int n, m;
int a[maxn], b[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}
	a[n] = b[m] = inf;
	int i = 0, j = 0;
	int pos = (n + m - 1) / 2;
	int cnt = 0;
	while (cnt<pos)
	{
		if (a[i] == b[j])
		{
			i++;
			j++;
			cnt += 2;
		}
		else if (a[i] < b[j])
		{
			i++;
			cnt++;
		}
		else if (a[i] > b[j])
		{
			j++;
			cnt++;
		}
	}
	int ans = min( a[i],b[j] );
	printf("%d", ans);
}