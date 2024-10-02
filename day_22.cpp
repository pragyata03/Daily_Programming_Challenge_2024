#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int first_Element_Repeat_K_Times(vector<int>& arr, int k) {
    unordered_map<int, int> frequency;
    for (int i : arr) {
        if (frequency.find(i) != frequency.end()) {
            frequency[i]++;
        } 
        else {
            frequency[i] = 1;
        }
    }
    for (auto& pair : frequency) {
        if (pair.second == k) {
            return pair.first;
        }
    }
    return -1;
}

//Main Function
int main() {
    vector<int> arr = {3, 1, 4, 4, 5, 2, 6, 1, 4};
    int k = 2;
    int result = first_Element_Repeat_K_Times(arr, k);
    if (result != -1) {
        cout << "First element that appears exactly " << k << " times: " << result << endl;
    } 
    else {
        cout << "No element appears exactly " << k << " times in the array." << endl;
    }
    return 0;
}
