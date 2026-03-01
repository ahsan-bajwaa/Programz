#include "Node.cpp"

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

    void enqueue(int data)
    {
        Node *newNode = new Node();
        newNode->set_data(data);
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

    void displayQueue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty.\n";
            return;
        }

        Node *temp = front;
        cout << "Queue elements (Front → Rear): ";
        while (temp != nullptr)
        {
            cout << temp->get_data() << " ";
            temp = temp->get_link();
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.displayQueue();

    q.dequeue();
    q.displayQueue();

    return 0;
}
