#include<iostream>
using namespace std;

class Node
{
private:
    int data;
    Node* left;
    Node* right;
public:
    Node(int data)
    {
        this->data = data;
        left = right = 0;
    }

    void setData(int data) {this->data = data;}
    void setLeft(Node *left) {this->left = left;}
    void setRight(Node *right) {this->right = right;}

    int getData(){return data;}
    Node* getLeft(){return left;}
    Node* getRight(){return right;}
};

class BST
{
private:
    Node* root;

    Node* insert(Node* node, int value)
    {
        if(node == NULL)
            return new Node(value);
        if(value < node->getData())
            node->setLeft(insert(node->getLeft(), value));
        else if(value > node->getData())
            node->setRight(insert(node->getRight(), value));
        return node;
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
};
