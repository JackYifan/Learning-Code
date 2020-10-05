#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
const int maxn = 100010;
bool cmp(string a, string b)
{
	return a + b < b + a;
}
int main()
{
	//vector<string>v;
	//char a[1000][1000];
	string str[maxn];
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		//scanf("%s", a[i]);
		cin >> str[i];
	}
	sort(str,str+n,cmp);
	string ans;
	for (int i = 0; i < n; i++)
	{
		ans += str[i];
	}
	while (ans.size() != 0 && ans[0] == '0')
	{
		ans.erase(ans.begin());
	}
	if (ans.size() == 0) cout << 0;
	else cout << ans;

}
