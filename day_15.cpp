#include <iostream>
#include <vector>
using namespace std;

int find_Longest_Unique_Substring(const string& input) {

    if (input.empty())
        return 0;

    if (input.size() == 1)
        return 1;

    int max_Length = 0;
    vector<bool> is_Char_Present(256, false);

    int window_Start = 0, window_End = 0;

    while (window_End < input.size()) {

        // encounter a duplicate character, adjust the window from the start
        while (is_Char_Present[input[window_End]]) {
            is_Char_Present[input[window_Start]] = false; // Unmark the character
            window_Start++;
        }

        // Mark the current character as visited
        is_Char_Present[input[window_End]] = true;

        max_Length = max(max_Length, window_End - window_Start + 1);

        window_End++;
    }

    return max_Length;
}

//Main Function
int main() {
    string S = "abcabcbb";
    cout << "Length of the longest substring with unique characters: "<< find_Longest_Unique_Substring(S) <<endl;
    return 0;
}