#include<stdio.h>
int main(){
   char str[100][100];
   int i=0,j;
while(scanf("%s", str[i]) != EOF)//�ںڿ����ֶ�����ʱ��ϵͳ����֪��ʲôʱ�򵽴�����ν�ġ��ļ�ĩβ���������Ҫ��< Ctrl + Z >��ϼ���Ȼ��< Enter >���ķ�ʽ������ϵͳ�Ѿ����� EOF������ϵͳ�Ż���� while
i++;                           //while((str[i]=getchar())!='\n')
 
for(j=i-1;j>=0;j--){
	printf("%s",str[j]);
	if(j!=0)
	printf(" ");
} 
 
return 0;
}

