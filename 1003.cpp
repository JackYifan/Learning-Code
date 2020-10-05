#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=501;
const int inf=1000000000;
int n,m,st,ed;
int num[maxn]={0};//路线总数
int weight[maxn];//该点的救援队
int d[maxn];//从起点到i的距离
int G[maxn][maxn];//表示线
int tot[maxn]={0};//总共救援队
bool visit[maxn]={false};
void DFS(int st,int ed)
{
    //初始化
    fill(d,d+maxn,inf);
    memset(num,0,sizeof(num));
    memset(tot,0,sizeof(tot));
    d[st]=0;
    tot[st]=weight[st];
    num[st]=1;
    //
    for(int i=0;i<n;i++)//因为有要访问到所有的点，所以需要循环n遍
    {
        //寻找距离st最近的点
        int min=inf,u=-1;
        for(int j=0;j<n;j++)
        {
            if(visit[j]==false&&d[j]<min)
            {
                u=j;
                min=d[j];
            }
        }
        //访问u
        if(u==-1) return ;
        visit[u]=true;
        for(int k=0;k<n;k++)
        {
            //判断结点是否能到达
            if(visit[k]==false && G[u][k]!=inf)
            {
                if(d[u]+G[u][k]<d[k])
                {
                    d[k]=d[u]+G[u][k];
                    tot[k]=tot[u]+weight[k];
                    num[k]=num[u];
                }
                else if(d[u]+G[u][k]==d[k])
                {
                    if(tot[u]+weight[k]>tot[k])
                    {
                        tot[k]=tot[u]+weight[k];
                    }
                    num[k]+=num[u];
                }
            }
            
        }
        
    }
    
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&weight[i]);//输入vi的救援队数
    }
    //初始化
    fill(G[0],G[0]+maxn*maxn,inf);
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        G[x][y]=w;
        G[y][x]=w;
    }
    
    DFS(st,ed);
    printf("%d %d\n",num[ed],tot[ed]);
    return 0;
}