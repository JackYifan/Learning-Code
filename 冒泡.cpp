#include<iostream>
#include<algorithm>
using namespace std;
// void swap(int &a,int &b)
// {
//     int temp=a;
//     a=b;
//     b=temp;
// }
int main()
{
    const int n=10;
    int a[10]={9,8,7,6,5,4,3,2,1,0};
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    
}