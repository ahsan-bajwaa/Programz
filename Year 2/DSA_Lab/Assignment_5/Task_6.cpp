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

    void Push(char ch)
    {
        Node *newNode = new Node();
        newNode->set_data(ch);
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
    //--------------
    bool isEmpty()
    {
        return head == nullptr;
    }

    void checkBalancedParenthesis(string str)
    {
        for (char ch : str)
        {
            if (ch == '(')
                Push(ch);
            else if (ch == ')')
            {
                if (isEmpty())
                {
                    cout << "Unbalanced\n";
                    return;
                }
                Pop();
            }
        }

        if (isEmpty())
            cout << "Balanced\n";
        else
            cout << "Unbalanced\n";
    }
};

int main()
{
    Stack s;

    s.checkBalancedParenthesis("(A+B)");
    s.checkBalancedParenthesis("(A+B*(C-D))");
    s.checkBalancedParenthesis("(A+B*(C-D)");

    return 0;
}
