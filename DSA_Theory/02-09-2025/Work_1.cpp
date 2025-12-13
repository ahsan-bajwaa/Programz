#include <iostream>
using namespace std;

#define SIZE 6
int Array[SIZE];
int front= -1;
int rear = -1;

void addQueue(int data)
{
    if (rear == SIZE -1)
    {
        cout << "Queue is already full..." << endl;
    }
    if (rear == -1)
    {
        front = rear = 0;
        Array[rear] = data;
        rear++;
        return;
    }
    else
    {
        Array[rear] = data;
        rear++;
    }
}