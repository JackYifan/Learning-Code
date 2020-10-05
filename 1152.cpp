#include<iostream>
#include<string>
using namespace std;
bool isprime(int n){
	if(n==0||n==1) return false ;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false ;
	}
	return true;
	
}
int main()
{
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s; 
	for(int i=0;i<=n-m;i++){
		string t=s.substr(i,m);
		int num=stoi(t);
		if(isprime(num)) {
			cout<<t<<endl;
			return 0;
		}
	}
	cout<<"404"<<endl;
	return 0;
}
