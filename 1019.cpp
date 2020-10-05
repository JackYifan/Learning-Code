#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    int n;
    int radix;
    scanf("%d%d",&n,&radix);
    vector<int>v;
    while(n){
        int x=n%radix;
        v.push_back(x);
        n=n/radix;
    }
    int len=v.size();
    int flag=1;
    for(int i=0;i<len/2;i++)
    {
        if(v[i]!=v[len-i-1])
        {
            flag=0;
            break;
        }
    }
    if(flag==0) printf("No\n");
    else printf("Yes\n");
    for(int i=len-1;i>=0;i--)
    {
        printf("%d",v[i]);
        if(i!=0) printf(" ");
    }
}