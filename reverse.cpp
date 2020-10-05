#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    char a[100]="hello";
    reverse(a,a+5);
    printf("%s",a);
    gets(a);
    char c=getchar();
    putchar(c);
    gets(a);
    gets(a);
}