#include<iostream>
using namespace std;

class Node
{
private:
    int data;
    Node* left;
    Node* right;
    Node* root;
public:
    Node()
    {
        data = 0;
        left = right = 0;
        root = NULL;
    }

    void setData(int data) {this->data = data;}
    void setLeft(Node *left) {this->left = left;}
    void setRight(Node *right) {this->right = right;}
    void setRoot(Node *root) {this->root = root;}

    int getData(){return data;}
    Node* getLeft(){return left;}
    Node* getRight(){return right;}
};

