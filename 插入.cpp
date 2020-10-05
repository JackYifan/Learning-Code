#include<stdio.h>
#include<stdio.h>
int number[100000000];     //在外面定义数组 
void insertion_sort(int *number,int n)    //定义一个插入函数"insertion_sort" 
{
    int i=0,ii=0,temp=0;  
    for(i=1;i<n;i++)  //循环遍历 
    {
        temp=number[i];  //将temp每一次赋值为number[i] 
        ii=i-1;  
        while(ii>=0&&temp<number[ii])   //这里改顺序 (temp后的)"<"为小到大，">"为大到小 ！！！
        {
            number[ii+1]=number[ii];    //将大的元素往前放 
            ii--; 
        }
        number[ii+1]=temp;   //与"number[ii+1]=number[ii];"一起意为 
    }              //如果插入的数比之前的大,将number[ii]与number[ii+1]互换 
}

int main()
{
    const int n=10;
    int a[10]={1,8,7,5,6,4,3,2,1,0};
    int temp;
    int i,j;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(temp<a[j]) 
            {
                a[j+1]=a[j];
            }
            else break;
        }
        a[j+1]=temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
