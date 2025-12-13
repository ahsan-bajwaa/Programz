#include<iostream>
using namespace std;

class BST
{
private:
    Node* root;

public:
    BST()
    {
        root = NULL;
    }

    int findMin()
    {
        if(root == NULL) return -1;
        Node* temp = root;
        while(temp->getLeft() != NULL)
            temp = temp->getLeft();
        return temp->getData();
    }

    int findMax()
    {
        if(root == NULL) return -1;
        Node* temp = root;
        while(temp->getRight() != NULL)
            temp = temp->getRight();
        return temp->getData();
    }
};
