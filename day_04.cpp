#include <iostream>
using namespace std;

// Function to merge two sorted array
void merge_Arrays(int arr1[], int m, int arr2[], int n) {
    int i = m - 1;  // Last element in arr1's original part
    int j = n - 1;  // Last element in arr2
    int k = m + n - 1;  // Last position in arr1

    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j]) {
            arr1[k--] = arr1[i--];  // Placing the larger element at the end
        } 
        else {
            arr1[k--] = arr2[j--];  // Placing the element from arr2 in arr1
        }
    }
    while (j >= 0) {
        arr1[k--] = arr2[j--];
    }
}

int main() {
    int arr1[8] = {1, 3, 5, 7};
    int arr2[4] = {2, 4, 6, 8};

    int m = 4;  // arr1 elements number
    int n = 4;  // arr2 elements number

    // Calling the merge function
    merge_Arrays(arr1, m, arr2, n);
    for (int i = 0; i < m + n; i++) {
        cout << arr1[i] << " ";
    }
    return 0;
}