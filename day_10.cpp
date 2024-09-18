#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> group_Anagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagram_Map;

    for (string str : strs) {
        string sorted_Str = str;
        sort(sorted_Str.begin(), sorted_Str.end());
        anagram_Map[sorted_Str].push_back(str);
    }

    vector<vector<string>> result;
    for (auto& group : anagram_Map) {
        result.push_back(group.second);
    }

    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> grouped_Anagrams = group_Anagrams(strs);

    for (const auto& group : grouped_Anagrams) {
        cout << "[ ";
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
