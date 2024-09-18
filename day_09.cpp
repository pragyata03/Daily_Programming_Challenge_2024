#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longest_Common_Prefix(vector<string>& strs) {
    if (strs.empty()) return ""; 
    string prefix = strs[0];//First string: prefix
    
    // Comparing the assumed prefix with each string in the list.
    for (int i = 1; i < strs.size(); ++i) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);  // Remove the last character.
            if (prefix.empty()) return "";  // If prefix becomes empty, return empty string.
        }
    }
    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    string result = longest_Common_Prefix(strs);
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}
