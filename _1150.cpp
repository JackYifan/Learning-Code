#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int maxn=100010;
int e[maxn][maxn];
int n,m;
int ans=999999999,ansid;
/*
Path 1: 11 (TS simple cycle)
Path 2: 13 (TS simple cycle)
Path 3: 10 (Not a TS cycle)
Path 4: 8 (TS cycle)
Path 5: 3 (Not a TS cycle)
Path 6: 13 (Not a TS cycle)
Path 7: NA (Not a TS cycle)
Shortest Dist(4) = 8

*/
void check(int index){
	int cnt;
	cin>>cnt;
	int flag=1;
	set<int>s;//用来记录是否重复 
	vector<int>v(cnt);
	for(int i=0;i<cnt;i++){
		cin>>v[i];
		s.insert(v[i]);
	}
	//检验是否是通路
	int sum=0;
	for(int i=0;i<cnt-1;i++){
		if(e[v[i]][v[i+1]]==0) flag=0;
		sum+=e[v[i]][v[i+1]];
	} 
	if(flag==0) printf("Path %d: NA (Not a TS cycle)\n",index);
	else if(v[0]!=v[n-1]||s.size()!=n) 
		printf("Path %d: %d (Not a TS cycle)\n",index,sum);
	else if(cnt!=n+1){
		printf("Path %d: %d (TS cycle)\n",index,sum);
		if(sum<ans){
			ans=sum;
			ansid=index;
		}
	}else{
		printf("Path %d: %d (TS simple cycle)\n",index,sum);
		if(sum<ans){
			ans=sum;
			ansid=index;
		}
	}
}
int main(){

	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,d;
		cin>>x>>y>>d;
		e[x][y]=e[y][x]=d;
	}
	int k;
	cin>>k;
	for(int i=1;i<=k;i++){
		check(i);
	}
	printf("Shortest Dist(%d) = %d",ansid,ans);
	return 0;
	
}
