#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=100010;
int age[maxn]={0};

struct Node
{
    char name[30];
    int age;
    int value;
}node[maxn];
vector<Node>valid;
bool cmp(Node a,Node b)
{
    if(a.value!=b.value)  return a.value>b.value;
    else if(a.age!=b.age) return a.age<b.age;
    else return strcmp(a.name,b.name)<0;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=0;i<n;i++)
    {
        scanf("%s%d%d",node[i].name,&node[i].age,&node[i].value);
        getchar();
    }
    sort(node,node+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(age[node[i].age]<100)
        {
            valid.push_back(node[i]);
            age[node[i].age]++;
        }

    }
    int k,low,high;
    vector<Node>v;
    for(int i=1;i<=m;i++)
    {
        v.clear();
        scanf("%d %d %d",&k,&low,&high);
        for(int i=0;i<valid.size();i++)
        {
            if(valid[i].age>=low&&valid[i].age<=high)
            {
                v.push_back(valid[i]);
            }
        }
       // sort(v.begin(),v.end(),cmp);
        printf("Case #%d:\n",i);
        if(v.size()==0) printf("None\n");
        else 
        {
            for(int j=0;j<k&&j<v.size();j++)
            {
                printf("%s %d %d\n",v[j].name,v[j].age,v[j].value);
            }
        }
    }
    return 0;
}