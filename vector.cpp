#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void myPrint(int val){
    cout<<val<<endl;
}
int main(){
    vector<int>v;
    for(int i=1;i<=5;i++){
        v.push_back(i*10);
    }
    vector<int>::iterator pbegin=v.begin();
    vector<int>::iterator pend=v.end();
    while(pbegin!=pend)
    {
        cout<<*pbegin<<endl;
        pbegin++;
    }
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }
    cout<<"============"<<endl;
    for_each(v.begin(),v.end(),myPrint);

}