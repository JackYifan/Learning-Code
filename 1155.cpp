#include<iostream>
#include<vector> 
using namespace std;
int n;
int a[1010];
int ismin=1,ismax=1;
//��root��Ҷ���,dfs
vector<int>v;//���ڴ洢·�� 
void dfs(int index){
	//�жϵ���Ҷ���
	if(index*2>n&&index*2+1>n){
		if(index<=n){
			//��ӡ·��
			for(int i=0;i<v.size();i++){
				//���û�ж���ո��д�� 
				printf("%d%s",v[i],i!=v.size()-1?" ":"\n");
			} 
		}
	}else{
		//���Һ��Ӽ��뵽·����
		v.push_back(a[index*2+1]);
		dfs(index*2+1);
		//���ݺ��ټ�������
		v.pop_back();
		v.push_back(a[index*2]);
		dfs(index*2);
		v.pop_back();  
	}
} 
int main()
{
	cin>>n;
	//��ȫ��������������ʽ�洢��Ҫ��1��ʼ
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	//��root���뵽·����
	v.push_back(a[1]) ;
	dfs(1);
	//�жϴ󶥻���С��
	for(int i=2;i<=n;i++){
		//���ڵ���a[i/2]
		if(a[i/2]>a[i]) ismin=0;
		if(a[i/2]<a[i]) ismax=0; 
	} 
	if(ismin==1) printf("Min Heap");
	else printf("%s",ismax==1?"Max Heap":"Not Heap");
	return 0;
	
}
