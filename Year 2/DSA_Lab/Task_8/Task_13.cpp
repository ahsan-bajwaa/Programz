#include <iostream>
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

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);

        return node;
    }

    void insertNode(int val) {
        root = insert(root, val);
    }

    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void mirrorTree(Node* node) {
        if (node == nullptr)
            return;

        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;

        mirrorTree(node->left);
        mirrorTree(node->right);
    }
};

int main() {
    BST tree;
    tree.insertNode(50);
    tree.insertNode(30);
    tree.insertNode(70);
    tree.insertNode(20);
    tree.insertNode(40);
    tree.insertNode(60);
    tree.insertNode(80);

    cout << "Inorder before mirror: ";
    tree.inorder(tree.root);
    cout << endl;

    tree.mirrorTree(tree.root);

    cout << "Inorder after mirror: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
