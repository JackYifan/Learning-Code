#include<iostream>
#include<set>
using namespace std;
int getid(int x){
    int sum=0;
    while(x!=0){
        sum+=x%10;
        x/=10;
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    set<int>set;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        set.insert(getid(x));
    }
    cout<<set.size()<<endl;
    for(auto it=set.begin();it!=set.end();it++){
        if(it!=set.begin()) cout<<" ";
        cout<<*it;
    }
    return 0;
}