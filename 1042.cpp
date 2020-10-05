/*
S1, S2, ..., S13, 
H1, H2, ..., H13, 
C1, C2, ..., C13, 
D1, D2, ..., D13, 
J1, J2
*/
#define N 54
char m[5]={'S','H','C','D','J'};
int start[55],end[55],next[55],fun[55];
#include<stdio.h>
int main()
{
    int k;
    scanf("%d",&k);
    //初始化
    for(int i=1;i<=N;i++)
    {
        start[i]=i;
    }
    //输入操作
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&fun[i]);
    }
    //移动k次
    for(int step=0;step<k;step++)
    {
        for(int i=1;i<=N;i++)
        {
            end[fun[i]]=start[i];
        }
        for(int i=1;i<=N;i++)
        {
            start[i]=end[i];
        }
    }
    //输出结果
    for(int j=1;j<=N;j++)
    {
        int i=end[j];
        printf("%c",m[(i-1)/13]);
        printf("%d",(i-1)%13+1);
        if(j<N) printf(" "); 
    }
    return 0;
}