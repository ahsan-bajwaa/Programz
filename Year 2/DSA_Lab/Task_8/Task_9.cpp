#include<iostream>
using namespace std;

class BST
{
private:
    Node* root;

    int height(Node* node)
    {
        if(node == NULL)
            return 0;
        int leftHeight = height(node->getLeft());
        int rightHeight = height(node->getRight());
        return 1 + max(leftHeight, rightHeight);
    }

public:
    BST()
    {
        root = NULL;
    }

    int findHeight(){
        return height(root);
    }
};
