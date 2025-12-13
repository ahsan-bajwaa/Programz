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
    int count(Node* node){
        if(node == NULL)
        return 0;
        return 1 + count(node->getLeft()) + count(node->getRight());
    }
public:
    BST(){
       root = 0;
    }
    int countNodes(){
        return count(root);
    }
};

