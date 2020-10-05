#include<stdio.h>
int main()
{
    FILE * fp;
    if((fp=fopen("D:\\cg.txt","r"))==NULL)
    {
        printf("error");
    }
    long s,t,size;
    fseek(fp,0,SEEK_SET);
    s=ftell(fp);
    fseek(fp,0,SEEK_END);
    t=ftell(fp);
    size=t-s;
    printf("size=%d",size);
    char a[1000][100];
   
    int cnt=0;
    do{
        fgets(fp);
    }while(!feof(fp));
    printf("word=%d",cnt);
    
}   
