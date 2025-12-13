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

    int getQueueSize()
    {
        int count = 0;
        Node *temp = front;

        while (temp != nullptr)
        {
            count++;
            temp = temp->get_link();
        }

        return count;
    }

    void display()
    {
        Node *temp = front;
        if (temp == nullptr)
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
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

    q.display();

    cout << "Queue size: " << q.getQueueSize() << endl;

    q.dequeue();
    cout << "Queue size after dequeue: " << q.getQueueSize() << endl;

    return 0;
}
