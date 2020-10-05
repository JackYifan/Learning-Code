#include<cstdio>
#include<vector>
using namespace std;
char mp[14];
int main()
{
    for(int i=0;i<=9;i++)
    {
        mp[i]='0'+i;
    }
    for(int i=10;i<=13;i++)
    {
        mp[i]='A'+i-10;
    }
    
    for(int i=0;i<3;i++)
    {
        vector<char>v;
        int x;
        scanf("%d",&x);
        if(i==0)printf("#");
        if(x<13) printf("0%c",mp[x]);
        else 
        {
            while(x)
            {
                int a=x%13;
                char c=mp[a];
                v.push_back(c);
                x/=13;
            }
            for(int i=v.size()-1;i>=0;i--)
            {
                printf("%c",v[i]);
            }
        }
    }
    
}