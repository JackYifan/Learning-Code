#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int inf=999999999;
struct Node {
	double price;
	double dis;
};
bool cmp(Node a, Node b)
{
	return a.dis < b.dis;
}
int main()
{
	double cmax;
	double d;
	double davg;
	int n;
	scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
	vector<Node>node(n+1);
	node[0]={0.0,d};
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf %lf", &node[i].price, &node[i].dis);
	}
	sort(node.begin(),node.end(),cmp);
	double nowdis=0.0,maxdis=0.0,nowprice=0.0,totprice=0.0,leftdis=0.0;
	if(node[0].dis!=0){
		printf("The maximum travel distance = 0.00");
		return 0;
	}else {
		nowprice =node[0].price;
	}
	while(nowdis<d){
		maxdis=nowdis+cmax*davg;//油箱加满后能到达的最远距离,在该范围内寻找价格最低的地方开往那里
		double minpricedis=0,minprice=inf;
		//从前往后寻找更便宜的加油站
		int flag=0;
		for(int i=1;i<=n&&node[i].dis<=maxdis;i++){
			if(node[i].dis<=nowdis) continue;
			if(node[i].price<nowprice){
				totprice+=(node[i].dis-nowdis-leftdis)*nowprice/davg;
				leftdis=0.0;//剩余的油为0
				nowprice=node[i].price;
				nowdis=node[i].dis;
				flag=1;
				break;
			}
			if(node[i].price<minprice){
				minprice=node[i].price;
				minpricedis=node[i].dis;
			}
		}
		//没有找到价格更低的就找剩下价格最低的，加满油往哪里开
		if(flag==0&&minprice!=inf){
			totprice+=(nowprice*(cmax-leftdis/davg));
			leftdis=cmax*davg-(minpricedis-nowdis);
			nowprice=minprice;
			nowdis=minpricedis;
		}
		//开不到下一个加油站了
		if(flag==0&&minprice==inf){
			nowdis+=cmax*davg;
			printf("The maximum travel distance = %.2f",nowdis);
			return 0;
		}
	}
	printf("%.2f",totprice);
	return 0;
}