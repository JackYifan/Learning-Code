#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
	map<int,vector<int> >mp;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;int y;
		cin>>x>>y;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	for(int l=0;l<m;l++){
		int hash[100010]={0};
		int k;
		cin>>k;
		vector<int>v(k); 
		int flag=1;
		for(int i=0;i<k;i++){
			cin>>v[i];
			hash[v[i]]=1;
		}
		for(int i=0;i<v.size();i++){
			for(int j=0;j<mp[v[i]].size();j++){
				if(hash[mp[v[i]][j]]==1) flag=0;
			}
		}
		if(flag==0) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
