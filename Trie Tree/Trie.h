#pragma once
#include<iostream>
#include <string>
#include "TrieNode.h"
using namespace std;
class Trie
{
public:
	const int ALPHABET_SIZE = 26;
	Trie();
	TrieNode* root = new TrieNode();
	TrieNode* new_node();//To start a new node with sons that are equal to null
	void insert(string word);//Inserting new word
	bool del(string word);//Deleting word.Calls the function remove to help
	bool isEmpty(TrieNode* root);//Checking if a node has sons
	int depth = 0;
	TrieNode* remove(TrieNode* root, string key, int depth = 0);
	bool search(string word);
	int printAutoSuggestions(string word);//Calls printing
	int printing(TrieNode* current, string str,int counter);//Printing all word with given prefix
	~Trie();
};



