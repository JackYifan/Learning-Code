#include<stdio.h>
#include<string.h>
int main()
{
    //输入
    char firstline[1010];
    char catline[1010];
    char string[1010];
    char total[1010];
    char c;
    gets(firstline);
    scanf("%c",&c);
    getchar();
    gets(catline);

    printf("[");
    int i=0;
    int k=0;
    int t;
    for(;i<strlen(firstline);i++)
    {
        int j=0;
        while(firstline[i]!=c&&firstline[i]!='\0') 
        {
            total[k]=string[j]=firstline[i];
            k++;j++;i++;
        }
//        if(firstline[i-2]!=c&&firstline[i-1]=='\0')
//        {
//        	string[0]='\0';
//		}
        for(t=0;t<strlen(catline)&&firstline[i]!='\0';)
        {
            total[k++]=catline[t++];
        }



        string[j]='\0';
        printf("\"%s\"",string);
        if(firstline[i]!='\0')
        {
            printf(", ");
        }
    }
    if(firstline[strlen(firstline)-1]==c)
    {
    	printf("\"\"");
	}
    printf("]\n");
    total[k]='\0';
    printf("%s",total);
    
}
