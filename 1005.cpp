#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<map>
using namespace std;
vector<int>v;
//map<int,string>mp={{0,"zero"},{"one"},{"two"},{"three"},{"four"},{"five"},{"six"},"seven" ,"eight" ,"nine"};
char mp[11][10]={"zero","one","two","three","four","five","six","seven" ,"eight" ,"nine"};
int main()
{
    char a[100];
    scanf("%s",a);
    int len=strlen(a);
    int tot=0;
    for(int i=0;i<len;i++)
    {
        int x=a[i]-'0';
        tot+=x;
    }
    int t=tot;
    if(tot==0)
    {
        printf("zero");
    }
    else
    {
        
        while(tot!=0)
        {
            int val=tot%10;
            v.push_back(val);
            tot/=10;
        }
        for(int i=v.size()-1;i>=0;i--)
        {
            printf("%s",mp[v[i]]);
            if(i!=0) printf(" ");
        }
    // printf("%s",a[1]);
    }
    
}