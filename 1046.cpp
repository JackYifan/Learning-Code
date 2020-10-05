#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int a[maxn];
int dis[maxn]={0};
int x,y;
int n;
int tot;
int mindistance()
{
    int sum=0;
    if(x>y) swap(x,y);
    for(int i=x;i<y;i++)
    {
        sum+=a[i];
    }
    return sum;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        tot+=a[i];
        dis[i+1]=tot;
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
       scanf("%d%d",&x,&y);
       //int r1=mindistance();
       if(x>y) swap(x,y);
       int r1=dis[y]-dis[x];
       int r2=tot-r1;
       printf("%d\n",min(r1,r2));
    }
    
}