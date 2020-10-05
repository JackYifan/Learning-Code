#include<stdio.h>
#include <string.h>
static int array[20];
static int ascending(int a, int b);
static int descending(int a, int b);
static void sortAorD(int array[ ], int n, int  (*compare)(int a, int b)) ; 
typedef  struct {
    char name;
    int (*cmd)(int a, int b);
}SortCmd;

int main()
{
    int k,n;
    char cmdType;
    scanf("%c", &cmdType);
    scanf("%d", &n) ;
    SortCmd cmds[]={
    		{'A', ascending},      /* Ascending */
    		{'D', descending}		/*Descending */
	};
	for (k = 0; k<n; k++) scanf("%d", &array[k]);

    for (k = 0; k < sizeof(cmds)/sizeof(cmds[0]); k++) {
        if (cmdType==cmds[k].name) 
            sortAorD(array, n, cmds[k].cmd);
    }
    for (k=0; k<n; k++) printf("%d ", array[k]);
} 

static int ascending(int a, int b) 
{    return (a>=b);    
}

static int descending(int a, int b) 
{    return (a<b);   
}
static void sortAorD(int *array, int n, int  (*compare)(int a, int b)) 
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if((*compare)(array[j],array[j+1]))
            {
                int temp;
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}