#include<cstdio>
#include<iostream>
#include<map>
#include<set>
using namespace std;
bool notbroken[256];
int main()
{
    int k;
    cin>>k;
    string s;
    cin>>s;
    map<char,bool>m;//记录坏掉的键true
    set<char>print;
    char temp=s[0];
    int cnt=1;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]==temp) 
        {
            cnt++;
            if(i==s.length()-1)
            {
                if(cnt%k!=0) notbroken[temp]=true;
                else m[temp]=true;
            }
        }
        else {
            /**
            * 先记录，后面有错再修改
            */
            if(cnt%k!=0) notbroken[temp]=true;
            else m[temp]=true;
            temp=s[i];
            cnt=1;
        }
    }
    for(int i=0;i<s.length();i++)
    {
        if(notbroken[s[i]]) m[s[i]]=false ;
    }
    //用set记录已经输出过的字母，防止重复输出
    for(int i=0;i<s.length();i++)
    {
        if(m[s[i]]&&print.find(s[i])==print.end()){
            printf("%c",s[i]);
            print.insert(s[i]);
        }
    }
    cout<<endl;
    for(int i=0;i<s.length();i++)
    {
        printf("%c",s[i]);
        //跳过坏掉的字母
        if(m[s[i]])
        {
            i=i+k-1;
        }
    }
}