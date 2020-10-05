#include <stdio.h>

// 带纠错的整数输入函数
void IntInput(int *num);

int main()
{
    int x;
    IntInput(&x);
	printf("%d\n", x);
    return 0;
}
void IntInput(int *num)
{
    while(scanf("%d",num)!=1)
    {
        printf("不正确的整数! 请重新输入: ");
        while(getchar()!='\n'){}
    }
    
}