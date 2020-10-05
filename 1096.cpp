#include<cstdio>
#include<cmath>
using namespace std;
typedef long long LL;
int main(){
    LL n;
    scanf("%lld",&n);
    LL sqr=(LL)sqrt(1.0*n);
    LL ansfirst=0;
    LL anslen=0;
    //遍历连续质因数的第一个数字
    for(LL i=2;i<=sqr;i++){
        //对于每一个i进行模拟
        LL j=i;
        LL temp=1;
        while(1){
            temp*=j;
            if(n%temp!=0) break;
            //如果没有break,j可以加入队列
            if(j-i+1>anslen){
                ansfirst=i;
                anslen=j-i+1;
            }
            j++;
        }
    }
    if(anslen==0) printf("1\n%lld",n);
    else 
    {
        printf("%lld\n",anslen);
        for(LL i=0;i<anslen;i++){
            printf("%lld",ansfirst+i);
            if(i<anslen-1){
                printf("*");
            }
        }
    }
    return 0;
}