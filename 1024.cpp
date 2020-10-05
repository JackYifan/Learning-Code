#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char a[10010];
    gets(a);
    char op=a[0];
    int zhengshu=0;
    int i;
    for(i=1;a[i]!='.';i++)
    {
        zhengshu=zhengshu*10+a[i]-'0';
    }
    int num=-1;
    double xiaoshu=0;
    for(i=i+1;a[i]!='E';i++)
    {
        xiaoshu=xiaoshu+(a[i]-'0')*pow(10,num);
        num--;
    }
    i++;
    char c=a[i];
    int cishu=0;
    for(i=i+1;a[i]!='\0';i++)
    {
        cishu=cishu*10+a[i]-'0';
    }
    if(c=='-') cishu=-cishu;
    //输出
    if(op=='-') printf("-");
    double n;
    n=(zhengshu+xiaoshu)*pow(10,cishu);
    printf("%f",n);
    
    




    
}