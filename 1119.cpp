#include<iostream>
#include<vector>
using namespace std;
vector<int>pre,post,in;
bool unique=true;
void getIn(int preleft,int preright,int postleft,int postright){
    //子树只有一个结点
    if(preleft==preright){
        in.push_back(pre[preleft]);
        return;
    }
    if(pre[preleft]==post[postright]){
        int i=preleft+1;
        while(pre[i]!=post[postright-1]&&i<=preright) i++;//找子树根节点
        int num=i-preleft-1;
        if(i-preleft-1>0){
            //左子树不为空,递归左子树
            
            getIn(preleft+1,i-1,postleft,postleft+num-1);
        }
        else unique=false ;
        in.push_back(post[postright]);//根结点
        //递归右子树
        getIn(i,preright,postleft+num,postright-1);
    }
}
int main()
{
    int n;
    cin>>n;
    pre.resize(n);post.resize(n);
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    for(int i=0;i<n;i++){
        cin>>post[i];
    }
    getIn(0,n-1,0,n-1);
    printf("%s\n",unique==true?"Yes":"No");
    cout<<in[0];
    for(int i=1;i<in.size();i++){
        cout<<" "<<in[i];
    }
    cout<<endl;
    return 0;
}