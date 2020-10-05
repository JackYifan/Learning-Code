#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=100010;
struct node{
    string school;
    int sum,cnt;
};
bool cmp(node a,node b){
    if(a.sum!=b.sum) return a.sum>b.sum;
    else if(a.cnt!=b.cnt) return a.cnt<b.cnt;
    else return a.school<b.school;
}
unordered_map<string,int>cnt;
unordered_map<string,double>sum;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string id,school;
        cin>>id;
        double score;
        cin>>score>>school;
        //学校转为小写
        for(int j=0;j<school.length();j++){
            school[j]=tolower(school[j]);
        }
        if(id[0]=='B') score/=1.5;
        else if(id[0]=='T') score*=1.5;
        cnt[school]++;
        sum[school]+=score;
    }
    //对两个数据进行汇总
    vector<node>ans;
    for(auto it=cnt.begin();it!=cnt.end();it++){
        ans.push_back(node{it->first,(int)sum[it->first],it->second});
    }
    sort(ans.begin(),ans.end(),cmp);
    cout<<ans.size()<<endl;
    //对同分的处理
    int rank=0,pre=-1;
    for(int i=0;i<ans.size();i++){
        if(ans[i].sum!=pre) rank=i+1;//否则rank不变
        pre=ans[i].sum;
        cout<<rank<<" "<<ans[i].school<<" "<<ans[i].sum<<" "
        <<ans[i].cnt<<endl;
    }
    return 0;
}