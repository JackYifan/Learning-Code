#include<cstdio>
#include<iostream>
using namespace std;
struct Node{
    int l,r;
}node[100];
int root;
int maxn=-1,ans;//最大的Index结点
//root的index是1
void DFS(int root,int index)
{
    if(index>maxn)
    {
        maxn=index;
        ans=root;
    }
    if(node[root].l!=-1) DFS(node[root].l,index*2);
    if(node[root].r!=-1) DFS(node[root].r,index*2+1);
}
int main()
{
    int n;
    bool have[100]={false};//没有成为子节点的就是root
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        string left,right;
        
        cin>>left>>right;
        if(left=="-"){
            node[i].l=-1;
        }else{
            node[i].l=stoi(left);
            have[stoi(left)]=true;
        }
        if(right=="-"){
            node[i].r=-1;
        }else{
            node[i].r=stoi(right);
            have[stoi(right)]=true;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(!have[i])
        {
            root=i;
            break;
        }
    }
    DFS(root,1);
    if(maxn==n) cout<<"YES "<<ans;
    else cout<<"NO "<<root;
    return 0;
    
}