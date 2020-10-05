#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int n;
double p,r;
double price;
const int maxn=100010;
struct node
{
    /* data */
    int data;
    vector<int>q;
}Node[maxn];
int maxdepth;
double minprice;
int num;
void DFS(int index,int depth)
{
    if(Node[index].q.size()==0)
    {
        price=p*pow(1+r,depth);
        if(price<minprice)
        {
            minprice=price;
            num=0;
        }
        if(price==minprice) num++;
        return ;
    }
    //遍历子结点
    for(int i=0;i<Node[index].q.size();i++)
    {
        DFS(Node[index].q[i],depth+1);
    }
}
int main()
{
    scanf("%d%lf%lf",&n,&p,&r);
    r/=100;
    for(int i=0;i<n;i++)
    {
        int tot;
        scanf("%d",&tot);
        if(tot!=0)
        {
            for(int j=0;j<tot;j++)
            {
                int child;
                scanf("%d",&child);
                Node[i].q.push_back(child);
            }
        }
    }
    minprice=p*pow(1+r,n);
    DFS(0,0);
    printf("%.4f %d",minprice,num);
    return 0;

    
}
