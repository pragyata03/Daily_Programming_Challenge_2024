#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(const string& exp) {
    stack<int> s;  // Stack to store operands

    for (size_t i = 0; i < exp.length(); i++) {
        if (exp[i] == ' ')
            continue;
            
        if (isdigit(exp[i])) {
            int num = 0;

            while (i < exp.length() && isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            s.push(num);
        }

        else {
            int val1 = s.top(); s.pop();
            int val2 = s.top(); s.pop();

            switch (exp[i]) {
                case '+': s.push(val2 + val1); 
                break;
                case '-': s.push(val2 - val1); 
                break;
                case '*': s.push(val2 * val1); 
                break;
                case '/': s.push(val2 / val1); 
                break;
            }
        }
    }
    return s.top();
}

//Main Function
int main() {
    string exp = "2 1 + 3 *";
    cout << "Solution of the Postfix Expression: " << evaluatePostfix(exp) << endl;
    return 0;
}
