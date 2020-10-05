#include<stdio.h>
#include<string.h>
int main()
{
    char a[20];
    char b[20];
    gets(a);
    while(strcmp(a,"q")!=0)
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
        if(a[i]=='-'&&(a[i+1]=='.'||a[i+1]>='0'&&a[i+1]<='9'))
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
        while(flag==0&&a[i]=='0')
        {
            i++;
        }
        int cnt=0;
        int tot=0;
        while(a[i]!='\0'&&a[i]>='0'&&a[i]<='9'&&cnt<6||(a[i]=='.'&&flag==0))
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
           // printf("%d ",cnt);
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
