#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(char x, char y) {
	return x > y;
}
int convert(char a[]) {
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		ans = ans * 10 + a[i] - '0';
	}
	return ans;
}
bool issame(char a[])
{
	int x = a[0];
	for (int i = 1; i < 4; i++)
	{
		if (a[i] != x) return false;
	}
	return true;
}
void convertToString(int x, char a[])
{
	int cnt = 3;
	for (int i = 0; i < 4; i++) {
		int temp = x % 10;
		a[cnt--] = temp + '0';
		x /= 10;
	}
}
int main()
{
	char a[5];
	int n;
	scanf("%d", &n);
	convertToString(n,a);
	while (1) {
		sort(a, a + 4, cmp);
		int x = convert(a);
		sort(a, a + 4);
		int y = convert(a);
		int ans = x - y;
		printf("%04d - %04d = %04d\n", x, y, ans);
		if (ans == 6174 || ans == 0) break;
		convertToString(ans, a);
	}

}
