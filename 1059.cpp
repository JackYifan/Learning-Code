#include<cstdio>
#include<cmath>
const int maxn = 100010;
int prime[maxn];
struct factor {
	int val;
	int num;
}fac[10];
bool isprime(int n)
{
	if (n == 1) return false;
	int sqr = (int)sqrt(1.0*n);
	for (int i = 2; i <= sqr; i++)
	{
		if (n%i == 0) return false;
	}
	return true;
}
int pnum = 0;
void find_prime() {

	for (int i = 2; i < maxn; i++)
	{
		if (isprime(i))
			prime[pnum++] = i;
	}
}
int main()
{
	//质数表
	find_prime();
	//
	int n;
	int cnt = 0;
	scanf("%d", &n);
	int temp = n;
	int upper = (int)sqrt(1.0*n);
	for (int i = 0; prime[i] < upper&&i < pnum; i++)
	{
		if (n%prime[i] == 0)
		{
			fac[cnt].val = prime[i];
			fac[cnt].num++;
			n /= prime[i];
			while (n%prime[i] == 0)
			{
				fac[cnt].num++;
				n /= prime[i];
			}
			cnt++;
		}
		if (n == 1) break;
	}
	if (n != 1) {
		fac[cnt].val = n;
		fac[cnt].num = 1;
		cnt++;
	}
	//打印
	printf("%d=", temp);
	for (int i = 0; i < cnt; i++)
	{
		printf("%d", fac[i].val);
		if (fac[i].num != 1) printf("^%d", fac[i].num);
		if (i < cnt - 1) printf("*");
	}

}