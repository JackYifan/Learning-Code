#include<stdio.h>

int main()
{
    FILE*fp;
    FILE*fp1;
    if((fp=fopen("C:\\Users\\HONOR\\Desktop\\filehomework\\cg.txt","r"))==NULL)
    {
        printf("error");
        
    }
    if((fp1=fopen("C:\\Users\\HONOR\\Desktop\\filehomework\\encript.txt","a"))==NULL)
    {
        printf("error");
        
    }
    int a[30];
    while(!feof(fp))
    {
        char ch;
        ch=fgetc(fp);
        fputc(ch,fp1);
    }
    
    
    
    return 0;
}
