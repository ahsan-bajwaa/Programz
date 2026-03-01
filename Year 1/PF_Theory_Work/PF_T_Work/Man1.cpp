#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double apples, mangoes, bananas;
    const float a = 1.20; // Price of apples
    const float m = 1.50; // Price of mangoes
    const float b = 0.50; // Price of bananas

    cout << "Enter the number of apples: ";
    cin >> apples;
    cout << "Enter the number of mangoes: ";
    cin >> mangoes;
    cout << "Enter the number of bananas: ";
    cin >> bananas;
    cout << endl;

    cout << "************ Receipt ************" << endl;
    cout << left << setw(10) << "Fruit" 
         << setw(15) << "Unit Price" 
         << setw(10) << "Quantity" 
         << setw(10) << "Total" << endl;

    cout << left << setw(10) << "Apples";
    cout<<"$" << setw(15) << fixed << setprecision(2) << a 
         << setw(10) << apples; 
    cout<<"$"     << setw(10) << fixed << setprecision(2) << a * apples << endl;

    cout << left << setw(10) << "Mangoes"; 
    cout<<"$" << setw(15) << fixed << setprecision(2) << m 
         << setw(10) << mangoes;
    cout<<"$"     << setw(10) << fixed << setprecision(2) << m * mangoes << endl;

    cout << left << setw(10) << "Bananas"; 
    cout<<"$"     << setw(15) << fixed << setprecision(2) << b 
         << setw(10) << bananas ;
    cout<<"$"     << setw(10) << fixed << setprecision(2) << b * bananas << endl;

    double totalAmountDue = a * apples + m * mangoes + b * bananas;
    cout << "Total amount due: "<<"$" << fixed << setprecision(2) << totalAmountDue << endl;

    return 0;
}
