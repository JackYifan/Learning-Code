#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
struct node{
    string name;
    int gp,gm,gf,g;//g为最终的成绩
};
map<string,int>idx;
vector<node>v,ans;
bool cmp(node a,node b){
    return a.g!=b.g?a.g>b.g:a.name<b.name;
}
int main(){
    int p,n,m;
    cin>>p>>m>>n;
    string s;
    int score;
    int cnt=1;
    for(int i=0;i<p;i++){
        cin>>s>>score;
        //第一层筛选编程成绩大于200的人
        if(score>=200){
            v.push_back(node{s,score,-1,-1,0});
            //用于区分编程没合格的同学
            idx[s]=cnt++;
        }
    }
    for(int i=0;i<m;i++){
        cin>>s>>score;
        //编程成绩合格
        if(idx[s]!=0){
            v[idx[s]-1].gm=score;
        }
    }
    for(int i=0;i<n;i++){
        cin>>s>>score;
        if(idx[s]!=0){
            //真正在v中的位置
            int temp=idx[s]-1;
            v[temp].gf=v[temp].g=score;
            //四舍五入的方法
            if(v[temp].gm>v[temp].gf) v[temp].g=int(v[temp].gm*0.4+v[temp].gf*0.6+0.5);
        }
    }
    for(int i=0;i<v.size();i++){
        if(v[i].g>=60) ans.push_back(v[i]); 
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].name<<" "<<ans[i].gp<<" "<<ans[i].gm<<" "
        <<ans[i].gf<<" "<<ans[i].g<<endl;
    }
    return 0;
}