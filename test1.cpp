#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){};
    friend bool operator<(node a,node b);
};
bool operator<(node a,node b){
    return a.x<b.x;
}
node operator+(const node&a,const node&b){
    return node(a.x+b.x,a.y+b.y);
}
//out<<node
ostream& operator<<(ostream& out,const node& p){
    out<<"("<<p.x<<","<<p.y<<")";
    return out;
}
int main(){
    node x={1,2};
    node y={2,3};
    cout<<sizeof(char)<<endl;
    cout<<sizeof(int)<<endl;

}



