#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn=101;
vector<int> child[maxn];
int maxdepth;
int hashTable[maxn]={0};
void DFS(int index,int depth)
{
    if(depth>maxdepth)
    {
        maxdepth=depth;
    }
    if(child[index].size()==0)
    {
        hashTable[depth]++;
        return;
    }
    //遍历index的子结点
    for(int k=0;k<child[index].size();k++)
    {
        DFS(child[index][k],depth+1);
    }
}

int level[maxn]={0};
int maxlevel=1;
void BFS( )
{
    queue<int>q;
    //初始化操作
    q.push(1);
    level[1]=1;
    while(!q.empty())
    {
        int now=q.front();
        if(level[now]>maxlevel) maxlevel=level[now];
        q.pop();
        if(child[now].size()==0) hashTable[level[now]]++;
        else
        {
            for(int i=0;i<child[now].size();i++)
            {
                q.push(child[now][i]);
                level[child[now][i]]=level[now]+1;
            }
        }
        
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int tot,_index;
        scanf("%d",&_index);
        scanf("%d",&tot);
        for(int j=0;j<tot;j++)
        {
            int x;
            scanf("%d",&x);
            child[_index].push_back(x);
        }
    }
    //DFS(1,1);
    BFS();
    // for(int i=1;i<=maxdepth;i++)
    // {
    //     printf("%d",hashTable[i]);
    //     if(i<maxdepth) printf(" ");
    // }
    for(int i=1;i<=maxlevel;i++)
    {
        printf("%d",hashTable[i]);
        if(i<maxlevel) printf(" ");
    }
}