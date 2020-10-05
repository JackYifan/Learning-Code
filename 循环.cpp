#include<stdio.h>
int main()
{
    int a[10][10];
    int n,m;
    scanf("%d %d",&m,&n);
    //读入n*n矩阵
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    //移动m次
    m=m%n;//m=1;n=3
    int i,j,k;
    int b[10][10];

    for(j=n-m;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            b[i][m-n+j]=a[i][j];
        }
    }
    for(j=n-m-1;j>=0;j--)
    {
        for(i=0;i<n;i++)
        {
            a[i][j+m]=a[i][j];
        }
    }
    for(j=0;j<m;j++)
    {
        for(i=0;i<n;i++)
        {
            a[i][j]=b[i][j];
        }
    }

    //输出矩阵
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

}
