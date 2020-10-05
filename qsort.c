#include<stdio.h>
#include<stdlib.h>
cmp(const void *a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int a[5]={5,4,3,2,1};
    qsort(a,5,sizeof(int),cmp);
    for(int i=0;i<5;i++)
    {
        printf("%d",a[i]);
    }

}