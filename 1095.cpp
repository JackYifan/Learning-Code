#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include <string>
#include<iostream>
using namespace std;
const int maxn = 100010;
int n, m;
struct Node {
	char name[15];
	int time;
	char status[4];
}node[maxn];
bool cmp(Node a, Node b) {
	if (strcmp(a.name,b.name)!=0) return strcmp(a.name,b.name)<0;
	else return a.time < b.time;
}


map<string, int>parktime;
int main()
{
	scanf("%d%d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++)
	{
		int hh, mm, ss;
		scanf("%s %d:%d:%d %s", node[i].name, &hh, &mm, &ss,node[i].status);
		int time = hh * 60 * 60 + mm * 60 + ss;
		node[i].time = time;
		getchar();
	}
	sort(node, node + n, cmp);
	
	for (int i = 0; i < n; )
	{
		if (strcmp(node[i].status, "in") == 0 && strcmp(node[i + 1].status,"out") == 0)
		{
			parktime[node[i].name] += node[i + 1].time - node[i].time;
			i += 2;
		}
		else
		{
			i++;
		}
	}
	for (int j = 0; j < m; j++)
	{
		int cnt = 0;
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int requery = h * 3600 + m * 60 + s;
		for (int i = 0; i < n; i++)
		{
			
			if (node[i].time<=requery && node[i + 1].time>requery&&strcmp(node[i].status,"in")==0&&strcmp(node[i+1].status,"out")==0)
			{
				if(strcmp(node[i].name, node[i + 1].name) == 0)
				cnt++;
			}
			
		}
		printf("%d\n", cnt);
	}
	int maxtime = 0;

	map<string, int>::iterator it;	
	for (it=parktime.begin(); it != parktime.end(); it++)
	{
		if (it->second > maxtime)
		{
			maxtime = it->second;
		}
	}
	for (it = parktime.begin(); it != parktime.end(); it++)
	{
		if (it->second==maxtime)
		{
			cout << it->first << " ";
		}
	}
	int hour = maxtime / 3600;
	maxtime %= 3600;
	int minute = maxtime / 60;
	maxtime %= 60;
	printf("%02d:%02d:%02d", hour, minute, maxtime);



	
}
