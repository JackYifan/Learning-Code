#include<iostream>
#include<vector>
using namespace std;
vector<int>pre,in;
bool flag=false ;
void build(int prel,int prer,int inl,int inr){
    if(prel>prer||flag==true) return ;
    int i=inl;
    while(in[i]!=pre[prel]) i++;
    int left=i-inl;
    build(prel+1,prel+left,inl,i-1);
    build(prel+left+1,prer,i+1,inr);
    //第一次递归返回的就是最深最左结点
    if(flag==false){
        cout<<in[i];
        flag=true;
    }
}
int main(){
    int n;
    cin>>n;
    pre.resize(n);in.resize(n);
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    build(0,n-1,0,n-1);
    return 0;
}