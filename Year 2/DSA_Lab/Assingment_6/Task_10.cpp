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

    void display(const string &label = "Queue")
    {
        if (rear == nullptr)
        {
            cout << label << " is empty.\n";
            return;
        }

        Node *temp = rear->get_link();
        cout << label << ": [Front → ";
        do
        {
            cout << temp->get_data() << " → ";
            temp = temp->get_link();
        } while (temp != rear->get_link());
        cout << "Front]" << endl;
    }

    int getSize()
    {
        if (rear == nullptr)
            return 0;

        int count = 0;
        Node *temp = rear->get_link();
        do
        {
            count++;
            temp = temp->get_link();
        } while (temp != rear->get_link());
        return count;
    }

    void split(CircularQueue &q1, CircularQueue &q2)
    {
        if (rear == nullptr || rear->get_link() == rear)
        {
            cout << "Not enough elements to split.\n";
            return;
        }

        int total = getSize();
        int mid = total / 2;

        Node *temp = rear->get_link();
        for (int i = 1; i < mid; i++)
        {
            temp = temp->get_link();
        }

        // temp now points to the end of the first half
        Node *head2 = temp->get_link();

        // Close the first half
        q1.rear = temp;
        q1.rear->set_link(rear->get_link());

        // Close the second half
        q2.rear = rear;
        q2.rear->set_link(head2);

        // Break the original queue
        rear = nullptr;
    }
};

int main()
{
    CircularQueue mainQ, firstHalf, secondHalf;

    mainQ.enqueue(10);
    mainQ.enqueue(20);
    mainQ.enqueue(30);
    mainQ.enqueue(40);
    mainQ.enqueue(50);
    mainQ.enqueue(60);

    cout << "Original Queue:\n";
    mainQ.display("Main Queue");

    mainQ.split(firstHalf, secondHalf);

    cout << "\nAfter Splitting:\n";
    firstHalf.display("First Half");
    secondHalf.display("Second Half");

    return 0;
}
