/** 
 * @author  Jane Smith
 * @date    2024-11-21
 * @version 1.0
 * @problem NONE
 * @license MIT
 */
#include <iostream>
using namespace std;
int main() {
    int num1, num2;
    char op;
    cin >> num1 >> num2 >> op;
    switch(op) {
        case '+':
            cout << num1 + num2;
            break;
        case '-':
            cout << num1 - num2;
            break;
        case '*':
            cout << num1 * num2;
            break;
        case '/':
            
            if(num2 == 0) {
                cout << "Divided by zero!";
            } else {
                cout << num1 / num2;
            }
            break;
        default:
            cout << "Invalid operator!";
    }
    
    return 0;
}