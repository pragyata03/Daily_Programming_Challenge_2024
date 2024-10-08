#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1);
    
    dp[0] = 0;
    dp[1] = 1;

    // Fill the array with the Fibonacci values up to nth number
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    // Return the nth Fibonacci number
    return dp[n];
}

//Main Function
int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "The " << n << "-th Fibonacci number is: " << fibonacci(n) << endl;
    return 0;
}
