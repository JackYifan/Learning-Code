#include<stdio.h>
int main()
{
	int a[2500005],b[2500005];
	int n,m,i,k=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
	}
	int p=0,q=0;
	int temp[5000010];
	while (p <= n-1 && q <= m-1) {
			if (a[p] < b[q])
				temp[k++] = a[p++];
			else
				temp[k++] = b[q++];
		}
		while (p <= n-1) {
			temp[k++] = a[p++];
		}
		while (q <= m-1) {
			temp[k++] = b[q++];
		}
	int t=(m+n)/2;
   printf("%d",temp[t]);
}