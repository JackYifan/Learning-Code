#include<cstdio>
#include<algorithm>
using namespace std;
int course[1001]={0};//第i个游戏喜欢的用户
int father[1001]={0};
int isroot[1001]={0};
/*
寻找每个元素的最初的父元素
isroot[对应父元素]++；
*/
bool cmp(int a,int b)
{
    return a>b;
}
int findFather(int x)//寻找x所在集合的根结点
{
    int a=x;//暂时保存x并找到x的根结点
    while(father[x]!=x)
    {
        x=father[x];
    }
    while(a!=father[a])
    {
        father[a]=x;
        a=father[a];
    }
    return x;
}
void Union(int a,int b)
{
    int faA=findFather(a);
    int faB=findFather(b);
    if(faA!=faB)
    {
        father[faB]=faA;
    }
}
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        father[i]=i;//各自为一个集合
        isroot[i]=0;
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    init(n);
    for(int i=1;i<=n;i++)//第i个人
    {
        int tot;
        scanf("%d:",&tot);
        for(int j=0;j<tot;j++)
        {
            int index;
            scanf("%d",&index);
            if(course[index]==0)
            {
                course[index]=i;
            }
            Union(i,findFather(course[index]));//把第i个人和第index游戏的根用户连接在一起；
        }
    }
    //统计相同father的元素个数
    for(int i=1;i<=n;i++)
    {
        isroot[findFather(i)]++;
    }
    sort(isroot+1,isroot+1+n,cmp);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(isroot[i]!=0) ans++;
    }
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++)
    {
        printf("%d",isroot[i]);
        if(i<ans) printf(" ");
    }
    return 0;
}