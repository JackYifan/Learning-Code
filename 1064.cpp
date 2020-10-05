#include<cstdio>
#include<algorithm>
using namespace std;
//运用中序遍历从小到大
const int maxn=1010;
int n;
int num[maxn];
int CBT[maxn];
int cnt=0;
void inorder(int root)
{
    //递归的本质是从叶结点开始处理
    if(root>n) return;
    inorder(2*root);//左子树根结点下标
    CBT[root]=num[cnt++];
    inorder(2*root+1);

}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    sort(num,num+n);
    inorder(1);
    for(int i=1;i<1+n;i++)
    {
        printf("%d",CBT[i]);
        if(i<n) printf(" ");
    }

}