#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
const int M = 26 * 26 * 26 * 10 + 1;
using namespace std;
int getID(char name[])
{
	int id = 0;
	for (int i = 0; i < 3; i++)
	{
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}
//每个学生有一个vector,所有学生的vector 组成一个数组
vector<int> selectCourse[M];
int main()
{
	int n, k;
	char name[20];
	scanf("%d %d", &n, &k);
	//输入数据
	for (int i = 1; i <= k; i++)
	{
		int course, x;
		scanf("%d %d", &course, &x);
		for (int j = 0; j < x; j++)
		{
			scanf("%s", name);
			int ID = getID(name);
			selectCourse[ID].push_back(course);
		}
	}
	//查询数据
	for (int i = 0; i < n; i++)
	{
		scanf("%s", name);
		int ID = getID(name);
		sort(selectCourse[ID].begin(), selectCourse[ID].end());
		printf("%s %d", name, selectCourse[ID].size());
		vector<int>::iterator it;
		for (it = selectCourse[ID].begin(); it != selectCourse[ID].end(); it++)
		{
			printf(" %d", *it);
		}
		printf("\n");
	}
	return 0;
}
