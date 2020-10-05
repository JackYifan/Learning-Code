#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
vector<int>v;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int N;
	scanf("%d", &N);
	int n, m;
	for (n = sqrt((double)N); n >= 1; n--)
	{
		if (N%n == 0)
		{
			m = N / n;
			break;
		}
	}

	for (int i=0; i < N; i++)
	{
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	sort(v.begin(), v.end(), cmp);
	//二维数组
	vector<vector<int> >b(m, vector<int>(n));
	int level = (m + 1) / 2;
	int t = 0;
	for (int i = 0; i < level; i++)
	{
		for (int j = i; j <= n - 1 - i && t <= N - 1; j++) b[i][j] = v[t++];
		for (int j = i + 1; j <= m - 2 - i && t <= N - 1; j++) b[j][n - 1 - i] = v[t++];
		for (int j = n - 1 - i; j >= i && t <= N - 1; j--) b[m - 1 - i][j] = v[t++];
		for (int j = m - 2 - i; j >= i + 1 && t <= N - 1; j--) b[j][i] = v[t++];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", b[i][j]);
			if (j < n - 1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}