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

void add(vector<int>& nums)
{
	for (int i = 1; i < nums.size(); i++)
		nums[i] += nums[i - 1];
}

int main() 
{
	int n1;
	int n2;
	int n3;
	cin >> n1 >> n2 >> n3;


	vector<int> h1(n1);
	for (int h1_i = n1-1; h1_i >= 0; h1_i--) 
	{
		cin >> h1[h1_i];
	}

	vector<int> h2(n2);
	for (int h2_i = n2 - 1; h2_i >= 0; h2_i--) 
	{
		cin >> h2[h2_i];
	}
	
	vector<int> h3(n3);
	for (int h3_i = n3 - 1; h3_i >= 0; h3_i--) 
	{
		cin >> h3[h3_i];
	}

	if (h1.size() == 0 || h2.size() == 0 || h3.size() == 0)
	{
		printf("0\n");
	}
	else
	{
		add(h1);
		add(h2);
		add(h3);

		int ind1 = h1.size() - 1;
		int ind2 = h2.size() - 1;
		int ind3 = h3.size() - 1;

		while (true)
		{
			if (ind1 < 0 || ind2 < 0 || ind3 < 0)
			{
				printf("0\n");
				break;
			}
			if (h1[ind1] == h2[ind2] && h1[ind1] == h3[ind3])
			{
				printf("%d\n", h1[ind1]);
				break;
			}

			int lowest = min(h1[ind1], h2[ind2]);
			lowest = min(lowest, h3[ind3]);

			if (h1[ind1] > lowest)
				ind1--;

			if (h2[ind2] > lowest)
				ind2--;

			if (h3[ind3] > lowest)
				ind3--;
		}
	}

	return 0;
}
