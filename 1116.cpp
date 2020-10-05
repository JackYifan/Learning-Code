#include<cstdio>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
const int maxn = 10010;
bool isvisit[maxn] = { false };
bool isprime(int n)
{
	if(n<=1) return false ;
	int Sqrt=sqrt((double)n);
	for(int i=2;i<=Sqrt;i++){
		if(n%i==0) return false ;
	}
	return true;
}
void print(int num)
{
	if (num == 1) printf("Mystery Award\n");
	if (isprime(num)) printf("Minion\n");
	else printf("Chocolate\n");
}
int ran[10000];
int main()
{
	int n;
	scanf("%d", &n);
	vector<int>v;
	for (int i = 0; i < n; i++)
	{
		int id;
		scanf("%d", &id);
		ran[id]=i+1;
	}
	int m;
	set<int>s;
	scanf("%d", &m);
	for(int j=0;j<m;j++)
	{
		int query;
		scanf("%d", &query);
		printf("%04d: ", query);
		// int i = 0;
		// for (i = 0; i < v.size(); i++)
		// {
		// 	if (v[i] == query)
		// 	{
		// 		if (!isvisit[query])
		// 		{
		// 			print(i+1);
		// 			isvisit[query] = true;
		// 			break;
		// 		}
		// 		else
		// 		{
		// 			printf("Checked\n");
		// 			break;
		// 		}
		// 	}
		// }
		// if (i == v.size()) printf("Are you kidding?\n");
		if(ran[query]==0){
			printf("Are you kidding?\n");
			continue;
		}
		if(s.find(query)==s.end()){
			s.insert(query);
		}else {
			printf("Checked\n");
			continue ;
		}
		if(ran[query]==1) printf("Mystery Award\n");
		else if(isprime(ran[query])) printf("Minion\n");
		else printf("Chocolate\n");


	}
}