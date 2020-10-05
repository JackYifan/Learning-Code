#include<cstdio>
#include<cstring>
const int maxn=10000;
char a[maxn];
int main()
{
    
    scanf("%s",a);
    int len=strlen(a);
    if(a[0]=='-') printf("-");
    int pos;
    int exp=0;
    for(pos=0;a[pos]!='E';pos++);
    for(int k=pos+2;k<len;k++)
    {
        exp=exp*10+a[k]-'0';
    }
    if(exp==0)
    {
        for(int i=1;i<pos;i++)
        {
            printf("%c",a[i]);
        }
    }
    else{
    if(a[pos+1]=='-')
    {
        printf("0.");
        for(int i=0;i<exp-1;i++)
        {
            printf("0");
        }
        for(int i=1;i<pos;i++)
        {
            if(a[i]=='.') continue;
            else printf("%c",a[i]);
        }
    }
    // else if(a[pos+1]=='+')
    // {
    //     int cnt=0;
    //     printf("%c",a[1]);
    //     // for(int i=2;i<pos;i++)
    //     // {
    //     //     if(a[i]=='.') continue;
    //     //     while(cnt<exp)
    //     //     {
    //     //         printf("%c",a[i]);
    //     //         i++;
    //     //         cnt++;
    //     //     }
    //     //     printf(".");
    //     //     printf("%c",a[--i]);
    //     // }
    //     int i;

    //     for(i=1;i<pos;i++)
    //     {
    //         if(a[i]=='.') continue;
    //         printf("%c",a[i]);
    //     }
    //     printf(".");
    //     for(;i<len;i++)
    //     {
    //         printf("%c",a[i]);
    //     }
    // }
    else if(a[pos+1]=='+')
    {   
        int xiaoshulen=pos-3;
        if(xiaoshulen<=exp)
        {
            for(int i=1;i<=exp+2;i++)
            {
                if(a[i]=='.') continue;
                else if(i<pos) printf("%c",a[i]);
                else printf("0");
            }
        }
        else 
        {
            int i;
            for(i=1;i<pos;i++)
            {
                if(a[i]=='.') continue;
                printf("%c",a[i]);
            }
            printf(".");
            for(;i<len;i++)
            {
                printf("%c",a[i]);
            }
        }
            
        
    }
    }

}






       