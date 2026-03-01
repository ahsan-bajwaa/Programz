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

    // --- Setters ---
    void setData(int data)
    {
        this->data = data;
    }
    void setLink(Node* link)
    {
        this->link = link;
    }

    // --- Getters ---
    int getData()
    {
        return data;
    }
    Node* getLink()
    {
        return link;
    }

    // --- Create initial 5 nodes ---
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

    // --- Display the List ---
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
};
