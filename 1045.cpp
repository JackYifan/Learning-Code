#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10010;
int HashTable[maxn];
int a[maxn];
int dp[maxn];
int main()
{
    memset(HashTable,-1,sizeof(HashTable));
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%d",&x);
        HashTable[x]=i;
    }
    int l;
    scanf("%d",&l);
    for(int i=0;i<l;i++)
    {
        scanf("%d",&a[i]);
    }
    int num=0;
    int c[maxn];
    for(int i=0;i<l;i++)
    {
        if(HashTable[a[i]]!=-1)
        {
            c[num++]=a[i];
        }
    }
    for(int i=0;i<num;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(HashTable[c[i]]>=HashTable[c[j]]&&dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
            }
        }
        
    }
    int max=0;
    for(int i=0;i<num;i++)
    {
        if(dp[i]>max)
        {
            max=dp[i];
        }
    }
    printf("%d",max);
    return 0;
    

}