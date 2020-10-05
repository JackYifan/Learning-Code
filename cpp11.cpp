#include<cstdio>
#include<iostream>
#include<vector>
#include<bitset>
#include<cctype>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c='H';
    cout<<isalpha(c)<<" "<<islower(c)<<" "<<isupper(c)<<" "<<isalnum(c)<<" "<<endl;
    cout<<isblank(' ')<<" "<<isspace('\n')<<endl;
    cout<<(char)tolower(c)<<" "<<(char)toupper('a')<<endl;
    cout<<"===================="<<endl;
    string s="hello world";
    for(auto it=s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    int arr[4]={1,2,3,4};
    for(int &el:arr){
        el*=2;
    }
    for(int el:arr){
        cout<<el<<" ";
    }
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    for(auto &i:v){
        i*=2;
    }
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl<<"=============="<<endl;
    cout<<to_string(12.34)<<endl;
    string str=to_string(123);
    printf("%s\n",str.c_str());
    cout<<stoi("123")<<" "<< stod("123.3")<<endl;
    cout<<int(sqrt(5*1.0));
}