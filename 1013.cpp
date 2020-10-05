#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1001;
vector<int>G[maxn];
bool visit[maxn]={false};
int n,m,k;
void DFS(int index,int inquire)
{
    if(index==inquire) return;
    visit[index]=true;
    for(int i=0;i<G[index].size();i++)
    {
        if(visit[G[index][i]]==false)
        DFS(G[index][i],inquire);
    }
}
int main()
{
    
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=0;i<k;i++)
    {
        memset(visit,false,sizeof(visit));
        int inquire;
        int num=0;
        scanf("%d",&inquire);
        for(int j=1;j<=n;j++)
        {
            if(j!=inquire&&visit[j]==false)
            {
                DFS(j,inquire);
                num++;
            }
        }
        printf("%d\n",num-1);
    }
    
}