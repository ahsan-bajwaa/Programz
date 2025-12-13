#include "Node.cpp"

class doublyLinkList
{
private:
    Node *currNode, *head;
public:
    doublyLinkList()
    {
        currNode = head = nullptr;
    }

    void createDoublyNode(int data)
    {
        Node *newNode = new Node();
        newNode->set_data(data);

        if (head == nullptr)
        {
            head = newNode;
            currNode = newNode;
            return;
        }
        currNode->set_next(newNode);
        newNode->set_prev(currNode);
        currNode = newNode;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << "Current Node Address: " << temp << endl;
            cout << "Currnet Node Data: " << temp->get_data() << endl;
            cout << "Next Node Address: " << temp->get_next() << endl;
            cout << "Previous Node Address: " << temp->get_prev() << endl;
            temp = temp->get_next();
        }
        
    }

};