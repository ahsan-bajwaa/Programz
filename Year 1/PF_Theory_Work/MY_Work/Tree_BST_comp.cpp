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

    // Helper function to insert nodes in BST manner
    Node* insertBST(Node* node, int value) {
        if (node == 0) {
            return new Node(value);
        }
        
        if (value < node->getValue()) {
            node->setLeft(insertBST(node->getLeft(), value));
        } else if (value > node->getValue()) {
            node->setRight(insertBST(node->getRight(), value));
        }
        
        return node;
    }

    // Calculate tree height (levels)
    int getHeight(Node* node) {
        if (node == 0) return 0;
        int leftHeight = getHeight(node->getLeft());
        int rightHeight = getHeight(node->getRight());
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }

    // Display tree structure visually
    void printTree(Node* node, int level, const string& prefix) {
        if (node == 0) return;
        
        cout << prefix;
        if (level == 0) {
            cout << "Root: ";
        } else {
            cout << "L" << level << ": ";
        }
        cout << node->getValue() << endl;
        
        printTree(node->getLeft(), level + 1, prefix + "   |--");
        printTree(node->getRight(), level + 1, prefix + "   |--");
    }

public:
    Binary_Tree()
    {
        root = 0;
        count = 0;
    }
    void setRoot(Node *root) { this->root = root; }
    Node* getRoot() { return root; }

    // Method to build BST from array data with 5 levels
    void buildBSTFromArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            root = insertBST(root, arr[i]);
        }
        cout << "BST built from array data.\n";
        cout << "Tree height (levels): " << getHeight(root) << endl;
    }

    // Preorder traversal
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

    // Postorder traversal  
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

    // Inorder traversal (gives sorted order for BST)
    void inorder(Node *node)
    {
        if (node == 0)
        {
            return;
        }
        inorder(node->getLeft());
        cout << node->getValue() << " ";
        inorder(node->getRight());
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

    // Display tree in tree-like structure
    void displayTreeStructure() {
        cout << "\nTree Structure (5 levels):\n";
        cout << "===========================\n";
        printTree(root, 0, "");
    }
};

int main()
{
    Binary_Tree bt;
    
    // Array data to create BST with 5 levels
    // Values arranged to ensure 5 levels in BST structure
    int bstArray[] = {50, 30, 70, 20, 40, 60, 80, 
                      10, 25, 35, 45, 55, 65, 75, 85,
                      5, 15, 28, 38, 48, 58, 68, 78, 88,
                      2, 8, 18, 32, 42, 52, 62, 72, 82, 92};
    
    int arraySize = sizeof(bstArray) / sizeof(bstArray[0]);
    
    cout << "Array data (" << arraySize << " elements): ";
    for (int i = 0; i < arraySize; i++) {
        cout << bstArray[i] << " ";
    }
    cout << "\n\n";
    
    // Build BST from array
    bt.buildBSTFromArray(bstArray, arraySize);
    
    Node* root = bt.getRoot();
    
    cout << "\n=== Tree Traversals ===\n";
    
    cout << "Preorder traversal: ";
    bt.preorder(root);
    cout << endl;
    
    cout << "Inorder traversal (sorted order): ";
    bt.inorder(root);
    cout << endl;
    
    cout << "Postorder traversal: ";
    bt.postOrder(root);
    cout << endl;
    
    cout << "\n=== Tree Statistics ===\n";
    cout << "Total Nodes: " << bt.countNodes(root) << endl;
    cout << "Total Leaf Nodes: " << bt.countLeafNodes(root) << endl;
    
    // Display tree structure
    bt.displayTreeStructure();

    return 0;
}