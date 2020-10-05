#include<cstdio>
#include<queue>
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
    int cnt=0;
    visit[maxn]={false};
    node[index].layer=0;
    queue<int>q;
    visit[index]=true;
    q.push(index);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(G[u][i]==1&&visit[i]==false)
            {
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
    for(int i=1;i<=n;i++)
    {
        int ans=BFS(i);
        printf("%d\n",ans);
    }
    

}
