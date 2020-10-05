#include<cstdio>
const int maxn = 100010;
int main() {
	int n;
	scanf("%d", &n);
	double a[maxn];
	double sum = 0;
	// (i)*(n-i+1)
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &a[i]);
		sum += a[i] * (i)*(n - i + 1);
	}
	printf("%.2f", sum);
}