#include <iostream>
using namespace std;

// Function to print permutations of the string
void permute(string&s, int idx)//Parameter: String, start index of string
{
    if (idx == s.size() - 1) {
        cout << s << endl;
        return;
    }

    for (int i = idx; i < s.size(); i++) {
      
        // Swapping 
        swap(s[idx], s[i]);

        // First idx+1 characters fixed
        permute(s, idx + 1);

        // Backtrack
        swap(s[idx], s[i]);
    }
}

// Wrapper function
void permute_display(string&s){
    permute(s, 0);
}

//Main function
int main(){
    string s = "abc";
    cout<<"Permutation of the string \'abc' is: ";
    permute_display(s);
    return 0;
}
