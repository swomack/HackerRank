#include <iostream>
#include <cstddef>
#include <algorithm>

using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};
class Solution 
{
public:
	Node* insert(Node* root, int data) 
	{
		if (root == NULL) 
		{
			return new Node(data);
		}
		else
		{
			Node* cur;
			if (data <= root->data) 
			{
				cur = insert(root->left, data);
				root->left = cur;
			}
			else 
			{
				cur = insert(root->right, data);
				root->right = cur;
			}

			return root;
		}
	}

	int getHeight(Node* root) 
	{
		if (root == NULL)
			return 0;

		if (root->left == NULL && root->right == NULL)
			return 0;

		return max(getHeight(root->left), getHeight(root->right)) + 1;
	}

}; 

int main() 
{
	Solution myTree;
	Node* root = NULL;
	int t;
	int data;

	cin >> t;

	while (t-- > 0) {
		cin >> data;
		root = myTree.insert(root, data);
	}
	int height = myTree.getHeight(root);
	cout << height;

	getchar();
	getchar();
	return 0;
}
