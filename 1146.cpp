#include<iostream>
#include<vector>
using namespace std;
//只有前面能指向后面，所以前面删除后入度为零 
int main()
{
	int n,m,a,b,k,flag=0;
	int in[1010];
	vector<int>v[1010];
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		v[a].push_back(b);
		in[b]++;
	}
	cin>>k;
	for(int i=0;i<k;i++){
		int judge=1;
		vector<int>tin(in,in+n+1);
		for(int j=0;j<n;j++){
			cin>>a;
			if(tin[a]!=0) judge=0;
			for(int it:v[a]) tin[it]--;
		}
		if(judge==1) continue;
		printf("%s%d",flag==1?" ":"",i);
		flag=1;
	}
	return 0;
}
