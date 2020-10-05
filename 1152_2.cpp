#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isprime(string s){
	int x=stoi(s);
	if(x==0||x==1) return false;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}
int main() {
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i=0;i<=n-k;i++){
		string temp=s.substr(i,k);
		if(isprime(temp)){
			cout<<temp;
			return 0;
		}
	} 
	cout<<"404";
}
