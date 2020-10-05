#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=1000000000;
const int maxn=501;
int G[maxn][maxn];
int cost[maxn][maxn];
int d[maxn];
int c[maxn];
bool visit[maxn]={false};
//vector<int>pre[maxn];
int pre[maxn];
vector<int>path[maxn];
int n,m,st,ed,x,y,length,fare;
int maxcost;
void Dij()
{
    // memset(d,0,sizeof(d));
    // memset(c,0,sizeof(c));
    fill(d,d+maxn,inf);
    fill(c,c+maxn,inf);
    for(int i=0;i<n;i++)
    {
        pre[i]=i;
    }
    d[st]=0;
    c[st]=0;
    //每个点访问一边故n重循环
    for(int k=0;k<n;k++)
    {
        //寻找未访问过的最短距离
        int min=inf,u=-1;
        for(int i=0;i<n;i++)
        {
            if(visit[i]==false&&d[i]<min)
            {
                min=d[i];
                u=i;
            }
        }
        if(u==-1) return ;
        //找到就访问这个结点
        visit[u]=true;
        //更新距离
        for(int v=0;v<n;v++)
        {
            if(G[u][v]!=inf&&visit[v]==false)
            {
                if(d[u]+G[u][v]<d[v])
                {
                    d[v]=d[u]+G[u][v];
                    c[v]=c[u]+cost[u][v];
                    pre[v]=u;
                }
                else if(d[u]+G[u][v]==d[v])
                {
                    if(c[u]+cost[u][v]<c[v])
                    {
                        c[v]=c[u]+cost[u][v];
                        pre[v]=u;
                    }
                }
            }
            

        }
    }

}
//利用pre 数组得出路径
void DFS(int v)
{
    if(v==st) 
    {
        printf("%d ",v);
        return;
    }
    DFS(pre[v]);
    printf("%d ",v);
}
int main()
{
    fill(G[0],G[0]+maxn*maxn,inf);
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d%d",&x,&y,&length,&fare);
        G[x][y]=G[y][x]=length;
        cost[x][y]=cost[y][x]=fare;
    }
    Dij();
    DFS(ed);
    printf("%d %d\n",d[ed],c[ed]);
    return 0;
}