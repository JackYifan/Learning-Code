#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const int maxn = 100010;
struct Node {
	string name;
	int height;
};
int n, k;

bool cmp(Node a, Node b)
{
	return a.height != b.height ? a.height > b.height:a.name < b.name;
}
int main()
{
	cin >> n >> k;
	vector<Node>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].name >> v[i].height;
	}
	sort(v.begin(), v.end(), cmp);
	int row = k;
	int m;//每排的人数
	int t = 0;//从头到尾 
	int j = 0;
	while (row) {
		//对每一行进行处理
		if (row == k) m = n - (k - 1)*n / k;//除了最后一排其他都是n/k;
		else m = n / k;
		vector<string>ans(m);
		ans[m / 2] = v[t].name;
		j = m / 2 - 1;
		for (int i = t + 1; i < t + m; i += 2)
		{
			ans[j--] = v[i].name;
		}
		j = m / 2 + 1;
		for (int i = t + 2; i < t + m; i += 2) {
			ans[j++] = v[i].name;
		}
		cout << ans[0];
		for (int i = 1; i < m; i++) {
			cout << " " << ans[i];
		}
		cout << endl;
		t = t + m;
		row--;
	}
	return 0;
}