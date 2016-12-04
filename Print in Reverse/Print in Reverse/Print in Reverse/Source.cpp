#include <iostream>
#include <cstdio>

using namespace std;

struct Node
{
	int data;
	struct Node *next;

	Node(int val) : data(val), next(NULL)
	{}
};

void ReversePrint(Node *head)
{
	if (head == NULL)
		return;

	ReversePrint(head->next);

	printf("%d\n", head->data);
}

int main()
{
	return 0;
}