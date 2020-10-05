#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int a[maxn];

//返回第一个大于x的数字的坐标
int find(int l,int r,long long x){
    //若所有书都小于x
    if(a[r]<=x) return r+1;
    while(l<r)
    {
        int mid=(r+l)/2;
        if(a[mid]<=x) l=mid+1;
        else r=mid;
    }
    return r;
}
int main()
{
	int n, p;
	scanf("%d%d", &n,&p);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a, a + n);
    //遍历查找用二分
    int maxlen=1;
    for(int i=0;i<n;i++)
    {
        int index=find(i+1,n-1,(long long)a[i]*p);
        int len=index-i;
        if(len>maxlen) maxlen=len;
    }
    printf("%d",maxlen);
    
}