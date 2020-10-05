#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node
{
    int id;
    char name[20];
    int score;
}node[1010];
bool cmp1(Node a,Node b)
{
    return a.id<b.id;
}
bool cmp2(Node a,Node b)
{
    if(strcmp(a.name,b.name)!=0) return strcmp(a.name,b.name)<0;
    else return  a.id<b.id;
}
bool cmp3(Node a,Node b)
{
    if(a.score!=b.score) return a.score<b.score;
    else return  a.id<b.id;
}
int main()
{
    int n;
    scanf("%d",&n);
    int c;
    scanf("%d",&c);
    getchar();
    for(int i=0;i<n;i++)
    {
        scanf("%d",&node[i].id);
        getchar();
        scanf("%s %d",node[i].name,&node[i].score);
    }
    switch (c)
    {
        case 1:sort(node,node+n,cmp1);break;
        case 2:sort(node,node+n,cmp2);break;
        case 3:sort(node,node+n,cmp3);break;
    }
    for(int i=0;i<n;i++)
    {
        printf("%06d %s %d\n",node[i].id,node[i].name,node[i].score);
    }
    
}