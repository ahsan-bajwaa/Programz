#include <iostream>
#include "Node.cpp"
using namespace std;

class CircularQueue
{
private:
    Node *rear;

public:
    CircularQueue()
    {
        rear = nullptr;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node();
        newNode->set_data(value);

        if (rear == nullptr)
        {
            rear = newNode;
            rear->set_link(rear);
        }
        else
        {
            newNode->set_link(rear->get_link());
            rear->set_link(newNode);
            rear = newNode;
        }
    }

    void display()
    {
        if (rear == nullptr)
        {
            cout << "Queue is empty.\n";
            return;
        }

        Node *temp = rear->get_link();
        cout << "[Front → ";
        do
        {
            cout << temp->get_data() << " → ";
            temp = temp->get_link();
        } while (temp != rear->get_link());
        cout << "Front]" << endl;
    }

    void insertAfter(int target, int newValue)
    {
        if (rear == nullptr)
        {
            cout << "Queue is empty.\n";
            return;
        }

        Node *temp = rear->get_link(); // start from front
        bool found = false;

        do
        {
            if (temp->get_data() == target)
            {
                Node *newNode = new Node();
                newNode->set_data(newValue);
                newNode->set_link(temp->get_link());
                temp->set_link(newNode);

                if (temp == rear)
                    rear = newNode; // update rear if inserted after last node

                found = true;
                break;
            }
            temp = temp->get_link();
        } while (temp != rear->get_link());

        if (found)
            cout << "Inserted " << newValue << " after " << target << ".\n";
        else
            cout << "Value " << target << " not found in the queue.\n";
    }
};

int main()
{
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);

    cout << "Original Queue:\n";
    cq.display();

    cq.insertAfter(20, 25);
    cq.display();

    cq.insertAfter(40, 50);
    cq.display();

    cq.insertAfter(100, 200); // test for non-existent value

    return 0;
}
