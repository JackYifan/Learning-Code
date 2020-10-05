#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn=1010;
const int maxv=3030;
int n,m;
int ans=0;
int father[maxn];
int flag=1;
struct Road
{
    int u,v;
    int cost ;
    friend bool operator<(Road a,Road b)
    {
        return a.cost>b.cost;
    }
}road[maxv];
priority_queue<Road>q;
bool cmp(Road a,Road b){
    return a.cost<b.cost;
}
int findfather(int x){
    int temp=x;
    while(x!=father[x])
    {
        x=father[x];
    }
    while(temp!=x)
    {
        father[temp]=x;
        temp=father[temp];
    }
    return x;
}
void Kruskal()
{
    int num=0;
    //初始化
    for(int i=1;i<=n;i++)
    {
        father[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        // Road top=q.top();
        // q.pop();
        int fau=findfather(road[i].u);
        int fav=findfather(road[i].v);
        if(fau!=fav)
        {
            
            for(int j=i+1;j<m;j++)
            {
                if(road[j].cost==road[i].cost)
                {
                    int fa=findfather(road[j].u);
                    int fb=findfather(road[j].v);
                    
                    if(((fa==fau)&&(fb==fav))||((fa==fav)&&(fb==fau)))
                    {
                        flag=0;
                    }
                }
                else break;
            }
            father[fau]=fav;
            ans+=road[i].cost;
            num++;
        }
        // int fau=findfather(top.u);
        // int fav=findfather(top.v);
        // if(fau!=fav)
        // {
        //     father[fau]=fav;
        //     ans+=top.cost;
        //     num++;
        // }
        if(num==n-1) break;
    }
    if(num!=n-1){
        flag=-1;
        printf("No MST\n");
        printf("%d",n-num);
    }
    
}
int main()
{
    
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d%d",&road[i].u,&road[i].v,&road[i].cost);
        q.push(road[i]);
    }
    sort(road,road+m,cmp);
    Kruskal();
    if(flag!=-1)
    {
        printf("%d\n",ans);
        if(flag==1)
        {
            printf("Yes");
        }
        else printf("No");
    }
}