#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue
{
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int value)
    {
        if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front))
        {
            cout << "Queue is Full!" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        cout << value << " inserted into the queue." << endl;
    }
    
    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << arr[front] << " removed from the queue." << endl;

        // If only one element left
        if (front == rear)
        {
            front = -1;
            rear = -1;
        } else
        {
            front = (front + 1) % SIZE;
        }
    }
};

int main()
{
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);  // Will show "Queue is Full"

    q.dequeue();
    q.dequeue();

    q.enqueue(70);
    q.enqueue(80);

    return 0;
}