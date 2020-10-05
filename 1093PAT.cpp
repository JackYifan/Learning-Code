#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100010;
const int mod = 1000000007;
int p[maxn];
int t[maxn];
int main()
{
	char a[maxn];
	cin.getline(a, maxn);
	int len = strlen(a);
	int nump = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i] == 'P') nump++;
		else if (a[i] == 'A') p[i] = nump;
	}
	int numt = 0;
	int ans = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (a[i] == 'T') numt++;
		else if (a[i] == 'A') ans=(ans+ numt * p[i])%mod;
	}
	printf("%d", ans%mod);


}