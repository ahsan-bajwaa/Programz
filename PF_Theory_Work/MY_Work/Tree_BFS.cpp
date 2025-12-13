
/*

queue<Node*> q;
q.push(node);   // root

while (!q.empty())
{
    Node* current = q.front();
    q.pop();

    cout << current->getValue() << " ";

    if (current->getLeft() != 0)
        q.push(current->getLeft());

    if (current->getRight() != 0)
        q.push(current->getRight());
}

*/