#include <iostream>
using namespace std;

class Node
{
private: 
    int data;
    Node *next, *prev;
public:
    Node()
    {
        data = 0;
        next = prev = nullptr;
    }
    void set_data(int data)
    {
        this->data = data;
    }
    void set_next(Node *next)
    {
        this->next = next;
    }void set_prev(Node *prev)
    {
        this->prev = prev;
    }
    int get_data()
    {
        return data;
    }
    Node *get_next()
    {
        return next;
    }
    Node *get_prev()
    {
        return prev;
    }
};