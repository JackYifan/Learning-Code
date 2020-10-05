#include<iostream>
#include<vector>
#include<set>
using namespace std;
struct node{
	int t1,t2;
};
int main()
{
	int n,m;
	cin>>n>>m;
	vector<node>v(m);//m条边的信息
	for(int i=0;i<m;i++){
		cin>>v[i].t1>>v[i].t2;
	} 
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		//用数组储存每个点的颜色
		int a[100010]={0};
		set<int>se;//用集合来记录有多少种不同的颜色
		bool flag=true;
		for(int j=0;j<n;j++){
			cin>>a[j];
			se.insert(a[j]);
		} 
		//遍历每条边的两点
		for(int j=0;j<m;j++){
			if(a[v[j].t1]==a[v[j].t2]){
				flag=false ;
				break;
			}
		} 
		if(flag) printf("%d-coloring\n",se.size());
		else printf("No\n");
		
	}
	return 0;
	
}
