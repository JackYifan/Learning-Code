#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>v[n];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(i);
        v[y].push_back(i);
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int nn;
        cin>>nn;
        vector<int>hash(m,0);
        for(int j=0;j<nn;j++){
            int num;
            cin>>num;
            for(int t=0;t<v[num].size();t++){
                //该点引发的边标记为1
                hash[v[num][t]]=1;
            }
        }
        //遍历所有边，看有没有全标记
        int flag=0;
        for(int j=0;j<m;j++){
            if(hash[j]==0){
                cout<<"No"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0) cout<<"Yes"<<endl;
    }
}