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

    // Merge this queue with another circular queue
    void merge(CircularQueue &q2)
    {
        if (q2.rear == nullptr)
        {
            cout << "Second queue is empty, nothing to merge.\n";
            return;
        }

        if (rear == nullptr)
        {
            rear = q2.rear;
            q2.rear = nullptr;
            return;
        }

        Node *temp1 = rear->get_link();   // front of first queue
        Node *temp2 = q2.rear->get_link(); // front of second queue

        rear->set_link(temp2);     // connect end of first to start of second
        q2.rear->set_link(temp1);  // connect end of second to start of first

        rear = q2.rear;            // update rear to the new rear (end of merged queue)
        q2.rear = nullptr;         // clear second queue to avoid double-free issue
    }
};

int main()
{
    CircularQueue q1, q2;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    q2.enqueue(40);
    q2.enqueue(50);
    q2.enqueue(60);

    cout << "Queue 1 before merge:\n";
    q1.display();

    cout << "Queue 2 before merge:\n";
    q2.display();

    q1.merge(q2);

    cout << "\nAfter merging Queue 1 and Queue 2:\n";
    q1.display();

    return 0;
}
