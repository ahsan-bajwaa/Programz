#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node* link;

public:
    Node* head;
    Node* currNode;

    Node()
    {
        data = 0;
        link = nullptr;
        head = nullptr;
        currNode = nullptr;
    }

    void setData(int data)
    {
        this->data = data;
    }
    void setLink(Node* link)
    {
        this->link = link;
    }

    int getData()
    {
        return data;
    }
    Node* getLink()
    {
        return link;
    }

    void create_nodes()
    {
        for (int i = 1; i <= 5; i++)
        {
            Node* newNode = new Node();
            newNode->data = i;

            if (head == nullptr)
            {
                head = newNode;
            }
            else
            {
                currNode->link = newNode;
            }
            currNode = newNode;
        }
    }

    void display()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << "Current Node Data: " << temp->data << endl;
            cout << "Current Node Address: " << temp << endl;
            cout << "Next Node Link: " << temp->link << endl << endl;
            temp = temp->link;
        }
    }

    bool searchByValue(int value)
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return true;
            }
            temp = temp->link;
        }
        return false;
    }
};

int main()
{
    Node list;
    list.create_nodes();
    list.display();
    if(list.searchByValue(3))
        cout << "Value found in the list." << endl;
    else
        cout << "Value not found in the list." << endl;
    return 0;
}