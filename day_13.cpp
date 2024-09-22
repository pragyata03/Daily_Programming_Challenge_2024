#include <iostream>
using namespace std;

string longest_Pal_Str(string &s) {
    int n = s.length();
    if (n == 0) 
        return "";

    int start = 0, maxLen = 1;

    // Traversing the input string
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 1; j++) {
            int low = i;
            int high = i + j; 

            // Expanding substring while it is a palindrome
            while (low >= 0 && high < n && s[low] == s[high]) {
                int currLen = high - low + 1;
                if (currLen > maxLen) {
                    start = low;
                    maxLen = currLen;
                }
                low--;
                high++;
            }
        }
    }

    return s.substr(start, maxLen);
}

//Main Function
int main() {
    string s = "babad";
    cout << longest_Pal_Str(s) << endl;
    return 0;
}
