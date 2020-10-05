#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
typedef long long LL;
int cnt;
string _double(string a)
{

	string ans = a;

	int flag = 0;
	for (int i=a.length()-1;i>=0;i--)
	{
		int x =( a[i]-'0') * 2+flag;
		flag = x / 10;
		ans[i] = x % 10+'0';
	}
	if (flag == 1) ans.insert(ans.begin(), '1');
	return ans;
}
string change(LL x)
{
	string ans;
	while (cnt--) {
		ans.append(1, x % 10 + '0');
		x /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main() {
	string str;
	cin >> str;
	cnt = str.length();
	string temp = str;
	str = _double(str);
	string print = str;
	sort(str.begin(), str.end());
	sort(temp.begin(), temp.end());
	if (str == temp)
	{
		printf("Yes\n");
	}
	else printf("No\n");
	cout << print;


}