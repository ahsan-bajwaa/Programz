// queue.cpp
#include <iostream>
#include "Node.cpp"
using namespace std;

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node();
        newNode->set_data(value);
        newNode->set_link(nullptr);

        if (rear == nullptr)
        {
            front = rear = newNode;
            return;
        }

        rear->set_link(newNode);
        rear = newNode;
    }

    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty.\n";
            return;
        }

        Node *temp = front;
        front = front->get_link();

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    void display()
    {
        Node *temp = front;
        if (temp == nullptr)
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue (Front -> Rear): ";
        while (temp != nullptr)
        {
            cout << temp->get_data() << " ";
            temp = temp->get_link();
        }
        cout << endl;
    }

    // Problem 5 — Delete Alternate Nodes (2nd, 4th, 6th, ...)
    void deleteAlternateNodes()
    {
        if (front == nullptr)
            return;

        Node *current = front;

        while (current != nullptr && current->get_link() != nullptr)
        {
            Node *toDelete = current->get_link();
            current->set_link(toDelete->get_link());

            if (toDelete == rear) // if we deleted the last node, update rear
                rear = current;

            delete toDelete;

            current = current->get_link(); // move to the next node to continue
        }
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Original: ";
    q.display();

    q.deleteAlternateNodes();

    cout << "After deleting alternate nodes: ";
    q.display();

    return 0;
}
