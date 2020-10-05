#include<cstdio>
#include<vector>
using namespace std;
struct node
{
    /* data */
    int data;
    node*lchild,*rchild;
};
vector<int>origin,pre,preM,post,postM;
void insert(int x,node*&root)
{
    //递归到空指针时即为插入位置
    if(root==NULL)
    {
        root=new node;//新开一块node区域并把地址付给root
        root->data=x;
        root->lchild=NULL;
        root->rchild=NULL;
        return ;
    }
    if(x>=root->data) insert(x,root->rchild);
    else insert(x,root->lchild);
}
void preorder(node*root)
{
    if(root==NULL) return ;
    pre.push_back(root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void preMorder(node*root)
{
    if(root==NULL) return ;
    preM.push_back(root->data);
    preMorder(root->rchild);
    preMorder(root->lchild);
   
}
void postorder(node*root)
{
    if(root==NULL) return ;
    postorder(root->lchild);
    postorder(root->rchild);
    post.push_back(root->data);
}
void postMorder(node*root)
{
    if(root==NULL) return ;
    postMorder(root->rchild);
    postMorder(root->lchild);
    postM.push_back(root->data);
} 
int main()
{
    int n,data;
    node *root=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        origin.push_back(data);
        insert(data,root);
    }
    preorder(root);
    preMorder(root);
    postorder(root);
    postMorder(root);

    if(pre==origin) 
    {
        printf("YES\n");
        for(int i=0;i<post.size();i++)
        {
            printf("%d",post[i]);
            if(i<post.size()-1) printf(" ");
        }
    }
    else if(preM==origin) 
    {
        printf("YES\n");
        for(int i=0;i<postM.size();i++)
        {
            printf("%d",postM[i]);
            if(i<postM.size()-1) printf(" ");
        }
    }
    else printf("NO");
    return 0;
}