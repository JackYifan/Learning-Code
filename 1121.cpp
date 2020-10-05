#include<iostream>
#include<set>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=100010;
int couple[maxn];
int main()
{
    memset(couple,-1,sizeof(couple));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x, y;
        cin>>x>>y;
        couple[x]=y;
        couple[y]=x;
    }
    int m;
    cin>>m;
    vector<int>guest(m);
    bool come[maxn];
    for(int i=0;i<m;i++){
        cin>>guest[i];
        come[guest[i]]=true;
    }
    set<int>single;
    for(int i=0;i<m;i++){
        if(couple[guest[i]]!=-1&&come[couple[guest[i]]]) continue;
        single.insert(guest[i]);
    }
    cout<<single.size()<<endl;
    for(auto it=single.begin();it!=single.end();it++){
        if(it!=single.begin()) cout<<" ";
        printf("%05d",*it);
    }
    return 0;
}