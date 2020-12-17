#include "Trie.h"
Trie::Trie()
{
}
//Making a new node and setting the sons to null
TrieNode*  Trie::new_node()
{
	TrieNode* new_node = new TrieNode();
	new_node->isWord = false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		new_node->sons[i] = NULL;
	}
	return new_node;
}
//Inserting a word
void Trie::insert(string word)
{
	TrieNode* current = root;
	for (int i = 0; i < word.length(); i++) {
		int index = word[i] - 'a';
		if (current->sons[index] == NULL)//Checking if the letter already exists
			current->sons[index] = new_node();//Creating new empty node
		current = current->sons[index];
	}
	current->isWord = true;
}
//Deleting a word
bool Trie::del(string word)
{
	if (!search(word))//If it doesnt exist on the tree
		return false;
	remove(this->root, word, 0);//Calls help function
	return true;
}
//Searcing if a word exsists
bool Trie::search(string wrd)
{
	if (this->isEmpty(this->root))//If the tree is empty
		return false;
	TrieNode*  current = this->root;
	//Go to all sons and if we see that we dont have letters , that means the word doest nto exist
	for (int i = 0; i < wrd.length(); i++)
	{
		int index = wrd[i] - 'a';
		if (!current->sons[index])
			return false;//The word doesnt exist
		current = current->sons[index];
	}
	return (current != NULL && current->isWord);//Return true if the word exist
}
bool Trie::isEmpty(TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->sons[i])
			return false;
	return true;
}



//Function to delete a key from the Trie 
TrieNode* Trie::remove(TrieNode* root, string key, int depth)
{
	// If tree is empty 
	if (!root)
		return NULL;
	// If last character of key is being processed 
	if (depth == key.size()) {
		//Now this node is not end of word anymore
		if (root->isWord)
			root->isWord = false;
		// If there is no other word starting with this prefix 
		if (isEmpty(root)) {
			delete (root);
			root = NULL;
		}
		return root;
	}


	// If not last character, recur for the child 
	// obtained using ASCII value 
	int index = key[depth] - 'a';
	root->sons[index] = remove(root->sons[index], key, depth + 1);

	  //Not have child and is not end of the word
	if (isEmpty(root) && root->isWord == false) {
		delete (root);
		root = NULL;
	}
	return root;
}


//printing all the words to given prefix
int Trie::printAutoSuggestions(string word)
{
	int counter = 0;//How many words
	TrieNode* current =root;
	//Making recursive calls where we have the letter
	for (int i = 0; i < word.length(); i++)
	{
		int index = word[i] - 'a';
		if (current->sons[index] == NULL)
			return 0;
		current = current->sons[index];
	}
	return printing(current, word, counter);

}
//Help function to print the word
int Trie::printing(TrieNode * current, string str,int counter)
{
	if (current->isWord == true)//If it`s a word , print it
	{
		cout<< str<<endl;
		counter++;
	}

	for (int i = 0; i < ALPHABET_SIZE; i++)//Recursive call
	{
		if (current->sons[i] != NULL) {
			counter = printing(current->sons[i], str + ((char)(i + 'a')), counter);
		}
	}
	return counter;
}
Trie::~Trie()
{
}


