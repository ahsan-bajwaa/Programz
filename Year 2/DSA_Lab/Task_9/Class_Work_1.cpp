#include<iostream>
using namespace std;

class Node{
private:
        Node *left;
        int value;
        Node *right;
public:
        Node(int value){
        this->value = value;
        left = right = 0;
        }
void setLeft(Node *left){this->left = left;}
void setValue(int value){this->value = value;}
void setRight(Node *right){this->right = right;}

Node *getLeft(){return left;}
int getValue(){return value;}
Node *getRight(){return right;}

};

class BST
{
private:
    Node *root;
    int height(Node* node)
    {
        if(node == NULL)
            return 0;
        int leftHeight = height(node->getLeft());
        int rightHeight = height(node->getRight());
        return 1 + max(leftHeight, rightHeight);
    }
public:
    BST(){
       root = 0;
    }
    int findHeight(){
        return height(root);
    }
};
