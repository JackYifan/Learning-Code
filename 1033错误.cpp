#include<cstdio>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct Node {
	double price;
	double dis;
}node[maxn];
bool cmp(Node a, Node b)
{
	return a.dis < b.dis;
}
int main()
{
	double col;
	double distance;
	double perdis;
	int n;
	scanf("%lf%lf%lf%d", &col, &distance, &perdis, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf %lf", &node[i].price, &node[i].dis);
	}
	node[n].dis = distance;
	node[n].price = 0;
	sort(node, node + n+1, cmp);
	double nowdis = 0;
	double nowcol = 0;
	double totprice = 0;
	int index = 0;
	//初始化
    if (node[0].dis != 0) {
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	while (index<n)
	{
		double range = nowdis + col * perdis;
		/*if (range >= distance)
		{
			totprice += (distance - nowdis) / perdis * node[index].price;
			break;
		}*/
		double min = maxn;
		int temp = index;
		if (node[index + 1].dis > range)
		{
			double max = node[index].dis + col * perdis;
			printf("The maximum travel distance = %.2f", max);
			return 0;
		}
		for (int i = index+1; node[i].dis <= range; i++)
		{
			if (node[i].price < min)
			{
				min = node[i].price;
				index = i;
				if(min < node[temp].price) break;
			}
		}
		//int farindex = i - 1;

		//若初始点的价格最便宜则油箱加满
		if (min>node[temp].price)
		{
			totprice += (col - nowcol) * node[temp].price;
			nowcol = col - 1.0 * (node[index].dis-nowdis) / perdis;
			nowdis = node[index].dis;
		}
		else
		{
			double x = node[index].dis - nowdis;//x为走过的路程
			nowcol = 0;
			totprice += 1.0 * x / perdis * node[temp].price;
			nowdis = node[index].dis;
		}
		
		
	}
	printf("%.2f", totprice);
}