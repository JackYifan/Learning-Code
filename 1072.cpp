#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
const int inf=1000000000;
int G[maxn][maxn];
int n,m,k,ds;
int d[maxn];
int stringTonum(char a[])
{
    int len=strlen(a);
    int id=0;
    for(int i=0;i<len;i++)
    {
        if(a[i]!='G')
        {
            id = id*10+(a[i]-'0');
        }
    }
    if(a[0]=='G') return n+id;
    else return id;
}
bool visit[maxn]={false};
void dijkstra(int s)//用于得到d数组
{
    fill(d,d+maxn,inf);
    fill(visit,visit+maxn,false);
    d[s]=0;
    for(int i=1;i<=n+m;i++)
    {
        int min=inf,u=-1;
        for(int j=1;j<=n+m;j++)
        {
            if(d[j]<min&&visit[j]==false) 
            {
                u=j;
                min=d[j];
            }
        }
        if(u==-1) return ;
        visit[u]=true;
        for(int v=1;v<=n+m;v++)
        {
            if(visit[v]==false &&G[u][v]!=inf)
            {
                if(d[u]+G[u][v]<d[v])
                {
                    d[v]=d[u]+G[u][v];
                }
            }
        }
    }
    
    
}
int main()
{
    fill(G[1],G[1]+maxn*maxn,inf);
    scanf("%d%d%d%d",&n,&m,&k,&ds);
    getchar();
    for(int i=1;i<=k;i++)
    {
        char a[5];
        char b[5];
        int dis;
        scanf("%s %s %d",a,b,&dis);
        int x=stringTonum(a);
        int y=stringTonum(b);
        G[x][y]=G[y][x]=dis;
    }
    double ansdis=-1,ansavg=inf;
    int ansid;
    for(int i=n+1;i<=n+m;i++)
    {
        dijkstra(i);
        // 选择Gi号的情况
        
        double avg=0;
        int mindis=inf;
        for(int j=1;j<=n;j++)
        {
            avg+=d[j]*1.0/n;
            if(d[j]>ds) 
            {
                mindis=-1;
                break;
            }
            if(d[j]<mindis)
            {
                mindis=d[j];
            }
        }
        if(mindis==-1) continue;
        if(mindis>ansdis) 
        {
            ansdis=mindis;
            ansid=i;
            ansavg=avg;
        }
        else if(mindis==ansdis)
        {
            if(avg<ansavg)
            {
                ansavg=avg;
                ansid=i;
            }
        }
        
    }
    if(ansdis==-1) printf("No Solution\n");
    else 
    {
        printf("G%d\n",ansid-n);
        printf("%.1f %.1f\n",ansdis,ansavg);
    }
    return 0;
}