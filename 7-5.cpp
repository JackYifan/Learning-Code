#include<string.h>
#include<stdio.h>
void strmcpy( char *t, int m, char *s )
{    
	char *a;
	a=t+m-1;    
	strcpy(s,a);
}
int main(void){
    int i,j,n,x,a[100];
    char t[100][100],*s;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
	{
        
        gets(t[i]);
        scanf("%d",&a[i]);
        getchar();
    }
	for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
	 } 
//    for(i=0;i<n;i++){
//        if(strlen(t[i])<=a[i]){
//            printf("error input\n");
//            break;
//        }
//        strmcpy(t[i],a[i],s);
//        printf("%s\n",s);
//    }
    return 0;
}
/*
3              
happy new year
7
happy
1
new
4
*/
