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
    //----------------------
    int getStackSize()
    {
        int count = 0;
        Node *temp = head;

        while (temp != nullptr)
        {
            count++;
            temp = temp->get_link();
        }

        return count;
    }
};

int main()
{
    Stack s;

    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << "Total elements in stack: " << s.getStackSize() << endl;

    s.Pop();
    cout << "After one pop, total elements: " << s.getStackSize() << endl;

    s.Pop();
    s.Pop();
    cout << "After clearing all, total elements: " << s.getStackSize() << endl;

    return 0;
}
