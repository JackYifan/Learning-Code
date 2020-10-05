#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10010;
int HashTable[maxn];
int a[maxn];
int b[maxn];
int dp[maxn][maxn];
int main()
{
    memset(HashTable,-1,sizeof(HashTable));
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
    }
    int l;
    scanf("%d",&l);
    for(int i=1;i<=l;i++)
    {
        scanf("%d",&b[i]);
    }
    //边界
    for(int i=0;i<=m;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=l;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=l;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j])+1;
            }
            else 
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    printf("%d",dp[m][l]);
    

}