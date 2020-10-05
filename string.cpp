#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string str;
    str="abcdefg";
    cout<<str<<endl;
    string::iterator it;
    for(it=str.begin();it!=str.end();it++)
    {
        printf("%c",*it);
    }
    cout<<endl;
    reverse(str.begin()+1,str.end()-1);
    cout<<str<<endl;

}