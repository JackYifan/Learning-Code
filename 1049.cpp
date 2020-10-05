#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int left=0,right=0;
	int now=1;
	int a=1;//当前是第几位 
	int ans=0;
	//每一位分析 
	while(n/a){
		left=n/(a*10),now=n/a%10,right=n%a;
		if(now==0) ans+=left*a;
		else if(now==1) ans+=left*a+right+1;
		else ans+=(left+1)*a;
		a*=10;
	}
	printf("%d",ans);
	return 0;
}
