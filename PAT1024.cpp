#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bign
{
	int d[20];
	int len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};
bign add(bign a,bign b)
{
	bign ans;
	int carry = 0;
	int i;
	for ( i = 0; i < a.len; i++)
	{
		int x = a.d[i] + b.d[i] + carry;
		carry = x / 10;
		ans.d[i] = x % 10;
	}
	if (carry != 0) ans.d[i++] = carry;
	ans.len = i;
	return ans;

}
bign f(bign n)
{
	bign ans;
	bign temp = n;
	reverse(n.d, n.d + n.len);
	ans = add(n, temp);
	return ans;
}
bool is(bign a)
{
	for (int i = 0; i <= a.len/2; i++)
	{
		if (a.d[i] != a.d[a.len - 1 - i]) return false;
	}
	return true;
}
int main()
{
	char a[20];
	int k;
	scanf("%s%d", &a,&k);
	bign n;
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		n.d[i] = a[len - 1 - i]-'0';
		n.len++;
	}
	int cnt = 0;
	for (;cnt<k&&!is(n);)
	{
		n = f(n);
		cnt++;
	}
	if (cnt == k)
	{
		
		for (int i = n.len - 1; i >= 0; i--)
		{
			printf("%d", n.d[i]);
		}
		printf("\n");
		printf("%d\n", k);
	}
	else
	{
		for (int i = n.len - 1; i >= 0; i--)
		{
			printf("%d", n.d[i]);
		}
		printf("\n");
		printf("%d\n", cnt);
		
	}

}