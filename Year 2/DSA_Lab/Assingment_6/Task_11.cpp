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

    void countEvenOdd()
    {
        if (rear == nullptr)
        {
            cout << "Queue is empty.\n";
            return;
        }

        int evenCount = 0, oddCount = 0;
        Node *temp = rear->get_link();

        do
        {
            int value = temp->get_data();
            if (value % 2 == 0)
                evenCount++;
            else
                oddCount++;

            temp = temp->get_link();
        } while (temp != rear->get_link());

        cout << "Even elements: " << evenCount << endl;
        cout << "Odd elements: " << oddCount << endl;
    }
};

int main()
{
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(15);
    cq.enqueue(22);
    cq.enqueue(37);
    cq.enqueue(48);

    cout << "Circular Queue:\n";
    cq.display();

    cout << "\nCounting Even and Odd Elements:\n";
    cq.countEvenOdd();

    return 0;
}
