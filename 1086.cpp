#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
stack<int> st;
int pre[50],in[50];
int precnt=0,incnt=0;
struct node
{
    int data;
    node* lchild;
    node* rchild;
}Node;
node* create(int prel,int prer,int inl,int inr)
{
    //递归出口
    if(prel>prer) return NULL;
    int k;
    node* root=new node;
    root->data=pre[prel];
    for(k=inl;k<inr;k++)
    {
        if(in[k]==pre[prel]) break;
    }
    int numl=k-inl;
    root->lchild=create(prel+1,prel+numl,inl,k-1);
    root->rchild=create(prel+numl+1,prer,k+1,inr);
    return root;
}
int num=0,n;
void postorder(node* root)
{
    //递归出口
    if(root==NULL) return ;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d",root->data);
    num++;//全局变量n记录输出了多少个数
    if(num<n) printf(" ");
}

int main()
{
    char str[5];
    scanf("%d",&n);
    for(int i=0;i<2*n;i++)
    {
        //得到先序、中序的数组
       
        scanf("%s",str);
        
        if(strcmp(str,"Push")==0)
        {
            int x;
            scanf("%d",&x);
            st.push(x);
            pre[precnt++]=x;
            
        }
        else 
        {
            int x=st.top();
            in[incnt++]=x;
            st.pop();
        }
        getchar();
    }
    
    node* root=create(0,n-1,0,n-1);
    //后序遍历
    postorder(root);
    return 0;
    
}