#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

#define MAX_NODES 1001

vector<int> adj_list[MAX_NODES];

bool adj_matrix[MAX_NODES][MAX_NODES];

vector<int> shortest_paths(MAX_NODES);

int nodes, edges;

class CompareDist
{
public:
	bool operator()(pair<int, int> n1, pair<int, int> n2) {
		return n1.second>n2.second;
	}
};


int main() 
{
	int total_queries;

	cin >> total_queries;

	while (total_queries--)
	{
		cin >> nodes >> edges;

		for (int i = 0; i <= nodes; i++)
		{
			adj_list[i].clear();
			shortest_paths[i] = INT_MAX;

			for (int j = 0; j <= nodes; j++)
			{
				adj_matrix[i][j] = false;
			}
		}

		



		while (edges--)
		{
			int a, b;
			cin >> a >> b;

			if (adj_matrix[a][b] == false) {
				adj_list[a].push_back(b);
				adj_list[b].push_back(a);

				adj_matrix[a][b] = true;
				adj_matrix[b][a] = true;
			}
			
		}

		int starting_node;
		cin >> starting_node;

		priority_queue < pair<int, int>, vector<pair<int, int>>, CompareDist> shortest_path_queue;
		shortest_paths[starting_node] = 0;

		shortest_path_queue.push(make_pair(starting_node, 0));

		while (!shortest_path_queue.empty())
		{
			pair<int, int> node = shortest_path_queue.top();
			shortest_path_queue.pop();

			if (shortest_paths[node.first] < node.second)
				continue;

			shortest_paths[node.first] = node.second;

			for (int i = 0; i < adj_list[node.first].size(); i++)
			{
				shortest_path_queue.push(make_pair(adj_list[node.first][i], shortest_paths[node.first] + 6));
			}
		}

		for (int i = 1; i <= nodes; i++)
		{
			if (i != starting_node) 
			{
				fprintf(stdout, "%d", (shortest_paths[i] != INT_MAX ? shortest_paths[i] : -1));
				fprintf(stdout, " ");
			}
				
		}
		fprintf(stdout, "\n");

	}

	return 0;
}
