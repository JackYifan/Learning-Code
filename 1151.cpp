#include<iostream>
#include<map>
#include<vector>
using namespace std;
vector<int>in,pre;
map<int,int>pos;
void lca(int inl,int inr,int preRootPos,int a,int b){
	if(inl>inr ) return ;
	int inRoot=pos[pre[preRootPos]];
	int aIn=pos[a],bIn=pos[b];
	if(aIn<inRoot&&bIn<inRoot){
		lca(inl,inRoot-1,preRootPos+1,a,b);//再in得右边找 
	}
	else if((aIn<inRoot&&bIn>inRoot)||(aIn>inRoot&&bIn<inRoot)){
		printf("LCA of %d and %d is %d.\n",a,b,in[inRoot]);
	}
	else if(aIn>inRoot&&bIn>inRoot){
		lca(inRoot+1,inr,preRootPos+1+(inRoot-inl),a,b);//再in得右边找 
	}
	else if(aIn==inRoot) printf("%d is an ancestor of %d.\n",a,b);
	else if(bIn==inRoot) printf("%d is an ancestor of %d.\n",b,a);
}
int main(){
	int m,n;
	int a,b;
	cin>>m>>n;
	in.resize(n);
	pre.resize(n);
	for(int i=1;i<=n;i++){
		cin>>in[i];
		pos[in[i]]=i;//再in中的位置 
	}
	for(int i=1;i<=n;i++){
		cin>>pre[i];
	}
	for(int i=0;i<m;i++){
		cin>>a>>b;
		if(pos[a]==0&&pos[b]==0){
			printf("ERROR: %d and %d are not found.\n",a,b);
		}
		else if(pos[a]==0||pos[b]==0){
			printf("ERROR: %d is not found.\n",pos[a]==0?a:b);
		}
		else lca(1,n,1,a,b);
	}
	return 0;
}
