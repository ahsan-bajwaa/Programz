#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node* link;
    Node* currNode;
    Node *head;
public:
    Node()
    {
        data = 0;
        link = 0;
        currNode = 0;
        head = 0;
    }

    // Set data...
    void set_data(int data)
    {
        this->data = data;
    }
    // Set link...
    void set_link()
    {
        this->link = link;
    }

    // Get data...
    void get_data(int data)
    {
        this->data = data;
    }
    // Get link...
    void get_link(Node *link)
    {
        this->link = link;
    }

    void create_nodes()
    {
        for (int i  = 1; i <=20; i++)
        {
            Node *newNode = new Node();
            newNode->data = i;
            
            if (head == 0)
            {
                head = newNode;
            }
            else
            {
                currNode->link = newNode;
            }
            currNode = newNode;
        }
    }

    // Display the Nodes....
    void display()
    {
        Node *temp;
        temp = head;
        while (temp != 0)
        {
            cout << "Currnet Node Data: " << temp->data << endl;
            cout << "Currnet NOde link: " << temp << endl;
            cout << "Next Node link: " << temp->link << endl << endl;
            temp = temp->link;
        }
    }
};

int main()
{
    Node node;

    node.create_nodes();

    node.display();

    return 0;
}
