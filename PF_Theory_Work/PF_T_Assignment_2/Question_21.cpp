#include <iostream>
using namespace std;

int main(){
    int n, mark, highest_mark = 0, lowest_mark = 100;

    cout << "Enter number of students: ";
    cin >> n;

    for(int i = 1; i <= n; i++){
        cout << "Enter marks of student " << i << ": ";
        cin >> mark;

        if(mark > highest_mark){
            highest_mark = mark;
        }

        if(mark < lowest_mark){
            lowest_mark = mark;
        }
    }

    cout << "Highest marks: " << highest_mark << endl;
    cout << "Lowest marks: " << lowest_mark << endl;
}

