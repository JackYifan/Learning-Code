#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
const int maxn = 10000000;
struct Stu
{
	int id;
	int a, c, m, e;
	int ar, cr, mr, er;
}stu[maxn];
bool cmpa(Stu x, Stu y)
{
	return x.a > y.a;
}
bool cmpc(Stu x, Stu y)
{
	return x.c > y.c;
}
bool cmpm(Stu x, Stu y)
{
	return x.m > y.m;
}
bool cmpe(Stu x, Stu y)
{
	return x.e > y.e;
}
int bestrank(Stu x)
{
	int ans = min(min(x.ar, x.cr), min(x.mr, x.er));
	return ans;
}
char bestsub(Stu x, int s)
{
	if (x.ar == s) return 'A';
	else if (x.cr == s) return 'C';
	else if (x.mr == s) return 'M';
	else if (x.er == s) return 'E';
}
int main()
{
	/*char mp[5] = { 'A','C','M','E' };*/
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &stu[i].id, &stu[i].c, &stu[i].m, &stu[i].e);
		stu[i].a = (stu[i].c + stu[i].m + stu[i].e) / 3;
	}
	sort(stu, stu + n, cmpa);
	stu[stu[0].id].ar = 1;
	for (int i = 1; i < n; i++)
	{
		if (stu[i].a == stu[i - 1].a) stu[stu[i].id].ar = stu[stu[i - 1].id].ar;
		else stu[stu[i].id].ar = i + 1;
	}
	sort(stu, stu + n, cmpc);
	stu[stu[0].id].cr = 1;
	for (int i = 0; i < n; i++)
	{
		if (stu[i].c == stu[i - 1].c) stu[stu[i].id].cr = stu[stu[i - 1].id].cr;
		else stu[stu[i].id].cr = i + 1;
	}
	sort(stu, stu + n, cmpm);
	stu[stu[0].id].mr = 1;
	for (int i = 0; i < n; i++)
	{
		if (stu[i].m == stu[i - 1].m) stu[stu[i].id].mr = stu[stu[i - 1].id].mr;
		else stu[stu[i].id].mr = i + 1;
	}
	sort(stu, stu + n, cmpe);
	stu[stu[0].id].er = 1;
	for (int i = 0; i < n; i++)
	{
		if (stu[i].e == stu[i - 1].e) stu[stu[i].id].er = stu[stu[i - 1].id].er;
		else stu[stu[i].id].er = i + 1;
	}
	for (int i = 0; i < m; i++)
	{
		int enq;
		scanf("%d", &enq);
		int flag = 0;
		for (int j = 0; j < n; j++)
		{
			if (enq == stu[j].id) flag = 1;
		}
		if (flag == 0) printf("N/A\n");
		else
		{
			printf("%d %c", bestrank(stu[enq]), bestsub(stu[enq], bestrank(stu[enq])));
			printf("\n");
		}

	}
}