#include<cstdio>
#include<iostream>
#include<map>
#include<string>
using namespace std;
string low[13]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high[13]={"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string,int> translate;
void init()
{
    for(int i=0;i<13;i++)
    {
        translate[low[i]]=i;
    }
    for(int i=0;i<13;i++)
    {
        translate[high[i]]=i*13;
    }
    
}
void numToStr(string str)
{
    int ans=0;
    int k=0;
    while(k<str.length())
    {
        ans=ans*10+str[k++]-'0';
    }
    int x;
    if(ans/13==0)
    {
        x=ans%13;
        cout<<low[x];
    }
    else
    {
        x=ans/13;
        cout<<high[x];
        x=ans%13;
        if(x!=0) cout<<" "<<low[x];
    }
    cout<<endl;
}
int strToNum(string str)
{
    int i;
    int ans=0;
    string temp1;
    string temp2;
    if(str.length()>4)
    {
        for(int i=0;i<3;i++)
        {
            temp1+=str[i];
        }
        ans+=translate[temp1];
        for(int i=4;i<7;i++)
        {
            temp2+=str[i];
        }
        ans+=translate[temp2];
    }
    else 
    {
        for(int i=0;i<3;i++)
        {
            temp1+=str[i];
        }
        ans+=translate[temp1];
    }
    return ans;
}

int main()
{
    int n;
    string str;
    init();
    scanf("%d%*c",&n);
    for(int i=0;i<n;i++)
    {
        getline(cin,str);
        if(str[0]>='a'&&str[0]<='z')
        {
            cout<<strToNum(str)<<endl;
        }
        else numToStr(str);
    }
}