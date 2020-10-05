#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1001;
struct Node
{
    int id;
    int layer;
};
vector<Node> v[maxn];
bool inq[maxn]={false};//判断编号是否已经入队


int BFS(int now,int maxlayer)
{
    int num=0;
    queue<Node> q;
    Node start;
    start.id=now;
    start.layer=0;
    q.push(start);
    inq[start.id]=true;
    while(!q.empty())
    {
        Node front=q.front();
        q.pop();//加入的时候增加数量，源头的层数为0
        //提出结点的编号
        int u=front.id;
        for(int i=0;i<v[u].size();i++)
        {
            Node next;
            next=v[u][i];//u为结点的编号，第i个子结点
            next.layer=front.layer+1;
            if(inq[next.id]==false&&next.layer<=maxlayer)
            {
                q.push(next);
                inq[next.id]=true;
                num++;
            }
        }
    }
    return num;
}
int main()
{
    int n,maxlayer;
    scanf("%d%d",&n,&maxlayer);
    for(int i=1;i<=n;i++)
    {
        Node user;
        user.id=i;
        int tot;
        scanf("%d",&tot);
        for(int j=1;j<=tot;j++)
        {
            int x;
            scanf("%d",&x);
            v[x].push_back(user);
        }
    }
    int sum;
    scanf("%d",&sum);
    for(int i=1;i<=sum;i++)
    {
        memset(inq,false,sizeof(inq));
        int choice;
        scanf("%d",&choice);
        int num=BFS(choice,maxlayer);
        printf("%d\n",num);
    }
    return 0;
}