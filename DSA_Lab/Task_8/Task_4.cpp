#include<iostream>
using namespace std;

class BST{
private:
    Node* root;

    void inorder(Node* node){
        if(node == NULL) return;
        inorder(node->getLeft());
        cout << node->getData() << " ";
        inorder(node->getRight());
    }

    void preorder(Node* node){
        if(node == NULL) return;
        cout << node->getData() << " ";
        preorder(node->getLeft());
        preorder(node->getRight());
    }

    void postorder(Node* node){
        if(node == NULL) return;
        postorder(node->getLeft());
        postorder(node->getRight());
        cout << node->getData() << " ";
    }

public:
    BST(){
        root = NULL;
    }

    void inorderTraversal(){
        inorder(root);
    }

    void preorderTraversal(){
        preorder(root);
    }

    void postorderTraversal(){
        postorder(root);
    }
};
