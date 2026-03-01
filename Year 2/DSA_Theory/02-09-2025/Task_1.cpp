#include <iostream>
using namespace std;

const int SIZE = 10;
int Q1[SIZE];
int frontIndex = -1;
int rearIndex = -1;

class Node
{
    int data;
    Node *link, *front, *rear;
public:
    Node()
    {
        data = 0;
        link = front = rear = nullptr;
    }
    void enqueue (int value)
    {
        Node *newNode = new Node();
        newNode->data= value;

        if( front == nullptr)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->link = newNode;
            rear = newNode;
        }
    }

    void dequeue ()
    {
        if(frontIndex == -1)
        {
            cout<<"Queue is empty\n";
        }
        else
        {
            if(front == rear)
            {
                free(front);
                front = rear = nullptr;
            }
            else
            {
                Node *temp = front;
                front = front->link;
                free(temp);
            }
        }
    }
    
    void serveStudent()
    {
        if (frontIndex == -1 || frontIndex > rearIndex)
        {
            cout << "No students in the queue." << endl;
            return;
        }
        int roll = Q1[frontIndex++];
        cout << "Student with roll number " << roll << " is served." << endl;
        
    
        if (frontIndex > rearIndex)
        {
            frontIndex = rearIndex = -1;
        }
    }
};

int main()
{
    Node n;
    n.enqueue(101);
    n.enqueue(102);
    n.enqueue(103);


    n.dequeue();
    n.dequeue();
    n.dequeue();

    return 0;
}
