#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=2020;
struct Node
{
    int ex;
    double co;
    /* data */
};
vector<Node>p1,p2;
double ans[maxn]={0};
int main()
{
    memset(ans,0,sizeof(ans));
    int n1;
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        int x;
        double y;
        scanf("%d%lf",&x,&y);
        Node node;
        node.co=y;
        node.ex=x;
        p1.push_back(node);
    }
    int n2;
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
    {
        int x;
        double y;
        scanf("%d%lf",&x,&y);
        Node node;
        node.co=y;
        node.ex=x;
        p2.push_back(node);
    }
    for(int i=0;i<p1.size();i++)
    {
        for(int j=0;j<p2.size();j++)
        {
            double u=p1[i].co*p2[j].co;
            int v=p1[i].ex+p2[j].ex;
            ans[v]+=u;
        }
    }
    int cnt=0;
    for(int i=maxn-1;i>=0;i--)
    {
        if(ans[i]!=0)
        {
            cnt++;
        }
    }
    printf("%d",cnt);
    for(int i=maxn-1;i>=0;i--)
    {
        if(ans[i]!=0)
        {
            printf(" %d %.1f",i,ans[i]);
        }
    }
    return 0;
}