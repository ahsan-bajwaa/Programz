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
            cout << "IT's empty...\n";
            return;
        }

        head = head->get_link();
        delete temp;
    }

    void display()
    {
        Node *temp = head;
        cout << "\nDisplaying Stack.....\n";

        while (temp != 0)
        {
            cout << "Data: " << temp->get_data() << endl;
            cout << "Link: " << temp->get_link() << endl << endl;
            temp = temp->get_link();
        }
    }
};

int main()
{
    Stack s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    s.display();
    s.Pop();
    s.display();
    s.Pop();
    s.display();
    s.Pop();
    s.display();
    s.Pop();
    s.display();
    s.Pop();
    s.display();
}