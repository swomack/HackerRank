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


long get_result(long n)
{
	long total_ans = 1;

	while (n)
	{
		if (!(n & 1))
			total_ans *= 2;
		n >>= 1;
	}

	return total_ans;
}


int main() {
	long n;
	cin >> n;

	long result = get_result(n);

	cout << result << endl;

	return 0;
}