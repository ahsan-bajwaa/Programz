#include<iostream>
using namespace std;

class Node
{
private:
    int data;
    Node* left;
    Node* right;
public:
    Node()
    {
        data = 0;
        left = right = 0;
    }

    void setData(int data) {this->data = data;}
    void setLeft(Node* left) {this->left = left;}
    void setRight(Node* right) {this->right = right;}

    int getData(){return data;}
    Node* getLeft(){return left;}
    Node* getRight(){return right;}
};
