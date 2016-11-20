#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;

#define MAX_NODES 1001

vector<int> adj_list[MAX_NODES];

vector<int> shortest_paths(MAX_NODES);

int nodes, edges;


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
		}

		while (edges--)
		{
			int a, b;
			cin >> a >> b;

			adj_list[a].push_back(b);
		}

		int starting_node;
		cin >> starting_node;

		priority_queue<pair<int, int>> shortest_path_queue;
		shortest_paths[starting_node] = 0;

		shortest_path_queue.push(make_pair(starting_node, 0));

		while (!shortest_path_queue.empty())
		{
			
		}


	}

	return 0;
}
