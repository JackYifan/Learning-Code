#include<cstdio>
#include<queue>
using namespace std;
struct node
{
    /* data */
    int data;
    node*left,*right;
};
void insert(int x,node*&root)
{
    if(root==NULL)
    {
        root=new node ;
        root->data=x;
        root->left=root->right=NULL;
        return;
    }
    if(x<root->data) insert(x,root->left);
    else insert(x,root->right);
}
int main()
{
    int n;
    node*root=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        insert(x,root);
    }
    queue<node*>q;
    q.push(root);
    for(int i=0;i<n;i++)
    {
        node* now=q.front();
        q.pop();
        printf("%d ",now->data);
        if(now->left!=NULL) q.push(now->left);
        if(now->right!=NULL) q.push(now->right);
    }
    return 0;
}
