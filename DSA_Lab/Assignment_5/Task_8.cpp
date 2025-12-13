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
        newNode->set_link(head);
        head = newNode;
    }

    void Pop()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        head = head->get_link();
        delete temp;
    }
    // --------------
    void displayWithoutAltering()
    {
        Node *temp = head;

        cout << "Stack elements (top to bottom): ";
        while (temp != nullptr)
        {
            cout << temp->get_data() << " ";
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

    s.displayWithoutAltering();

    return 0;
}
