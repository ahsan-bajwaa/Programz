#include "Node.cpp"

class Stack
{
private:
    Node *head;

public:
    Stack()
    {
        head = nullptr;
    }

    void Push(int data)
    {
        Node *newNode = new Node();
        newNode->set_data(data);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->set_link(head);
        head = newNode;
    }

    void Pop()
    {
        Node *temp = head;

        if (temp == nullptr)
        {
            cout << "It's empty...\n";
            return;
        }

        head = head->get_link();
        delete temp;
    }
    //------------------------
    void isEmpty()
    {
        if (head == nullptr)
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            cout << "Stack is not empty.\n";
        }
    }
};

int main()
{
    Stack s;

    s.isEmpty(); // Should say "Stack is empty"

    s.Push(10);
    s.isEmpty(); // Should say "Stack is not empty"

    s.Pop();
    s.isEmpty(); // Should say "Stack is empty" again

    return 0;
}
