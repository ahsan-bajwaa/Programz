#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *link;

public:
    Node()
    {
        data = 0;
        link = nullptr;
    }

    void set_data(int d)
    {
        data = d;
    }

    int get_data()
    {
        return data;
    }

    void set_link(Node *l)
    {
        link = l;
    }

    Node *get_link()
    {
        return link;
    }
};

class Stack
{
private:
    Node *head;

public:
    Stack()
    {
        head = nullptr;
    }

    void Push(int value)
    {
        Node *newNode = new Node();
        newNode->set_data(value);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->set_link(head);
            head = newNode;
        }

        cout << value << " pushed into the stack." << endl;
    }

    void Pop()
    {
        if (head == nullptr)
        {
            cout << "Stack is Empty!" << endl;
            return;
        }

        cout << head->get_data() << " popped from the stack." << endl;
        Node *temp = head;
        head = head->get_link();
        delete temp;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "Stack is Empty!" << endl;
            return;
        }

        Node *temp = head;
        cout << "\nDisplaying Stack (Top to Bottom):\n";

        while (temp != nullptr)
        {
            cout << temp->get_data() << endl;
            temp = temp->get_link();
        }
        cout << endl;
    }
};

int main()
{
    Stack s;

    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Push(40);
    s.Push(50);

    s.display();

    s.Pop();
    s.Pop();

    s.display();

    s.Push(60);
    s.Push(70);

    s.display();

    return 0;
}
