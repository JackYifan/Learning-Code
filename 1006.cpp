#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node
{
    int hour1,minute1,second1;
    int hour2,minute2,second2;
    char id[100];
    /* data */
}node[100];
bool cmp1(Node a,Node b)
{
    if(a.hour1==b.hour1)
    {
        if(a.minute1==b.minute1)
        {
            return a.second1<b.second1;
        }
        else return a.minute1<b.minute1;
    }
    else return a.hour1<b.hour1;
}
bool cmp2(Node a,Node b)
{
    if(a.hour2==b.hour2)
    {
        if(a.minute2==b.minute2)
        {
            return a.second2>b.second2;
        }
        else return a.minute2>b.minute2;
    }
    else return a.hour2>b.hour2;
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        scanf("%s %d:%d:%d",node[i].id,&node[i].hour1,&node[i].minute1,&node[i].second1);
        scanf("%d:%d:%d",&node[i].hour2,&node[i].minute2,&node[i].second2);
    }
    sort(node,node+n,cmp1);
    printf("%s ",node[0].id);
    sort(node,node+n,cmp2);
    printf("%s",node[0].id);
    // for(int i=0;i<n;i++)
    // {
    //     char in[20],out[20];
    //     scanf("%s %s %s",node[i].id,in,out);
    //     int len1=strlen(in);
    //     int len2=strlen(out);
    //     int x,y;
    //     int a[5];
    //     int k=0;
    //     for(int j=0;j<len1;j++)
    //     {
    //         x=0;
    //         while(in[j]!=':'&&j<len1);
    //         {
    //             x=x*10+in[j]-'0';
    //             j++;
    //         }
    //         a[k++]=x;
    //     }
    //     for(int i=0;i<3;i++)
    //     {
    //         printf("%d ",a[i]);
    //     }
        
    // }
    return 0;
}