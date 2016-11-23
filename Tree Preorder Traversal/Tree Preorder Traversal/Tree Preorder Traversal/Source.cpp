#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	node(int val) : data(val), left(NULL), right(NULL)
	{

	}
};


void preOrder(node *root) 
{
	if (root == NULL)
		return;

	fprintf(stdout, "%d ", root->data);

	preOrder(root->left);
	preOrder(root->right);
}

int main()
{
	node* root = new node(3);
	root->left = new node(5);
	root->left->left = new node(1);
	root->left->right = new node(4);
	root->right = new node(2);
	root->right->left = new node(6);

	preOrder(root);

	getchar();
	getchar();
	return 0;
}
