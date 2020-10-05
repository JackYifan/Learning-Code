#include<iostream>
#include<vector>
using namespace std;
vector<int>v;int n;
vector<int>path;
void dfs(int root){
    //根据root dfs
    path.push_back(root);
    if(root*2>n){
        if(root<=n){
            for(int i=0;i<path.size();i++){
                printf("%d",v[path[i]]);
                if(i!=path.size()-1) printf(" ");
                else printf("\n");
            }
        }
        
    }else {
        dfs(root*2+1);
        path.pop_back();
        dfs(root*2);
        path.pop_back();
    }

}
int main()
{
    cin>>n;
    v.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    dfs(1);
    //判断父子节点的关系
    bool maxHeap=true;
    bool minHeap=true;
    for(int i=1;i<n;i++){
        if(2*i<=n){
            if(v[i]<v[2*i]) maxHeap=false;
            if(v[i]>v[2*i]) minHeap=false;
        }
        if(2*i+1<=n){
            if(v[i]<v[2*i+1]) maxHeap=false;
            if(v[i]>v[2*i+1]) minHeap=false;
        }
    }
    if(maxHeap) printf("Max Heap\n");
    else if(minHeap) printf("Min Heap\n");
    else printf("Not Heap\n");
}