#include<cstdio>
const int maxn = 10010;
struct Num
{
	long long up;
	long long down;
}num[maxn];
Num add(Num a, Num b)
{
	Num ans;
	ans.up = a.up*b.down + a.down*b.up;
	ans.down = a.down*b.down;
	return ans;
}
long long gcb(long long a, long long b)
{
	if (b == 0) return a;
	else return gcb(b, a%b);
}
int flag = 0;
long long x=0;
void adjust(Num&a)
{
	
	if (a.down < 0)
	{
		a.up = -a.up;
		a.down = -a.down;
	}
	if (a.up < 0)
	{
		a.up = -a.up;
		flag = -1;
	}
	long long fac = gcb(a.down, a.up);
	if (fac != 0)
	{
		a.up /= fac;
		a.down /= fac;
	}
	
	if (a.up > a.down)
	{
		x = a.up / a.down;
		a.up = a.up%a.down;
	}

}
int main()
{
	long long n;
	scanf("%ld", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%ld/%ld", &num[i].up, &num[i].down);
	}
	Num sum=num[0];
	for (int i = 1; i < n; i++)
	{
		sum=add(sum, num[i]);
	}
	adjust(sum);
	if (flag == -1) printf("-");
	if (x > 0) printf("%ld", x);
    if(x==0&&sum.up==0) printf("0");
	if (sum.up != 0)
	{
		if (x > 0) printf(" ");
		printf("%ld/%ld", sum.up, sum.down);
	}

}
