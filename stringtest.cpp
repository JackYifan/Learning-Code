#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1="hello ";
    string s2;
    // s2.assign(s1,0,2);
    // s2[5]='a';
    // for(int i=0;i<s1.length();i++)
    // {
    //     cout<<s1.at(i)<<endl;
    // }
    s2="world";
    s1+=s2;
    cout<<s1<<endl;
    s1.append(s2,1,2);
    cout<<s1<<endl;
    cout<<s1.compare(1,2,s2,0,3)<<endl;
    s1="hello world";
    s2=s1.substr(4,5);
    cout<<s2<<endl;
    s2.swap(s1);
    cout<<s2<<endl;
    cout<<"========"<<endl;
    s1="hello world llo";
    int pos=s1.rfind("llo");
    cout<<pos;
    cout<<s1.find_first_of("llo");
    cout<<s1.find_last_of("llo");
    cout<<s1.find_first_not_of("llo");
    // s1.erase(1);
    // cout<<s1;
    s1.replace(0,2,"hahahahhahah",0,2);
    cout<<s1;
    

    



    


    // cout<<s2;


}