#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 110;
const int inf=1000000000;
int G[maxn][maxn];
int n, m;
int ans[maxn][maxn];
int high[maxn];
void floyed()
{
    // for(int i=1;i<=n;i++)
    // {
    //     G[i][i]=0;
    // }
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i!=j&&G[i][k] + G[k][j] < G[i][j])
				{
					G[i][j] = G[i][k] + G[k][j];
				}
			}
		}

	}
}
int main()
{
    int flag=1;
	scanf("%d%d", &n, &m);
    fill(G[0],G[0]+maxn*maxn,inf);
	for (int i = 0; i < m; i++)
	{
		int x,y,z;
		scanf("%d%d%d", &x, &y, &z);
		G[x][y] = G[y][x] = z;

	}
	floyed();
    
	for (int i = 1; i <= n; i++)
	{
        int max=0;
		// sort(G[i]+1, G[i] + n+1);
        for(int j=1;j<=n;j++)
        {
            if(i!=j&&G[i][j]>max)
            {
                max=G[i][j];
            }
        }

		high[i] = max;
	}
    for(int i=1;i<=n;i++)
    {
        if(high[i]==inf)
        {
            flag=0;
            break;
        }
    }
    if(flag==0) printf("0");
    else 
    {
        int index=1;
        int min=high[1];
        for (int i = 1; i <= n; i++)
        {
            if (high[i] <min)
            {
                index = i;
                min = high[i];
            }
        }
        printf("%d %d", index, min);
    }
	
}