#include <stdio.h>

// ��������������뺯��
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
	int flag=(scanf("%d",num));
    while(flag==0)
    {
    	
        printf("����ȷ������! ����������:");
        
        flag=(scanf("%d",num));
    }
}
