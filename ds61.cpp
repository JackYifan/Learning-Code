#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1010;
int n,m;
int G[maxn][maxn];
bool visit[maxn];
struct Node
{
    int layer;
}node[maxn];
int BFS(int index)
{
    queue<int>q;
    int cnt=1;
    memset(visit,false,sizeof(visit));
    // for(int i=1;i<=n;i++)
    // {
    //     node[i].layer=0;
    // }
    node[index].layer=0;
    visit[index]=true;
    q.push(index);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(G[u][i]==1&&visit[i]==false)
            {
                visit[i]=true;
                node[i].layer=node[u].layer+1;
                if(node[i].layer<=6) cnt++;
                q.push(i);
            }
        }
    }
    
    return cnt;

}
int main()
{
    
    scanf("%d%d",&n,&m);
    fill(G[0],G[0]+maxn*maxn,0);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x][y]=G[y][x]=1;
    }
    for(int k=1;k<=n;k++)
    {
        double ans=BFS(k)*1.0/n*100;
        printf("%d: %.2f%%\n",k,ans);
    }
    //printf("%d\n",BFS(3));

}