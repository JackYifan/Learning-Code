#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=1000000000;
const int maxn=501;
int G[maxn][maxn];
int cost[maxn][maxn];
bool visit[maxn]={false};
int d[maxn];
vector<int>pre[maxn];
vector<int>path,temp;
int n,m,st,ed,x,y,length,fare;
int mincost=inf;
void Dij()
{
    // memset(d,0,sizeof(d));
    // memset(c,0,sizeof(c));
    fill(d,d+maxn,inf);
    d[st]=0;
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
        for(int v=0;v<n;v++)
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
//利用pre 数组得出路径
void DFS(int v)
{
    if(v==st) 
    {
        //到叶结点后结算费用
        int tempcost=0;
        temp.push_back(v);
        for(int i=temp.size()-1;i>0;i--)
        {
            int id=temp[i];
            int next=temp[i-1];
            tempcost+=cost[id][next];
        }
        //更新最值
        if(tempcost<mincost)
        {
            mincost=tempcost;
            path=temp;
        }
        temp.pop_back();
        return;
        
    }
    temp.push_back(v);
    for(int i=0;i<pre[v].size();i++)
    {
        DFS(pre[v][i]);
    }
    temp.pop_back();
}
int main()
{
    fill(G[0],G[0]+maxn*maxn,inf);
    fill(cost[0],cost[0]+maxn*maxn,inf);
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d%d",&x,&y,&length,&fare);
        G[x][y]=G[y][x]=length;
        cost[x][y]=cost[y][x]=fare;
    }
    Dij();
    DFS(ed);
    for(int i=path.size()-1;i>=0;i--)
    {
        printf("%d ",path[i]);
    }
    printf("%d %d\n",d[ed],mincost);
    return 0;
}