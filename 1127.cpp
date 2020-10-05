#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int tree[35][2];//两个坐标分别表示左右
int root;
vector<int>in, post, result[35];
struct Node {
	int index, depth;
};
void DFS(int &index, int inleft, int inright, int postleft, int postright) {
	if (inleft > inright) return;
	index = postright;
	int i=0;
	while (in[i] != post[postright]) i++;
	int left = i - inleft;
	DFS(tree[index][0], inleft, i - 1, postleft, postleft + left - 1);
	DFS(tree[index][1], i + 1, inright, postleft + left, postright-1);
}
//每一层从左到右形成向量
void BFS() {
	queue<Node>q;
	q.push(Node{ root,0 });
	while (!q.empty()) {
		Node temp = q.front();
		q.pop();
		result[temp.depth].push_back(post[temp.index]);
		if (tree[temp.index][0] != 0) q.push(Node{ tree[temp.index][0],temp.depth + 1 });
		if (tree[temp.index][1] != 0) q.push(Node{ tree[temp.index][1],temp.depth + 1 });
	}
}

int map[100][100];
int main() {
	int n;
	cin >> n;
	in.resize(n + 1); post.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> in[i];
	for (int i = 1; i <= n; i++) cin >> post[i];
	DFS(root, 1, n, 1, n);
	BFS();
	printf("%d", result[0][0]);
	for (int i = 1; i < 35; i++) {
		//从左到右
		if (i % 2 == 1) {
			for (int j = 0; j < result[i].size(); j++) {
				printf(" %d", result[i][j]);
			}
		}
		else {
			for (int j = result[i].size() - 1; j >= 0; j--) {
				printf(" %d", result[i][j]);
			}
		}
	}

}