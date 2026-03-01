#include <iostream>
using namespace std;

class Base
{
public:
    void public_function()
    {
        cout << "Base: Public Function\n";
    }

protected:
    void protected_function()
    {
        cout << "Base: Protected Function\n";
    }

private:
    void private_function()
    {
        cout << "Base: Private Function\n";
    }
};

// 1. Public Inheritance
class Public_drived : public Base
{
public:
    void access()
    {
        public_function();
        protected_function();
        // private_function(); // Not accessible.
    }
};

// 2. Protected Inheritance
class Protected_derived : protected Base
{
public:
    void access()
    {
        public_function();
        protected_function();
        // private_function(); // Not accessible private fun.
    }
};

// 3. Private Inheritance
class Pirvate_derived : private Base
{
public:
    void access()
    {
        public_function();
        protected_function();
        // private_function(); // Not accessible private fun.
    }
};

int main()
{
    cout << "From Public inheritence.\n"; 
    Public_drived public_drived;
    public_drived.access();

    cout << "From Protected inheritence.\n";
    Protected_derived protected_derived;
    protected_derived.access();
    // protected_derived.public_function(); // Error: Becomes protected

    cout << "From Private inheritence.\n";
    Pirvate_derived pirvate_derived;
    pirvate_derived.access();
    // pirvate_derived.public_function(); // Error: Becomes private

    return 0;
}
