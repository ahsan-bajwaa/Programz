#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

     // Count internal nodes...
    int countInternalNodes(Node *node)
    {
        // 1. Base Case: If the current node is null (end of a branch), return 0.
        if (node == 0)
        {
            return 0;
        }

        // 2. Recursive Step: Count nodes in the left and right subtrees.
        int count = countInternalNodes(node->getLeft()) + countInternalNodes(node->getRight());

        // 3. Check for Internal Node (The condition for counting)
        // A node is an internal node if it has at least one child.
        // Note: This check includes the absolute root temporarily.
        if (node->getLeft() != 0 || node->getRight() != 0)
        {
            // If the node has at least one child, it contributes 1 to the count.
            count += 1;
        }

        // 4. Return the total count for this subtree.
        return count;
    }

    // BST search elements...
    Node* searchBST(Node *node, int target)
    {
        // 1. Base Case 1: Node is null (reached the end of a branch)
        // If the tree is empty or we've reached a leaf's child without finding the value, it's not present.
        if (node == 0)
        {
            return 0; // Not found
        }

        // 2. Base Case 2: Target found
        // If the current node's value matches the target, we found it.
        if (target == node->getValue())
        {
            return node; // Found! Return the pointer to this node.
        }

        // 3. Recursive Step: Decide whether to search left or right

        // If the target value is smaller than the current node's value,
        // we must go to the LEFT subtree (due to BST property).
        if (target < node->getValue())
        {
            return searchBST(node->getLeft(), target);
        }
        // If the target value is larger than the current node's value,
        // we must go to the RIGHT subtree (due to BST property).
        else // (target > node->getValue())
        {
            return searchBST(node->getRight(), target);
        }
    }

    // BFS......
    void BFS_using_queue(Node *node)
    {
        // Handle the case of an empty tree
        if (node == 0)
        {
            return;
        }

        queue<Node*> q;
        q.push(node);   // root

        while (!q.empty())
        {
            Node* current = q.front();
            q.pop();

            cout << current->getValue() << " ";

            if (current->getLeft() != 0)
                q.push(current->getLeft());

            if (current->getRight() != 0)
                q.push(current->getRight());
        }
    }

    // DFS....
    void DFS_using_Stack(Node* root)
    {
        if (root == 0)
            return;

        stack<Node*> st;
        st.push(root);

        while (!st.empty())
        {
            Node* current = st.top();
            st.pop();

            cout << current->getValue() << " ";

            // Push right first so left is processed first
            if (current->getRight() != 0)
                st.push(current->getRight());

            if (current->getLeft() != 0)
                st.push(current->getLeft());
        }
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