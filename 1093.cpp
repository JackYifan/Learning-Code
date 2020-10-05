#include<stdio.h>
int  HashTable[130]={0};
void print(char c)
{
    if(HashTable[c]==0)
    {
        printf("%c",c);
        HashTable[c]=1;
    }
}
int main()
{
    char a[100010];
    char b[100010];
    gets(a);
    gets(b);
    for(int i=0;a[i]!='\0';i++)
    {
        print(a[i]);
    }
    for(int i=0;b[i]!='\0';i++)
    {
        print(b[i]);
    }
    return 0;
    
}