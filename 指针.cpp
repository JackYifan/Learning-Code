#include<stdio.h>
#include<string.h>
int main()
{
    // char a[3][3]={"ad","ce","fb"};
    // char *s=(char *)a;
    // printf("%c",s[1]);
    // putchar("hello"[1]);
    // int x=1;
    // printf("%d",-x--);
    // printf("%d",x);
    // printf("#");
    // int aa=1;
    // int *p=&aa;
    // printf("%d",*p++);
    // char bb[10];
    // gets(bb);
    // puts(bb);
    char xx[]="hello";
    char yy[]="world";
    strcpy(xx,yy);
    printf("%s",xx);
    printf("%d %d",'a','A');
    printf("%lld",__INT64_MAX__);

}