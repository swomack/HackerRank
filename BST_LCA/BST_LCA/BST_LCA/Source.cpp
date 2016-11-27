#include <iostream>
#include <algorithm>

using namespace std;


typedef struct node
{
	int data;
	node * left;
	node * right;
}node;


node * lca(node * root, int v1, int v2)
{
	int low = min(v1, v2);
	int high = max(v1, v2);
	if (low <= root->data && high >= root->data)
		return root;

	if (low < root->data)
		return lca(root->left, low, high);
	else
		return lca(root->right, low, high);
}

int main()
{
	node* root = new node; root->data = 4;
	root->left = new node; root->left->data = 2;
	root->left->left = new node; root->left->left->data = 1;
	root->left->right = new node; root->left->right->data = 3;
	root->right = new node; root->right->data = 7;
	root->right->left = new node; root->right->left->data = 6;
	root->right->right = new node; root->right->right->data = 8;

	node* output = lca(root, 6, 8);

	getchar();
	return 0;
}
