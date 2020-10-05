#include<cstdio>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string s;
    stack<char>st;
        if(s.length()==0) return true;
    if(s.length()==1) return false;
    stack<char>st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='{'||s[i]=='['||s[i]=='(')
        {
            st.push(s[i]);
        }
        else 
        {
            if(st.empty()) return false;
            char c=st.top();
            st.pop();
            if(s[i]==')'&&c=='(') continue;
            else if(s[i]==']'&&c=='[') continue;
            else if(s[i]=='}'&&c=='{') continue;
            else return false;
        }
    }
    if(st.empty()) return true;
    else return false;
}