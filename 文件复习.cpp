#include<stdio.h>
int main ()
{
    FILE*fp;
    if((fp=fopen("C://a.txt","w"))==NULL)
    {
        printf("error");
    }
    int x;
    double y;
    char a[100];
    fscanf(fp,"%d%f",&x,&y);
    fprintf(fp,"%d%f",x,y);
    fgetc(fp);
    fgets(a,10,fp);
    fputc('c',fp);
    fputs("hello",fp);
    fseek(fp,20L,SEEK_CUR);
    int pos=ftell(fp);
    if(feof(fp))
    {
        printf("over");
    }
    rewind(fp);
    if(fclose(fp)) printf("error");

}
