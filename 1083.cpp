#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10010;
struct Node
{
    char name[20];
    char id[20];
    int score;
    /* data */
}node[maxn];
bool cmp(Node a,Node b)
{
    return a.score>b.score;
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        scanf("%s%*c%s%d",node[i].name,node[i].id,&node[i].score);
        getchar();
    }
    int low,high;
    scanf("%d%d",&low,&high);
    int valid[maxn];
    sort(node,node+n,cmp);
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(node[i].score>=low&&node[i].score<=high)
        {
            printf("%s %s\n",node[i].name,node[i].id);
            flag=1;
        }

    }
    if(flag==0) printf("NONE\n");
}