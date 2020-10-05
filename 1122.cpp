#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int maxn=10010;
int G[maxn][maxn];
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        G[x][y]=G[y][x]=1;
    }
    int cnt;
    cin>>cnt;
    while(cnt--){
        int tot;
        cin>>tot;
        vector<int>v(tot);
        set<int>s;
        for(int i=0;i<tot;i++){
            cin>>v[i];
            s.insert(v[i]);
        }
        bool flag1=true,flag2=true;
        if(s.size()!=n||tot!=n+1||v[0]!=v[tot-1]) flag1=false ;
        for(int i=0;i<tot-1;i++){
            if(!G[v[i]][v[i+1]]) {
                flag2=false ;
                break;
            }
        }
        printf("%s\n",flag1&&flag2?"YES":"NO");

    }
    return 0;
    
}