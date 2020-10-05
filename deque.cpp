#include<bits/stdc++.h>
using namespace std;
void print(const deque<int>&d)
{
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main()
{
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(30);
    d.push_front(40);
    // print(d);
    // d.pop_back();
    // d.pop_front();
    print(d);
    d.insert(d.begin(),10000);
    d.insert(d.end()-2,2,30000);
    print(d);
    d.erase(d.begin()+2);
    print(d);
}