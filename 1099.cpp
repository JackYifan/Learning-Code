#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n;
const int maxn=101;
struct node
{
    /* data */
    int data;
    int left,right;
}Node[maxn];
int num[maxn];
int cnt=0;
void inorder(int root)
{
    if(root==-1 ) return;
    inorder(Node[root].left);
    Node[root].data=num[cnt++];
    inorder(Node[root].right);
}
void levelorder(int root)
{
    queue<int>q;
    q.push(root);
    int cnt=0;
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        cnt++;
        printf("%d",Node[now].data);
        if(cnt<n) printf(" ");
        if(Node[now].left!=-1) q.push(Node[now].left);
        if(Node[now].right!=-1) q.push(Node[now].right);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&Node[i].left,&Node[i].right);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    sort(num,num+n);
    inorder(0);
    levelorder(0);
}