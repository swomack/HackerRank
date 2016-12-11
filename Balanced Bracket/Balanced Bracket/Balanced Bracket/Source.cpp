#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() 
{
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++) 
	{
		string s;
		cin >> s;

		if (s.length() % 2)
		{
			printf("NO\n");
			continue;
		}


		stack<char> balance;

		bool valid = true;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
				balance.push(s[i]);
			else if (s[i] == ')')
			{
				if (balance.empty() || balance.top() != '(')
				{
					valid = false;
					break;
				}
				else
					balance.pop();
			}
			else if (s[i] == '}')
			{
				if (balance.empty() || balance.top() != '{')
				{
					valid = false;
					break;
				}
				else
					balance.pop();
			}
			else if (s[i] == ']')
			{
				if (balance.empty() || balance.top() != '[')
				{
					valid = false;
					break;
				}
				else
					balance.pop();
			}

		}

		if (valid && balance.empty())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
