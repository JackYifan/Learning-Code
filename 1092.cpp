#include<cstdio>
#include<cstring>
int hashtable[128];
int main()
{
    char a[100];
    char b[100];
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    int lena=strlen(a);
    int lenb=strlen(b);
    int flag=1;
    int duo=0;
    int que=0;
    //判断
    for(int i=0;i<lena;i++)
    {
        hashtable[a[i]]++;
    }
    
    for(int i=0;i<lenb;i++)
    {
        hashtable[b[i]]--;
    }
    for(int i=0;i<128;i++)
    { 
        if(hashtable[i]<0)
        {
            flag=0;
            que+=(-hashtable[i]);
        } 
        else if(hashtable[i]>0)
        {
            duo+=hashtable[i];
        }
    }
    if(flag==0)
    {
        printf("No ");
        printf("%d",que);
    } 
    else 
    {
        // memset(hashtable,false,sizeof(hashtable));
        // for(int i=0;i<lenb;i++)
        // {
        //     hashtable[b[i]]=true;
        // }
        // for(int i=0;i<lena;i++)
        // {
        //     if(hashtable[a[i]]==false)
        //     {
        //         cnt++;
        //     }
        // }
        printf("Yes ");
        printf("%d",duo);
    }
}