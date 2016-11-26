#include <iostream>

using namespace std;


#define LEFT_CHILD 1
#define RIGHT_CHILD 2


struct node
{
	int data;
	node* left;
	node* right;
};

void top_view_helper(node* root, int side)
{
	if (root == NULL)
		return;

	
	
	if (side == LEFT_CHILD)
		top_view_helper(root->left, side);

	printf("%d ", root->data);

	if (side == RIGHT_CHILD)
		top_view_helper(root->right, side);
}

void top_view(node * root)
{
	if (root == NULL)
		return;


	top_view_helper(root->left, LEFT_CHILD);

	printf("%d ", root->data);

	top_view_helper(root->right, RIGHT_CHILD);
}

int main()
{

}
