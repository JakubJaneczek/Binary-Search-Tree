#include <iostream>

class BST
{
public:
	int data;
	BST* left, * right;

	BST();
	BST(int);

	BST* Insert(BST*, int);
	BST* Delete(BST*, int);
	bool FindOne(BST*, int value);
	BST* FindMax(BST*);
	BST* FindMin(BST*);
	~BST();

};
BST::BST() : data(0), left(NULL), right(NULL)
{
}

BST::BST(int value)
{
	data = value;
	left = right = NULL;
}

BST* BST::Insert(BST* root, int value)
{
	if (root == NULL)
	{
		return new BST(value);
	}

	if (value >= root->data)
	{
		root->right = Insert(root->right, value);
	}
	else
	{
		root->left = Insert(root->left, value);
	}
	return root;
}

BST* BST::Delete(BST* root, int value)
{	
	if (root == NULL) return root;

	if (value < root->data)
		root->left = Delete(root->left, value);
	else if (value > root->data)
		root->right = Delete(root->right, value);
	else
		{
		if (root->left == NULL)
		{
			BST* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			BST* temp = root->left;
			delete root;
			return temp;
		}

		BST* temp = FindMin(root->right);

		root->data = temp->data;

		root->right = Delete(root->right, temp->data);
	}
	return root;
	
}

bool BST::FindOne(BST* root, int value) 
{
	if (root != NULL)
	{
		if (value < root->data)
		{
			FindOne(root->left, value);
		}
		if (root->data == value)
		{
			std::cout << "1\n";
			return true;
		}
		if (value >= root->data)
		{
			FindOne(root->right, value);
		}
	}
	return false;
}

BST* BST::FindMin(BST* root)
{
	BST* current = root;

	while (current && current->left != NULL)
		current = current->left;

	return current;
}

BST* BST::FindMax(BST* root)
{
	BST* current = root;

	while (current && current->right != NULL)
		current = current->right;

	return current;
}

BST::~BST()
{
}

int main()
{
	BST a, *root = NULL;
	char command;
	int number;
	while (std::cin.good())
	{
		std::cin >> command;
		switch (command)
		{
		case '+':
			std::cin >> number;
			root = a.Insert(root, number);

			break;
		case '-':
			std::cin >> number;
			root = a.Delete(root, number);
			break;
		case '?':
			std::cin >> number;
			if (a.FindOne(root, number))
			{
				std::cout << "1\n";
			}
			else
			{
				std::cout << "0\n";
			}
			break;
		case 'm':
			std::cout << a.FindMin(root)->data << "\n";
			break;
		case 'M':
			std::cout << a.FindMax(root)->data << "\n";
			break;
		case 'q':
			exit(0);
		}

	}
}