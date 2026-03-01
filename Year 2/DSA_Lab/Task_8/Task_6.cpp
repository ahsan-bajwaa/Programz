#include<iostream>
using namespace std;

class BST
{
private:
    Node* root;

    bool search(Node* node, int key)
    {
        if(node == NULL)
            return false;
        if(node->getData() == key)
            return true;
        if(key < node->getData())
            return search(node->getLeft(), key);
        else
            return search(node->getRight(), key);
    }

public:
    BST()
    {
        root = NULL;
    }

    void insertNode(int value)
    {
        root = insert(root, value);
    }

    void searchNode(int key)
    {
        if(search(root, key))
            cout << key << " found in the tree." << endl;
        else
            cout << key << " not found in the tree." << endl;
    }
};
