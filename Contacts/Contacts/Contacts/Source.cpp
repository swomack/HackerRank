#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>


using namespace std;


const int NODE_CHILD_LENGTH = 26;

struct TrieNode
{
	vector<TrieNode*> nodes;
	bool isLeaf;
	int count;

	TrieNode()
	{
		nodes.resize(NODE_CHILD_LENGTH);
		memset(&nodes[0], 0, 26 * sizeof(size_t));
		isLeaf = false;
		count = 0;
	}
};


class Trie 
{
protected:
	TrieNode* root;

public:
	/** Initialize your data structure here. */
	Trie() 
	{
		root = new TrieNode();
	}

	
	void insert(string word) 
	{
		TrieNode* current_node = root;

		for (int i = 0; i < word.length(); i++)
		{
			if (current_node->nodes[word[i] - 'a'] == NULL)
				current_node->nodes[word[i] - 'a'] = new TrieNode();

			current_node = current_node->nodes[word[i] - 'a'];
			current_node->count++;
		}

		current_node->isLeaf = true;
	}

	
	int find(string prefix)
	{
		TrieNode* current_node = root;

		for (int i = 0; i < prefix.length(); i++)
		{
			if (current_node->nodes[prefix[i] - 'a'] == NULL)
				return 0;

			current_node = current_node->nodes[prefix[i] - 'a'];
		}

		return current_node->count;
	}
};


int main()
{
	int N;
	cin >> N;
	Trie* t = new Trie();

	while (N--)
	{
		string command, data;
		cin >> command >> data;

		if (command == "add")
		{
			t->insert(data);
		}
		else
		{
			fprintf(stdout, "%d\n", t->find(data));
		}
	}

	return 0;
}