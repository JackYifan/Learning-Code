#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct fruit
{
    string name ;
    int price ;
    friend bool operator < (fruit f1,fruit f2){
        return f1.price > f2.price;
    }
    
    /* data */
}f1,f2,f3;

class cmp{
    public:
    bool operator()(fruit f1,fruit f2){
        return f1.price>f2.price;
    }
};


int main()
{
    // priority_queue<int,vector<int>,greater<int> > q;
    // q.push(5);
    // q.push(1);
    // q.push(3);
    // q.push(2);
    // cout<<q.top();
    // q.pop();
    // cout<<q.top();
    f2.name="Orange";
    f2.price=200;
    f1.name="Apple";
    f1.price=100;
    f3.name="Banana";
    f3.price=300;
    priority_queue<fruit,vector<fruit>,cmp >q;
    q.push(f1);
    q.push(f2);
    q.push(f3);
    cout<<q.top().name<<q.top().price;
    
    
}