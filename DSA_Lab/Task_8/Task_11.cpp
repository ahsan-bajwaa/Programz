#include<iostream>
using namespace std;

int main(){
    BST tree;
    int choice, value;

    while(true){
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Display Inorder Traversal\n";
        cout << "3. Display Preorder Traversal\n";
        cout << "4. Display Postorder Traversal\n";
        cout << "5. Search Node\n";
        cout << "6. Find Minimum\n";
        cout << "7. Find Maximum\n";
        cout << "8. Count Total Nodes\n";
        cout << "9. Find Tree Height\n";
        cout << "10. Delete Node\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insertNode(value);
                cout << "Node inserted.\n";
                break;

            case 2:
                cout << "Inorder Traversal: ";
                tree.inorderTraversal();
                cout << endl;
                break;

            case 3:
                cout << "Preorder Traversal: ";
                tree.preorderTraversal();
                cout << endl;
                break;

            case 4:
                cout << "Postorder Traversal: ";
                tree.postorderTraversal();
                cout << endl;
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                tree.searchNode(value);
                break;

            case 6:
                cout << "Minimum value: " << tree.findMin() << endl;
                break;

            case 7:
                cout << "Maximum value: " << tree.findMax() << endl;
                break;

            case 8:
                cout << "Total nodes: " << tree.countNodes() << endl;
                break;

            case 9:
                cout << "Tree height: " << tree.findHeight() << endl;
                break;

            case 10:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.deleteNode(value);
                cout << "Node deleted (if existed)." << endl;
                break;

            case 11:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
