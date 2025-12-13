/*

#include <stack>

void dfsUsingStack(Node* root)
{
    if (root == 0)
        return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty())
    {
        Node* current = st.top();
        st.pop();

        cout << current->getValue() << " ";

        // Push right first so left is processed first
        if (current->getRight() != 0)
            st.push(current->getRight());

        if (current->getLeft() != 0)
            st.push(current->getLeft());
    }
}

*/
