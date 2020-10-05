#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10010;
struct Node
{
    int id;
    int score[6];
    int totscore=0;
    //bool haspost[6];
    int perfect=0;
    bool flag=false ;
    int rank;
    /* data */
}node[maxn];
int tot[6];
bool cmp(Node a,Node b)
{
    if(a.totscore!=b.totscore) return a.totscore>b.totscore;
    else if(a.perfect!=b.perfect) return a.perfect>b.perfect;
    return a.id<b.id;
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&tot[i]);
    }
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=n;j++)
        {
            node[j].score[i]=-1;
        }
    }
    for(int i=0;i<k;i++)
    {
        int x,index,z;
        scanf("%d%d%d",&x,&index,&z);
        node[x].id=x;
        if(z==-1&&node[x].score[index]==-1) node[x].score[index]=0;
        if(z==tot[index]&&node[x].score[index]<tot[index]) node[x].perfect++;
        if(z>node[x].score[index]) 
        {
            // node[x].totscore=node[x].totscore-node[x].score[index]+z;
            node[x].score[index]=z;
        }
        if(z!=-1) node[x].flag=true;
        // node[x].haspost[index]=true;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(node[i].score[j]!=-1) node[i].totscore+=node[i].score[j];
        }
    }
    sort(node+1,node+1+n,cmp);
    for(int i=1;i<n+1;i++)
    {
        node[i].rank=i;
    }
    for(int i=1;i<n+1;i++)
    {
        if(node[i].flag==false) continue;
        if(node[i].totscore==node[i-1].totscore) 
        {
            node[i].rank=node[i-1].rank;
        }
        printf("%d ",node[i].rank);
        printf("%05d %d ",node[i].id,node[i].totscore);
        for(int j=1;j<=m;j++)
        {
            // if(node[i].score[j]==-1) printf("0");
            if(node[i].score[j]==-1) printf("-");
            else printf("%d",node[i].score[j]);
            if(j<m) printf(" ");
            else printf("\n");
        }


        //printf("%d",node[i].id);
    }
    
}
