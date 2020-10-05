#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int hashtable[maxn];
int a[maxn];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a[i]=x;
        hashtable[x]++;
    }
    sort(a,a+n);
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<m)
        {
            hashtable[a[i]]--;
            if(hashtable[m-a[i]]>0)
            {
                printf("%d %d\n",a[i],m-a[i]);
                flag=1;
                break;
            }
            hashtable[a[i]]++;
        }
        
    }
    if(flag==0) printf("No Solution\n");
    return 0;
}