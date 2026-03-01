#include <iostream>
#include <vector>
using namespace std;

class Node
{
private:
    string myName;
    string myPassword;
    vector<Node *> adjList;

public:
    Node(string myName, string myPassword)
    {
        this->myName = myName;
        this->myPassword = myPassword;
    }
    void setMyName(string myName)
    {
        this->myName = myName;
    }
    void setMypassword(string myPassword)
    {
        this->myPassword = myPassword;
    }
    void setNeigbour(Node *neigbour)
    {
        adjList.push_back(neigbour);
    }

    string getMyName() { return myName; }
    string getMyPass() { return myPassword; }
    vector<Node *> &getMyNeigbours() { return adjList; }
};

class Graph
{
private:
    vector<Node *> fAccounts;

public:
    bool isExist(string name, string pass)
    {
        for (int i = 0; i < fAccounts.size(); i++)
        {
            if (name == fAccounts[i]->getMyName() && pass == fAccounts[i]->getMyPass())
            {
                return true;
            }
        }
        return false;
    }
    void addAccount(string name, string password)
    {
        if (isExist(name, password))
        {
            cout << "Account already exists" << endl;
            return;
        }

        Node *newAccount = new Node(name, password);
        fAccounts.push_back(newAccount);
        cout << "Account Created with name : " << name << " password: " << password << endl;
    }

    Node *findAddress(string name, string pass)
    {
        for (int i = 0; i < fAccounts.size(); i++)
        {
            if (name == fAccounts[i]->getMyName() && pass == fAccounts[i]->getMyPass())
            {
                return fAccounts[i];
            }
        }
        return 0;
    }
    void addEdge(string name1, string pass1, string name2, string pass2)
    {
        if (isExist(name1, pass1) && isExist(name2, pass2))
        {
            Node *account1 = findAddress(name1, pass1);
            Node *account2 = findAddress(name2, pass2);

            account1->setNeigbour(account2);
            account2->setNeigbour(account1);
            cout << "Friend Request Accepted" << endl;
        }
        else
        {
            cout << "Edge can not be created" << endl;
        }
    }

    void displayFriends(string name, string pass)
    {
        Node *acc = findAddress(name, pass);

        vector<Node *> friends = acc->getMyNeigbours();
        cout << "Friends of " << name << " are : " << endl;
        for (int i = 0; i < friends.size(); i++)
        {
            cout << "Name " << friends[i]->getMyName() << endl;
        }
    }
};

int main()
{

    Graph g;

    g.addAccount("Ali", "ali@123");
    g.addAccount("Subhan", "twoazx");
    g.addAccount("Shehryar", "sher@123");
    g.addAccount("Gohar Sb", "gohar@hod");
    g.addAccount("Chairman sb", "abdul@chairmain");
    g.addAccount("Nadeem Jabbar", "dontknow@23");
    g.addAccount("Ilyas", "gobabygo");
    g.addAccount("Ans", "and@444");

    g.addEdge("Ali", "ali@123", "Nadeem Jabbar", "dontknow@23");
    g.addEdge("Ali", "ali@123", "Ans", "and@444");
    g.addEdge("Ans", "and@444", "Gohar Sb", "gohar@hod");
    g.addEdge("Gohar Sb", "gohar@hod", "Chairman sb", "abdul@chairmain");
    g.addEdge("Chairman sb", "abdul@chairmain", "Ilyas", "gobabygo");
    g.addEdge("Ilyas", "gobabygo", "Shehryar", "sher@123");
    g.addEdge("Subhan", "twoazx", "Ilyas", "gobabygo");

    g.displayFriends("Ilyas", "gobabygo");

    return 0;
}