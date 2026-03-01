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
        int values[] = {5, 2, 4, 1, 3};
        for (int i = 0; i < 5; i++)
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

    void bubbleSort()
    {
        if (head == nullptr || head->link == nullptr)
        {
            return;
        }

        bool swapped;
        Node* ptr;
        Node* last = nullptr;

        do
        {
            swapped = false;
            ptr = head;

            while (ptr->link != last)
            {
                if (ptr->data > ptr->link->data)
                {
                    int temp = ptr->data;
                    ptr->data = ptr->link->data;
                    ptr->link->data = temp;
                    swapped = true;
                }
                ptr = ptr->link;
            }
            last = ptr;
        } while (swapped);
    }
};

int main()
{
    Node list;
    list.create_nodes();
    list.display();
    list.bubbleSort();
    list.display();
    return 0;
}