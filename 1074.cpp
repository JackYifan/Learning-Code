#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct node
{
    int address,data,next;
    int order;
}node[maxn];
bool cmp(struct node a,struct node b)
{
    return a.order<b.order;
}
int main()
{
    for(int i=0;i<maxn;i++)
    {
        node[i].order=maxn;
    }
    //读入数据
    int begin,n,k,address;
    scanf("%d%d%d",&begin,&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&address);
        scanf("%d %d",&node[address].data,&node[address].next);
        node[address].address=address;
    }
    int p=begin,cnt=0;
    while(p!=-1)
    {
        node[p].order=cnt++;
        p=node[p].next;
    }
    sort(node,node+maxn,cmp);
    n=cnt;
    //前N组k个元素倒序输出
    for(int i=0;i<n/k;i++)
    {
        for(int j=(i+1)*k-1;j>i*k;j--)
        {
            printf("%05d %d %05d\n",node[j].address,node[j].data,node[j-1].address);
        }
        //处理最后一个
        printf("%05d %d ",node[i*k].address,node[i*k].data);
        //如果不是最后一个整块
        if(i<n/k-1)
        {
            printf("%05d\n",node[(i+2)*k-1].address);
        }
        else
        {
            //如果是整个最后一个
            if(n%k==0) printf("-1\n");
            else  
            {
                printf("%05d\n",node[(i+1)*k].address);
                //剩余的原序列输出
                for(int i=n/k*k;i<n;i++)
                {
                    printf("%05d %d ",node[i].address,node[i].data);
                    if(i<n-1)
                    {
                        printf("%05d\n",node[i+1].address);
                    }
                    else printf("-1\n");
                }
            }
        }
    }

    return 0;
    
    
}