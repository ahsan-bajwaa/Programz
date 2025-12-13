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

    // Enqueue operation
    void enqueue(int value)
    {
        Node *newNode = new Node();
        newNode->set_data(value);

        if (rear == nullptr)
        {
            rear = newNode;
            rear->set_link(rear); // circular link
        }
        else
        {
            newNode->set_link(rear->get_link()); // new node points to front
            rear->set_link(newNode);              // old rear points to new node
            rear = newNode;                       // update rear
        }
    }

    // Dequeue operation
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
            // only one node
            delete rear;
            rear = nullptr;
        }
        else
        {
            rear->set_link(front->get_link());
            delete front;
        }
    }

    // Display queue
    void display()
    {
        if (rear == nullptr)
        {
            cout << "Queue is empty.\n";
            return;
        }

        Node *temp = rear->get_link(); // start from front
        cout << "Circular Queue: ";

        do
        {
            cout << temp->get_data() << " ";
            temp = temp->get_link();
        } while (temp != rear->get_link());

        cout << endl;
    }
};

int main()
{
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);

    cout << "After Enqueue Operations:\n";
    cq.display();

    cq.dequeue();
    cq.dequeue();

    cout << "After Dequeue Operations:\n";
    cq.display();

    return 0;
}
