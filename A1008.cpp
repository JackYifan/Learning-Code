#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
int pos=0;
int time(int des)
{
    int x=des-pos;
    if(x>0)
    {
        pos=des;
        return 6*x;
    }
    else 
    {
        pos=des;
        return 4*(-x);
    }

}

int main()
{
    int a[maxn];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int tot=0;
    for(int i=0;i<n;i++)
    {
        tot+=time(a[i]);
    }
    tot+=5*n;
    printf("%d",tot);
    
}