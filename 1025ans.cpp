#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    long long no;
    int score,finrank,loca,locarank;
};
//地区排名
bool cmp1(node a,node b){
    return a.score!=b.score?a.score>b.score:a.no<b.no;
}
int main()
{
    int n,m;
    cin>>n;
    vector<node>fin;
    for(int i=1;i<=n;i++){
        cin>>m;
        vector<node>v(m);
        for(int j=0;j<m;j++){
            cin>>v[j].no>>v[j].score;
            v[j].loca=i;
        }
        sort(v.begin(),v.end(),cmp1);
        v[0].locarank=1;
        fin.push_back(v[0]);
        for(int j=1;j<m;j++){
            v[j].locarank=(v[j].score==v[j-1].score)?(v[j-1].locarank):(j+1);
            fin.push_back(v[j]);
        }
    }
    sort(fin.begin(),fin.end(),cmp1);
    fin[0].finrank=1;
    for(int i=1;i<fin.size();i++){
        fin[i].finrank=(fin[i].score==fin[i-1].score)?(fin[i-1].finrank):(i+1);
    }
    cout<<fin.size()<<endl;
    for(int i=0;i<fin.size();i++){
        printf("%013lld %d %d %d\n",fin[i].no,fin[i].finrank,fin[i].loca,fin[i].locarank);
    }

}