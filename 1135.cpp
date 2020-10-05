#include<iostream>
#include<vector>
using namespace std;
vector<int>arr;
struct node{
    int val;
    node*left;
    node*right;
};
node* build(node* root,int v){
    if(root==NULL){
        root=new node();
        root->val=v;
        root->left=root->right=NULL;
    }else if(abs(v)<=abs(root->val)){
        root->left=build(root->left,v);
    }else{
        root->right=build(root->right,v);
    }
    return root;
}
bool judge1(node *root){
    if(root==NULL) return true;
    //子节点不是红色，首先先判断是否为空否则空指针异常
    if(root->val<0){
        if(root->left!=NULL&&root->left->val<0) return false ;
        if(root->right!=NULL&&root->right->val<0) return false ;

    }
    return judge1(root->left)&&judge1(root->right);
}
//计算黑高
int getNum(node* root){
    if(root==NULL) return 0;
    int l=getNum(root->left);
    int r=getNum(root->right);
    return root->val>0?max(l,r)+1:max(l,r);
}
bool judge2(node*root){
    if(root==NULL) return true;
    int l=getNum(root->left);
    int r=getNum(root->right);
    if(l!=r) return false ;
    return judge2(root->left)&&judge2(root->right);
}
int main(){
    int n,k;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>n;
        arr.resize(n);
        node*root=NULL;
        //平衡二叉树逐个插入的过程就是先序遍历
        for(int j=0;j<n;j++){
            cin>>arr[j];
            root=build(root,arr[j]);
        }
        if(arr[0]<0||judge1(root)==false||judge2(root)==false){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}