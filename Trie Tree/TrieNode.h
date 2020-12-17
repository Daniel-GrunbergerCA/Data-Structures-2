#pragma once
#include <iostream> 
#include <list> 
#include <iterator> 
#include "TrieNode.h"
using namespace std;
class TrieNode 
{
public:
	TrieNode();
	//Letters
	TrieNode* sons[26];
	bool isWord = false;
	~TrieNode();
};



