#include <iostream>
using namespace std;

// Function to find the greatest common divisor (GCD) using recursion
long long find_GCD(long long x, long long y) {
    if (y == 0)
        return x;

    return find_GCD(y, x % y);
}

// Function to calculate the least common multiple (LCM) of two numbers
long long find_LCM(int x, int y) {
    // LCM formula: (x * y) / GCD(x, y)
    return (x / find_GCD(x, y)) * y;
}

//Main Function
int main() {
    int num1 = 4, num2 = 6;
    cout << "The LCM of " << num1 << " and " << num2 << " is: " << find_LCM(num1, num2) << endl;

    return 0;
}
