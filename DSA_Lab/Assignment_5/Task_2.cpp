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

    void get_top()
    {
        cout << "Top: " << head->get_data() << endl;
    }
};

int main()
{
    Stack s;
    s.Push(1);
    s.Push(2);
    s.Push(4);
    s.get_top();
}