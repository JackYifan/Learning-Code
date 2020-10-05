#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1010;
char a[maxn];
int dp[maxn][maxn];
int main()
{
    cin.getline(a,maxn);
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
        dp[i][i]=1;
    }
    int ans=0;
    for(int i=0;i<len-1;i++)
    {
        if(a[i]==a[i+1])
        {
            dp[i][i+1]=2;
        }
        else dp[i][i+1]=0;
        if(dp[i][i+1]>ans) ans=dp[i][i+1];
    }
    for(int i=3;i<=len;i++)
    {
        //iÎª²½³¤
        for(int j=0;j<len-i;j++)
        {
            if(a[j]==a[j+i-1])
            {
                dp[j][j+i-1]=dp[j+1][j+i-2]+2;
            }
            else dp[j][j+i-1]=0;
            if(dp[j][j+i-1]>ans)
            {
                ans=dp[j][j+i-1];
            }
        }
    }
    printf("%d",ans);
    return 0;
}
