#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 2000;
const int inf = 1000000000;
int n, m, k, q;
struct Node {
	int id;
	int begin;
	int server_time;
	int finish;
}node[maxn];
struct Window {
	int pop;
	int end;
	queue<Node>que;
}window[250];

int time[maxn];
inline int gettime(int hour, int minute) {
	return hour * 60 + minute;
}
void printtime(int time) {
	int hour = time / 60;
	int minute = time % 60;
	printf("%02d:%02d\n", hour, minute);
}
int main()
{
	int begin_time = gettime(8, 0);
	int end_time = gettime(17, 0);
	int cur = begin_time;

	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &node[i].server_time);
		node[i].id = i;
	}
	//初始化
	for (int i = 1; i <= n; i++)
	{
		window[i].end = begin_time;
	}
	int index = 1;
	for (int i = 1; i <= n * m; i++)
	{
		if (index > m) index = 1;

		node[i].finish = window[index].end + node[i].server_time;
		window[index].end = node[i].finish;
		window[index].que.push(node[i]);
		index++;
	}
	for (int i = n * m + 1; i <= k; i++)
	{
		//对每个人分析
		//找队伍最后一个人finish最短的窗口
		int min = inf, index = -1;
		for (int j = 1; j <= n; j++)
		{
			if ((window[j].pop = window[j].que.front().finish) < min)
			{
				min = window[j].pop;
				index = j;
			}

		}
		window[index].que.pop();

		node[i].finish = window[index].end + node[i].server_time;
		window[index].end = node[i].finish;
		window[index].que.push(node[i]);

	}
	for (int i = 0; i < q; i++)
	{
		int query;
		scanf("%d", &query);
		if (node[query].finish - node[query].server_time >= end_time) {
			printf("Sorry\n");
		}
		else printtime(node[query].finish);
	}
}