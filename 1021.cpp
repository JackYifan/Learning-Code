#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100010;
int n;
vector<int> G[maxn];//表示边
//并查集的常规操作
int father[maxn];
bool isroot[maxn];
int findfather(int x)
{
    int a=x;
    while(x!=father[x])
    {
        x=father[x];
    }
    while(a!=father[a])
    {
        father[a]=x;
        a=father[a];
    }
    return x;
}
void Union(int a,int b)
{
    int faA=findfather(a);
    int faB=findfather(b);
    if(faA!=faB) father[faB]=faA;
}
void init()
{
    for(int i=1;i<=n;i++)
    {
        father[i]=i;
        isroot[i]=false ;
    }
    
}
int calBlock()
{
    int block=0;
    for(int i=1;i<=n;i++)
    {
        isroot[findfather(i)]=true;
    }
    for(int i=1;i<=n;i++)
    {
        if(isroot[i]) block++;
    }
    return block;
}
vector<int> temp,ans;
int maxheight=0;
void DFS(int now,int height,int pre)
{
    if(height>maxheight)
    {
        temp.clear();
        temp.push_back(now);
        maxheight=height;
    }
    else if(height==maxheight)
    {
        temp.push_back(now);
    }
    // vector<int>::iterator it ;
    // for(it=G[now].begin();it!=G[now].end();it++)
    // {
    //     if(*it!=pre)
    //     {
    //         DFS(*it,height+1,now);
    //     }
    // }
    for(int i=0;i<G[now].size();i++)
    {
        if(G[now][i]==pre) continue;
        DFS(G[now][i],height+1,now);
    }
    
    

}
int main()
{
    scanf("%d",&n);
    init();
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
        Union(x,y);//x,y是一个集合的
    }
    int block=calBlock();
    if(block!=1) printf("Error: %d components",block);
    else 
    {
        DFS(1,1,-1);

        ans=temp;
        DFS(ans[0],1,-1);
        for(int i=0;i<temp.size();i++)
        {
            ans.push_back(temp[i]);
        }
        sort(ans.begin(),ans.end());
        printf("%d\n",ans[0]);
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i]!=ans[i-1])
            printf("%d\n",ans[i]);
        }
    }

}