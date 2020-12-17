#include "TrieNode.h"

TrieNode::TrieNode()
{
	for (int i = 0; i < 26; i++)
		this->sons[i] = NULL;
	this->isWord = false;
}

TrieNode::~TrieNode()
{
}
