#include<iostream>
#include<vector>
using namespace std;
int e[210][210];
int main(){
    int nv,ne;
    cin>>nv>>ne;
    for(int i=0;i<ne;i++){
        int x,y;
        cin>>x>>y;
        e[x][y]=e[y][x]=1;
    }
    int m;
    cin>>m;
    
    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        vector<int>v(k);
        int isclique=1,ismaximal=1;
        int hash[210]={0};
        for(int j=0;j<k;j++){
            cin>>v[j];
            hash[v[j]]=1;
        }
        for(int j=0;j<k;j++){

            for(int t=j+1;t<k;t++){
                if(e[v[j]][v[t]]==0) {
                    isclique=0;
                    cout<<"Not a Clique"<<endl;
                    break;
                }
            }
            if(isclique==0) break;
        }
        if(isclique==0) continue;
        for(int j=1;j<=nv;j++){
            //没有在集合中
            if(hash[j]==0){
                for(int l=0;l<k;l++){
                    if(e[v[l]][j]==0) break;
                    //替代flag；判断方法
                    if(l==k-1) ismaximal=0;
                }
            }
            //提前结束降低复杂度
            if(ismaximal==0){
                cout<<"Not Maximal"<<endl;
                break;
            }
        }
        if(ismaximal==1) cout<<"Yes"<<endl;

    }
    return 0;
}