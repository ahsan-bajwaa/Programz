#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *right, *left;
public:
    Node()
    {
        data = 0;
        right = left = nullptr;
    }

    // Setter...
    void set_data(int d) {data = d;}
    void set_left(Node *l) {left = l;}
    void set_left(Node *r) {right = r;}

    // Getter
    int get_data() {return data;}
    Node *get_left() {return left;}
    Node *get_right() {return right;}
};

class Tree
{
private:
    Node *root;
public:
    Tree()
    {
        root = nullptr;
    }
    
    void insertTree(Node node, int data)
    {
        if (root == nullptr)
        {
            
        }
    }
};