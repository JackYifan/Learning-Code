#include<bits/stdc++.h>
using namespace std;
void println(vector<int>& v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
    println(v1);
    v1.insert(v1.begin(),100);
    println(v1);
    v1.erase(v1.end()-2);
    println(v1);
    cout<<v1.back()<<endl;
    
}