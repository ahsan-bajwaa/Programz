#include <iostream>
using namespace std;

string reverse_string(string str, int index = 0){
    if(index == str.length()){
        return "";
    }
    return reverse_string(str, index + 1) + str[index];
}

int main(){
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string reversed = reverse_string(input);
    cout << "The reversed string is: " << reversed << endl;

}

