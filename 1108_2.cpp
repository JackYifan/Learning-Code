#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<string>
using namespace std;
int cnt;
double sum;
bool judge(string a)
{
	int cnt = 0;
	int sum = 0;

	for (auto it = a.begin(); it != a.end(); it++)
	{
		if (isalpha(*it)) return false;
		if (*it == '.')
		{
			cnt++;
			if (cnt > 1) return false;
		}
		if (cnt > 0)
		{
			sum++;
			if (sum > 3) return false;
		}
	}
	double x = stod(a);
	if (x < -1000 || x>1000) return false;
	return true;
}
int main()
{
	int n;
	scanf("%d", &n);
	string a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (!judge(a))
		{
			cout << "ERROR: " << a << " is not a legal number" << endl;
		}
		else
		{
			cnt++;
			sum += stod(a);
		}

	}
	if (cnt == 1)
	{
		printf("The average of 1 number is %.2f\n", sum);
	}
	else if (cnt > 1)
	{
		printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
	}
	else
	{
		printf("The average of 0 numbers is Undefined\n");
	}
}