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

    char Pop()
    {
        if (head == nullptr)
            return '\0';

        Node *temp = head;
        char ch = head->get_data();
        head = head->get_link();
        delete temp;
        return ch;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
    //----------
    bool isPalindrome(string str)
    {
        for (char ch : str)
            Push(ch);

        string reversed = "";
        while (!isEmpty())
            reversed += Pop();

        return (str == reversed);
    }
};

int main()
{
    Stack s;

    string word1 = "MADAM";
    string word2 = "HELLO";

    if (s.isPalindrome(word1))
        cout << word1 << " is Palindrome\n";
    else
        cout << word1 << " is Not Palindrome\n";

    if (s.isPalindrome(word2))
        cout << word2 << " is Palindrome\n";
    else
        cout << word2 << " is Not Palindrome\n";

    return 0;
}
