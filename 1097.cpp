#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int number[10010]={0};
struct Node
{
    int address;
    int data;
    int order;
    int next;
}node[maxn];
bool cmp(Node a,Node b)
{
    return a.order<b.order;
}
int main ()
{
    int n,begin;
    for(int i=0;i<maxn;i++)
    {
        node[i].order=2*maxn;
    }
    scanf("%d%d",&begin,&n);
    for(int i=0;i<n;i++)
    {
        int address;
        scanf("%d",&address);
        scanf("%d%d",&node[address].data,&node[address].next);
        node[address].address=address;
    }
    int p;
    int cnt=0,cnt2=0;
    for(p=begin;p!=-1;p=node[p].next)
    {
        if(number[abs(node[p].data)]==0)
        {
            number[abs(node[p].data)]=1;
            node[p].order=cnt++;
        }
        else 
        {
            node[p].order=maxn+cnt2++;
        }
    }
    
    std::sort(node,node+maxn,cmp);
    for(int j=0;j<cnt;j++)
    {
        printf("%05d %d ",node[j].address,node[j].data);
        if(j<cnt-1) printf("%05d\n",node[j+1].address);
        else printf("-1\n");
    }
    for(int j=cnt;j<cnt+cnt2;j++)
    {
        printf("%05d %d ",node[j].address,node[j].data);
        if(j<cnt+cnt2-1) printf("%05d\n",node[j+1].address);
        else printf("-1\n");
    }
    
    return 0;
    
}
