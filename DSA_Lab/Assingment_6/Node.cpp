#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *link;

public:
    Node()
    {
        data = 0;
        link = nullptr;
    }

    void set_data(int d)
    {
        data = d;
    }

    void set_link(Node *l)
    {
        link = l;
    }

    int get_data()
    {
        return data;
    }

    Node *get_link()
    {
        return link;
    }
};
