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

        if (rear == nullptr) // Queue is empty
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

        // If queue becomes empty after dequeue
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
    q.enqueue(40);

    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    return 0;
}
