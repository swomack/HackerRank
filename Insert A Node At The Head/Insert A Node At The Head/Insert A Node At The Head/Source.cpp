#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};


Node* Insert(Node *head, int data)
{
	Node* n_node = new Node();
	n_node->data = data;
	n_node->next = head;

	return n_node;
}

int main()
{
	Node* head = Insert(NULL, 1);
	Node* first = Insert(head, 2);

	return 0;
}
