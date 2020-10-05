#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
bool hashmap[maxn]={false};
int main()
{
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x>0){
			hashmap[x]=true;
		}
		
	}
	for(int i=1;;i++){
		if(hashmap[i]==false){
			cout<<i;
			break;
		}
		
	}
}
