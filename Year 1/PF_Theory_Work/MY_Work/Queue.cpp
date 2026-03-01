#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node* link;
public:
    Node()
    {
        data = 0;
        link = nullptr;
    }

    void set_data(int data) {this->data = data;}
    void set_link(Node *link) {this->link = link;}

    int get_data() {return data;}
    Node *get_link() {return link;}
};

class Queue
{
private:
    Node *front, *rear;
public:
    Queue()
    {
        front = rear = nullptr;
    }

    void enQueue(int data)
    {
        Node *newNode = new Node();
        newNode->set_data(data);
        // Check if node is first...
        if (front == nullptr)
        {
            front = rear = newNode;
            return;
        }
        // Rest of nodes..
        rear->set_link(newNode);
        rear = newNode;
    }

    void deQueue()
    {
        // Check if Queue is empty..
        if (front == nullptr)
        {
            cout << "Queue is empty..\n";
            return;
        }

        Node *temp = front;
        
        // Check if the queue is last one..
        if (front == rear)
        {
            cout << "Node DeQueue: " << temp->get_data() << "\n";
            front = rear = nullptr;
            delete temp;
            return;
        }
        cout << "Node DeQueue: " << temp->get_data() << "\n";
        front = front->get_link();
        delete temp;
    }

    void display_queue()
    {
        Node *temp = front;
        while (temp != nullptr)
        {
            cout << "Data: " << temp->get_data() << "\n";
            temp = temp->get_link();
        }

    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.display_queue();
    q.deQueue();
    q.display_queue();
}