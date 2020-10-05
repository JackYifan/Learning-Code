#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
const int maxn=100010;
vector<int>v[maxn];//邻接表同性朋友
unordered_map<int,bool>arr;//a*1000+b 表示是否是朋友
struct node{
    int a,b;
};
bool cmp(node x,node y){
    return x.a!=y.a?x.a<y.a:x.b<y.b;
}
int main(){
    int n,m,k;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        string a,b;
        cin>>a>>b;
        //长度相同相同性别
        if(a.length()==b.length()){
            v[abs(stoi(a))].push_back(abs(stoi(b)));
            v[abs(stoi(b))].push_back(abs(stoi(a)));
        }
        arr[abs(stoi(a))*10000+abs(stoi(b))]=
        arr[abs(stoi(b))*10000+abs(stoi(a))]=true;
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int c,d;
        cin>>c>>d;
        vector<node>ans;//一对组合就是答案
        //遍历所有同性朋友
        for(int j=0;j<v[abs(c)].size();j++){
            for(int k=0;k<v[abs(d)].size();k++){
                //c是d的同性朋友就跳过
                if(v[abs(c)][j]==abs(d)||v[abs(d)][k]==abs(c)) continue;
                if(arr[ v[abs(c)][j]*10000+v[abs(d)][k]]==true){
                    ans.push_back(node{v[abs(c)][j],v[abs(d)][k]});
                }
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        cout<<ans.size()<<endl;
        for(int j=0;j<ans.size();j++){
            printf("%04d %04d\n",ans[j].a,ans[j].b);
        }
    }
    return 0;
}