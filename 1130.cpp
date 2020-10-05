#include<bits/stdc++.h>
using namespace std;
struct Node{
    string data;
    int l,r;
}node[100];
string DFS(int root){
    //拼串
    if(node[root].l==-1&&node[root].r==-1) return node[root].data;
    if(node[root].l==-1&&node[root].r!=-1) return "("+node[root].data+DFS(node[root].r)+")";
    if(node[root].l!=-1&&node[root].r!=-1)
        return "("+DFS(node[root].l)+node[root].data+DFS(node[root].r) +")";
}
int main(){
    int n;
    cin>>n;
    int have[100];//查找哪个结点没有父节点
    for(int i=1;i<=n;i++){
        cin>>node[i].data>>node[i].l>>node[i].r;
        if(node[i].l!=-1) have[node[i].l]=1;
        if(node[i].r!=-1) have[node[i].r]=1;
    }
    int root=1;
    while(have[root]==1) root++;
    string ans=DFS(root);
    if(ans[0]=='(') ans=ans.substr(1,ans.size()-2);
    cout<<ans;
    return 0;

}