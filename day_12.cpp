#include <iostream>
using namespace std;

// Check if characters match
bool check(char c1, char c2){
    if (c1 == '(' && c2 == ')') return true;
    if (c1 == '[' && c2 == ']') return true;
    if (c1 == '{' && c2 == '}') return true;
    else return false;
}

// Check if parentheses are balanced
bool parenthesis(string s){
  
    // Initialize with -1 on top of stack
    int top = -1;
    for (int i = 0; i < s.length(); ++i){
      
        // Push char if stack is empty or no match
        if (top < 0 || !check(s[top], s[i])){
            ++top;
            s[top] = s[i];
        }
        else{
            // Pop from stack
            --top;
        }
    }
  
    // Return true if stack is empty (is balanced)
    return top == -1;
}

//Main Function
int main(){
    string s = "{[()]}";
    cout << (parenthesis(s) ? "True" : "False") << endl;
    return 0;
}
