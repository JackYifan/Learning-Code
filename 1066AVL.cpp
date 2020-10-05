#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
    /* data */
    int v,height=0;
    node*lchild,*rchild;
};
int getHeight(node*root)
{
    if(root==NULL) return 0;
    return root->height;
}
node* newnode(int x)
{
    node*root=new node;
    root->v=x;
    root->height=1;
    root->lchild=root->rchild=NULL;
    return root;
}
int getBalanceFactor(node*root)
{
    return getHeight(root->lchild)-getHeight(root->rchild);
}
void updateHeight(node*&root)
{
    root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}
//左旋
void L(node*&root)
{
    node*temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
//右旋
void R(node*&root)
{
    node*temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
void insert(int x,node*&root)
{
    if(root==NULL)
    {
        root=newnode(x);
        return;
    }
    if(x<root->v)
    {
        insert(x,root->lchild);
        updateHeight(root);
        if(getBalanceFactor(root)==2)
        {
            if(getBalanceFactor(root->lchild)==1)
            {
                R(root);
            }
            else if(getBalanceFactor(root->lchild)==-1)
            {
                
                L(root->lchild);
                R(root);
            } 
        }
    }
    else 
    {
        insert(x,root->rchild);
        updateHeight(root);
        if(getBalanceFactor(root)==-2)
        {
            if(getBalanceFactor(root->rchild)==-1)
            {
                L(root);
            }
            else if(getBalanceFactor(root->rchild)==1)
            {
                R(root->rchild);
                L(root);
            }
        }

    }
}
int main()
{
    node*root=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        insert(x,root);
    }
    printf("%d",root->v);
}