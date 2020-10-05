#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll inf=(1ll << 32)-1;
ll map[256];
void init()
{
    for(char c='0';c<'9';c++)
    {
        map[c]=c-'0';
    }
    for(char c='a';c<='z';c++)
    {
        map[c]=c-'a'+10;
    }
}
ll convertNum10(char a[],int radix,ll top)
{
    int len=strlen(a);
    ll result=0;
    int x;
    for(int i=0;i<len;i++)
    {
        if(a[i]>='a'&&a[i]<='z')
        {
            x=a[i]-'a'+10;
            result=result*radix+x;
        }
        else 
        {
            x=a[i]-'0';
            result=result*radix+x;
        }
    }
    if(result<0||result>top) return -1;
    else return result;
}
int cmp(char y[],ll radix,ll t)
{
    int num=convertNum10(y,radix,t);
    if(num<0) return 1;
    else if(t>num) return -1;
    else if(t==num) return 0;
    else return 1;
}
ll BS(char y[],ll low,ll high,ll t)
{
    int mid=(low+high)/2;
    while(low<high)
    {
        if(cmp(y,mid,t)==0) return mid;
        if(cmp(y,mid,t)<0)
        {
            low=mid+1;
        }
        else if(cmp(y,mid,t)>0)
        {
            high=mid-1;
        }
    }
    return -1;
}
ll findMaxDigit(char a[])
{
    int len=strlen(a);
    ll max=-1;
    for(int i=0;i<len;i++)
    {
        if(map[a[i]]>max)
        {
            max=map[a[i]];
        }
    }
    return max+1;
}
int main()
{
    init();
    char x[11],y[11];
    int tag,radix;
    scanf("%s %s",x,y);
    scanf("%d%d",&tag,&radix);
    if(tag==2)
    {
        char temp[11];
        strcpy(temp,x);
        strcpy(x,y);
        strcpy(y,temp);
    }
    //change x
    ll t=convertNum10(x,radix,inf);
    ll low=findMaxDigit(y);
    ll high=max(low,t)+1;
    ll ans=BS(y,low,high,t);
    if(ans==-1) printf("Impossible\n");
    else printf("%lld\n",ans);
    return 0;
}