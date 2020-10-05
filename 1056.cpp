#include<cstdio>
#include<queue>
using namespace std;
struct mice {
	int weight;
	int order;
}a[1010];
queue<int>q;
int main()
{
	int ng, np;
	scanf("%d %d", &np, &ng);
	//输入老鼠的重量
	for (int i = 0; i < np; i++)
	{
		scanf("%d", &a[i].weight);
	}
	//用编号代表老鼠时期排队
	for (int i = 0; i < np; i++)
	{
		int x;
		scanf("%d", &x);
		q.push(x);
	}
	int temp = np,group;
	//循环模拟相同的操作
	while (q.size() != 1)
	{
		if (temp % ng == 0) group = temp / ng;
		else group = temp / ng + 1;
		//每一组
		for (int i = 0; i < group; i++)
		{

			int k = q.front();
			for (int j = 0; j < ng; j++)
			{
				//最后一组不足的情况
				if (i * ng + j >= temp) break;
				int front = q.front();
//				if (a[q.front()].weight <= a[k].weight)
//				{
//					a[q.front()].order = group + 1;
//				}
//				else
				if(a[front].weight>a[k].weight)
				{
					k = q.front();
				}
				a[front].order = group + 1;
				q.pop();
			}
			//k为优胜的小鼠
			q.push(k);
		}
		temp = group;
	}
	a[q.front()].order = 1;
	for (int i = 0; i < np; i++)
	{
		printf("%d", a[i].order);
		if (i < np - 1) printf(" ");
	}
}
