#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


int main() {
	
	int N;
	cin >> N;

	unordered_map<string, int> map;

	int zero_string = 0;
	while(N--)
	{
		string inp;
		cin >> inp;

		if (inp.length() == 0)
			zero_string++;
		else
			map[inp] ++;
	}

	int Q;
	cin >> Q;

	while (Q--)
	{
		string query;
		cin >> query;

		if(query.length() > 0)
			fprintf(stdout, "%d\n", map[query]);
		else
			fprintf(stdout, "%d\n", zero_string);
	}


	return 0;
}
