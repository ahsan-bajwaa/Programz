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

class Singly_Link_List
{
private:
    Node *head, *currNode;
public:
    Singly_Link_List()
    {
        head = nullptr;
        currNode = nullptr;
    }

    void insert_node(int data)
    {
        Node *newNode = new Node();
        newNode->set_data(data);
        // Check if node is first or not.
        if (head == nullptr)
        {
            head = newNode;
            currNode = head;
            return;
        }
        currNode->set_link(newNode);
        currNode = newNode;
    }

    void delete_head()
    {
        Node *temp = head;
        head = head->get_link();
        delete temp;
    }

    void delete_at_position(int pos)
    {
        Node *temp = head;
        Node *node_to_delete = nullptr;
        int count = 1;
        while(temp != nullptr)
        {
            if (count +1 == pos)
            {
                node_to_delete = temp->get_link();
                temp->set_link(node_to_delete->get_link());
                cout << "Number Deleted: " << node_to_delete->get_data();
                delete node_to_delete;
            }
            temp = temp->get_link();
            count++;

        }
    }

    void delete_by_value(int data)
    {
        Node *temp, *node_to_delete;
        temp = head;
        while (temp != nullptr)
        {

            // For the first Node
            if (temp->get_data() == data)
            {
                node_to_delete = temp;
                head = head->get_link();
                delete node_to_delete;
                return;
            }
            // Rest of Nodes.
            if (temp->get_link() != nullptr && temp->get_link()->get_data() == data)
            {
                node_to_delete = temp->get_link();
                temp->set_link(node_to_delete->get_link());
                cout << "Node deleted: " << node_to_delete->get_data() << "\n";
                delete node_to_delete;
                return;
            }
            temp = temp->get_link();
        }
        cout << "Number not founded...\n";
    }

    void display_node()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << "\nData: " << temp->get_data();
            temp = temp->get_link();
        }
    }

};

int main()
{
    Singly_Link_List s;
    s.insert_node(1);
    s.insert_node(2);
    s.insert_node(3);
    s.insert_node(4);
    s.display_node();
    cout << "\n";
    s.delete_by_value(5);
    cout << "\n";
    s.display_node();
}