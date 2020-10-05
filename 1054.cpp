#include<cstdio>
#include<map>
using namespace std;
map<int,int>cnt;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x;
            scanf("%d",&x);
            if(cnt.find(x)!=cnt.end()) cnt[x]++;
            else cnt[x]=1;
        }
    }
    //寻找最大值
    map<int,int>::iterator it;
    int max=-1,k;
    for(it=cnt.begin();it!=cnt.end();it++)
    {
        if(it->second>max)
        {
            k=it->first;
            max=it->second;
        }
    }
    printf("%d\n",k);
}