#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
    int v;
    Node *left,*right;
};
Node* build(Node*root,int v){
    //找到树的最深处插入v
    if(root==NULL){
        root=new Node;
        root->v=v;
        root->left=root->right=NULL;
    }else if(v<=root->v) root->left=build(root->left,v);
    else root->right=build(root->right,v);
    return root;
}
int maxdepth;
vector<int>v(1000);
void DFS(Node* root,int depth){
    if(root==NULL){
        maxdepth=max(depth,maxdepth);
        return ;
    }
    v[depth]++;
    DFS(root->left,depth+1);
    DFS(root->right,depth+1);
}
int main()
{
    int n;
    scanf("%d",&n);
    Node* root=NULL;
    for(int i=0;i<n;i++){
        int v;
        scanf("%d",&v);
        root=build(root,v);
    }
    DFS(root,0);
    cout<<v[maxdepth-1]<<" + "<<v[maxdepth-2]<<" = "<<v[maxdepth-1]+v[maxdepth-2]<<endl;
    return 0;
}