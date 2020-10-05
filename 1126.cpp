#include<iostream>
#include<vector>
using namespace std;
const int maxn=10010;
vector<vector<int> >v;
bool visit[maxn];
int cnt=0;
void DFS(int index){
    visit[index]=true;
    cnt++;
    for(int i=0;i<v[index].size();i++){
        if(visit[v[index][i]]==false){
            DFS(v[index][i]);
        }
    }
}
int oven=0;
int main(){
    int n,m;
    cin>>n>>m;
   
    v.resize(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    //遍历N个结点
    
    for(int i=1;i<=n;i++){
        if(i!=1) cout<<" ";
        cout<<v[i].size();
        if(v[i].size()%2==0) oven++;
    }
    cout<<endl;
    DFS(1);
    if(oven==n&&cnt==n) cout<<"Eulerian\n";
    else if(oven==n-2&&cnt==n) cout<<"Semi-Eulerian\n";
    else cout<<"Non-Eulerian\n";
    return 0;

}