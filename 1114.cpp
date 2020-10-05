#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 10005;
struct Node
{
	int id, fid, mid, num, area;
	int cid[10];
}node[maxn];
struct Family
{
	int id, people;
	double num, area;

}family[maxn];
int father[maxn];
bool visit[maxn];
bool cmp(Family a, Family b) {
	return a.area == b.area ? a.id<b.id : a.area>b.area;
}
//并查集模板代码
int find(int x)
{
	while (x != father[x]) x = father[x];
	return x;
}
void Union(int a, int b)
{
	int faA = find(a);
	int faB = find(b);
	if (faA > faB) father[faA] = faB;
	else if (faA < faB) father[faB] = faA;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < maxn; i++)
	{
		father[i] = i;
	}
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d %d %d %d", &node[i].id, &node[i].fid, &node[i].mid, &k);
		visit[node[i].id] = true;
		if (node[i].fid != -1) {
			visit[node[i].fid] = true;
			Union(node[i].id, node[i].fid);
		}
		if (node[i].mid != -1) {
			visit[node[i].mid] = true;
			Union(node[i].id, node[i].mid);
		}
		for (int j = 0; j < k; j++) {
			scanf("%d", &node[i].cid[j]);
			visit[node[i].cid[j]] = true;
			Union(node[i].cid[j], node[i].id);
		}
		scanf("%d %d", &node[i].num, &node[i].area);
	}
	//形成多条链
	//int cnt=0;
	set<int>set;
	for (int i = 0; i < n; i++) {
		int id = find(node[i].id);
		set.insert(id);
		family[id].id = id;
		family[id].num += node[i].num;
		family[id].area += node[i].area;
	}
	for (int i = 0; i < maxn; i++) {
		if (visit[i]) family[find(i)].people++;
	}
	for (auto it = set.begin(); it != set.end(); it++) {
		int i = *it;
		family[i].num = (double)(family[i].num*1.0 / family[i].people);
		family[i].area = (double)(family[i].area*1.0 / family[i].people);
	}
	sort(family, family + maxn, cmp);
	printf("%d\n", set.size());
	for (int i = 0; i < set.size(); i++) {
		printf("%04d %d %.3f %.3f\n", family[i].id, family[i].people, family[i].num, family[i].area);
	}
	return 0;
}