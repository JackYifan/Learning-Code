#include<cstdio>
const int maxn=100010;
int a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int left=0;
    int right=1;
    int len=1;
    int anslen=1,ansleft,ansright;
    for(;right<n;right++)
    {
        if(a[right]>a[right-1]) 
        {
            right++;
            len++;
        }
        else
        {
            if(len>anslen)
            {
                ansleft=left;
                ansright=right-1;
                anslen=len;
            }
            left=right;
            //right=left+1;
            len=0;
        } 
    }
    for(int i=ansleft;i<=ansright;i++)
    {
        printf("%d ",a[i]);
    }
}