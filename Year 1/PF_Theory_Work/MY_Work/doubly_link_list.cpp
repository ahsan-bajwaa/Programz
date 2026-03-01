#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node* next;
    Node* prev;
public:
    Node()
    {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }

    void set_data(int data) {this->data = data;}
    void set_next(Node *link) {this->next = link;}
    void set_prev(Node *link) {this->prev = link;}

    int get_data() {return data;}
    Node *get_next() {return next;}
    Node *get_prev() {return prev;}
};

class Doubly_Link_List
{
private:
    Node *head, *currNode;
public:
    Doubly_Link_List()
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
        currNode->set_next(newNode);
        newNode->set_prev(currNode);
        currNode = newNode;
    }

    void delete_head()
    {
        Node *temp = head;
        head = head->get_next();
        head->set_prev(nullptr);
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
                node_to_delete = temp->get_next();
                temp->set_next(node_to_delete->get_next());
                node_to_delete->get_next()->set_prev(temp);
                cout << "Number Deleted: " << node_to_delete->get_data();
                delete node_to_delete;
            }
            temp = temp->get_next();
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
                head->set_prev(nullptr);
                head = head->get_next();
                delete node_to_delete;
                return;
            }
            // Rest of Nodes.
            if (temp->get_next() != nullptr && temp->get_next()->get_data() == data)
            {
                node_to_delete = temp->get_next();
                temp->set_next(node_to_delete->get_next());
                node_to_delete->get_next()->set_prev(temp);
                cout << "Node deleted: " << node_to_delete->get_data() << "\n";
                delete node_to_delete;
                return;
            }
            temp = temp->get_next();
        }
        cout << "Number not founded...\n";
    }

    void display_node()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << "\nData: " << temp->get_data();
            temp = temp->get_next();
        }
    }

};

int main()
{
    Doubly_Link_List s;
    s.insert_node(1);
    s.insert_node(2);
    s.insert_node(3);
    s.insert_node(4);
    s.display_node();
    cout << "\n";
    s.delete_by_value(3);
    cout << "\n";
    s.display_node();
}