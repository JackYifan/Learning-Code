#include<cstdio>
#include<cstring>
const int maxn=10010;
int hashtable[maxn];
int a[maxn];
int main()
{
    memset(hashtable,0,sizeof(hashtable));
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a[i]=x;
        hashtable[x]++;
    }
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(hashtable[a[i]]==1)
        {
            printf("%d",a[i]);
            flag=1;
            break;
        }
    }
    if(flag==0) printf("None");
}