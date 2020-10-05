#include<bits/stdc++.h>
using namespace std;
void print(const list<int>&l)
{
    for(list<int>::const_iterator it=l.begin();it!=l.end()
    ;it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main()
{
    list<int>l;
    l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
    print(l);
    list<int>::iterator it=l.begin();
    
    list<int>::iterator temp=l.insert(++it,1000);
    print(l);
    it=l.begin();
    temp=l.erase(++it);
    cout<<*temp<<endl;
    print(l);
    cout<<l.front()<<l.back()<<endl;
    l.reverse();
    print(l);
    l.sort();
    print(l);
    
}