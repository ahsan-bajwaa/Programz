Node.cpp

#include<iostream>
using namespace std;

class Node{
private:
        Node *preLink; //its pointer of Node data type can store the address of previous node
        int value; // its a data to be stored in the node
        Node *nextLink; //its a pointer of Node data type can store the address of next node
public:
        Node(){   //Node()
        preLink = 0;
        value = 0;
        nextLink = 0;
        }
//setter functions

void setPreLink(Node *preLink){
this->preLink = preLink;
}

void setValue(int value){
this->value = value;
}

void setNextLink(Node *nextLink){
this->nextLink = nextLink;
}

//getter functions

Node *getPreLink(){return preLink;}

int getValue(){return value;}

Node *getNextLink(){return nextLink;}




};



class doublyLinkedList{
private:
        Node *head;
        Node *currNode;
public:
        doublyLinkedList(){
        head = 0;
        currNode = 0;
        }
void createList(int value){
Node *newNode = new Node();
newNode->setValue(value);

if(head == 0){
    head = newNode;
}
else{
currNode->setNextLink(newNode); //its actually storing the address of next node in the previous node using currNode pointer

newNode->setPreLink(currNode); // its storing the address of previous node in the next node using newNode poitner
}
currNode = newNode; // its moving current Node to nextnode
}

void display(){
Node *temp = head;

while(temp!=0){
    cout<<"Address of previous node : "<<temp->getPreLink()<<endl;
    cout<<"Value : "<<temp->getValue()<<endl;
    cout<<"Address of node : "<<temp<<endl;
    cout<<"Address of next node : "<<temp->getNextLink()<<endl;
    temp = temp->getNextLink();
    cout<<"\n\n";
}
}
};


int main(){
doublyLinkedList dlist1;

dlist1.createList(50);
dlist1.createList(80);
dlist1.createList(60);
dlist1.createList(90);
dlist1.createList(10);
dlist1.createList(20);

dlist1.display();
return 0;}