#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
bool hashtable[128];
int main()
{
    char a[1000];
    char b[1000];
    cin.getline(a,1000);
    cin.getline(b,1000);
    int lenb=strlen(b);
    for(int i=0;i<lenb;i++)
    {
        hashtable[b[i]]=true;
    }
    int lena=strlen(a);
    for(int i=0;i<lena;i++)
    {
        if(hashtable[a[i]]==false)
        {
            printf("%c",a[i]);
        }
    }

}