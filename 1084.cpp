#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
bool hashtable[128];
char change(char c)
{
    if(c<='z'&&c>='a')
    {
        c=c-'a'+'A';
    }
    return c;
}
int main()
{
    int i;
    memset(hashtable,false,sizeof(hashtable));
    char a[100];
    char b[100];
    scanf("%s",a);
    int lena=strlen(a);
    getchar();
    scanf("%s",b);
    int lenb=strlen(b);
    int pa=0;
    int pb=0;
    vector<char>v;
    while(pa<lena&&pb<lenb)
    {
        char x=change(a[pa]);
        char y=change(b[pb]);
        if(x==y)
        {
            pa++;
            pb++;
        }
        else
        {
            for(i=0;i<v.size();i++)
            {
                if(v[i]==x) break;
            }
            if(i==v.size())
            {
                printf("%c",x);
                v.push_back(x);
            }
            pa++;
        }
    }
    
    for(;pa<lena;pa++)
    {
        int x=change(a[pa]);
        for(i=0;i<v.size();i++)
        {
            if(v[i]==x) break;
        }
        if(i==v.size())
        {
            printf("%c",x);
            v.push_back(x);
        }
        
    }
    
}