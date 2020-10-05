#include<cstdio>
#include<queue>
using namespace std;
int post[30],in[30];
int n;
struct node
{
    int data;
    node* lchild;
    node* rchild;
}Node;
//用下标表示node
node* create(int postl,int postr,int inl,int inr)
{
    //递归出口
    if(postl>postr) return NULL;
    //构建二叉树需要创建结点
    node* root=new node;
    root->data=post[postr];
    int i,numl,numr;
    for(i=inl;i<=inr;i++)
    {
        if(in[i]==post[postr]) break;
    }
    numl=i-inl;
    numr=inr-i;
    root->lchild=create(postl,postl+numl-1,inl,i-1);
    root->rchild=create(postl+numl,postr-1,i+1,inr);
    return root;
}
//层序遍历二叉树
queue<node*>q;
void BFS(node*root)
{
    int cnt=0;
    q.push(root);
    while(!q.empty())
    {
        node*temp=q.front();
        q.pop();
        cnt++;
        if(temp->lchild!=NULL) q.push(temp->lchild);
        if(temp->rchild!=NULL) q.push(temp->rchild);
        printf("%d",temp->data);
        if(cnt<n) printf(" ");
    }
}
int main()
{
    
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&post[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&in[i]);
    }
    //根据2组数据，构建二叉树
    node*root=create(0,n-1,0,n-1);
    BFS(root);
    return 0;
}