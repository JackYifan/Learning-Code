#include<iostream>
#include<set>
using namespace std;
const int maxn=10010;
int father[maxn];
bool visit[maxn];
int find(int x){
    int a=x;
    while(x!=father[x]){
        x=father[x];
    }
    while(a!=x){
        int t=a;
        a=father[a];
        father[t]=x;
    }
    return x;
}
void Union(int a,int b){
    int faA=find(a);
    int faB=find(b);
    if(faA!=faB) father[faB]=faA;
}
int n,k;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<maxn;i++){
        father[i]=i;
    }
    int id;
    for(int i=0;i<n;i++){
        scanf("%d%d",&k,&id);
        visit[id]=true;
        for(int j=0;j<k-1;j++){
            int temp;
            scanf("%d",&temp);
            visit[temp]=true;
            Union(id,temp);
        }
    }
    int numTrees=0,numBirds=0;
    int cnt[maxn]={0};
    set<int>s;
    for(int i=0;i<maxn;i++){
        if(visit[i]){
            int root=find(i);
            s.insert(root);
            cnt[root]++;
        }
    }
    numTrees=s.size();
    for(auto it=s.begin();it!=s.end();it++){
        numBirds+=cnt[*it];
    }
    printf("%d %d\n",numTrees,numBirds);
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%s\n",(find(x)==find(y))?"Yes":"No");
    }
    return 0;

}