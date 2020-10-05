#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>v(n+1);
	for(int i=1;i<=n;i++) cin>>v[i];
	//假设i,j是狼人 
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			//实际情况用a 来记录 
			vector<int>lie;
			vector<int>a(n+1,1);
			a[i]=a[j]=-1;
			//检验每一个人说的话
			for(int k=1;k<=n;k++){
				if(v[k]*a[abs(v[k])]<0) lie.push_back(k);
			} 
			if(lie.size()==2&&a[lie[0]]+a[lie[1]]==0){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	cout<<"No Solution\n";
	return 0;
}
 
