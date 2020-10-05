#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int x, radix;
vector<int>v;
int reverse(int x, int radix) {
	v.clear();
	for (int i = 0;; i++) {
		if (x == 0) break;
		v.push_back(x%radix);
		x /= radix;
	}
	int ans = 0;
	for (int i = 0; i < v.size();i++) {
		ans = ans * radix + v[i];
	}
	return ans;
}
bool isprime(int x) {
	for (int i = 2; i < sqrt(x); i++) {
		if (x%i == 0) return false;
	}
	return true;
}

bool isreverse(int x, int radix) {
	if (isprime(x) && isprime(reverse(x, radix))) return true;
	else return false;
}
int main() {
	while (scanf("%d", &x) != EOF) {
		if (x < 0) break;
		scanf("%d", &radix);

		if (isreverse(x, radix)) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
}