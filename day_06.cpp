#include <iostream>
using namespace std;

void zero_Sum_Subarrays(const int arr[], int n) {
    int max_Subarrays = n * (n + 1) / 2;  
    int result[max_Subarrays][2];  
    int count = 0; 
    
    // Traversing each subarray
    for (int start = 0; start < n; ++start) {
        int sum = 0;
        for (int end = start; end < n; ++end) {
            sum += arr[end];  // Calculate sum of subarray
            
            // If the sum is zero, store the subarray's start and end indices
            if (sum == 0) {
                result[count][0] = start;
                result[count][1] = end;   
                count++;  
            }
        }
    }
    if (count == 0) {
        cout << "No subarray with zero sum found." << endl;
    } else {
        for (int i = 0; i < count; ++i) {
            cout << "Subarray found from index (" <<result[i][0]<< ","<< result[i][1]<<")" << endl;
        }
    }
}

int main() {
    int arr[] = {1, 2, -3, 3, -1, 2};
    int n = sizeof(arr) / sizeof(int);
    zero_Sum_Subarrays(arr, n);
    return 0;
}
