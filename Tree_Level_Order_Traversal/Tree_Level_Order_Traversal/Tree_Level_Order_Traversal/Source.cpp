#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;


struct node
{
	int data;
	node *left;
	node *right;
	node(int x) : data(x), left(NULL), right(NULL) {}
};

void LevelOrder(node* root)
{
	if (root == NULL)
		return;

	queue<node*> level_queue;

	level_queue.push(root);

	while (!level_queue.empty())
	{
		int level_size = level_queue.size();


		while (level_size--)
		{
			node* level_element = level_queue.front();
			level_queue.pop();

			fprintf(stdout, "%d ", level_element->data);

			if (level_element->left)
				level_queue.push(level_element->left);

			if (level_element->right)
				level_queue.push(level_element->right);
		}
	}
}

int main()
{
	return 0;
}