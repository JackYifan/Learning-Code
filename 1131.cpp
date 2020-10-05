#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<vector<int> >v(10000);
unordered_map<int, int>line;
const int maxn = 100010;
int visit[maxn];
int mincnt, mintransfer;
int start, end1;
vector<int>path, temppath;
int transfercnt(vector<int>a) {
	//把第一次也视为一次transfer故从-1开始数
	int cnt = -1, preline = 0;
	for (int i = 1; i < a.size(); i++) {
		if (line[a[i - 1] * 10000 + a[i]] != preline) cnt++;
		preline = line[a[i - 1] * 10000 + a[i]];
	}
	return cnt;
}
void DFS(int node, int cnt) {

	//更新条件
	if (node == end1 && (cnt < mincnt || (cnt == mincnt && transfercnt(temppath) < mintransfer))) {
		mincnt = cnt;
		path = temppath;
		mintransfer = transfercnt(temppath);
	}
	//递归结束条件
	if (node == end1) return;
	//遍历结点所有的下一步
	for (int i = 0; i < v[node].size(); i++) {
		if (visit[v[node][i]] == 0)
		{
			visit[v[node][i]] = 1;
			temppath.push_back(v[node][i]);
			DFS(v[node][i], cnt + 1);
			temppath.pop_back();
			visit[v[node][i]] = 0;
		}
	}

}
int main() {
	int n, m, k;
	int pre, temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m >> pre;
		for (int j = 1; j < m; j++) {
			cin >> temp;
			v[pre].push_back(temp);
			v[temp].push_back(pre);
			line[pre * 10000 + temp] = line[temp * 10000 + pre] = i + 1;
			pre = temp;
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> start >> end1;
		mincnt = 99999; mintransfer = 99999;
		//上一个结点为起点的path需要清空
		temppath.clear();
		temppath.push_back(start);
		visit[start] = 1;
		DFS(start, 0);
		visit[start] = 0;
		cout << mincnt << endl;
		int preline = 0;
		int prestation = start;
		for (int j = 1; j < path.size(); j++) {
			//j-1->j换了一条线路
			if (line[path[j - 1] * 10000 + path[j]] != preline) {
				if (preline != 0) printf("Take Line#%d from %04d to %04d.\n", preline, prestation, path[j - 1]);
				preline = line[path[j - 1] * 10000 + path[j]];
				prestation = path[j - 1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", preline, prestation, end1);

	}
	return 0;
}
