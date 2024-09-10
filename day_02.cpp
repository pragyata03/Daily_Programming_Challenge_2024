#include <iostream>
using namespace std;

int missing_Number(int n, int arr[])
{
    int sum = 0;
    // Calculating the sum of array elements
    for (int i = 0; i < n - 1; i++) {
        sum += arr[i];
    }

    // Calculating the expected sum
    int expected_Sum = (n * (n + 1)) / 2;

    // Return the missing number
    return expected_Sum - sum;
}

// Main function
int main()
{
    int arr[] = { 1, 2, 4, 5 }; // Array provided in problem statement
    int n = 5;
    
    cout <<"Missing number is: "<< missing_Number(n, arr);
    return 0;
}
