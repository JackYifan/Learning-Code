#include<cstdio>
#include<cmath>
const int maxn = 100010;
bool hashTable[maxn];
int ans[maxn];
bool isprime(int x) {
	if (x <= 1) return false;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0) return false;
	}
	return true;
}
int findMinPrime(int x) {
	for (int i = x;; i++) {
		if (isprime(i)) return i;
	}
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if (!isprime(n)) n = findMinPrime(n);
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		if (hashTable[x%n] == false)
		{
			hashTable[x%n] = true;
			printf("%d", x%n);
		}
		else {
			int step = 1;
			for (;step<n; step++) {
				int pos = (x + step * step)%n;
				if(hashTable[pos] == false)
				{
					hashTable[pos] = true;
					printf("%d", pos);
				}
			}
			if (step == n) printf("-");
		}
		if(i!=m-1)printf(" ");
	}
}