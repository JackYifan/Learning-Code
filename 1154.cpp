#include<iostream>
#include<vector>
#include<set>
using namespace std;
struct node{
	int t1,t2;
};
int main()
{
	int n,m;
	cin>>n>>m;
	vector<node>v(m);//m���ߵ���Ϣ
	for(int i=0;i<m;i++){
		cin>>v[i].t1>>v[i].t2;
	} 
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		//�����鴢��ÿ�������ɫ
		int a[100010]={0};
		set<int>se;//�ü�������¼�ж����ֲ�ͬ����ɫ
		bool flag=true;
		for(int j=0;j<n;j++){
			cin>>a[j];
			se.insert(a[j]);
		} 
		//����ÿ���ߵ�����
		for(int j=0;j<m;j++){
			if(a[v[j].t1]==a[v[j].t2]){
				flag=false ;
				break;
			}
		} 
		if(flag) printf("%d-coloring\n",se.size());
		else printf("No\n");
		
	}
	return 0;
	
}
