#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node* prev;
    Node* next;

public:
    Node* head;
    Node* tail;

    Node()
    {
        data = 0;
        prev = nullptr;
        next = nullptr;
        head = nullptr;
        tail = nullptr;
    }

    void setData(int data)
    {
        this->data = data;
    }
    void setPrev(Node* prev)
    {
        this->prev = prev;
    }
    void setNext(Node* next)
    {
        this->next = next;
    }

    int getData()
    {
        return data;
    }
    Node* getPrev()
    {
        return prev;
    }
    Node* getNext()
    {
        return next;
    }

    void create_nodes()
    {
        for (int i = 1; i <= 20; i++)
        {
            Node* newNode = new Node();
            newNode->data = i;

            if (head == nullptr)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
    }

    void display()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << "Current Node Data: " << temp->data << endl;
            cout << "Current Node Address: " << temp << endl;
            cout << "Previous Node Link: " << temp->prev << endl;
            cout << "Next Node Link: " << temp->next << endl << endl;
            temp = temp->next;
        }
    }

    void insertBeforeHead(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtPosition(int value, int keyValue)
    {
        Node* newNode = new Node();
        newNode->data = value;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != keyValue)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr)
            {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            if (newNode->next == nullptr)
            {
                tail = newNode;
            }
        }
    }
};

int main()
{
    Node list;
    list.create_nodes();
    list.display();
    list.insertAtPosition(10, 3);
    list.display();
    return 0;
}