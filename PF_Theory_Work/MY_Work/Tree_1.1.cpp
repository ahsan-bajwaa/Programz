#include <iostream>
using namespace std;

class Node
{
private:
    Node *left; // address of left child of parent
    int value;
    Node *right; // address of right child of parent
public:
    Node(int value)
    {
        this->value = value;
        left = right = 0;
    }
    // setter functions

    void setLeft(Node *left) { this->left = left; }
    void setValue(int value) { this->value = value; }
    void setRight(Node *right) { this->right = right; }

    // getter functions

    Node *getLeft() { return left; }
    int getValue() { return value; }
    Node *getRight() { return right; }
};

class Binary_Tree
{
private:
    Node *root;
    int count;

public:
    Binary_Tree()
    {
        root = 0;
        count = 0;
    }
    void setRoot(Node *root) { this->root = root; }

    void preorder(Node *node)
    {

        // base case

        if (node == 0)
        {
            return;
        }
        cout << node->getValue() << " ";
        preorder(node->getLeft());
        preorder(node->getRight());
    }

    void postOrder(Node *node)
    {

        // base case

        if (node == 0)
        {
            return;
        }

        postOrder(node->getLeft());
        postOrder(node->getRight());
        cout << node->getValue() << " ";
    }

    int countLeafNodes(Node *node)
    {
        // base condition

        if (node == 0)
        {
            return 0;
        }
        if (node->getLeft() == 0 && node->getRight() == 0)
            return 1;
        return countLeafNodes(node->getLeft()) + countLeafNodes(node->getRight());
    }

    int countNodes(Node *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + countNodes(node->getLeft()) + countNodes(node->getRight());
    }

};

int main()
{
    Binary_Tree bt;

    Node *root = new Node(50);
    bt.setRoot(root);

    Node *node1 = new Node(40);
    Node *node2 = new Node(80);
    Node *node3 = new Node(90);
    Node *node4 = new Node(70);
    Node *node5 = new Node(10);

    root->setLeft(node1);
    root->setRight(node2);
    node1->setLeft(node3);
    node1->setRight(node4);

    node2->setRight(node5);

    bt.preorder(root);

    cout << endl;

    bt.postOrder(root);

    cout << endl;
    cout << "Toal Leaf Nodes " << bt.countLeafNodes(root) << endl;
    cout << "Toal Nodes " << bt.countNodes(root) << endl;
}