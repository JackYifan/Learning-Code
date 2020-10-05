#include<cstdio>
const int maxn=100010;
struct Node
{
    char data;
    int next;
    int flag;
}node[maxn];
int main()  
{
    int add1,add2;
    int n,result;
    scanf("%d %d %d",&add1,&add2,&n);
    for(int i=0;i<maxn;i++)
    {
        node[i].flag=0;
    }
    for(int i=0;i<n;i++)
    {
        int address,data,next;
        scanf("%d %c%d",&address,&data,&next);
        node[address].data=data;
        node[address].next=next;
        
    }
    int p,q,flag=0;
    for(p=add1;p!=-1;p=node[p].next)
    {
        node[p].flag=1;
    }
    for(q=add2;q!=-1;q=node[q].next)
    {
        if(node[q].flag==1) break;
    }
    if(q==-1) printf("-1");
    else printf("%05d",q);
    //暴力方法运行超时
    // for(p=add1;node[p].next!=-1;p=node[p].next)
    // {
    //     for(q=add2;node[q].next!=-1;q=node[q].next)
    //     {
    //         if(node[q].next==node[p].next)
    //         {
    //             result=node[q].next;
    //             flag=1;
    //             break;
    //         }
    //     }
    //     if(flag==1) break;
    // }
    // if(flag==0) printf("-1");
    // else printf("%05d",result);
    return 0;
}
