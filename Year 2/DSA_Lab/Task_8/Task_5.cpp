#include<iostream>
using namespace std;

int main(){
    BST tree;

    tree.insertNode(50);
    tree.insertNode(30);
    tree.insertNode(70);
    tree.insertNode(20);
    tree.insertNode(40);
    tree.insertNode(60);
    tree.insertNode(80);

    cout << "Inorder Traversal: ";
    tree.inorderTraversal();
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.preorderTraversal();
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorderTraversal();
    cout << endl;

    return 0;
}
