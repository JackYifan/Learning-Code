#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=101;
int path[maxn]={0};
struct Node
{
    /* data */
    int weight;
    vector<int> child;
}node[maxn];
bool cmp(int a,int b)
{
    return node[a].weight>node[b].weight;
}


int n,m,sum;
//index是父结点,目前的路径上已经有num个
void DFS(int index,int num,int nowsum)
{
    if(nowsum>sum) return ;
    if(node[index].child.size()==0)
    {
        if(nowsum==sum) 
        {
            for(int k=0;k<num;k++)
            {
                printf("%d",node[path[k]].weight);
                if(k<num-1) printf(" ");
                else printf("\n");
            }
        
        }
        return ;
    }

    for(int i=0;i<node[index].child.size();i++)
    {
        path[num]=node[index].child[i];
        DFS(node[index].child[i],num+1,nowsum+node[node[index].child[i]].weight);
    }
    
    
}
int main()
{
    
    scanf("%d%d%d",&n,&m,&sum);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&node[i].weight);
    }
    for(int i=0;i<m;i++)
    {
        int index;
        scanf("%d",&index);
        int tot;
        scanf("%d",&tot);
        for(int j=0;j<tot;j++)
        {
            int x;
            scanf("%d",&x);
            node[index].child.push_back(x);
        }
        //每一个结点的子结点都排序
        sort(node[index].child.begin(),node[index].child.end(),cmp);
    }
    path[0]=0;
    DFS(0,1,node[0].weight);


}