#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int n;
int origin[maxn], temp[maxn], changed[maxn];
bool issame(int a[], int b[]) {
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i]) return false;
	}
	return true;
}
void showArray(int a[]) {
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i < n - 1) printf(" ");
	}
}
//判断是否为插入排序
bool insert()
{
	bool flag = false;
	//进行一轮操作
	for (int i = 1; i < n; i++)
	{
		if (issame(temp, changed)&&i!=1)
		{
			flag = true;
		}
		int x = temp[i];
		int j = i;
		while (j > 0 && temp[j - 1]>x)
		{
			temp[j] = temp[j - 1];
			j--;
		}
		temp[j] = x;
		if (flag == true) return true;
		
	}
	return false ;

}
void mergesort() {
	bool flag = false;
	for (int step = 2; step <= n; step *= 2) {
		if (issame(temp, changed)&&step!=2)
		{
			flag = true;
		}
		for (int i = 0; i < n; i += step) {
			sort(temp + i, temp + min(i + step, n));
		}
		if (flag == true) {
			showArray(temp);
			return;
		}
	}
	
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &origin[i]);
		temp[i] = origin[i];
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &changed[i]);
	}
	//对temp进行操作
	if (insert())
	{
		printf("Insertion Sort\n");
		showArray(temp);
	}
	else
	{
		printf("Merge Sort\n");
		//还原
		for (int i = 0; i < n; i++)
		{
			temp[i] = origin[i];
		}
		mergesort();
	}
	return 0;

	

}