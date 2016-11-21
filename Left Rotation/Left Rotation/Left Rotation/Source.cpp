#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	int n, d;

	scanf("%d %d", &n, &d);

	int arr[100000];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int index = (n + d) % n;

	for (int i = index; i < n; i++)
		fprintf(stdout, "%d ", arr[i]);

	for (int i = 0; i < index; i++)
		fprintf(stdout, "%d ", arr[i]);

	fprintf(stdout, "\n");

	return 0;
}
