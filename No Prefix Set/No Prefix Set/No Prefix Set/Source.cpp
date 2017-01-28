#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int NODE_CHILD_LENGTH = 10;

struct TrieNode
{
	vector<TrieNode*> nodes;
	bool isLeaf;
	int count;

	TrieNode()
	{
		nodes.resize(NODE_CHILD_LENGTH);
		memset(&nodes[0], 0, NODE_CHILD_LENGTH * sizeof(size_t));
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


	bool insert(string word)
	{
		TrieNode* current_node = root;

		bool res = false;

		for (int i = 0; i < word.length(); i++)
		{
			if (current_node->nodes[word[i] - 'a'] == NULL)
			{
				current_node->nodes[word[i] - 'a'] = new TrieNode();
				res = true;
			}
				

			current_node = current_node->nodes[word[i] - 'a'];
			current_node->count++;

			if (current_node->isLeaf)
				return false;
		}

		current_node->isLeaf = true;
		return res;
	}
};

int main() 
{
	int N;
	Trie* t = new Trie();
	vector<string> strs;
	cin >> N;

	while (N--)
	{
		string s;
		cin >> s;
		strs.push_back(s);
	}

	bool res = true;
	string res_str;

	for (int i = 0; i < strs.size(); i++)
	{
		if (t->insert(strs[i]) == false)
		{
			res_str = strs[i];
			res = false;
			break;
		}
	}

	if (res)
	{
		cout << "GOOD SET" << endl;
	}
	else
	{
		cout << "BAD SET" << endl;
		cout << res_str << endl;
	}

	return 0;
}