#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000];
    char b[1000];
    char c[1000];
    gets(a);
    gets(b);
    int i,j,k;
    char*p=strstr(a,b);
    while(p){
        
        *p='\0';
        strcpy(c,p+strlen(b));
        strcat(a,c);
        
        p=strstr(a,b);
    }
    printf("%s",a);
    
    
    
}