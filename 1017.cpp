#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int inf = 1000000000;
const int maxn = 100010;
struct Node {
	int come;
	int time;
}node[maxn];
vector<Node> q;
int ans;
int convert(int hour, int min, int sec)
{
	int ans = hour * 3600 + min * 60 + sec;
	return ans;
}
bool cmp(Node a, Node b)
{
	return a.come < b.come;
}
int freetime[maxn];//第I个窗口的空闲时间
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int startTime = convert(8, 0, 0);
	for (int i = 0; i < m; i++)
	{
		freetime[i] = startTime;
	}
	int endTime = convert(17, 0, 0);
	for (int i = 0; i < n; i++)
	{
		int hour, min, sec;
		int during;
		scanf("%d:%d:%d", &hour, &min, &sec);
		scanf("%d", &during);
		int come_time= convert(hour, min, sec);
		if (come_time > endTime) continue;
		node[i].come = come_time;
		node[i].time = during <= 60 ? during*60 : 3600;
		q.push_back(node[i]);
	}
	sort(q.begin(), q.end(), cmp);
	for (int i = 0; i < q.size(); i++)
	{
		//找到最早free的窗口
		int minindex = -1, mintime = inf;
		for (int i = 0; i < m; i++)
		{
			
			if (freetime[i] < mintime)
			{
				minindex = i;
				mintime = freetime[i];
			}
		}
		//最早的人到最早的窗口办理业务
		Node firstnode = q[i];
		if (freetime[minindex] <= firstnode.come) freetime[minindex] = firstnode.come + firstnode.time;
		else
		{
			ans += freetime[minindex] - firstnode.come;
			freetime[minindex] += firstnode.time;
		}
		
	}
	if (q.size() == 0) printf("0.0\n");
	else printf("%.1f", ans/60.0/q.size());


}