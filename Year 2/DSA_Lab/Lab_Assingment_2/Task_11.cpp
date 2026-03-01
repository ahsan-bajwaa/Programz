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
        int values[] = {1, 2, 2, 3, 3, 4, 5};
        for (int i = 0; i < 7; i++)
        {
            Node* newNode = new Node();
            newNode->data = values[i];

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

    void removeDuplicates()
    {
        if (head == nullptr || head->link == nullptr)
        {
            return;
        }

        Node* current = head;
        while (current->link != nullptr)
        {
            if (current->data == current->link->data)
            {
                Node* temp = current->link;
                current->link = temp->link;
                if (temp == currNode)
                {
                    currNode = current;
                }
                delete temp;
            }
            else
            {
                current = current->link;
            }
        }
    }
};

int main()
{
    Node list;
    list.create_nodes();
    list.display();
    list.removeDuplicates();
    list.display();
    return 0;
}