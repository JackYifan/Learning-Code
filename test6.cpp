#include<stdio.h>
int main()
{
    const int n=10;
    int a[10]={1,8,7,5,6,4,3,2,0};
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
        a[j+1]=temp;//jΪǰһ��ֵ��j+1Ϊ�ճ��������� 
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

