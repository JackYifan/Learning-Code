#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    int m,n,s;
    cin>>m>>n>>s;
    map<string,int>map;
    bool flag=false ;
    for(int i=1;i<=m;i++){
        string temp;
        cin>>temp;
        if(map[temp]==1) s++;
        if(i==s&&map[temp]==0){
            map[temp]=1;
            cout<<temp<<endl;
            flag=true;
            s+=n;
        }
        
    }
    if(flag==false ) cout<<"Keep going...\n";
}