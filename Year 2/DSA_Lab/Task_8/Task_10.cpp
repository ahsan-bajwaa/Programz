#include<iostream>
using namespace std;

class BST{
private:
    Node* root;

    Node* deleteNodeRec(Node* node, int key)
    {
        if(node == NULL)
            return node;

        if(key < node->getData())
            node->setLeft(deleteNodeRec(node->getLeft(), key));
        else if(key > node->getData())
            node->setRight(deleteNodeRec(node->getRight(), key));
        else {
            if(node->getLeft() == NULL && node->getRight() == NULL)
            {
                delete node;
                return NULL;
            }
            else if(node->getLeft() == NULL)
            {
                Node* temp = node->getRight();
                delete node;
                return temp;
            }
            else if(node->getRight() == NULL)
            {
                Node* temp = node->getLeft();
                delete node;
                return temp;
            }
            else
            {
                Node* temp = findMinNode(node->getRight());
                node->setData(temp->getData());
                node->setRight(deleteNodeRec(node->getRight(), temp->getData()));
            }
        }
        return node;
    }
public:
    BST()
    {
        root = NULL;
    }

    void deleteNode(int key)
    {
        root = deleteNodeRec(root, key);
    }
};
