#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

void displayMenu(string menu[], int prices[], int menuCount) {
    cout << "Menu:" << endl;
    for (int i = 0; i < menuCount; i++) {
        cout << "- " << menu[i] << " - " << prices[i] << " Rs" << endl;
    }
}


bool takeOrder(string menu[], int prices[], int menuCount, string cart[], int quantities[], int& cartSize) {
    string order;
    int quantity;
    
    cout << "Enter the name of the product you want to order: ";
    cin >> ws;
    cin >> order;
    
    
    bool found = false;
    for (int i = 0; i < menuCount; i++) {
        if (menu[i] == order) {
            cout << "Enter quantity: ";
            cin >> quantity;
            
            cart[cartSize] = order;
            quantities[cartSize] = quantity;
            cartSize++;
            
            found = true;
            break;
        }
    }
    return found;
}

int calculateTotal(string cart[], int quantities[], int prices[], int cartSize) {
    int total = 0;
    for (int i = 0; i < cartSize; i++) {
        for (int j = 0; j < 5; j++) {
            if (cart[i] == cart[j]) {
                total += prices[j] * quantities[i];
            }
        }
    }
    return total;
}

double applyDiscount(int total, string coupon) {
    double discount = 0;
    if (coupon == "DISCOUNT10") {
        discount = total * 0.10;
    }
    return discount;
}


void displayBill(string cart[], int quantities[], int prices[], int cartSize, int total, double discount) {
    cout << "\n----- BILL -----" << endl;
    cout << left << setw(20) << "Item" << setw(10) << "Quantity" << setw(10) << "Price" << "Total" << endl;
    cout << "---------------------------------------------" << endl;

    for (int i = 0; i < cartSize; i++) {
        for (int j = 0; j < 5; j++) {
            if (cart[i] == cart[j]) {
                int itemTotal = prices[j] * quantities[i];
                cout << left << setw(20) << cart[i]
                     << setw(10) << quantities[i]
                     << setw(10) << prices[j]
                     << itemTotal << " Rs" << endl;
            }
        }
    }

    cout << "---------------------------------------------" << endl;
    cout << "Total: " << total << " Rs" << endl;

    if (discount > 0) {
        cout << "Discount Applied: -" << discount << " Rs" << endl;
        cout << "Final Amount: " << total - discount << " Rs" << endl;
    } else {
        cout << "No discount applied." << endl;
    }
    cout << "Thank you for dining with us!" << endl;
}


int main() {
    string menu[] = {"Burger", "Pizza", "Shawarma", "Sandwich", "Fries"};
    int prices[] = {850, 3000, 750, 500, 600};
    int menuCount = 5;
    
    string cart[100]; 
    int quantities[100];  
    int cartSize = 0;  
    int total = 0;
    string coupon;
    char choice;
    
    cout << "----- Welcome to Our Restaurant -----" << endl;
    

    displayMenu(menu, prices, menuCount);
    
    do {
        
        if (!takeOrder(menu, prices, menuCount, cart, quantities, cartSize)) {
            cout << "Invalid item. Try again." << endl;
        }
        
        cout << "Do you want to add more items? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
    
    cout << "Enter coupon code (if any, else press enter): ";
    cin >> coupon;
    
    
    total = calculateTotal(cart, quantities, prices, cartSize);
    
    
    double discount = applyDiscount(total, coupon);
    
    
    displayBill(cart, quantities, prices, cartSize, total, discount);
    
    return 0;
}