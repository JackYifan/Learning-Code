#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int a[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	//sort(a+1,a+n+1);
	// int now=1;
	// int res=a[1]-1;
	// for(int i=a[1];i<=a[n];i++){
	// 	while(a[now]<=i&&now<=n) now++;
	// 	if(n-now+1==i) 
	// 	{
	// 		res=i;
	// 	} 
	// }
	sort(a,a+n,cmp);
	int res=0;
	while(res<n&&a[res]>res+1) res++;
	printf("%d",res);
	return 0;
}
