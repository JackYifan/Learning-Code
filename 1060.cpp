#include<iostream>
#include<string>
using namespace std;
int n;
string f(string s,int&e)
{
    //寻找记数字开始的点k与指针配合使用
    //在寻找小数点的过程中得到指数的次数
    int k=0;
    //除去前导0
    while(s.length()>0&&s[0]=='0')
    {
        s.erase(s.begin());
    }
    //判断数字是否小于一
    if(s[0]=='.')
    {
        s.erase(s.begin());
        while(s.length()>0&&s[0]=='0')
        {
            s.erase(s.begin());
            e--;
        }
    }
    //数字大于1，寻找小数点
    else 
    {
        while(k<s.length()&&s[k]!='.')
        {
            k++;
            e++;
        }
        if(k<s.length())
        {
            s.erase(s.begin()+k);
        }
    }
    k=0;
    //以上操作的目的是把数字编程非零数字开头的没有小数点的数字
    //cout<<s;
    int cnt=0;
    string result;
    while(cnt<n)
    {
        if(k<s.length())
        {
            result+=s[k++];
            cnt++;
        }
        else
        {
            result+='0';
            cnt++;
        } 
        
    }
    return result;
}
int main()
{
    string s1,s2,s3,s4;
    cin>>n>>s1>>s2;
    int e1=0,e2=0;
    s3=f(s1,e1);
    s4=f(s2,e2);
    if(s3==s4) 
    {
        cout<<"YES "<<"0."<<s3<<"*10^"<<e1<<endl;
    }
    else 
    {
        cout<<"NO "<<"0."<<s3<<"*10^"<<e1<<" "<<"0."<<s4<<"*10^"<<e2<<endl;
    }
    return 0;

}