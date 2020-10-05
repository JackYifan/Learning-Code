#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int i=0;
    while(s[i]!='E') i++;//此时s[i]=='E'
    string t=s.substr(1,i-1);
    int n=stoi(s.substr(i+1));//次数
    if(s[0]=='-') cout<<"-";
    if(n<0) {
        cout<<"0.";
        for(int i=0;i<abs(n)-1;i++) cout<<"0";
        for(int i=0;i<t.length();i++){
            if(t[i]!='.') cout<<t[i]; 
        }
    }else{
        cout<<t[0];
        int cnt=0,j;
        for(j=2;j<t.length()&&cnt<n;j++,cnt++) cout<<t[j];
        //小数点移到最后还要移动
        if(j==t.length()){
            for(int k=0;k<n-cnt;k++) cout<<"0";
        }else{
            //小数点移动完成后输出小数点和剩下的数字
            cout<<".";
            for(int k=j;k<t.length();k++) cout<<t[k];
        }
    }
    return 0;
}