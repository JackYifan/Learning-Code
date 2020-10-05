#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
int choice;
map<string,set<int> >mpname,mpauthor,mpkey,mpprint,mptime;
void alter(map<string,set<int> >&mp,string &x)
{
    cout<<choice<<": "<<x<<endl;
    set<int>::iterator it;
    if(mp.find(x) == mp.end()) printf("Not Found\n");
    for(it=mp[x].begin();it!=mp[x].end();it++)
    {
        printf("%07d\n",*it);
    }
}
        
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
        mpname[name].insert(id);
        string author;
        getline(cin,author);
        mpauthor[author].insert(id);
        string key;
        while(cin>>key)
        {
            mpkey[key].insert(id);
            char c=getchar();
            if(c=='\n') break;
        }   
        string print;
        getline(cin,print);
        mpprint[print].insert(id);
        string time;
        getline(cin,time);
        mptime[time].insert(id);
    }
    int tot;
    scanf("%d",&tot);
    for(int i=0;i<tot;i++)
    {
        scanf("%d: ",&choice);
        string x;
        getline(cin,x);
        switch (choice)
        {
            case 1: alter(mpname,x);break;
            case 2: alter(mpauthor,x);break;
            case 3: alter(mpkey,x);break;
            case 4: alter(mpprint,x);break;
            case 5: alter(mptime,x);break;
        }
    }
    return 0 ;
}
