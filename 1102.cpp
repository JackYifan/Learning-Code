#include<cstdio>
#include<queue>
#include<string.h>
using namespace std;
int n;
bool notroot[10]={false};//不要用true 默认为false(0)
struct node
{
   int lchild,rchild;
}Node[10];
void postorder(int root)
{
    //递归出口
    if(root==-1) return ;
    postorder(Node[root].lchild);
    postorder(Node[root].rchild);
    int temp;
    temp=Node[root].lchild;
    Node[root].lchild=Node[root].rchild;
    Node[root].rchild=temp;
}

int invertToNum(char c)
{
    if(c=='-') return -1;
    else 
    {
        notroot[c-'0']=true;
        return c-'0';
    }
}
void levelorder(int root)
{
    queue<int>q;
    q.push(root);
    int cnt=0;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        cnt++;
        printf("%d",front);
        if(cnt<n) printf(" ");
        if(Node[front].lchild!=-1)  q.push(Node[front].lchild);
        if(Node[front].rchild!=-1)  q.push(Node[front].rchild);
    }
}
int ins=0;
void inorder(int root)
{
    if(root==-1) return ;
    inorder(Node[root].lchild);
    printf("%d",root);
    ins++;
    if(ins<n) printf(" ");
    inorder(Node[root].rchild);
}

int main()
{
    
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char c1,c2;
        scanf("%*c%c %c",&c1,&c2);
        Node[i].lchild=invertToNum(c1);
        Node[i].rchild=invertToNum(c2);
    }
    //没有被当成子节点的数字即为根结点
    int root=0;
    for(int i=0;i<n;i++)
    {
        if(notroot[i]==false)
        {
            root=i;
            break;
        }
    }
  
    //后序遍历交换
    postorder(root);
    levelorder(root);
    printf("\n");
    inorder(root);
    return 0;
}

