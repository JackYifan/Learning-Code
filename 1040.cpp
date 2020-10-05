#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1010;
char a[maxn];
int dp[maxn][maxn];
int main()
{
    memset(dp,0,sizeof(dp));
    cin.getline(a,maxn);
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
        dp[i][i]=1;
    }
    int ans=1;
    for(int i=0;i<len-1;i++)
    {
        if(a[i]==a[i+1])
        {
            dp[i][i+1]=1;
            ans=2;
        }
        else dp[i][i+1]=0;
    }
    for(int i=3;i<=len;i++)
    {
        //i为步长
        for(int j=0;j<=len-i;j++)
        {
            if(a[j]==a[j+i-1]&&dp[j+1][j+i-2]==1)
            {
                dp[j][j+i-1]=1;
                ans=i;
            }
            else dp[j][j+i-1]=0;
        }
    }
    printf("%d",ans);
    return 0;
}