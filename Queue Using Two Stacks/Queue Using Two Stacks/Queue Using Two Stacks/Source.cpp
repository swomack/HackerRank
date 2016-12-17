#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

int main() {

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	int q;

	cin >> q;

	stack<int> stk;
	stack<int> queue;

	while (q--)
	{
		int command, data;
		cin >> command;

		switch (command)
		{
		case 1:
			cin >> data;
			stk.push(data);
			break;
		case 2:
			if (queue.empty())
			{
				while(!stk.empty())
				{
					queue.push(stk.top());
					stk.pop();
				}
			}
			
			queue.pop();
			
			break;
		case 3:
			if (queue.empty())
			{
				while (!stk.empty())
				{
					queue.push(stk.top());
					stk.pop();
				}
			}
			
			fprintf(stdout, "%d\n", queue.top());

			break;
		}

	}

	return 0;
}
