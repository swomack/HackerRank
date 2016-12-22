#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int goLeft(vector<vector<char>>& matrix, int a, int b, int c, int d, vector<vector<int>> &distances, vector<vector<bool>>& visited);
int goRight(vector<vector<char>>& matrix, int a, int b, int c, int d, vector<vector<int>> &distances, vector<vector<bool>>& visited);
int goUp(vector<vector<char>>& matrix, int a, int b, int c, int d, vector<vector<int>> &distances, vector<vector<bool>>& visited);
int goDown(vector<vector<char>>& matrix, int a, int b, int c, int d, vector<vector<int>> &distances, vector<vector<bool>>& visited);

int goLeft(vector<vector<char>>& matrix, int a, int b, int c, int d, vector<vector<int>> &distances, vector<vector<bool>>& visited)
{
	if (a < 0 || b < 0 || a >= matrix.size() || b >= matrix[0].size())
		return INT_MAX - 1;

	if (matrix[a][b] == 'X')
		return INT_MAX - 1;

	if (a == c && b == d)
		return 0;

	if (visited[a][b])
		return INT_MAX - 1;

	if (distances[a][b] != -1)
		return distances[a][b];

	visited[a][b] = true;

	int dL = goLeft(matrix, a, b - 1, c, d, distances, visited);
	int dU = goUp(matrix, a - 1, b, c, d, distances, visited) + 1;
	int dD = goDown(matrix, a + 1, b, c, d, distances, visited) + 1;
	

	distances[a][b] = min(min(dL, dU), dD);

	return distances[a][b];
}

int goRight(vector<vector<char>>& matrix, int a, int b, int c, int d, vector<vector<int>> &distances, vector<vector<bool>>& visited)
{
	if (a < 0 || b < 0 || a >= matrix.size() || b >= matrix[0].size())
		return INT_MAX - 1;

	if (matrix[a][b] == 'X')
		return INT_MAX - 1;

	if (a == c && b == d)
		return 0;

	if (visited[a][b])
		return INT_MAX - 1;

	if (distances[a][b] != -1)
		return distances[a][b];

	visited[a][b] = true;

	int dL = goRight(matrix, a, b + 1, c, d, distances, visited);
	int dU = goUp(matrix, a - 1, b, c, d, distances, visited) + 1;
	int dD = goDown(matrix, a + 1, b, c, d, distances, visited) + 1;


	distances[a][b] = min(min(dL, dU), dD);

	return distances[a][b];
}

int goUp(vector<vector<char>>& matrix, int a, int b, int c, int d, vector<vector<int>> &distances, vector<vector<bool>>& visited)
{
	if (a < 0 || b < 0 || a >= matrix.size() || b >= matrix[0].size())
		return INT_MAX - 1;

	if (matrix[a][b] == 'X')
		return INT_MAX - 1;

	if (a == c && b == d)
		return 0;

	if (visited[a][b])
		return INT_MAX - 1;

	if (distances[a][b] != -1)
		return distances[a][b];

	visited[a][b] = true;

	int dL = goRight(matrix, a, b + 1, c, d, distances, visited) + 1;
	int dU = goLeft(matrix, a, b - 1, c, d, distances, visited) + 1;
	int dD = goUp(matrix, a - 1, b, c, d, distances, visited);


	distances[a][b] = min(min(dL, dU), dD);

	return distances[a][b];
}

int goDown(vector<vector<char>>& matrix, int a, int b, int c, int d, vector<vector<int>> &distances, vector<vector<bool>>& visited)
{
	if (a < 0 || b < 0 || a >= matrix.size() || b >= matrix[0].size())
		return INT_MAX - 1;

	if (matrix[a][b] == 'X')
		return INT_MAX - 1;

	if (a == c && b == d)
		return 0;

	if (visited[a][b])
		return INT_MAX - 1;

	if (distances[a][b] != -1)
		return distances[a][b];

	visited[a][b] = true;

	int dL = goRight(matrix, a, b + 1, c, d, distances, visited) + 1;
	int dU = goLeft(matrix, a, b - 1, c, d, distances, visited) + 1;
	int dD = goDown(matrix, a + 1, b, c, d, distances, visited);


	distances[a][b] = min(min(dL, dU), dD);

	return distances[a][b];
}

int distance(vector<vector<char>>& matrix, int a, int b, int c, int d, vector<vector<int>> &distances, vector<vector<bool>>& visited)
{
	visited[a][b] = true;

	int dR = goRight(matrix, a, b + 1, c, d, distances, visited) + 1;
	int dL = goLeft(matrix, a, b - 1, c, d, distances, visited) + 1;
	int dD = goDown(matrix, a + 1, b, c, d, distances, visited) + 1;
	int dU = goUp(matrix, a - 1, b, c, d, distances, visited) + 1;

	distances[a][b] = min(min(dL, dR), min(dD, dU));

	return distances[a][b];
}

int main()
{
	int N;

	scanf("%d", &N);
	getchar();

	vector<vector<char>> matrix(N);
	vector<vector<int>> distances(N);
	vector<vector<bool>> visited(N);

	for (int i = 0; i < N; i++)
		matrix[i].resize(N);

	for (int i = 0; i < N; i++)
		distances[i].resize(N);

	for (int i = 0; i < N; i++)
		visited[i].resize(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int c;
			scanf("%c", &matrix[i][j]);

			distances[i][j] = -1;
			visited[i][j] = false;
		}

		getchar();
	}

	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	int dist = distance(matrix, a, b, c, d, distances, visited);

	fprintf(stdout, "%d\n", dist);

	return 0;
}