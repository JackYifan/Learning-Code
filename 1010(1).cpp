#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
char N1[11], N2[11];
int tag;
ll radix;
int map[256];
const ll inf = (1LL << 63) - 1;
void init()
{
	for (char c = '0'; c <= '9'; c++)
	{
		map[c] = c - '0';
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		map[c] = c - 'a' + 10;
	}
}
ll changeToTen(char a[], ll radix, ll high) {
	int len = strlen(a);
	ll ans=0;
	for (int i = 0; i < len; i++)
	{
		ans = ans * radix + map[a[i]];
		//考虑溢出
		if (ans < 0||ans>high) return -1;
	}
	return ans;
}
int maxDigit(char a[]) {
	int ans = -1;
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		int digit = map[a[i]];
		if (digit > ans) ans = digit;
	}
	return ans;
}
int cmp(char a[], ll radix, ll n1) {
	ll temp = changeToTen(a, radix,n1);
	if (temp < 0) return 1;
	else if (temp < n1) return -1;
	else if (temp > n1) return 1;
	else if (temp == n1) return 0;
}
ll search(char a[], ll low, ll high, ll n1)
{
	ll left = low;
	ll right = high;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		int flag = cmp(a, mid, n1);
		if (flag==0)
		{
			return mid;
		}
		if (flag < 0) left = mid + 1;
		else if (flag > 0) right = mid - 1;
	}
	return -1;
}
int main()
{
	init();
	scanf("%s %s %d %d", N1, N2, &tag, &radix);
	//设置N1为已知
	if (tag == 2) {
		char temp[20];
		strcpy(temp,N1);
		strcmp(N1,N2);
		strcpy(N2,temp);
	}
	ll n1 = changeToTen(N1,radix,inf);
	ll low = maxDigit(N2) + 1;
	ll high = max(low, n1) + 1;
	ll ans=search(N2, low, high, n1);
	if (ans == -1) printf("Impossible\n");
	else printf("%lld\n", ans);
	return 0;
}
