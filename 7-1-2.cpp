#include<stdio.h>
#include<string.h>

int main()
{
    char a[100];
    char b[100];
    gets(a);
    int i,j,k;
    int cnt=0;
    int len=strlen(a);
    b[cnt++]=a[0];
    for(i=1;a[i]!='\0';i++)
    {
        int flag=1;
        for(j=0;j<cnt;j++)
        {
            if(b[j]==a[i])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        b[cnt++]=a[i];
    }
    b[cnt]='\0';
    for(int i=0;b[i]!='\0';i++)
    {
    	int index=i;
        for(int j=i;b[j]!='\0';j++)
        {
        	if(b[j]<b[index])
        	{
        		index=j;
			}
		}
		char temp;
		temp=b[index];
		b[index]=b[i];
		b[i]=temp;
    }
    printf("%s",b);
    
}
