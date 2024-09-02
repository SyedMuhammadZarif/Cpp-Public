#include <iostream>
#include <string>
using namespace std;

// Template function to find the maximum of two values
template <typename T>
T custom_max(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    int choice;
    cout << "Enter the type of data you want to compare: " << '\n';
    cout << "#1 Integer" << '\n';
    cout << "#2 String" << '\n';
    cout << "#3 Char" << '\n';
    cout << "#4 Float" << '\n';
    cout << "Your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int x, y;
            cout << "\nEnter the first integer: ";
            cin >> x;
            cout << "Enter the second integer: ";
            cin >> y;
            cout << "The maximum value is: " << custom_max(x, y) << endl;
            break;
        }
        case 2: {
            string x, y;
            cout << "\nEnter the first string: ";
            cin >> x;
            cout << "Enter the second string: ";
            cin >> y;
            cout << "The maximum value is: " << custom_max(x, y) << endl;
            break;
        }
        case 3: {
            char x, y;
            cout << "\nEnter the first character: ";
            cin >> x;
            cout << "Enter the second character: ";
            cin >> y;
            cout << "The maximum value is: " << custom_max(x, y) << endl;
            break;
        }
        case 4: {
            float x, y;
            cout << "\nEnter the first float: ";
            cin >> x;
            cout << "Enter the second float: ";
            cin >> y;
            cout << "The maximum value is: " << custom_max(x, y) << endl;
            break;
        }
        default:
            cout << "Invalid Choice! Please run the program again and select a valid option." << endl;
            return 0;
    }

    return 0;
}
