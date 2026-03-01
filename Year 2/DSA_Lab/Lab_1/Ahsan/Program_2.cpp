#include "Node.cpp"

class singlyNode
{
private:
    Node *head, *currNode;
public:
    singlyNode()
    {
        head = nullptr;
        currNode = nullptr;
    }
    void create_node(int data)
    {
        Node *newNode = new Node();
        newNode->set_data(data);
        if (head == nullptr)
        {
            head = newNode;
            currNode = newNode;
            return;
        }
        currNode->set_link(newNode);
        currNode = newNode;
        return;
    }

    bool searchByValue(int value)
    {
        Node *temp = head;
        while (temp != 0)
        {
            if (temp->get_data() == value)
            {
                return true;
            }
            temp = temp->get_link();
        }
        return false;
    }

    void display()
    {
        Node *temp = head;
        cout << "Head: " << head << endl;
        while (temp != nullptr)
        {
            cout << "Current Node Data: " << temp->get_data() << endl;
            cout << "Current Node Link: " << temp << endl;
            cout << "Next Node Link: " << temp->get_link() << endl;
            temp = temp->get_link();
        }
    
    }
};