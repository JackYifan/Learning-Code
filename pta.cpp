#include <stdio.h>
#include <math.h>

int search( int n );

int main()
{
    int number;

    scanf("%d",&number);
    printf("count=%d\n",search(number));
		
    return 0;
}


/* 你的代码将被嵌在这里 */
int search( int n )
{
	
	int tot=0;
	for(int i=11;i<sqrt(n);i++)
	{
		int x=i*i;
		int a[4];
        for(int j=0;j<3;j++)
        {
            a[j]=x%10;
            x/=10;
        }
        if(a[0]==a[1]||a[1]==a[2]||a[2]==a[0]) tot++;
	}
	return tot;
}





//int a[4];
//bool judge(int x)
//{
//	for(int j=0;j<3;j++)
//	{
//		a[j]=x%10;
//		x/=10;
//	}
//	if(a[0]==a[1]||a[1]==a[2]||a[2]==a[0]) return true;
//	else return false ;
//}
//int search( int n )
//{
//	
//	int tot=0;
//	for(int i=11;i<sqrt(n);i++)
//	{
//		int x=i*i;
//		if(judge(x)) tot++;
//	}
//	return tot;
//}
