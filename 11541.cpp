#include<iostream>
#include<vector>
#include<set>
using namespace std;
struct node{
    int v1,v2;
};//一条边
int main(){
    int n,m;
    cin>>n>>m;
    vector<node>e(m);
    for(int i=0;i<m;i++){
        cin>>e[i].v1>>e[i].v2;
    }
    int k;cin>>k;
    for(int i=0;i<k;i++){
        set<int>se;//记录多少种颜色；
        bool flag=true;
        vector<int>color(n);
        for(int j=0;j<n;j++){
            cin>>color[j];//第i个点的颜色
            se.insert(color[j]);
        }
        for(int j=0;j<m;j++){
            if(color[e[j].v1]==color[e[j].v2]) flag=false ;
        }
        if(flag) printf("%d-coloring\n",se.size());
        else printf("No\n");
    }
}
/**
 * 4-coloring
No
6-coloring
No*/