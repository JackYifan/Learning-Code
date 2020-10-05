#include<iostream>
#include<vector>
using namespace std;
const int maxn = 100010;
int n, head, k;
//vector 常用于中间存储改变顺序
struct Node {
	int address, data, next;
}node[maxn];
vector<Node>v,ans;
int main() {
	cin >> head >> n >> k;
	for (int i = 0; i < n; i++) {
		int address, data, next;
		cin >> address >> data >> next;
		node[address] = { address,data,next };
	}
	//有序存入vector
	for (; head != -1; head = node[head].next) {
		v.push_back(node[head]);
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i].data<0) ans.push_back(v[i]);
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i].data >= 0 &&v[i].data<=k ) ans.push_back(v[i]);
	}
    for (int i = 0; i < v.size(); i++) {
		if (v[i].data>k ) ans.push_back(v[i]);
	}
    for(int i=0;i<ans.size()-1;i++){
        //输出与next 
        printf("%05d %d %05d\n",ans[i].address,ans[i].data,ans[i+1].address);
    }
    printf("%05d %d -1\n",ans[ans.size()-1].address,ans[ans.size()-1].data);
    return 0;
}

