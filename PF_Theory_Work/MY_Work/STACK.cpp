#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node* link;
public:
    Node()
    {
        data = 0;
        link = nullptr;
    }

    void set_data(int data) {this->data = data;}
    void set_link(Node *link) {this->link = link;}

    int get_data() {return data;}
    Node *get_link() {return link;}
};

class Stack
{
private:
    Node *top;
public:
    Stack()
    {
        top = nullptr;
    }

    void push(int data)
    {
        Node *newNode = new Node();
        newNode->set_data(data);

        // If node is first..
        if (top == nullptr)
        {
            top = newNode;
            return;
        }
        newNode->set_link(top);
        top = newNode;
    }

    void pop()
    {
        Node *temp = top;
        // If stack is empty..
        if (temp == nullptr)
        {
            cout << "IT's empty...\n";
            return;
        }
        cout << "\nData deleted: " << temp->get_data() << "\n";
        top = temp->get_link();
        delete temp;
    }

    void display_stack()
    {
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << "Data: " << temp->get_data() << "\n";
            temp = temp->get_link();
        }
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display_stack();
    s.pop();
    s.pop();
    s.display_stack();
}