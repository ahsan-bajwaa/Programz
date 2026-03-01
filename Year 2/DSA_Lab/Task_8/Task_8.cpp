#include<iostream>
using namespace std;

class BST
{
private:
    Node* root;

    int count(Node* node)
    {
        if(node == NULL)
            return 0;
        return 1 + count(node->getLeft()) + count(node->getRight());
    }

public:
    BST()
    {
        root = NULL;
    }

    int countNodes()
    {
        return count(root);
    }
};
