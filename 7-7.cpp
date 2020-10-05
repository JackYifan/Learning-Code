#include<stdio.h>
int main()
{
    int n;
    int i,j,k;
    scanf("%d",&n);
    int a[10][10];
    int num=1;
    for(k=0;k<=n/2;k++)
    {
        for(j=k;j<=n-1-k;j++)
        {
            a[k][j]=num;
            num++;
        }
        for(i=k+1;i<=n-1-k;i++)
        {
            a[i][j-1]=num;
            num++;
        }
        for(j=n-2-k;j>=k;j--)
        {
            a[i-1][j]=num;
            num++;
        }
        for(i=n-2-k;i>=1+k;i--)
        {
            a[i][j+1]=num;
            num++;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
}
/*(0,1) (0,4)
  (0,4) (4,4)
  (1,1) (1,3)
  (1,3) (3,3)
*/









