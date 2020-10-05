#include<iostream>
#include<vector> 
using namespace std;
int n;
int a[1010];
int ismin=1,ismax=1;
//从root到叶结点,dfs
vector<int>v;//用于存储路径 
void dfs(int index){
	//判断到达叶结点
	if(index*2>n&&index*2+1>n){
		if(index<=n){
			//打印路径
			for(int i=0;i<v.size();i++){
				//最后没有多余空格的写法 
				printf("%d%s",v[i],i!=v.size()-1?" ":"\n");
			} 
		}
	}else{
		//把右孩子加入到路径中
		v.push_back(a[index*2+1]);
		dfs(index*2+1);
		//回溯后再加入左孩子
		v.pop_back();
		v.push_back(a[index*2]);
		dfs(index*2);
		v.pop_back();  
	}
} 
int main()
{
	cin>>n;
	//完全二叉数以数组形式存储需要从1开始
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	//把root加入到路径中
	v.push_back(a[1]) ;
	dfs(1);
	//判断大顶还是小顶
	for(int i=2;i<=n;i++){
		//父节点是a[i/2]
		if(a[i/2]>a[i]) ismin=0;
		if(a[i/2]<a[i]) ismax=0; 
	} 
	if(ismin==1) printf("Min Heap");
	else printf("%s",ismax==1?"Max Heap":"Not Heap");
	return 0;
	
}
