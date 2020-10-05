#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100010;
//用数组记录i的子结点
vector<int> child[maxn];
int n;
double p,r;
int maxdepth=0;
int num=0;
//全局变量+递归，当最大深度时返回就会递归完毕
//结点和结点的深度
void DFS(int root,int depth)
{

    //如果是叶结点
    if(child[root].size()==0)
    {
        if(depth>maxdepth)
        {
            maxdepth=depth;
            num=1;//重新记数
        } 
        else if(depth==maxdepth) num++;
        return ;
    }
    
    //遍历root的子结点
    for(int i=0;i<child[root].size();i++)
    {
        DFS(child[root][i],depth+1);
    }
}
int main()
{
    scanf("%d%lf%lf",&n,&p,&r);
    int root;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x!=-1)
        {
            child[x].push_back(i);
        }
        else root=i;
    }
    DFS(root,0);
    double result=p*pow(1+r/100,maxdepth);
    printf("%.2f %d",result,num);
    return 0;
}