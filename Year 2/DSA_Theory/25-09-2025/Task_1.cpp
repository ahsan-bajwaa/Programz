#include <iostream>
using namespace std;

class Stack
{
private:
    int data;
    Stack *Top, *currNode, *head;
public:
    Stack()
    {
        data = 0;
        Top = currNode = head = nullptr;
    }
    void get_data(int data)
    {
        this->data = data;
    }
    void get_Top(Stack *Top)
    {
        this->Top = Top;
    }

    void insert_value(int data)
    {
        Stack* newNode = new Stack();
        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            currNode->Top = newNode;
        }
        currNode = newNode;
    }

    void display()
    {
        Stack *temp = Top;
        while (temp != head)
        {
            cout << "Data: " << temp->data << endl;
            temp = temp->Top;
        }
    }

};

int main()
{
    Stack s1;
    s1.insert_value(3);
    s1.insert_value(9);
    s1.insert_value(56);
    s1.insert_value(15);
    s1.insert_value(53);
    s1.insert_value(75);
    s1.display();
}