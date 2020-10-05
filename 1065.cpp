#include<cstdio>
typedef long long ll; 
int cnt=1;
int main()
{
    bool flag;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        ll x;
        ll y;
        ll z;
        
        scanf("%lld%lld%lld",&x,&y,&z);
        ll result=x+y;
        if(x<0&&y<0&&result>0) flag=false;
        else if(x>0&&y>0&&result<0) flag=true;
        else if(result>z) flag=true;
        else flag=false;
        if(flag==true)
        {
            printf("Case #%d: true\n",cnt);
        }
        else if(flag==false)
        {
            printf("Case #%d: false\n",cnt);
        }
        cnt++;
    }
   
}