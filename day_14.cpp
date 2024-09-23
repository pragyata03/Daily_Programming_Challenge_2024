#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the number of substrings with at most k distinct characters
int count_At_Distinct(string &str, int k) {
    int n = str.size();
    int left_Pointer = 0, right_Pointer = 0;//Pointers to Traverse through string
    int unique_Chars = 0, total_Substrings = 0;
    vector<int> freq(26, 0);//Lowercase

    // Iterate with right pointer
    while (right_Pointer < n) {
        int right_Char_Index = str[right_Pointer] - 'a';
        freq[right_Char_Index]++;

        // If it's the first occurrence, increment unique character count
        if (freq[right_Char_Index] == 1) {
            unique_Chars++;
        }

        // If unique characters exceed k, move the left pointer to reduce
        while (unique_Chars > k) {
            int left_Char_Index = str[left_Pointer] - 'a';
            freq[left_Char_Index]--;

            if (freq[left_Char_Index] == 0) {
                unique_Chars--;
            }
            left_Pointer++;
        }
        total_Substrings += (right_Pointer - left_Pointer + 1);
        right_Pointer++;
    }

    return total_Substrings;
}

// Function to count substrings that have exactly k distinct characters
int count_Exactly_K_Distinct(string str, int k) {
    int at_Most_K = count_At_Distinct(str, k);
    int at_Most_K_Minus_One = count_At_Distinct(str, k - 1);
    return at_Most_K - at_Most_K_Minus_One;
}

int main() {
    string s = "pqpqs";
    int k = 2;

    int count = count_Exactly_K_Distinct(s, k);
    cout << "Number of substrings with exactly " << k << " distinct characters: " << count << endl;
    return 0;
}
