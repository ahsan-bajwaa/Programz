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

    void deleteHeadNode()
    {
        if (head == nullptr)
        {
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }

    void deleteTailNode()
    {
        if (tail == nullptr)
        {
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
    }

    void deleteByValue(int value)
    {
        if (head == nullptr)
        {
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != value)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            return;
        }

        if (temp == head)
        {
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
            delete temp;
            return;
        }

        if (temp == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
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
            temp = temp->next;
        }
        return false;
    }

    int countNodes()
    {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void removeDuplicates()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        Node* current = head;
        while (current->next != nullptr)
        {
            if (current->data == current->next->data)
            {
                Node* temp = current->next;
                current->next = temp->next;
                if (temp->next != nullptr)
                {
                    temp->next->prev = current;
                }
                else
                {
                    tail = current;
                }
                delete temp;
            }
            else
            {
                current = current->next;
            }
        }
    }

    void rotateDLL(int value)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != value)
        {
            temp = temp->next;
        }

        if (temp == nullptr || temp == head)
        {
            return;
        }

        head->prev = tail;
        tail->next = head;
        head = temp;
        tail = temp->prev;
        tail->next = nullptr;
        head->prev = nullptr;
    }
};

int main()
{
    Node list;
    list.create_nodes();
    list.display();
    list.rotateDLL(5);
    list.display();
    return 0;
}