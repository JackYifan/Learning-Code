#include<stdio.h>
int main(){
   char str[100][100];
   int i=0,j;
while(scanf("%s", str[i]) != EOF)//在黑框中手动输入时，系统并不知道什么时候到达了所谓的“文件末尾“，因此需要用< Ctrl + Z >组合键，然后按< Enter >键的方式来告诉系统已经到了 EOF，这样系统才会结束 while
i++;                           //while((str[i]=getchar())!='\n')
 
for(j=i-1;j>=0;j--){
	printf("%s",str[j]);
	if(j!=0)
	printf(" ");
} 
 
return 0;
}

