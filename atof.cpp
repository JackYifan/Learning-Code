#include<stdio.h>
int main()
{
    char a[20];
    char b[20];
    gets(a);
    while(a[0]!='q')
    {
        int flag=0;
        int i=0,j;
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='.'||a[i]=='+'||a[i]=='-'||(a[i]>='0'&&a[i]<='9'))
            {
                break;
            }
        }
        if(a[i]=='+') i++;
        if(a[i]=='-')
        {
            printf("-");
            i++;
        }
        if(a[i]=='.')
        {
            printf("0.");
            flag=1;
            i++;
        } 
        int cnt=0;
        int tot=0;
        while(a[i]!='\0'&&a[i]>='0'&&a[i]<='9'||(a[i]=='.'&&flag==0))
        {
            tot=1;
            printf("%c",a[i]);
            if(flag==1)
            {
                cnt++;
            }
            if((a[i]=='.'&&flag==0))
            {
                flag=1;
            }
            
            i++;
        }
        
        if(flag==0)
        {
            if(tot==0) printf("0.");
            else printf(".");
        } 

        while(cnt<6)
        {
            printf("0");
            cnt++;
        }
        
        printf("\n");
        gets(a);
    }
}