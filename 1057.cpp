#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100010;
const int sqrn = 316;
int block[sqrn];
int table[maxn];
vector<int> v;
vector<int> temp;
//查找第k大的元素,并打印
void peekMedian(int k) {
	int sum = 0;
	int cnt = 0;
	while (sum < k) {
		sum += block[cnt++];
	}
	//就在cnt-1这个块中,回退
	cnt--;
	sum -= block[cnt];
	int i;
	for ( i = sqrn *(cnt); i < sqrn*(cnt+1); i++) {
		if(sum < k) {
			sum += table[i];
		}
		else {
			break;
		}
	}
	printf("%d\n", --i);
}
int main()
{
	int n;
	scanf("%d", &n);
	memset(table, 0, sizeof(table));
	memset(block, 0, sizeof(block));
	getchar();
	for (int i = 0; i < n; i++)
	{
		char a[100];
		scanf("%s", a);
		if (strcmp(a, "Pop") == 0)
		{
			if (v.size() == 0) printf("Invalid\n");
			else {
				int val = v.at(v.size() - 1);
				block[val / sqrn]--;
				table[val]--;
				printf("%d\n", val);
				v.pop_back();
			}
		}
		else if (strcmp(a, "PeekMedian") == 0)
		{
			int cnt = v.size();
			if (cnt == 0) {
				printf("Invalid\n");
			}
			else {
				if (cnt % 2 == 0) cnt = cnt / 2;
				else cnt = (cnt + 1) / 2;
				//temp = v;
				//sort(temp.begin(), temp.end());
				//printf("%d\n", temp[cnt-1]);
				peekMedian(cnt);
			}
			
		}
		else
		{
			int x;
			scanf("%d", &x);
			block[x / sqrn]++;
			table[x]++;
			v.push_back(x);
		}
		getchar();
	}
}