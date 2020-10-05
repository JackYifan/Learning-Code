#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int book[maxn];
struct node{
    int value;
    int cnt;
    //this.operator<(a)
    bool operator<(const node&a)const{
        return(cnt!=a.cnt)?cnt>a.cnt:value<a.value;
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    set<node>s;//按照operator<从小到达排序
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(i!=0){
            cout<<num<<":";
            int innercnt=0;
            for(auto it=s.begin();it!=s.end()&&innercnt<k;it++){
                cout<<" "<<it->value;
                innercnt++;
            }
           cout<<endl;
        }
        
        //加入当前商品
        auto it=s.find(node{num,book[num]});
        if(it!=s.end()){
            s.erase(it);
        }
        book[num]++;
        s.insert(node{num,book[num]});
    }
    return 0;
}