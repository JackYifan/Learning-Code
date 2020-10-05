#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int a[maxn];
int leftmax[maxn];
int rightmin[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	leftmax[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > leftmax[i - 1]) leftmax[i] = a[i];
		else leftmax[i] = leftmax[i - 1];
	}
	rightmin[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (a[i] < rightmin[i + 1]) rightmin[i] = a[i];
		else rightmin[i] = rightmin[i + 1];
	}
	vector<int>ans;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == leftmax[i] && a[i] == rightmin[i])
		{
			ans.push_back(a[i]);
		}
	}
	sort(ans.begin(), ans.end());
	int cnt = ans.size();
	printf("%d\n", cnt);
	if (cnt == 0) printf("\n");
	for (int i = 0; i < cnt; i++)
	{
		printf("%d", ans[i]);
		if (i < cnt - 1) printf(" ");
	}
	return 0;
	

}