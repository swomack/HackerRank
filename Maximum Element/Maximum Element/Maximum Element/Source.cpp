#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

int main()
{
	int N;

	scanf("%d", &N);

	stack<int> cont;
	stack<int> helper;

	int pop = 0;

	while (N--)
	{
		int command;

		scanf("%d", &command);

		switch (command)
		{
		case 1:
			int element;
			scanf("%d", &element);

			helper.push(element);

			if (cont.empty())
				cont.push(element);
			else if (cont.top() <= element)
				cont.push(element);
			
			break;

		case 2:

			if (!cont.empty() && cont.top() == helper.top())
			{
				cont.pop();
				helper.pop();
			}
			else
				helper.pop();
			
			break;

		case 3:
			printf("%d\n", cont.top());
		}
	}

	return 0;
}
