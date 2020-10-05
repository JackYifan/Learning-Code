#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1010];
int ans[1010];
int getleft(int n)
{
    int h=log2(n+1);
    int x=n-pow(2,h)+1;
    int temp=pow(2,h-1);
    if(x>temp) x=temp;
    return pow(2,h-1)-1+x;
}
void solve(int aleft,int aright,int root)
{
    int n=aright-aleft+1;
    if(n==0) return ;
    int left=getleft(n);
    ans[root]=a[aleft+left];
    solve(aleft,aleft+left-1,2*root+1);
    solve(aleft+left+1,aright,2*root+2);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int root=getleft(n);
    solve(0,n-1,root);
    for(int i=0;i<n;i++)
    {
        printf("%d",ans[i]);
    }
}
