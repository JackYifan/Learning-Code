#include<stdio.h>
#include<string.h>
int main()
{
    printf("%%d\n");
    printf("%c\n",73);
    printf("\111\n");
//  64+8+1==73 常规ASCII码0-127扩展128-255
    printf("\73");
    printf("\073\n");
    printf("\x44");
    printf("\\\\n\"\"\\t");
    int a[10]={0};
    printf("%p\n",a);
    printf("%p\n",&a);
    printf("%p\n",&a[0]);
    char sp[]="hello";
    char *sq="world";
    printf("%s\n",sp);
    strcat(sp,sq);
    printf("%s",sp);
    printf("%lf\n",2E-5);
    char array[10]={'1','2','3','4'};
    char x[]="1234";
    printf("%d %d\n",strlen(array),sizeof(array));
    printf("%d %d",strlen(x),sizeof(x));
    int *q,*p;//p,q都是指针
    int *w,v;//w是指针，v是int
    if("faulse")
    {
        printf("#");
    }
    // int j;
    // printf("%d",(j=3,j+=2));     
    // char ps[10][10]="hello";
    // char **pp;
    // pp=ps;
    // int a[10][2]={1,1,1,1,1,1};
    // int **pd;
    // pd=a;
    int ii;
    for(ii=0;ii<10;ii++)
    {
        if(ii==3) break;
    }
    printf("%d",ii);
    return 0;
}