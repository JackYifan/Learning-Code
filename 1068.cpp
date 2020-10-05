#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10010;
const int maxv=110;
//int dp[maxn][maxn];//前i个银币凑j元,最多可以凑足多少
int dp[maxv]={0};
int w[maxn];
int flag[maxn]={0};
int num;
bool choice[maxn][maxv];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    memset(dp,0,sizeof(dp));
    memset(choice,false,sizeof(choice));
    int n,tot;
    scanf("%d%d",&n,&tot);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }
    sort(w+1,w+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        // for(int j=w[i];j<=tot;j++)
        // {
        //     if(dp[i-1][j-w[i]]+w[i]<=dp[i-1][j])
        //     {
        //         dp[i][j]=dp[i-1][j];
        //         choice[i][j]=false;
        //     }
        //     else 
        //     {
        //         dp[i][j]=dp[i-1][j-w[i]]+w[i];
        //         choice[i][j]=true;
        //     }
        // }
        for(int j=tot;j>=w[i];j--)
        {
            if(dp[j-w[i]]+w[i]>=dp[j])
            {
                dp[j]=dp[j-w[i]]+w[i];
                choice[i][j]=true;
            }
            else choice[i][j]=false;
        }
    }
    if(dp[tot]!=tot)
    {
        printf("No Solution\n");
    }
    else 
    {
        int k=n,v=tot;
        for(int k=n;k>=0;k--)
        {
            if(choice[k][v]==true)
            {
                flag[k]=1;
                v-=w[k];
                num++;
            }
            else flag[k]=0;
        }
    }
    for(int i=n;i>=1;i--)
    {
        if(flag[i]==1)
        {
            printf("%d",w[i]);
            num--;
            if(num>0)
            {
                printf(" ");
            }
        }
        
    }
    return 0;
}