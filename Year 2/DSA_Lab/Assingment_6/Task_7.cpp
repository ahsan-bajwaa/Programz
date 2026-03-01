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

    void dequeue()
    {
        if (rear == nullptr)
        {
            cout << "Queue is empty.\n";
            return;
        }

        Node *front = rear->get_link();

        if (front == rear)
        {
            delete rear;
            rear = nullptr;
        }
        else
        {
            rear->set_link(front->get_link());
            delete front;
        }
    }

    void displayCircular()
    {
        if (rear == nullptr)
        {
            cout << "Queue is empty.\n";
            return;
        }

        Node *temp = rear->get_link(); // start from front

        cout << "[Front → ";

        do
        {
            cout << temp->get_data() << " → ";
            temp = temp->get_link();
        } while (temp != rear->get_link());

        cout << "Front]" << endl;
    }
};

int main()
{
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);

    cout << "Displaying Circular Queue:\n";
    cq.displayCircular();

    cq.dequeue();
    cout << "\nAfter one Dequeue:\n";
    cq.displayCircular();

    return 0;
}
