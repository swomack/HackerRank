#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};


Node* InsertNth(Node *head, int data, int position)
{
	if (head == NULL && position == 0)
	{
		Node* n_node = new Node();
		n_node->data = data;
		n_node->next = head;

		return n_node;
	}

	if (position == 0)
	{
		Node* n_node = new Node();
		n_node->data = data;
		n_node->next = head;

		return n_node;
	}

	if (position == 1)
	{
		Node* n_node = new Node();
		n_node->data = data;
		n_node->next = head->next;
		head->next = n_node;

		return head;
	}

	InsertNth(head->next, data, position - 1);

	return head;
}

Node* Delete(Node *head, int position)
{
	if (position == 1)
	{
		Node* temp = head->next->next;
		delete head->next;
		head->next = temp;
		return head;
	}

	if (position == 0)
	{
		Node* temp = head->next;
		delete head;
		head = temp;
		return head;
	}

	Delete(head->next, position - 1);

	return head;
}

int main()
{
	Node* head = InsertNth(NULL, 3, 0);
	head = InsertNth(head, 5, 1);
	head = InsertNth(head, 4, 2);
	head = InsertNth(head, 2, 3);
	head = InsertNth(head, 10, 1);

	while (head)
	{
		printf("%d", head->data);
		head = head->next;
	}

	getchar();
	getchar();

	return 0;
}
