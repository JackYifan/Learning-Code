#include<bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(const int &a,const int &b){
        return a>b;
    }
};
void print(const multiset<int,cmp>&s)
{
    for(multiset<int,cmp>::const_iterator it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main()
{
    multiset<int,cmp>s;
    s.insert(40);
	s.insert(30);
	s.insert(20);
	s.insert(10);
    // print(s);
    // s.erase(s.begin());
    // s.erase(40);
    // print(s);
    multiset<int,cmp>::iterator it;
    it=s.find(30);
    cout<<*it<<endl;
    s.insert(10);
    s.insert(10);
    s.insert(10);
    s.insert(10);
    s.insert(10);
    print(s);




}