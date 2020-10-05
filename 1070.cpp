#include<cstdio>
#include<algorithm>
const int maxn = 10010;
using namespace std;
struct Node {
	double store;
	double totprice;
	double singleprice;
}node[maxn];
bool cmp(Node a, Node b)
{
	return a.singleprice > b.singleprice;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &node[i].store);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &node[i].totprice);
		node[i].singleprice = 1.0 * node[i].totprice / node[i].store;
	}
	double maxprice=0;
	sort(node, node + n, cmp);
	for (int i = 0; i < n; i++)
	{
		if (m > 0)
		{
			if (node[i].store <= m)
			{
				//maxprice += node[i].singleprice * node[i].store;
				maxprice += node[i].totprice;
				m -= node[i].store;
			}
			else
			{
				maxprice += node[i].singleprice * m;
				break;
			}
		}
		
	}
	printf("%.2f", maxprice);
	
}