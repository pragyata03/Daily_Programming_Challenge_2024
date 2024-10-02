#include <iostream>
#include <stack>
using namespace std;

void insert_At_Bottom(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
    } 
    else {
        int top_Element = st.top();
        st.pop();
        // Recursively insert the element at the bottom
        insert_At_Bottom(st, x);
        st.push(top_Element);
    }
}

// Recursive function to reverse the stack
void reverse_Stack(stack<int>& st) {
    if (!st.empty()) {
        int top_Element = st.top();
        st.pop();
        reverse_Stack(st);//Recursive call
        insert_At_Bottom(st, top_Element);
    }
}

//Function to print stack
void print_Stack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

//Main Function
int main() {
    stack<int> st;
    for (int i = 1; i <= 4; i++) {
        st.push(i);
    }
    cout << "Original Stack: ";
    print_Stack(st);
    reverse_Stack(st);
    cout << "Reversed Stack: ";
    print_Stack(st);
    return 0;
}
