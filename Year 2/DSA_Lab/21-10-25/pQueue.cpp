#include<iostream>
using namespace std;

class Node
{
    int value;
    int pr;
    Node *link;
public:
    Node()
    {
        value = 0;
        pr = 0;
        link = 0;
    }

    void setValue(int value){this->value = value; }
    void setPr(int pr){this->pr = pr; }
    void setLink(Node *link){this->link = link; }

    int getValue() {return value;}
    int getPr() {return pr;}
    Node *getLink() {return link;}

};

class pQueue
{
        Node *front;
public:
        pQueue() {front = 0;}

void enqueue(int value, int pr)
{
    Node *newNode = new Node();
    newNode->setValue(value);
    newNode->setPr(pr);

    if(front == 0)
    {
        front = newNode;
    }
    else if(pr < front->getPr())
    {
    newNode->setLink(front);
    front = newNode;
    }
    else
    {
        Node *temp = front;
        while(temp->getLink()!=0 && temp->getLink()->getPr()<=pr)
        {
            temp = temp->getLink();
        }
        newNode->setLink(temp->getLink());
        temp->setLink(newNode);
    }
}


void display()
{
    Node *temp = front;
    cout<<"[ Front -> ";
    while(temp!=0){
        cout<<"("<<temp->getValue()<<","<<temp->getPr()<<")";
        if(temp->getLink()!=0)cout<<"->";
        temp = temp->getLink();
    }
    cout<<"]"<<endl;
}

};

int main()
{
    pQueue pq;

    pq.enqueue(20,4);
    pq.enqueue(28,2);
    pq.enqueue(78,9);
    pq.enqueue(12,7);
    pq.enqueue(45,1);

    pq.display();

    return 0;
}