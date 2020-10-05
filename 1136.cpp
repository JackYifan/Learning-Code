#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool judge(string s){
    string temp=s;
    reverse(s.begin(),s.end());
    return s==temp;
}
string add(string s1,string s2){
    string s=s1;
    int carry=0;
    for(int i=s1.size()-1;i>=0;i--){
        s[i]=(s1[i]-'0'+s2[i]-'0'+carry)%10+'0';
        carry=(s1[i]-'0'+s2[i]-'0'+carry)/10;
    }
    if(carry>0) s="1"+s;
    return s;
}
int cnt=0;
int main(){
    string s;
    cin>>s;
    while(!judge(s)&&cnt<10){
        string temp=s;
        reverse(s.begin(),s.end());
        //大数不能直接相加
        string result=add(temp,s);
        cout<<temp<<" + "<<s<<" = "<<result<<endl;
        cnt++;
        s=result;
    }
    if(cnt<10) cout<<s<<" is a palindromic number."<<endl;
    else cout<<"Not found in 10 iterations."<<endl;
}
