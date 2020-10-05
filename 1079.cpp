#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int n;
double p,r;
double sum=0;
const int maxn=100010;
struct node
{
    /* data */
    int data;
    vector<int>q;
}Node[maxn];
int maxdepth;
void DFS(int index,int depth)
{
    if(Node[index].q.size()==0)
    {
        sum+=Node[index].data*p*pow(1+r,depth);
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
        if(tot==0) 
        {
            scanf("%d",&Node[i].data);
        }
        else
        {
            for(int j=0;j<tot;j++)
            {
                int child;
                scanf("%d",&child);
                Node[i].q.push_back(child);
            }
        }
    }
    DFS(0,0);
    printf("%.1f",sum);
    return 0;

    
}