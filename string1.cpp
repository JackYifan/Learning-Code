#include<bits/stdc++.h>
using namespace std;
int main(){
    string str1="hello world";
    string str2="hello";
    string str3="world";
    int a=str1.find("el",0);
    cout<<a<<endl;
    cout<<str1.find('l',0)<<endl;
    cout<<str1.find("l",2)<<endl;
    cout<<str1.replace(5,5,str3)<<endl;

}