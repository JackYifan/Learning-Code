#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>v1;
vector<int>v2;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        v1.push_back(x);
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%d",&x);
        v2.push_back(x);
    }
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp);
    int i,j;
    int ans=0;
    for(i=0,j=0;i<v1.size()&&j<v2.size()&&v1[i]>0&&v2[j]>0;i++,j++)
    {
        ans+=v1[i]*v2[j];
    }
    for(i=v1.size()-1,j=v2.size()-1;i>=0&&j>=0&&v1[i]<0&&v2[j]<0;i--,j--)
    {
        ans+=v1[i]*v2[j];
    }
    printf("%d",ans);
    

}