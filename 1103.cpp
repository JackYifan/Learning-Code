#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>fac;//用来存放n^p
vector<int>ans,temp;//ans存放最大的序列，temp存放当前最大的序列
int n,p,k;
int maxFacSum=-1;
int pow(int x)
{
    int result=1;
    for(int i=1;i<=p;i++)
    {
        result*=x;
    }
    return result;
}
void init()
{
    int i=0,temp=0;
    while(temp<=n)
    {
        fac.push_back(temp);
        temp=pow(++i);
    }
}
void DFS(int index,int nowk,int nowsum,int facsum)
{
    //设计递归出口
    if(nowsum==n&&nowk==k)
    {
        //更新最大值
        if(facsum>maxFacSum)
        {
            ans=temp;
            maxFacSum=facsum;
        }
        return ;
    }
    //返回情况
    if(nowsum>n||nowk>k) return;
    //两条路可以走
    if(index-1>=0)
    {
        //选择index
        temp.push_back(index);
        DFS(index,nowk+1,nowsum+fac[index],facsum+index);
        //不选择index
        temp.pop_back();
        DFS(index-1,nowk,nowsum,facsum);
    }
    

}
int main ()
{
    scanf("%d%d%d",&n,&k,&p);
    init();//初始化fac数组
    DFS(fac.size()-1,0,0,0);
    if(maxFacSum==-1) printf("Impossible");
    else 
    {
        printf("%d = %d^%d",n,ans[0],p);
        for(int i=1;i<ans.size();i++)
        {
            printf(" + %d^%d",ans[i],p);
        }
    }
return 0;
    

}