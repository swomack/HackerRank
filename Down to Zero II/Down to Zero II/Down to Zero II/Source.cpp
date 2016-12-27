#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int Q;
	int N;

	scanf("%d", &Q);

	while (Q--)
	{
		scanf("%d", &N);

		int steps = 0;

		while (N)
		{
			steps++;

			int root = sqrt(N);

			if (root <= 1)
			{
				N--;
				continue;
			}

		
			for (int i = root; i >= 2; i--)
			{
				if (N % i == 0)
				{
					N = max(i, (int) (N / i));
					break;
				}
			}

			N--;
		}

		fprintf(stdout, "%d\n", steps);
	}

	return 0;
}
