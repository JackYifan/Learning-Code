#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct Node {
	int val;
	Node*left, *right;
};
Node* left(Node*root) {
	Node*temp = root->right;
	root->right = temp->left;
	temp->left = root;
	return temp;
}
Node* right(Node*root) {
	Node*temp = root->left;
	root->left = temp->right;
	temp->right = root;
	return temp;
}
Node* leftright(Node*root) {
	root->left = left(root->left);
	return right(root);
}
Node* rightleft(Node*root) {
	root->right = right(root->right);
	return left(root);
}
int getheight(Node*root) {
	if (root == NULL) return 0;
	int l = getheight(root->left);
	int r = getheight(root->right);
	return max(l, r) + 1;
}
Node* insert(Node*root, int val) {
	if (root == NULL) {
		root = new Node();
		root->val = val;
	}
	else if (root->val > val) {
		root->left = insert(root->left, val);
		int l = getheight(root->left);
		int r = getheight(root->right);
		if (l - r >= 2) {
			if (val < root->left->val) {
				root = right(root);
			}
			else {
				root = leftright(root);
			}
		}
	}
	else {
		root->right = insert(root->right, val);
		int l = getheight(root->left);
		int r = getheight(root->right);
		if (r - l >= 2) {
			if (val > root->right->val) {
				root = left(root);
			}
			else {
				root = rightleft(root);
			}
		}
	}
	return root;
}
bool iscomplete = true;
int tot = 0;
vector<int> leveltraval(Node*root) {
	vector<int>ans;
	queue<Node*>q;
	q.push(root);
	while (!q.empty()) {
		Node*front = q.front();
		q.pop();
		ans.push_back(front->val);
		if (front->left != NULL) {
			if (tot) iscomplete = false;
			q.push(front->left);
		}
		else {
			tot++;
		}
		if (front->right != NULL) {
			if (tot) iscomplete = false;
			q.push(front->right);
		}
		else {
			tot++;
		}
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	Node*root = NULL;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		root = insert(root, val);
	}
	vector<int>ans = leveltraval(root);
	for (int i = 0; i < ans.size(); i++) {
		if (i != 0) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	printf("%s\n", iscomplete ? "YES" : "NO");
	return 0;

}