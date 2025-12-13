#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    bool isBST(Node* node, int minVal, int maxVal) {
        if (node == nullptr)
            return true;

        if (node->data <= minVal || node->data >= maxVal)
            return false;

        return isBST(node->left, minVal, node->data) &&
               isBST(node->right, node->data, maxVal);
    }

    void checkBST() {
        if (isBST(root, INT_MIN, INT_MAX))
            cout << "This tree is a BST" << endl;
        else
            cout << "This tree is NOT a BST" << endl;
    }
};

int main() {
    Tree tree;

    tree.checkBST();

   
    tree.root->left->right->data = 100;
    tree.checkBST();

    return 0;
}
