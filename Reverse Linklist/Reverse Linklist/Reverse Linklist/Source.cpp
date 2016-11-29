#include <iostream>
#include <stack>

using namespace std;



struct Node
{
	int data;
	struct Node *next;

	Node(int val) : data(val)
	{

	}
};




Node* recursion(Node* prev, Node* next)
{
	if (next->next == NULL)
	{
		Node* tail = next;
		next->next = prev;
		return tail;
	}

	Node* temp = recursion(next, next->next);

	next->next = prev;

	return temp;
}

Node* Reverse(Node* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	Node* temp = recursion(head, head->next);
	head->next = NULL;
	return temp;
}

int main()
{

	Node* root = new Node(1);
	root->next = new Node(2);
	root->next->next = new Node(3);

	Node* rev = Reverse(root);

	return 0;
}