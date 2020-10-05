#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=101;
int hashTable[maxn]={0};
vector<int>child[maxn];
void DFS(int index,int depth)
{
    hashTable[depth]+=1;
    if(child[index].size()==0)
    {
        return;
    }
    for(int i=0;i<child[index].size();i++)
    {
        DFS(child[index][i],depth+1);
    }
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int index;
        scanf("%d",&index);
        int tot;
        scanf("%d",&tot);
        for(int i=0;i<tot;i++)
        {
            int x;
            scanf("%d",&x);
            child[index].push_back(x);
        }
    }
    DFS(1,1);
    int index=-1,k;
    int max=hashTable[0];
    for(k=0;k<maxn;k++)
    {
        if(hashTable[k]>max)
        {
            max=hashTable[k];
            index=k;
        }
    }
    printf("%d %d",hashTable[index],index);
    return 0;

}