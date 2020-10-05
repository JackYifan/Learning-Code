#include<cstdio>
int main()
{
    int c[10];
    int d[10];
    int x,y,z;
    int a,b,e;
    scanf("%d.%d.%d",&x,&y,&z);
    scanf("%d.%d.%d",&a,&b,&e);
    c[2]= (e+z)%29;
    d[2]=(e+z)/29;
    c[1]=(y+b+d[2])%17;
    d[1]=(y+b+d[2])/17;
    c[0]=x+a+d[1];
    printf("%d.%d.%d",c[0],c[1],c[2]);
}