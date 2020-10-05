#include<cstdio>
#include<algorithm>
const int maxn=100010;
struct Node
{
    int address;
    int data;
    int flag;
    int next;
}node[maxn];
bool cmp(Node a,Node b)
{
    if(a.flag==1&&b.flag==1)
    {
        return a.data<b.data;
    }
    else return a.flag>b.flag;
}
int main ()
{
    int n,begin;
    for(int i=0;i<maxn;i++)
    {
        node[i].flag=0;
    }
    scanf("%d%d",&n,&begin);
    for(int i=0;i<n;i++)
    {
        int address;
        scanf("%d",&address);
        scanf("%d%d",&node[address].data,&node[address].next);
        node[address].address=address;
    }
    int p;
    int cnt=0;
    for(p=begin;p!=-1;p=node[p].next)
    {
        node[p].flag=1;
        cnt++;
    }
    if(cnt==0) printf("0 -1");
    else
    {
        std::sort(node,node+maxn,cmp);
        printf("%d %05d\n",cnt,node[0].address);
        for(int j=0;j<cnt;j++)
        {
            printf("%05d %d ",node[j].address,node[j].data);
            if(j<cnt-1) printf("%05d\n",node[j+1].address);
            else printf("-1\n");
        }
    }
    return 0;
    
}
