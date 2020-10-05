#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] ); /* 裁判提供，细节不表 */

int main()
{
    char s[MAXS], t[MAXS], *pos;

    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

/* 你的代码将被嵌在这里 */



char *search( char *s, char *t ){
    char *q=t;
    while(*s!='\0'){
        while(*s!=*t&&*s!='\0'){
            s++;
        } 
        char *p=s;
        while(*s==*t&&*s!='\0'&&*t!='\0'){
            s++;
            t++;
        }
        if(*t=='\0') return p;
        else {
            s=p+1;
            t=q;
        }
    }
    

}