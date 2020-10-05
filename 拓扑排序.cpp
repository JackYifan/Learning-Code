#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn=110;
int n,m;
int ve[maxn]={0};

int indegree[maxn]={0};
struct Node
{
    int time;
    int v;
};
vector<Node>G[maxn];
int cnt=0;
int flag=1;
  stack<int>st;
void tuopu()
{
  
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        st.push(u);
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i].v;
            indegree[v]--;
            if(indegree[v]==0)
            {
                q.push(v);
            }
            if(ve[u]+G[u][i].time>ve[v])
            {
                ve[v]=ve[u]+G[u][i].time;
            }
        }
    }
    
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v,t;
        scanf("%d%d%d",&u,&v,&t);
        Node a;
        a.time=t;
        a.v=v;
        G[u].push_back(a);
        indegree[v]++;
    }
    tuopu();
    if(st.size()!=n) printf("Impossible");
    else 
    {
        printf("%d",ve[n-1]);
    }
    
}