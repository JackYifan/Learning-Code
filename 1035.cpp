#include<cstdio>
#include<cstring>
struct Node
{
    char name[100];
    char password[100];
    bool ischange=false ;
}node[1000];
int change(char a[])
{
    int flag=0;
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
        switch (a[i])
        {
            case '1':a[i]='@';flag=1;break;
            case '0':a[i]='%';flag=1;break;
            case 'l':a[i]='L';flag=1;break;
            case 'O':a[i]='o';flag=1;break;
        }
    }
    return flag;
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        scanf("%s %s",node[i].name,node[i].password);
        node[i].ischange=change(node[i].password);
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(node[i].ischange)
        {
            cnt++;
        }
    }
    if(cnt==0)
    {
        if(n==1)
        {
            printf("There is 1 account and no account is modified");
        }
        else 
        {
            printf("There are %d accounts and no account is modified",n);
        }
    }
    else 
    {
        printf("%d\n",cnt);
        for(int i=0;i<n;i++)
        {
            if(node[i].ischange)
            {
                printf("%s %s\n",node[i].name,node[i].password);
            }
        }
    }
   


}