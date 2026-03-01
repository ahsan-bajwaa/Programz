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

    bool isIdentical(Node* t1, Node* t2) {
        if (t1 == nullptr && t2 == nullptr)
            return true;
        if (t1 == nullptr || t2 == nullptr)
            return false;
        return (t1->data == t2->data) &&
               isIdentical(t1->left, t2->left) &&
               isIdentical(t1->right, t2->right);
    }
};

int main() {
    BST tree1, tree2;

    if (tree1.isIdentical(tree1.root, tree2.root))
        cout << "Both BSTs are identical" << endl;
    else
        cout << "BSTs are NOT identical" << endl;

    return 0;
}
