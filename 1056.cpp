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
	//�������������
	for (int i = 0; i < np; i++)
	{
		scanf("%d", &a[i].weight);
	}
	//�ñ�Ŵ�������ʱ���Ŷ�
	for (int i = 0; i < np; i++)
	{
		int x;
		scanf("%d", &x);
		q.push(x);
	}
	int temp = np,group;
	//ѭ��ģ����ͬ�Ĳ���
	while (q.size() != 1)
	{
		if (temp % ng == 0) group = temp / ng;
		else group = temp / ng + 1;
		//ÿһ��
		for (int i = 0; i < group; i++)
		{

			int k = q.front();
			for (int j = 0; j < ng; j++)
			{
				//���һ�鲻������
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
			//kΪ��ʤ��С��
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
