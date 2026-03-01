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
    //--------------------
    void Push(char ch)
    {
        Node *newNode = new Node();
        newNode->set_data(ch);
        newNode->set_link(head);
        head = newNode;
    }

    void printReverse()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << (char)temp->get_data();
            temp = temp->get_link();
        }
        cout << endl;
    }
};

int main()
{
    Stack s;

    s.Push('H');
    s.Push('E');
    s.Push('L');
    s.Push('H');
    s.Push('O');
    cout << "Reversed word: ";
    s.printReverse();

    return 0;
}
