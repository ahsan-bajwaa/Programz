#include <iostream>
using namespace std;

class Book
{
    string title;
    string author;
    int price;
public:

    void saveInfo()
    {
        title = "Python Crash Course, 3rd Edition";
        author = "Eric Matthes";
        price = 3999;
    };
    void displayInfo()
    {
        cout << "Book Title: " << title << endl;
        cout << "Aurthor name: " << author << endl;
        cout << "Price: " << price;
    }
};

int main()
{
    Book obj1;

    obj1.saveInfo();
    obj1.displayInfo();
}