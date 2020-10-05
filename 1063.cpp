#include<cstdio>
#include<set>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	set<int> st[51];
	for (int i = 1; i <= n; i++)
	{
		int num;
		scanf("%d", &num);
		for (int j = 1; j <= num; j++)
		{
			int x;
			scanf("%d", &x);
			st[i].insert(x);
		}
	}
	int tot,x,y;
	set<int>::iterator it;
	scanf("%d", &tot);
	for (int i = 1; i <= tot; i++)
	{
		
		scanf("%d%d", &x, &y);
		int totalnumber = st[y].size(), samenumber = 0;
		//处理数据
		for (it = st[x].begin(); it != st[x].end(); it++)
		{
			if (st[y].find(*it) == st[y].end())
			{
				totalnumber++;
			}
			else samenumber++;
		}
		double result = 100.0 * samenumber / totalnumber;
		printf("%.1f%%\n", result);
	}
	return 0;
}
