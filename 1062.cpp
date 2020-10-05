#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;
struct Node
{
	char id[10];
	int de, cai, sum;
	int flag;
}node[maxn];
bool cmp(Node x, Node y)
{
	if (x.flag == y.flag)
	{
		if (x.sum == y.sum)
		{
			if (x.de == y.de)
			{
				return strcmp(x.id, y.id)<=0;
			}
			else return x.de > y.de;
		}
		else return x.sum > y.sum;
	}
	else return x.flag < y.flag;
}
int main()
{
	int n, l, h;
	scanf("%d%d%d", &n, &l, &h);
	int tot = n;
	getchar();
	for (int i = 0; i < tot; i++)
	{
		scanf("%s%d%d", node[i].id, &node[i].de, &node[i].cai);
		node[i].sum = node[i].de + node[i].cai;
		if (node[i].de < l || node[i].cai < l)
		{
			node[i].flag = 5;
			n--;
		}
		else
		{
			if (node[i].de >= h && node[i].cai >= h) node[i].flag = 1;
			else if (node[i].de >= h && node[i].cai < h) node[i].flag = 2;
			else if (node[i].de>=node[i].cai) node[i].flag = 3;
			else node[i].flag = 4;
		}
		getchar();
	}
	sort(node, node + tot, cmp);
	printf("%d\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("%s %d %d\n", node[i].id, node[i].de, node[i].cai);
	}
	return 0;

}