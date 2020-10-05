#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
struct Node {
	string id;
	int val;
};


bool cmp(Node a, Node b) {
	return a.val != b.val ? a.val > b.val:a.id < b.id;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<Node>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].id >> v[i].val;
	}
	for (int i = 1; i <= m; i++) {
		int x; string s;
		cin >> x >> s;
		printf("Case %d: %d %s\n", i, x, s.c_str());
		if (x == 1) {
			vector<Node>ans;
			for (int j = 0; j < n; j++) if (v[j].id[0] == s[0]) ans.push_back(v[j]);
			if (ans.size() == 0) {
				printf("NA\n");
				continue;
			}
			sort(ans.begin(), ans.end(), cmp);
			for (auto it : ans) {
				cout << it.id << " " << it.val << endl;
			}
		}
		else if (x == 2) {
			vector<Node>ans;
			for (int j = 0; j < n; j++) {

				string t = v[j].id.substr(1, 3);
				if (t == s) ans.push_back(v[j]);
			}

			int num = 0, tot = 0;
			for (auto it : ans) {
				num++;
				tot += it.val;
			}
			if (num == 0) {
				printf("NA\n");
				continue;
			}
			cout << num << " " << tot << endl;
		}
		else if (x == 3) {
			vector<Node>ans;
			unordered_map<string, int>mp;
			//map 考场->考场人数
			for (int j = 0; j < n; j++) {
				string site = v[j].id.substr(1, 3);
				string date = v[j].id.substr(4, 6);
				if (date == s) {
					mp[site]++;
				}
			}
			for (auto it : mp) ans.push_back({ it.first,it.second });
			if (ans.size() == 0) {
				printf("NA\n");
				continue;
			}

			sort(ans.begin(), ans.end(), cmp);
			for (auto it : ans) {
				cout << it.id << " " << it.val << endl;
			}
		}


	}
}