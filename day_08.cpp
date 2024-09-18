#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string reverse_Words(string s) {
    vector<string> words;  // To store the words
    string word;
    
    // Use stringstream to split the string by spaces
    stringstream ss(s);
    while (ss >> word) {
        words.push_back(word);
    }
    
    // Reverse the order of words
    reverse(words.begin(), words.end());
    
    // Join the words back into a single string: result
    string result;
    for (int i = 0; i < words.size(); ++i) {
        if (i > 0) result += " ";  // Adding spaces between words
        result += words[i];
    }
    return result;
}

int main() {
    string s = "the sky is blue";
    string result = reverse_Words(s);
    cout << "Reversed String: \"" << result << "\"" << endl;
    return 0;
}
