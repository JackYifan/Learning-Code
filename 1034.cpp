#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
//有权重的问题使用邻接矩阵
const int maxn=1001;
int weight[maxn]={0};
int mp[maxn][maxn]={0};
map<string,int> strToNum;
map<int,string> numToStr;
map<string,int>gang;
bool visit[maxn]={false};
int cnt=0;
int n,k;
int change(string str)
{
    if(strToNum.find(str)!=strToNum.end())
    {
        return strToNum[str];
    }
    else 
    {
        strToNum[str]=cnt;
        numToStr[cnt]=str;
        cnt++;
    } 
    return strToNum[str];
}
//遍历每一个人
void DFS(int now,int& head,int& num,int& tot)
{
    num++;
    visit[now]=true;
    if(weight[now]>weight[head]) 
    {
        head=now;
    }
    for(int i=0;i<cnt;i++)
    {
        int x=mp[now][i];
        if(x!=0) 
        {
            tot+=x;
            mp[now][i]=mp[i][now]=0;
            if(visit[i]==false)
            {
                DFS(i,head,num,tot);
            }
        }
    }
    
    
}
void travel()
{
    for(int i=0;i<cnt;i++)
    {
        //找到没有访问过的点就访问它所在连通块中的所有点
        if(visit[i]==false)//i所在的连通图中
        {
            int head=i,num=0,tot=0,maxweight=weight[i];
            DFS(i,head,num,tot);
            if(num>2&&tot>k)
            {
                //cout<<head<<endl;
                gang[numToStr[head]]=num;
            }
        }
        
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        string str1,str2;
        int w;
        cin>>str1>>str2>>w;
        int id1=change(str1);
        int id2=change(str2);
        //cout<<id1<<" "<<id2<<" "<<cnt<<endl;
        mp[id1][id2]+=w;
        mp[id2][id1]+=w;
        weight[id1]+=w;
        weight[id2]+=w;
    }
    // for(int i=0;i<cnt;i++)
    // {
    //     printf("%d ",weight[i]);
    // }
    travel();
    cout<<gang.size() <<endl;
    // cout<<weight[6]<<strToNum["GGG"]<<numToStr[6]<<endl;
    map<string,int>::iterator it;
    for(it=gang.begin();it!=gang.end();it++)
    {
        cout<<it->first <<" "<<it->second<<endl;
    }
    return 0;
}