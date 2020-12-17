#pragma once;
#include <iostream>
#include <cstring>
#include <list>
#include <string>
using namespace std;

class ValidAnswer;
class DecisionTreeNode
{
public:
	string value;
	bool isLeaf;
	list<ValidAnswer*> answersList;
	DecisionTreeNode() { isLeaf = true; }
	DecisionTreeNode* next;
	DecisionTreeNode(string question) { this->value = question; isLeaf = true; }
};
class ValidAnswer
{
public:
	ValidAnswer();
	ValidAnswer(string ans, DecisionTreeNode* son) { this->ans = ans; this->son = son; }
	string ans;
	DecisionTreeNode* son;

};
class DecisionTree {
public:
	DecisionTree();
	~DecisionTree();
	DecisionTree(string first_question);
	DecisionTreeNode* root;
	void addRoot(string value);
	bool deleteSubTree(string question);
	DecisionTreeNode* find(string question, DecisionTreeNode*& current);
	bool addSon(string father, string val, string son);
	void printAllTree(DecisionTreeNode * current, int counter);
	void printAllTree() { printAllTree(this->root, 0); }//To use in main
	void searchAndPrint(string value) { searchAndPrint(value, root); }//To use in main
	void searchAndPrint(string value, DecisionTreeNode* current) {
		DecisionTreeNode* path = find(value, current);
		if (path != NULL)
		{
			if (path != current)
			{
				for (list<ValidAnswer*>::iterator it = current->answersList.begin(); it != current->answersList.end(); it++)
				{
					searchAndPrint(value, (*it)->son);
				}
			}
			cout << current->value;
			if (current != root)
				cout << "=>";
			else
				cout << endl;
		}
		else
			cout << "no such value" << endl;
	};
	void process() { process(root); }	//To use in main
	void process(DecisionTreeNode* current)
	{
		string ans;
		cout << current->value;
		//If it`s a solution
		if (current->answersList.empty() == 1)
		{
			cout << endl;
			return;
		}
		cout << endl;
		//If it`s a question
		cin >> ans;
		for (list<ValidAnswer*>::iterator it = current->answersList.begin(); it != current->answersList.end(); it++)
		{
			//Finding this answer and going on on the tree
			if (ans == (*it)->ans)
				process((*it)->son);
		}
	}
};



