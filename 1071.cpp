#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int> cnt;
bool check(char c)
{
    if(c>='a'&&c<='z') return true;
    if(c>='A'&&c<='Z') return true;
    if(c>='0'&&c<='9') return true;
    return false;
}
int main()
{
    string str;
    getline(cin,str);
    int i=0;
    while(i<str.length())
    {
        string word; 
        while(check(str[i])) 
        {
            if(str[i]>='A'&&str[i]<='Z')
            {
                str[i]=str[i]-'A'+'a';
            }
            word+=str[i];
            i++;
        }
        if(cnt.find(word)!=cnt.end()) cnt[word]++;
        else cnt[word]=1;
        while(!check(str[i]))
        {
            i++;
        }
    }
    int max=-1;
    string result;
    map<string,int>::iterator it;
    for(it=cnt.begin();it!=cnt.end();it++)
    {
        if(it->second>max) 
        {
            result=it->first;
            max=it->second;
        }
    }
    cout<<result<<" "<<max<<endl;

}