#include <iostream>
#include <stack>
using namespace std;

void insert_In_Sorted_Order(stack<int> &s, int element) {
    if (s.empty() || element >= s.top()) {
        s.push(element);
        return;
    }

    int top_Element = s.top();
    s.pop();
    insert_In_Sorted_Order(s, element);
    s.push(top_Element);
}

// Recursive function to sort the stack
void sort_Stack(stack<int> &s) {
    if (s.empty())
        return;
        
    int top_Element = s.top();
    s.pop();
    sort_Stack(s);

    insert_In_Sorted_Order(s, top_Element);
}

// Function to print the stack
void print_Stack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

//Main Function
int main() {
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);

    cout << "Original stack: ";
    print_Stack(s);//LIFO
    sort_Stack(s);
    
    // Printing the sorted stack
    cout << "Sorted stack: ";
    print_Stack(s);
    return 0;
}
