#include<stdio.h>
#include<algorithm>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
	int h;
};
int getHeight(Node*& root)
{
	if (root == NULL) return 0;
    return root->h;
}
void update(Node*& root)
{
    root->h=max(getHeight(root->left),getHeight(root->right)) + 1;
}
void LL(Node*& root)
{
	Node* p = root->left;
	root->left = p->right;
	p->right = root;
	update(root);
    update(p);
    root=p;
}
void RR(Node*& root)
{
	Node* p = root->right;
	root->right = p->left;
	p->left = root;
	update(root);
    update(p);
    root=p;
}
void LR(Node*& root)
{
	RR(root->left);
	LL(root);
}
void RL(Node*& root)
{
	LL(root->right);
	RR(root);
}
int cal(Node*root)
{
    return getHeight(root->left) - getHeight(root->right);
}
void insert(Node*& root, int x)
{
	if (root == NULL)
	{
		root = new Node;
		root->data = x;
        root->h=1;
		root->left = root->right = NULL;
	}
	else if (x < root->data)
	{
		insert(root->left, x);
        update(root);
		if (cal(root)== 2)
		{
			if (cal(root->left)==1)
			{
				LL(root);
			}
			else if(cal(root->left)==-1) LR(root);
		}
		
	}
	else if(x > root->data)
    {   
        insert(root->right, x);
        update(root);
        if (cal(root) == -2)
		{
			if (cal(root->right)==-1)
			{
				RR(root);
			}
			else if(cal(root->right)==1) RL(root);
		}

    }
}

int main()
{
	int n;
	scanf("%d", &n);
	Node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		insert(root, x);
	}
	printf("%d", root->data);
}