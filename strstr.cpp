#include<stdio.h>
#include<string.h>
int main()
{
    char a[]="hello world";
    char b[]="llo";
    char*p;
    int i,j;
    for(i=0;i<strlen(a);i++)
    {
        int k=i;
        if(a[i]==b[0])
        {
            for(j=0;j<strlen(b);j++)
            {
                if(a[i++]!=b[j]) break;
            }
            if(j==strlen(b)) p=&a[k];
        }
        i=k;
    }
    printf("%s",p);
}