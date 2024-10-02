#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Function to get the maximum element in each sliding window of size k
vector<int> find_Max_In_Windows(vector<int>& arr, int k) {
    vector<int> result;
    set<pair<int, int>, greater<pair<int, int>>> window_Elements;
    for (int i = 0; i < k; ++i)
        window_Elements.insert({arr[i], i});
    result.push_back(window_Elements.begin()->first);

    for (int i = k; i < arr.size(); ++i) {
        window_Elements.insert({arr[i], i});
        window_Elements.erase({arr[i - k], i - k});
        result.push_back(window_Elements.begin()->first);
    }
    return result;
}

//Main Function
int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = find_Max_In_Windows(arr, k);\
    cout<< "Sliding window output: "<< endl; 
    for (int max_Val : result)
        cout << max_Val << " ";
    cout << endl;
    return 0;
}
