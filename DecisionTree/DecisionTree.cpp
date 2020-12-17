
#include "DecisionTree.h"
#include <iostream>
#include<string>
using namespace std;
DecisionTree::DecisionTree()
{
}
DecisionTree::DecisionTree(string first_question)
{

}
//Adding root
void DecisionTree::addRoot(string value)
{
	DecisionTreeNode* new_node = new DecisionTreeNode(value);
	this->root = new_node;
}
void erase_Answers(DecisionTreeNode* current);
//Deleting subtree from given question
bool DecisionTree::deleteSubTree(string question)
{
	DecisionTreeNode* our_question = find(question, this->root);
	if (our_question == NULL)
		return false;
	else if (our_question->answersList.empty() == 0) //If there are snwers
	{
		erase_Answers(our_question);
		return true;
	}
	//If it`s a solution
	else
		return false;
}
//function to help clearing the answers and their sons
void clear(DecisionTreeNode* current) {
	if (current)
	{
		if (current->answersList.empty() == 0)
		{
			clear(current->answersList.back()->son);
			delete current->answersList.back();
			current->answersList.pop_back();
			clear(current);
		}
		else
		{
			if (current)
				delete current;
		}
	}
}
//Function to erase the answers(from the sons also)
void erase_Answers(DecisionTreeNode* current)
{
	if (current)
	{
		if (current->answersList.empty() == 0)
		{
			clear(current->answersList.back()->son);
			delete current->answersList.back();
			current->answersList.pop_back();
			erase_Answers(current);//Making the recursive call to erase all of them
		}
		else
			current->isLeaf = true;
	}
}


DecisionTreeNode * DecisionTree::find(string question, DecisionTreeNode*& current)
{
	DecisionTreeNode* result;
	//If we got to the question
	if (current->value == question)
	{
		return current;
	}
	//We didn`t get there yet , so let`s make the recursive call!!
	else
	{
		for (list<ValidAnswer*>::iterator it = current->answersList.begin(); it != current->answersList.end(); it++) 
		{
			result = find(question, (*it)->son);
			if (result != NULL)		//If we don`t get to the question , so we gonna always return only NULL				  
				return result;
		}
		return NULL;//The question is not on the tree
	}
}
bool DecisionTree::addSon(string father, string val, string son)
{
	DecisionTreeNode* current = this->find(father, this->root);
	if (current == NULL)
		return false;//There is no such a question
	else
	{
		DecisionTreeNode* new_son = new DecisionTreeNode(son);//The question/solution after the answer that we added
		ValidAnswer* new_ans = new ValidAnswer(val, new_son);
		current->answersList.push_back(new_ans);//Adding the new answer to our question
		current->isLeaf = false;
		return true;
	}

}

void DecisionTree::printAllTree(DecisionTreeNode * current, int counter)
{
	//Printing the right number of spaces
	for (int i = 0; i < counter; i++)
		cout << "   ";
	//Printing the question
	cout << current->value << endl;
	if (current->answersList.empty() == 0)
	{
		for (list<ValidAnswer*>::iterator it = current->answersList.begin(); it != current->answersList.end(); ++it)
		{
			for (int i = 0; i < counter; i++)
				cout << "   ";
			cout << ": " << (*it)->ans << endl;
			printAllTree((*it)->son, counter + 1);//We gonna make the recursive call to print all the tree
		}
	}
}

	DecisionTree::~DecisionTree()
	{
	}

	ValidAnswer::ValidAnswer()
	{
	}
