#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=501;
const int inf=1000000000;
int cmax,n,sp,m;
int cur[maxn];
int G[maxn][maxn];
int d[maxn];
bool visit[maxn]={false};
int weight[maxn];
vector<int>pre[maxn];
void Dijkstra()
{
    fill(d,d+maxn,inf);
    d[0]=0;
    for(int i=0;i<=n;i++)
    {
        int min=inf,u=-1;
        for(int j=0;j<=n;j++)
        {
            if(d[j]<min&&visit[j]==false)
            {
                min=d[j];
                u=j;
            }
        }
        if(u==-1) return ;
        visit[u]=true;
        for(int v=0;v<=n;v++)
        {
            if(G[u][v]!=inf&&visit[v]==false)
            {
                if(d[u]+G[u][v]<d[v])
                {
                    d[v]=d[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[u]+G[u][v]==d[v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
vector<int> path,temppath;

int minneed=inf,minremain=inf;
void DFS(int v)
{
    if(v==0) 
    {
        int need=0,remain=0;
        temppath.push_back(v);
        //更新
        for(int i=temppath.size()-2;i>=0;i--)
        {
            int id=temppath[i];
            // int next=temppath[i-1];
            // temptime+=G[id][next];
            if(weight[id]>0)
            {
                remain+=weight[id];
            }
            else 
            {
                if(abs(weight[id])<=remain)
                {
                    remain-=abs(weight[id]);
                }
                else
                {
                    need+=abs(weight[id])-remain;
                    remain=0;
                }
            }
        }
       
        if(need<minneed)
        {
            minneed=need;
            minremain=remain;
            path=temppath;
        }
        else if(need==minneed)
        {
            if(remain<minremain)
            {
                minremain=remain;
                path=temppath;
            }
        }
    
        //
        temppath.pop_back();
        return ;
    }
    temppath.push_back(v);
    for(int i=0;i<pre[v].size();i++)
    {
        DFS(pre[v][i]);
    }
    temppath.pop_back();

}
int main()
{
    fill(G[0],G[0]+maxn*maxn,inf);
    scanf("%d%d%d%d",&cmax,&n,&sp,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&cur[i]);
        weight[i]=cur[i]-cmax/2;
    }
    for(int i=1;i<=m;i++)
    {
        int x,y,time;
        scanf("%d%d%d",&x,&y,&time);
        G[x][y]=G[y][x]=time;
    }
    Dijkstra();
    DFS(sp);
    printf("%d ",minneed);
    for(int i=path.size()-1;i>=0;i--)
    {
        printf("%d",path[i]);
        if(i>0) printf("->");
    }
    printf(" %d",minremain);
}