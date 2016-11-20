#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int maxXor(int l, int r) {

	if (l == r)
		return 0;

	int max_value = 0;

	for (int i = l; i < r; i++)
	{
		for (int j = i + 1; j <= r; j++)
		{
			int xor_val = i ^ j;
			max_value = max(max_value, xor_val);
		}
	}

	return max_value;
}

int main() {
	int res;
	int _l;
	cin >> _l;

	int _r;
	cin >> _r;

	res = maxXor(_l, _r);
	cout << res;

	return 0;
}
