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
}node[maxn],v[maxn];
bool cmp(Node a, Node b) {
	if (strcmp(a.name,b.name)!=0) return strcmp(a.name,b.name)<0;
	else return a.time < b.time;
}
bool cmpbytime(Node a, Node b)
{
	return a.time < b.time;
}
map<string, int>::iterator it;
int maxtime = 0;
//vector<Node>v;
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
	std::sort(node, node + n, cmp);
	int tot = 0;
	for (int i = 0; i < n-1; i++)
	{
		if (strcmp(node[i].status, "in") == 0 && strcmp(node[i + 1].status, "out") == 0&&!strcmp(node[i].name,node[i+1].name))
		{
			v[tot++] = node[i];
			v[tot++] = node[i + 1];
			int intime= node[i + 1].time - node[i].time;
			if (parktime.count(node[i].name) == 0)
			{
				parktime[node[i].name] += intime;
			}
			maxtime = max( maxtime,parktime[node[i].name]);
			
			/*v.push_back(node[i]);
			v.push_back(node[i + 1]);*/
		}
	}
	//for (it = parktime.begin(); it != parktime.end(); it++)
	//{
	//	if (it->second > maxtime)
	//	{
	//		maxtime = it->second;
	//	}
	//}
	std::sort(v, v+tot,cmpbytime);
	//int tot = v.size();
	for (int j = 0; j < m; j++)
	{
		int cnt = 0;
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int requery = h * 3600 + m * 60 + s;
		int i = 0;
		while(i<tot&&v[i].time <= requery)
		{
			if (strcmp(v[i].status, "in") == 0) cnt++;
			else cnt--;
			i++;
		}	
		/*if (node[i].time<=requery && node[i + 1].time>requery&&strcmp(node[i].status,"in")==0&&strcmp(node[i+1].status,"out")==0)
		{
			if (strcmp(node[i].name, node[i + 1].name) == 0)
			{
				cnt++;
			}
				
		}*/
		printf("%d\n", cnt);
	}
	

		

	for (it = parktime.begin(); it != parktime.end(); it++)
	{
		if (it->second==maxtime)
		{
			printf("%s ", it->first.c_str());
			//cout << it->first << " ";
		}
	}
	printf("%02d:%02d:%02d", maxtime / 3600, maxtime%3600/60, maxtime % 60);



	
}
