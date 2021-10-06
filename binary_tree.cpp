// Project: Binary Tree
// File: binary_tree.cpp 

#include <iostream>

class TreeNode
{
public:
	int Key;
	TreeNode * Left;
	TreeNode * Right;
};

TreeNode * NewTreeNode(int key)
{
	// Create a new node 
	TreeNode * node = new TreeNode;

	// Assign a key 
	node->Key = key;

	// Initialize Left and Right pointer 
	node->Left = NULL;
	node->Right = NULL;

	return node;
}

void PrintTreeInOrder(TreeNode * node)
{
	if(node == NULL) return;

	PrintTreeInOrder(node->Left);
	std::cout << node->Key << " ";
	PrintTreeInOrder(node->Right);
}

void Print(TreeNode * x, int & id)
{
	if (!x) return;

	Print(x->Left, id);

	id++;
	std::cout << id << ' ' << x->Key << std::endl;

	Print(x->Right, id);
}

int main()
{
	std::cout << "Binary Tree" << std::endl;

	// Creating root element 
	TreeNode * root = NewTreeNode(1);
	// add children to the root element 
	root->Left = NewTreeNode(2);
	root->Right = NewTreeNode(3);
	// add children to element 2 
	root->Left->Left = NewTreeNode(4);
	root->Left->Right = NewTreeNode(5);
	// add children to element 3 
	root->Right->Left = NewTreeNode(6);
	root->Right->Right = NewTreeNode(7);

	int id = 0;
	Print(root, id);

	return 0;
}
