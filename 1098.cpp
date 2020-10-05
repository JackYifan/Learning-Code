#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1001;
int origin[maxn],temp[maxn],changed[maxn];
int n;
bool isSame(int a[],int b[])
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i]) return false;
    }
    return true;
}
void showArray(int a[])
{
    for(int i=1;i<=n;i++)
    {
        printf("%d",a[i]);
        if(i<n) printf(" ");
    }
    printf("\n");
}
//模拟堆排列
void downAdjust(int low,int high)
{
    int i=low,j=2*i;
    while(j<=high)
    {
        //找到子树中的最大值
        if(j+1<=high&&temp[j+1]>temp[j])
        {
            j=j+1;
        }
        if(temp[j]>temp[i])
        {
            swap(temp[i],temp[j]);
            //更新i,j
            i=j;j=2*i;
        }
        else break;//调整结束
    }
}
void heapsort()
{
    bool flag=false;
    //从上至下建堆
    for(int i=n/2;i>=1;i--)
    {
        downAdjust(i,n);
    }
    //排序
    for(int i=n;i>=2;i--)
    {
        if(i!=n&&isSame(temp,changed))
        {
            flag=true;
        }
        //已经找到相同的序列了，再处理一次就是下一个序列
        swap(temp[i],temp[1]);//把根结点放到最后并固定，处理1到i-1
        downAdjust(1,i-1);//i以及之后的数字固定
        if(flag==true) 
        {
            showArray(temp);
            return ;
        }
        // showArray(temp);
        // printf("\n");
    }

}
//模拟插入排序
bool insertSort()
{
    bool flag=false;
    //等价于第i次插入前i个元素从小到大有序排列
    for(int i=1;i<=n-1;i++)
    {
        if(i!=1&&isSame(temp,changed))
        {
            flag=true;
        }
        //进一步为i+1次排序
        sort(temp+1 ,temp+2+i);
        if(flag==true) return true;
    }
    return false;

}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&origin[i]);
        temp[i]=origin[i];
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&changed[i]);
    }
    if(insertSort())
    {
        printf("Insertion Sort\n");
        showArray(temp);
    }
    else 
    {
        printf("Heap Sort\n");
        //insert操作已经改变过temp
        for(int i=1;i<=n;i++)
        {
            temp[i]=origin[i];
        }
        heapsort();
    }
    return 0;

}