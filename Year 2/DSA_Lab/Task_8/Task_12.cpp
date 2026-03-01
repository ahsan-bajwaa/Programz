#include <iostream>
#include <queue>
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

    // Level Order Traversal
    void levelOrderTraversal(Node* root) {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        queue<Node*> q;
        q.push(root);

        cout << "Level Order Traversal: ";
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
        cout << endl;
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

    tree.levelOrderTraversal(tree.root);

    return 0;
}
