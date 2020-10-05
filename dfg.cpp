#include<iostream>
#include<map>
#include<set>
using namespace std;
map<string,set<int>>mp;
int main()
{
    int n;
    scanf("%d",&n);
    cout<<n;
    for(int i=0;i<n;i++)
    {
        int id;
        scanf("%d%*c",&id);
        string name;
        getline(cin,name);
        mp[name].insert(id);
        string author;
        getline(cin,author);
        mp[author].insert(id);
        string key;
        while(cin>>key)
        {
            mp[key].insert(id);
            char c=getchar();
            if(c=='\n') break;
        }   
        string print;
        getline(cin,print);
        mp[print].insert(id);
        string time;
        getline(cin,time);
        mp[time].insert(id);
    }
    int tot;
    scanf("%d",&tot);
    for(int i=0;i<tot;i++)
    {
        int choice;
        scanf("%d: ",&choice);
        string x;
        getline(cin,x);
        cout<<choice<<": "<<x<<endl;
        set<int>::iterator it;
        if(mp[x].size()==0) printf("Not Found\n");
        for(it=mp[x].begin();it!=mp[x].end();it++)
        {
            printf("%07d\n",*it);
        }
        
    }
    return 0 ;
}