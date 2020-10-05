#include<stdio.h>
int main()
{
    char a[100];
    char ch;
    int cnt=0;
    while((ch=getchar())!='.')
    {
        a[cnt++]=ch;
    }
    a[cnt]='\0';
    int i;
    int flag=1;
    for(i=0;a[i]!='\0';i++)
    {
        int cnt=0;
        if(a[i]!=' ')
        {
            while((a[i]!=' ')&&a[i]!='\0')
            {
                cnt++;
                i++;
            }
            if(a[i]=='\0') i--;
            if(flag==1)
            {
                printf("%d",cnt);
                flag=0;
            }
            else printf(" %d",cnt);
            
        }
        
    }
    return 0;
}
