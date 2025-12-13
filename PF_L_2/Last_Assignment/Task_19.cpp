#include <iostream>
using namespace std;

class Inventory
{
private:
    int price;
    static int total_items;
    static int total_values;

public:
    Inventory(int p)
    {
        price = p;
        total_items++;
        total_values += p;
    }

    // Static function to return total value.
    static int get_total_values()
    {
        return total_values;
    }

    // Static function to return total item count.
    static int get_item_count()
    {
        return total_items;
    }
};

int Inventory::total_items = 0;
int Inventory::total_values = 0;

int main()
{
    // Create inventory items
    Inventory item1(100);
    Inventory item2(150);
    Inventory item3(250);

    // Access static functions using class name (no object needed)
    cout << "Total value: " << Inventory::get_total_values() << endl;
    cout << "Total items: " << Inventory::get_item_count() << endl;

    /*
    Answer:
        - Static functions can be called without an object (Inventory::get_total_values()).
        - Static data is shared across all instances.
        - When new objects are created, static members update for all.
        - Non-static members (like price) belong to individual objects.
    */

    return 0;
}
